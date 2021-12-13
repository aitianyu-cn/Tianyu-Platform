/**
 * @file version.hpp(utils)
 * @author victor.yao
 * @brief
 * @version 0.1
 * @date 2021-12-13
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 * @link https://docs.microsoft.com/zh-cn/dotnet/api/system.version?view=net-6.0
 */

#ifndef __DTY_NATIVE_UTILS_VERSION_H_PLUS_PLUS__
#define __DTY_NATIVE_UTILS_VERSION_H_PLUS_PLUS__

#include "../utilize.h"

#ifdef __cplusplus
__CMODE__
{
#endif // !__cplusplus

    // Version for Pure C mode

typedef struct dty_native_c_version
{

}CVersion;

#ifdef __cplusplus
}
#endif // !__cplusplus

#ifdef __cplusplus

#include "../utilize.hpp"

namespace dty
{
    class Version final : public virtual dty::collection::IEquatable<dty::Version>,
        public virtual dty::collection::ICompareable<dty::Version>
    {
#pragma region dty::collection::IEquatable and ICompareable interface
        __PUB__ virtual dty::collection::CompareResult __VARIABLE__ CompareTo(Version __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ Equals(Version __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ operator ==(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(Version __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(Version __REFERENCE__ other) override;
#pragma endregion
    };
}

#endif // !__cplusplus

#endif // !__DTY_NATIVE_UTILS_VERSION_H_PLUS_PLUS__