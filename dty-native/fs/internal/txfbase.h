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

#include "../utilize.h"

#include "./error_list.h"

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

    // pure C definations

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
//                    (250 sections supported includes Data Recording Bootstrap)
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
    _TXFSectionList __POINTER__  _sectionList;
    int32           __VARIABLE__ _sectionCount;
#pragma endregion

#pragma region Data Recording Bootstrap Cache
    _TXFDRBCache    __POINTER__ _cacheForDRB;
#pragma endregion

#pragma region Segments Cache (Fact data Cache)
    _TXFFactDataCache __POINTER__ _cacheForFactData;
#pragma endregion

    int32    __VARIABLE__ _;
}_TXFBase;

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__DTY_NATIVE_FS_INTERNAL_TXFBASE_H__