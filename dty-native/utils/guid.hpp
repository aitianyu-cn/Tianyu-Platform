/**
 * @file guid.hpp(utils)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-13
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.guid?view=net-6.0
 */

#ifndef __DTY_NATIVE_UTILS_GUID_H_PLUS_PLUS__
#define __DTY_NATIVE_UTILS_GUID_H_PLUS_PLUS__

#include"../utilize.h"

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

    // Guid for Pure C mode

typedef struct dty_native_c_guid
{
    byte __VARIABLE__ _guid[dty_native_id_default_size];
}CGuid;

#ifdef __cplusplus
}
#endif // !__cplusplus

#ifdef __cplusplus

#include "../utilize.hpp"

namespace dty
{
    class Guid final : public virtual dty::collection::IEquatable<dty::Guid>,
        public virtual dty::collection::ICompareable<dty::Guid>
    {
#pragma region dty::collection::IEquatable and ICompareable interface
        __PUB__ virtual dty::collection::CompareResult __VARIABLE__ CompareTo(Guid __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ Equals(Guid __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ operator ==(Guid __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(Guid __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <(Guid __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(Guid __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(Guid __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(Guid __REFERENCE__ other) override;
#pragma endregion
    };
}

#endif // !__cplusplus

#endif // !__DTY_NATIVE_UTILS_GUID_H_PLUS_PLUS__