/**
 * @file error.h(utils/collection)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-26
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_COLLECTION_ERROR_H__
#define __DTY_NATIVE_UTILS_COLLECTION_ERROR_H__

#include"../error.h"

namespace dty::collection::except
{
#pragma region Exception ID Macros
    constexpr uint64 __VARIABLE__ DTY_Generic_CollectionReadOnlyException = 0x2000000000010001ULL;
    constexpr uint64 __VARIABLE__ DTY_Generic_CollectionOverMaxSizeException = 0x2000000000010001ULL;
#pragma endregion

    class CollectionReadOnlyException : public dty::except::OperationNotSupportException
    {
        __PUB__ CollectionReadOnlyException();

        __PUB__ virtual ~CollectionReadOnlyException() override;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() override;
#pragma endregion
    };

    class CollectionOverMaxSizeException : public dty::except::OperationNotSupportException
    {
        __PUB__ CollectionOverMaxSizeException();

        __PUB__ virtual ~CollectionOverMaxSizeException() override;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() override;
#pragma endregion
    };
}

#endif // !__DTY_NATIVE_UTILS_COLLECTION_ERROR_H__