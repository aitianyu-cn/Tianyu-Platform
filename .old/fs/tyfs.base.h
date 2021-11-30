/**
 * @file tyfs.base.h(utils/fs)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-29
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_FS_TYFS_BASE_H__
#define __DTY_NATIVE_UTILS_FS_TYFS_BASE_H__

#include"../pointer.h"
#include"../array.h"
#include"./utilize.h"

namespace dty::fs
{
    // using BitmapStatus = dty::bool_ptr;
    // using BitmapStatuses = dty::collection::Array<BitmapStatus>;

    // class VariableBitmap
    // {
    //     __PRO__ int32    __VARIABLE__ _BandSize;
    //     __PRO__ int64    __VARIABLE__ _ItemCount;
    //     __PRO__ byte_ptr __VARIABLE__ _Bitmap;

    //     __PUB__ VariableBitmap(int32 __VARIABLE__ bandSize, int32 __VARIABLE__ itemCount);
    //     __PUB__ VariableBitmap(int32 __VARIABLE__ bandSize, byte_ptr __VARIABLE__ sources, int32 __VARIABLE__ itemCount);
    //     __PUB__ VariableBitmap(VariableBitmap __REFERENCE__ bitmap);
    //     __PUB__ virtual ~VariableBitmap();

    //     __PUB__ void __VARIABLE__  SetStatus(int32 __VARIABLE__ index, BitmapStatus __REFERENCE__ status);
    //     __PUB__ void __VARIABLE__  SetStatus(int32 __VARIABLE__ index, int32 __VARIABLE__ bandLocate, bool __VARIABLE__ status);

    //     __PUB__ BitmapStatus   __VARIABLE__ GetStatus(int32 __VARIABLE__ index);
    //     __PUB__ BitmapStatuses __VARIABLE__ GetStatuses();

    //     __PUB__ BitmapStatus   __VARIABLE__ operator[](int32 __VARIABLE__ index);

    //     __PUB__ byte_ptr __VARIABLE__ ToBytes();

    //     __PRI__ static int32 __VARIABLE__ __GetTotalLength(int32 __VARIABLE__ bandSize, int32 __VARIABLE__ itemCount);
    //     __PRI__ static void  __VARIABLE__ __FillBytes(byte __POINTER__ bytes, int32 __VARIABLE__ length);

    //     __PRI__ typedef struct bitmap_item_point
    //     {
    //         __PUB__ int32 __VARIABLE__ BitmapStartIndex;
    //         __PUB__ int32 __VARIABLE__ BitmapEndIndex;
    //         __PUB__ int32 __VARIABLE__ BitmapOffset;
    //         __PUB__ int32 __VARIABLE__ TestStartValue;
    //     }BitmapItemPoint;

    //     __PRI__ static VariableBitmap::BitmapItemPoint __VARIABLE__ __CalculateBitmapItem(int32 __VARIABLE__ bandSize, int32 __VARIABLE__ itemIndex);
    // };

    class SingleBitmap final
    {
        __PRI__ int64    __VARIABLE__ _ItemCount;
        __PRI__ int64    __VARIABLE__ _BitmapLength;
        __PRI__ byte_ptr __VARIABLE__ _Bitmap;

        __PUB__ SingleBitmap(int64 __VARIABLE__ itemCount);
        __PUB__ SingleBitmap(byte_ptr __VARIABLE__ sources, int64 __VARIABLE__ itemCount);
        __PUB__ SingleBitmap(const SingleBitmap __REFERENCE__ bitmap);
        __PUB__ ~SingleBitmap();

        __PUB__ void __VARIABLE__ SetStatus(int64 __VARIABLE__ index, bool __VARIABLE__ status);
        __PUB__ bool __VARIABLE__ GetStatus(int64 __VARIABLE__ index);

        __PUB__ bool __VARIABLE__ operator[](int64 __VARIABLE__ index);

        __PUB__ byte_ptr __VARIABLE__ ToBytes();
    };

    // enum class DBitmapStatus
    // {
    //     AllFalse,
    //     FalseTrue,
    //     TrueFalse,
    //     AllTrue
    // };

    // class DoubleBitmap final
    // {
    //     __PUB__ DoubleBitmap(int32 __VARIABLE__ itemCount);
    //     __PUB__ DoubleBitmap(byte_ptr __VARIABLE__ sources, int32 __VARIABLE__ itemCount);
    //     __PUB__ DoubleBitmap(DoubleBitmap __REFERENCE__ bitmap);
    //     __PUB__ ~DoubleBitmap();

    //     __PUB__ void __VARIABLE__ SetStatus(int32 __VARIABLE__ index, DBitmapStatus __VARIABLE__ status);
    //     __PUB__ DBitmapStatus __VARIABLE__ GetStatus(int32 __VARIABLE__ index);

    //     __PUB__ DBitmapStatus __VARIABLE__ operator[](int32 __VARIABLE__ index);
    // };
}

#endif // !__DTY_NATIVE_UTILS_FS_TYFS_BASE_H__