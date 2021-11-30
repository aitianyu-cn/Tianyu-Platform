/**
 * @file utilize.h(utils/fs)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-29
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_FS_UTILIZE_H__
#define __DTY_NATIVE_UTILS_FS_UTILIZE_H__

#include"../utilize.h"
#include"./utilize.c.h"

namespace dty::fs
{
    /**
     * @brief 天宇文件系统基本魔数大小=8
     */
    constexpr int32 _TY_FS_MN_Length = 8;
    /**
     * @brief 天宇文件系统基础块大小=4096(4KBytes)
     */
    constexpr int32 _TY_FS_BlockBase = 4096;
    /**
     * @brief 天宇文件系统寻址长度=48bits
     */
    constexpr byte  _TY_FS_AddressBits = 48;


    /**
     * @brief 天宇文件系统磁盘分区表魔数(T.Y.D.S.)
     */
    constexpr byte  _TYDS_MagicNumber [] = { 'T','.','Y','.','D','.','S','.' };
    /**
     * @brief 天宇文件系统文件系统魔数(T.Y.F.S.)
     */
    constexpr byte  _TYFS_MagicNumber [] = { 'T','.','Y','.','F','.','S','.' };
    /**
     * @brief 天宇文件系统扩展文件魔数(T.Y.X.F.)
     */
    constexpr byte  _TYXF_MagicNumber [] = { 'T','.','Y','.','X','.','F','.' };

    constexpr uint64 _TYDS_MagicNumber_INT = 0x8446894668468346ULL;
    constexpr uint64 _TYFS_MagicNumber_INT = 0x8446894670468346ULL;
    constexpr uint64 _TYXS_MagicNumber_INT = 0x8446894688467046ULL;

    /**
     * @brief 天宇文件系统段寻址长度=16bits
     */
    constexpr int32 _TYFS_AddressGroup_Size = 16;

    enum class BlockType
    {
        MIR,
        IIR,
        DTR
    };
    constexpr byte _TY_FS_MIR [] = { 0x4D,0x46,0x52,0x30 };
    constexpr byte _TY_FS_IIR [] = { 0x49,0x4E,0x44,0x30 };
    constexpr byte _TY_FS_DTR [] = { 0x44,0x41,0x54,0x41 };

    constexpr uint32 _TY_FS_MIR_INT = 0x4D465230U;
    constexpr uint32 _TY_FS_IIR_INT = 0x494E4430U;
    constexpr uint32 _TY_FS_DTR_INT = 0x44415441U;

    namespace dsk
    {

    }

    namespace xfl
    {
        // 天宇文件系统-TYXF文件，用于块的位图大小=32字节
        constexpr int32 _TY_XF_BlockBitmapSize = 32;
        // 天宇文件系统-TYXF文件，文件中用于段的位图大小=2KB
        constexpr int32 _TY_XF_SegmentBitmapSize = 0x200000;
        // 天宇文件系统-TYXF文件，文件中MIR预读域的大小
        constexpr int32 _TY_XF_MIRDomainSize = 256;

        enum class SegmentType : byte
        {
            UnAllocated = 0b00,
            UnAssigned = 0b01,
            MainItemRec = 0b10,
            Internal = 0b11
        };

        // 天宇文件系统-TYXF文件
        // 段头的结构，用于指示当前段的类型、已使用的块数以及块的位图
        typedef struct fs_xf_segment_head
        {
            byte __VARIABLE__ _SegmentType;
            byte __VARIABLE__ _BlockUsed;
            byte __VARIABLE__ _BlockBitmap[_TY_XF_BlockBitmapSize];
        }FS_XF_SegmentHead;

        // 天宇文件系统-TYXF文件
        // 文件头部结构，用于指示当前文件的魔数、组号（用于多文件扩展）、文件名（最长256个汉字）
        typedef struct fs_xf_file_head
        {
            int64 __VARIABLE__ _FileMagic;
            int16 __VARIABLE__ _GroupIndex;
            byte  __VARIABLE__ _FileName[__FILESYSTEM_NAME_SIZE__];
        }FS_XF_FileHead;

        // 天宇文件系统-TYXF文件
        // 文件头部，段位图的定义，包含段分配状态以及使用状态，共同组合成为SegmentType
        typedef struct fs_xf_file_segment_bitmap
        {
            byte __VARIABLE__ _AllocatedStates[_TY_XF_SegmentBitmapSize];
            byte __VARIABLE__ _UsedStates[_TY_XF_SegmentBitmapSize];
        }FS_XF_FileSegmentBitmap;

        // 天宇文件系统-TYXF文件
        // 文件头部，文件内部根容器的预定义，提供根目录以及回收站目录
        typedef struct fs_xf_file_root_container
        {
            FS_MainItemRecordBase __VARIABLE__ _RootFolder;
            FS_MainItemRecordBase __VARIABLE__ _Recycle;
        }FS_XF_FileRootContainer;

        // 天宇文件系统-TYXF文件
        // 文件内MIR预读域项的定义，包含段号以及跨段状态
        typedef struct fs_xf_file_mir_domain_item
        {
            int32 __VARIABLE__ _SegmentIndex;
            int32 __VARIABLE__ _SegmentSpan;
        }FS_XF_FileMIRDomainItem;


    }
}

#endif // !__DTY_NATIVE_UTILS_FS_UTILIZE_H__