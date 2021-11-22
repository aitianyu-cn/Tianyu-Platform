/**
 * @file objectType.g.h(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-22
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_OBJECTTYPE_G_H__
#define __DTY_NATIVE_UTILS_OBJECTTYPE_G_H__

#include"./utilize.r.h"
#include"./interface.r.h"

namespace dty
{
    _interface IObjectTypeConverter
    {
        __PUB__ virtual object __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize) = 0;
        __PUB__ virtual object __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize, int32 __VARIABLE__ startIndex) = 0;
    };

    template <int32 _Size>
    class ObjectType final
        : public collection::ICompareable<ObjectType<_Size>>,
        public collection::IEquatable<ObjectType<_Size>>
    {
        __PRO__ byte  __POINTER__  _Obj;
        __PRO__ int32 __VARIABLE__ _Size;

        __PUB__ explicit BaseType();
        __PUB__ explicit BaseType(ObjectType<_Size > __REFERENCE__ other);
        __PUB__ ~BaseType();

        __PRI__ void _Destroy();

        __PUB__ int32 __VARIABLE__ Size();

        __PUB__ byte   __VARIABLE__ ToByte();
        __PUB__ sbyte  __VARIABLE__ ToSByte();
        __PUB__ int16  __VARIABLE__ ToInt16();
        __PUB__ uint16 __VARIABLE__ ToUInt16();
        __PUB__ int32  __VARIABLE__ ToInt32();
        __PUB__ uint32 __VARIABLE__ ToUInt32();
        __PUB__ int64  __VARIABLE__ ToInt64();
        __PUB__ uint64 __VARIABLE__ ToUInt64();
        __PUB__ float  __VARIABLE__ ToFloat();
        __PUB__ double __VARIABLE__ ToDouble();
        __PUB__ char   __VARIABLE__ ToChar();
        __PUB__ uchar  __VARIABLE__ ToUChar();
        __PUB__ string __VARIABLE__ ToString() const;
        __PUB__ object __VARIABLE__ ToObject();

        __PUB__ byte   __VARIABLE__ ToByte(int32 __VARIABLE__ startIndex);
        __PUB__ sbyte  __VARIABLE__ ToSByte(int32 __VARIABLE__ startIndex);
        __PUB__ int16  __VARIABLE__ ToInt16(int32 __VARIABLE__ startIndex);
        __PUB__ uint16 __VARIABLE__ ToUInt16(int32 __VARIABLE__ startIndex);
        __PUB__ int32  __VARIABLE__ ToInt32(int32 __VARIABLE__ startIndex);
        __PUB__ uint32 __VARIABLE__ ToUInt32(int32 __VARIABLE__ startIndex);
        __PUB__ int64  __VARIABLE__ ToInt64(int32 __VARIABLE__ startIndex);
        __PUB__ uint64 __VARIABLE__ ToUInt64(int32 __VARIABLE__ startIndex);
        __PUB__ float  __VARIABLE__ ToFloat(int32 __VARIABLE__ startIndex);
        __PUB__ double __VARIABLE__ ToDouble(int32 __VARIABLE__ startIndex);
        __PUB__ char   __VARIABLE__ ToChar(int32 __VARIABLE__ startIndex);
        __PUB__ uchar  __VARIABLE__ ToUChar(int32 __VARIABLE__ startIndex);
        __PUB__ string __VARIABLE__ ToString(int32 __VARIABLE__ startIndex) const;
        __PUB__ object __VARIABLE__ ToObject(int32 __VARIABLE__ startIndex);
        __PUB__ object __VARIABLE__ ToObject(int32 __VARIABLE__ startIndex, IObjectTypeConverter __REFERENCE__ converter);

        __PUB__ ObjectType<_Size> __REFERENCE__ operator=(ObjectType<_Size> __REFERENCE__ other);

        __PUB__ virtual bool __VARIABLE__ Equals(ObjectType<_Size> __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(ObjectType<_Size> __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(ObjectType<_Size> __REFERENCE__ other) override;

        __PUB__ virtual bool __VARIABLE__ operator <(ObjectType<_Size> __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >(ObjectType<_Size> __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator <=(ObjectType<_Size> __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator >=(ObjectType<_Size> __REFERENCE__ other) override;

        __PUB__ virtual collection::CompareResult __VARIABLE__ CompareTo(ObjectType<_Size> __REFERENCE__ other) override;
    };
}

#endif // !__DTY_NATIVE_UTILS_OBJECTTYPE_G_H__