/**
 * @file txfbase.h(fs/internal)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-08
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_FS_INTERNAL_TXFBASE_H__
#define __DTY_NATIVE_FS_INTERNAL_TXFBASE_H__

#include "./base.h"

#include "./error_list.h"

 // Define the default size for all the TXF cache
 // default size is 1 millin bytes
#define __DTY_FS_TXF_CACHE_DEFAULT_SIZE__ 0x100000

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

    // pure C definations

// ==========================================================================
// Const Value Definations for TYXF
// ==========================================================================

// Define TYXF addressing length for block part
// that means the lowest 8 bits are used to loacte block column
// each segment can contain 256 blocks, the first block is configure segment
// only 255 blocks can be used to save data.
__DEFAULT__ const int32 __VARIABLE__ dty_fs_internal_txf_address_block = 8;

// Define TYXF addressing length for segment part
// that means the mid 24 bits are used to loacte segment row
// each group can contain 2^24 segments, the first segment is configure group
// only 2^24 - 1 segment can be used to save data.
__DEFAULT__ const int32 __VARIABLE__ dty_fs_internal_txf_address_segment = 24;

// Define TYXF addressing length for group part
// that means the highest 16 bits are used to loacte group page
// each logic TYXF file(s) can contain 65536 pages, all of the pages can save
// data.
__DEFAULT__ const int32 __VARIABLE__ dty_fs_internal_txf_address_page = 16;

// Define TYXF section maximum size for customized area
__DEFAULT__ const int32 __VARIABLE__ dty_fs_internal_txf_section_size_max = 128;

// Define TYXF block size
// this is a const value
// for TYDS(tianyu disk system), this item is a variable value. But for TYXF, 
// to set a hard code value to reduce the complexity of decoding.
__DEFAULT__ const int32 __VARIABLE__ dty_fs_internal_txf_block_size = 4096;

__DEFAULT__ const byte __VARIABLE__ dty_fs_internal_txf_block_type_none = (byte)0x00;
__DEFAULT__ const byte __VARIABLE__ dty_fs_internal_txf_block_type_data = (byte)0xFF;
__DEFAULT__ const byte __VARIABLE__ dty_fs_internal_txf_block_type_sect = (byte)0xEF;
__DEFAULT__ const byte __VARIABLE__ dty_fs_internal_txf_block_type_dict = (byte)0x0E;
__DEFAULT__ const byte __VARIABLE__ dty_fs_internal_txf_block_type_idxf = (byte)0xA0;
__DEFAULT__ const byte __VARIABLE__ dty_fs_internal_txf_block_type_idxs = (byte)0xA1;
__DEFAULT__ const byte __VARIABLE__ dty_fs_internal_txf_block_type_idxt = (byte)0xA2;

// ==========================================================================
// Base Structures for TYXF
// ==========================================================================

// pre-define for TXF Section list type
// Section list is used to describe an additional info.
// eg:
// for DataBase, to provide index function
__PREDEFINE__ typedef struct dty_fs_internal_txf_section_list    _TXFSectionList;

// pre-define for TXF Data Recording Bootstrap Cache
// Data Recording Bootstrap is used to provide meter data indexable
// eg:
// create a new file will add a new record for it and link it into a folder line.
// each file or folder must to have a single strong recording line, and can also
// have some weak reference like a desktop shortcut.
__PREDEFINE__ typedef struct dty_fs_internal_txf_drb_cache       _TXFDRBCache;

// pre-define for TXF Fact Data Cache
// Fact Data Cache is used to provide data cache to save operation times. each load
// prograss will read or write a whole block. There will be a LRU if the cache is
// full. each cache line should have some flags to indicate the write-back and the
// reload strategies.
__PREDEFINE__ typedef struct dty_fs_internal_txf_fact_data_cache _TXFFactDataCache;

// Define TYXF basic structure
// pure C mode struct
// only provides some basic infos and basic operations in the following
// this structure should not be used without TYXF class package
//
// In designation of TYFS and TXF file, several million bytes should be cached
// in memory after the instance is loaded to keep some base infos.
// contains:
// + base configures: Page data, Usage Bitmap data, existed segment count
// + core data area : section list 
//                    (128 sections supported includes Data Recording Bootstrap)
// + directory cache: base on the open configure to allocate some memory to keep
//                    DRB relations and hierarchies.
// + segment cache  : base on the open configure to allocate some continues space
//                    to keep some fact data. in the cache, uses LRU to reload
//                    new data
//
// WARNING: Multi-threads is NOT supported in this instance, all the operations
//          are designed for Single-thread
//
// NOTES: for a same file, for designing, there should only one file instance
//        is existing.
typedef struct dty_fs_internal_txf_base
{
    // IO instance object
    // Get a Tianyu IO instance object to operate the TXF file
    // The IOHandle has dependency from dty_io module
    IOHandle   __VARIABLE__ _handle;

    // Tianyu internal error list 
    // There is a stack ring to push and pop errors, for safely,
    // there should be read and write only through error_list
    // internal functions.
    _ErrorList __VARIABLE__ _errorList;

    _FSUserTable __VARIABLE__ _userTable[dty_fs_internal_user_table_size];

    // The below part is the start of a file
    // page configure describes the current has a(some) connection
    // file(s) or not.
    // only for file pageIndex = 0 case, the core data and other
    // important part will be loaded into memory.
#pragma region pages configure part: page data
    // Flag for multi-page mode state
    // if true, that means this file has connected file(s) need to be
    // load, only this file is not supported to provide data operation
    // if false, that means this file is a single file, it can work
    // immediately 
    bool   __VARIABLE__ _isMultiPageMode;
    // Page index for current file
    // Get a unsigned short integer to describe which ths position of
    // this file is.
    // this field will work only when the _isMultiPageMode is true.
    // if this field is not zero, the data part will be ignored due to
    // the meter data is not here.
    uint16 __VARIABLE__ _pageIndex;
    // Page ID that is a description for this file which page is in.
    // this id is a 128bits(16bytes) GUID to, all the files which are
    // in a same page should have with non-difference.
    // if _isMultiPageMode is false, this field will be 0x00 and ignored,
    // there is also no matter for not 0x00.
    byte   __VARIABLE__ _pageId[dty_fs_default_ids_length];
    // Page count for the all multi pages need to be rquired
    // Use this field to check a page is loaded finished or not.
    uint16 __VARIABLE__ _pageCount;
#pragma endregion

#pragma region usage bitmap data
    // Usage Bitmap that can describe each segment is used entirely or not.
    // the size of the bitmap what is determined by _segmentCount.
    // the actul size of the bitmap is determined by bitmap operator.
    byte   __POINTER__  _usedBitmap;
#pragma endregion

#pragma region existed segment count
    // Segment Count that describes how many segments are exsiting in current
    // file.
    // this count comes from a pre-calculation by the file size.
    // why?
    // segment of the TYXF file is a const value, that means every file will
    // have a common size of growth.
    //
    // WARNING: Please do NOT operate the file that does not use TYXF operator,
    //          for TXF file will only get a integer number of segment to use,
    //          if you added some additonal data in the end of file after TYXF
    //          operator did, these data will be ignored and when you enter
    //          data, them will be overwritten. In another case, if you added
    //          a whole segment by your self, TYXF reader will get the additional
    //          segment like usual and there will some critical errors are triggered
    //          so that, keep them, and make changes by TYXF writer.
    int32  __VARIABLE__ _segmentCount;
#pragma endregion

#pragma region sections list
    // Section list that describes what section is stored in current file and 
    // provide some sections details
    // eg:
    // 1. the name of the section
    // 2. the index of the section
    // 3. what the segment(s) is(are) used for this section
    _TXFSectionList __POINTER__  _sectionList;

    // Section list count describes how many sections are in the file. The size
    // of Section List is determined by this field.
    // there are some default sections are used for TYXF itself, and to post
    // about 128 sections to be customized.
    byte            __VARIABLE__ _sectionCount;
#pragma endregion

#pragma region Data Recording Bootstrap Cache
    // Data Recording Bootstrap cache is used to provide a DRB pool to cache
    // what the user used recently.
    // Use LRU algor to execute the cache replacement when the cache pool is
    // full.
    // The size of DRB is determined by TXF configure when the TXF instance
    // is creating.
    // 
    // to be null, only when the _isMultiPageMode flag is true and _pageIndex
    // item is not zero.
    // 
    // WARNING: the first item of the cache are not avalid for userm, it will
    // keep the folders and files which are under the root path.
    _TXFDRBCache    __POINTER__  _cacheForDRB;
    // Data Recording Bootstrap Cache Bitmap to provide the usage state for 
    // DRB cache.
    byte            __POINTER__  _drbCacheBitmap;
    // Data Recording Bootstrap count
    // to record the actual size of DRB items.
    int32           __VARIABLE__ _drbCacheCount;
#pragma endregion

#pragma region Segments Cache (Fact data Cache)
    // Fact Data Cache is used to cache data what user used recently.
    // The size of fact data cache is determined by TXF configure then the TXF
    // instance is creating.
    //
    // NOTES:
    //       1. each cache line is 4 Kilo Bytes
    //       2. use LRU algor to replace cache line when the cache pool is full.
    _TXFFactDataCache __POINTER__  _cacheForFactData;
    // Fact Data Cache Bitmap to provide the usage state for fact data cache.
    // for cache replacement, to follow the steps below:
    // 1. check the bitmap state
    //    + firstly, each bit checking will be skiped when the byte is 255
    //    + other wise, less than 255, that means exist at least one bit is 0
    // (the cache could be load directly when the bitmap return false (bit = 0))
    // 2. if all of the bitmap items are used, should to do a full scan to use
    //    LRU algor to replace a(some) useless block(s).
    // 3. if the block is explicit unused, the bitmap bit will be set to false
    //    (bit = 0)
    byte              __POINTER__  _factDataCacheBitmap;
    // Fact Data Cache count
    // to record the actual size of fact data cache items.
    int32             __VARIABLE__ _factDataCacheCount;
#pragma endregion
}_TXFBase;


// implement: TXF Section list type
__PREREALIZ__ struct dty_fs_internal_txf_section_list
{
    // Section ID
    // Use a GUID (128bits) to description the current section
    // by this id, different sections could have a same name and description, and
    // all the segments which belong to this section have the same id in the start
    // block
    byte   __VARIABLE__ _sectionId[dty_fs_default_ids_length];
    // Section Name
    // for each Section in block side, name contains two parts
    //   1. Section Name
    //   2. Section Description
    // for this item, it only saves the Section Name
    string __VARIABLE__ _sectionName;
    // Section Name
    // for each Section in block side, name contains two parts
    //   1. Section Name
    //   2. Section Description
    // for this item, it only saves the Section Description
    string __VARIABLE__ _sectionDescription;
    // String length of Section Name
    int32  __VARIABLE__ _sectionNameLength;
    // String length of Section Description
    int32  __VARIABLE__ _sectionDescriptionLength;
    // Segment Start to indicate the first segment what is used.
    // this part could be changed when the section segment is expanding.
    int64  __VARIABLE__ _segmentStart;
    // Segment Span to indicate how many segment are using
    // for TYXF file, each section must to use a continues segment, so that, could 
    // use this flag to locate the section data item.
    int32  __VARIABLE__ _segmentSpan;
};

// TXF Data Recording Bootstrap Cache Line
// to provide the basic structure of DRB cache, for each line, it will keep a name
// of the file or folder and its type and fact data location
typedef struct dty_fs_internal_txf_drb_cache_line
{
    // File or Folder Id
    // cache the id for checking in some technical case
    byte   __VARIABLE__ _id[dty_fs_default_ids_length];
    // Name of the file or folder
    string __VARIABLE__ _name;
    // Indicate the DRB index of the file or folder
    // cache it in order to provide a quick search
    int64  __VARIABLE__ _index;
    // The Data location for the DRB item
    // cache it in order to provoide a faster data loading
    uint64 __VARIABLE__ _location;
    // Time Stamp is used to recording the latest shotting time of this line.
    // this field is a flag to LRU
    uint64 __VARIABLE__ _timeStamp;
    // The length of the Name
    int32  __VARIABLE__ _nameLength;
    // Get a value that indicates the type of the DRB item.
    // use this field to create a read/write strategy for this item:
    // file  : should read it directly
    // folder: should reload the children of it and get the sub item for it.
    byte   __VARIABLE__ _type;
}_TXFDRBCacheLine;

// implement: TXF Data Recording Bootstrap Cache
// for DRB, it must to cache some folders which are under the root path and in the 
// top of an indicated index. some files should be cache if they are in using
// recently.
// for the structure of the cache, it provides a two levels hierarchy to keep parent-
// child relationship.
// eg:
// for root path cache, it will keep some folders like [name]:[location]:[type]
__PREREALIZ__ struct dty_fs_internal_txf_drb_cache
{
    // folder id
    // for drb cache, each cache item must be a folder, through this id field, to
    // locate its sub-block more quickly because each block reading, should to check
    // the id is same or not.
    byte             __VARIABLE__ _id[dty_fs_default_ids_length];
    // Parent Name
    // to record the parent name of the cache item, keep it even through useless.
    string           __VARIABLE__ _parentName;
    // Parent DRB Index
    // to record the parent DRB index, to get a faster access for "cd .." operation
    int64            __VARIABLE__ _parentIndex;
    // Cache Lines
    // to save the actual DRB items that are under this folder and used recently.
    _TXFDRBCacheLine __POINTER__  _cacheLines;
    // Time Stamp is used to recording the latest shotting time of this cache.
    // this field is a flag to LRU
    uint64           __VARIABLE__ _timeStamp;
    // Parent Name Length
    int32            __VARIABLE__ _nameLength;
    // Cache Line Count
    // this is a const value for each DRB cache item
    // to record the maximum cache lines can be stored into DRB cache.
    int32            __VARIABLE__ _lineCount;
    // Cache Line Used Count
    // this is a variable value to record the count of cached line, when this field
    // equals to Cache Line Count, the next line should trigger a LRU collection to
    // remove an item which is no used recently.
    int32            __VARIABLE__ _lineUsed;
};

// implement: TXF Fact Data Cache
__PREREALIZ__ struct dty_fs_internal_txf_fact_data_cache
{
    // Fact Data Item usable state
    // this item is equivalent to Fact Data Cache bitmap item
    // if true, that means the cache item is unused and can be write
    // directly.
    bool   __VARIABLE__ _usable;
    // Fact Data Item available state
    // this item is used for the future feature.
    // NOT be used currently
    bool   __VARIABLE__ _available;
    // Cache Item edited state
    // if this item is true, that means the cached block should be written
    // back to file instance before the block is overwritten.
    bool   __VARIABLE__ _isEdited;
    // Time Stamp is used to recording the latest operation time of this block
    // this field is a flag to LRU
    uint64 __VARIABLE__ _timeStamp;
    // block code to record the actual block address
    // absolution address
    uint64 __VARIABLE__ _blockCode;
    // block data area
    // size always be 4096
    byte   __VARIABLE__ _block[dty_fs_internal_txf_block_size];
};

// ==========================================================================
// Base Operate Methods for TYXF
// ==========================================================================

_TXFBase __POINTER__  dty_fs_txf_create(const string __VARIABLE__ path);
_TXFBase __POINTER__  dty_fs_txf_createMulti(const string __VARIABLE__ path, bool __VARIABLE__ isMain);
_TXFBase __POINTER__  dty_fs_txf_defraggler(const string __VARIABLE__ path);
_TXFBase __POINTER__  dty_fs_txf_defragglerMulti(const string __POINTER__ paths, int32 __VARIABLE__ pathCount);

_TXFBase __POINTER__  dty_fs_txf_open(const string __VARIABLE__ path);
void     __VARIABLE__ dty_fs_txf_close(_TXFBase __POINTER__ txfInstance);
void     __VARIABLE__ dty_fs_txf_flush(_TXFBase __POINTER__ txfInstance);

IOHandle __VARIABLE__ dty_fs_txf_fopen(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ path);
void     __VARIABLE__ dty_fs_txf_fclose(IOHandle __VARIABLE__ handle);
void     __VARIABLE__ dty_fs_txf_fflush(IOHandle __VARIABLE__ handle);

void     __VARIABLE__ dty_fs_txf_clrError(_TXFBase __POINTER__ txfInstance);
bool     __VARIABLE__ dty_fs_txf_hasError(_TXFBase __POINTER__ txfInstance);
int32    __VARIABLE__ dty_fs_txf_popError(_TXFBase __POINTER__ txfInstance);

void         __VARIABLE__ dty_fs_txf_update_txfUserTable(_TXFBase __POINTER__ txfInstance);
void         __VARIABLE__ dty_fs_txf_update_userTable(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ path);
_FSUserTable __POINTER__  dty_fs_txf_req_txfUserTable(_TXFBase __POINTER__ txfInstance);
_FSUserTable __POINTER__  dty_fs_txf_req_userTable(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ path);

_FSFileInfo   __VARIABLE__ dty_fs_txf_req_file(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ path);
bool          __VARIABLE__ dty_fs_txf_del_file(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ path);
bool          __VARIABLE__ dty_fs_txf_new_file(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ path);
bool          __VARIABLE__ dty_fs_txf_copy_file(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ source, const string __VARIABLE__ target);
bool          __VARIABLE__ dty_fs_txf_move_file(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ source, const string __VARIABLE__ target);

_FSFolderInfo __VARIABLE__ dty_fs_txf_req_folder(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ path);
bool          __VARIABLE__ dty_fs_txf_del_folder(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ path);
bool          __VARIABLE__ dty_fs_txf_new_folder(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ path);
bool          __VARIABLE__ dty_fs_txf_copy_folder(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ source, const string __VARIABLE__ target);
bool          __VARIABLE__ dty_fs_txf_move_folder(_TXFBase __POINTER__ txfInstance, const string __VARIABLE__ source, const string __VARIABLE__ target);

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__DTY_NATIVE_FS_INTERNAL_TXFBASE_H__