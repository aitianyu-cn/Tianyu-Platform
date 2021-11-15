/**
 * @file TXF.h(fileSystem)
 * @author senyun.yao
 * @brief Description for Tianyu eXtened File
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#include"./utilize.h"

#define __DTY_FILE_SYSTEM_TXF_MAGIC__ 16
#define __DTY_FILE_SYSTEM_TXF_SYMBOL_RECORDER_COUNT__ 128

namespace dty
{
    namespace fs
    {
        namespace exf
        {
            struct SymbolAreaItem
            {
                /*
                 * Segment state
                 * Set the coordinate for symbol area that can redirect the data.
                */
                uint64 __VARIABLE__ _SegmentIndex;
                uint64 __VARIABLE__ _SegmentSpan;
                uint64 __VARIABLE__ _SegmentFree;
                
                /**
                 * @brief Set a 64bit unsigned integer to indicate the end of symbol index
                 * in current Symbol Item.
                 * 
                 */
                uint64 __VARIABLE__ _EndSymbolIndex;
            };

            struct RawRecorderItem
            {
                uint64 __VARIABLE__ _HashIndicate;

                uint32 __VARIABLE__ _SegmentCode;
                uint32 __VARIABLE__ _BlockCode;
            };

            struct RawRecorderBlock
            {
                /*
                 * Segment state
                 * Set the coordinate for raw recorder block that can redirect the data.
                */
                uint64 __VARIABLE__ _SegmentIndex;
                uint64 __VARIABLE__ _SegmentSpan;
                uint64 __VARIABLE__ _SegmentFree;
            };

            struct FileSegment
            {

            };

            struct FileAdditionalProperty
            {

            };

            struct FileHeader
            {
                byte           __VARIABLE__ _Magic[__DTY_FILE_SYSTEM_TXF_MAGIC__];
                byte           __VARIABLE__ _SegmentSize;
                byte           __VARIABLE__ _BlockSize;
                Bitmap         __VARIABLE__ _SegmentMap;
                SymbolAreaItem __VARIABLE__ _SymbolArea[__DTY_FILE_SYSTEM_TXF_SYMBOL_RECORDER_COUNT__];
            };

            struct TianyuExtenedFile
            {
                FileHeader              __VARIABLE__ _Header;
                FileAdditionalProperty  __VARIABLE__ _AdditionalProperty;
                FileSegment             __VARIABLE__ _Segment;
            };

            class TianyuEXFHelper final
            {

            };
        }
    }
}