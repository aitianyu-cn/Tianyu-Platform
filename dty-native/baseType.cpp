
#include "utilize.h"
#include <iostream>

const string __VARIABLE__ BaseTypeString = "DTY::BASETYPE";

#pragma region dty::BaseType<_Size>

template <int32 _Size>
dty::BaseType<_Size>::BaseType()
{
    if (_Size <= 0)
    {
        char* buffer = new char[255];
        std::snprintf(buffer, 255, "dty::BaseType::_Size = %d out of range", _Size);
        throw new std::exception(buffer);
    }

    this->_Ref = new int32(1);
    this->_Obj = new byte[_Size];
}
template <int32 _Size>
dty::BaseType<_Size>::BaseType(dty::BaseType<_Size>& other)
{
    this->_Obj = other._Obj;
    this->_Ref = other._Ref;

    __PTR_TO_VAR__(this->_Ref) += 1;
}
template <int32 _Size>
dty::BaseType<_Size>::~BaseType()
{
    this->_Destroy();
}
template <int32 _Size>
void dty::BaseType<_Size>::_Destroy()
{
    if (__PTR_TO_VAR__(this->_Ref) == 1)
    {
        delete this->_Ref;
        delete [] this->_Obj;
    }
    else
    {
        __PTR_TO_VAR__(this->_Ref) -= 1;
    }
}

template <int32 _Size>
int32 dty::BaseType<_Size>::Size()
{
    return _Size;
}

template <int32 _Size>
byte dty::BaseType<_Size>::ToByte()
{
    return this->_Obj[0];
}
template <int32 _Size>
sbyte dty::BaseType<_Size>::ToSByte()
{
    return __PTR_TO_VAR__(((sbyte __POINTER__)(this->_Obj))[0]);
}
template <int32 _Size>
int16 dty::BaseType<_Size>::ToInt16()
{
    int16 result = 0;
    if (dty::BytesToInt16(this->_Obj, _Size, result, 0))
        return result;

    return 0;
}
template <int32 _Size>
uint16 dty::BaseType<_Size>::ToUInt16()
{
    uint16 result = 0;
    if (dty::BytesToUInt16(this->_Obj, _Size, result, 0))
        return result;

    return 0;
}
template <int32 _Size>
int32 dty::BaseType<_Size>::ToInt32()
{
    int16 result = 0;
    if (dty::BytesToInt32(this->_Obj, _Size, result, 0))
        return result;

    return 0;
}
template <int32 _Size>
uint32 dty::BaseType<_Size>::ToUInt32()
{
    uint16 result = 0;
    if (dty::BytesToUInt32(this->_Obj, _Size, result, 0))
        return result;

    return 0;
}
template <int32 _Size>
int64 dty::BaseType<_Size>::ToInt64()
{
    int16 result = 0;
    if (dty::BytesToInt64(this->_Obj, _Size, result, 0))
        return result;

    return 0;
}
template <int32 _Size>
uint64 dty::BaseType<_Size>::ToUInt64()
{
    uint16 result = 0;
    if (dty::BytesToUInt64(this->_Obj, _Size, result, 0))
        return result;

    return 0;
}
template <int32 _Size>
float dty::BaseType<_Size>::ToFloat()
{
    int16 result = 0;
    if (dty::BytesToFloat(this->_Obj, _Size, result, 0))
        return result;

    return 0;
}
template <int32 _Size>
double dty::BaseType<_Size>::ToDouble()
{
    int16 result = 0;
    if (dty::BytesToDouble(this->_Obj, _Size, result, 0))
        return result;

    return 0;
}
template <int32 _Size>
char dty::BaseType<_Size>::ToChar()
{
    int16 result = 0;
    if (dty::BytesToChar(this->_Obj, _Size, result, 0))
        return result;

    return 0;
}
template <int32 _Size>
uchar dty::BaseType<_Size>::ToUChar()
{
    int16 result = 0;
    if (dty::BytesToUChar(this->_Obj, _Size, result, 0))
        return result;

    return 0;
}
template <int32 _Size>
string dty::BaseType<_Size>::ToString() const
{
    return BaseTypeString;
}
template <int32 _Size>
object dty::BaseType<_Size>::ToObject()
{
    return (object __VARIABLE__)(this->_Obj);
}

template <int32 _Size>
byte dty::BaseType<_Size>::ToByte(int32 startIndex)
{
    byte valueResult = 0;
    bool convertResult = dty::BytesToByte(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
sbyte dty::BaseType<_Size>::ToSByte(int32 startIndex)
{
    sbyte valueResult = 0;
    bool convertResult = dty::BytesToSByte(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
int16 dty::BaseType<_Size>::ToInt16(int32 startIndex)
{
    int16 valueResult = 0;
    bool convertResult = dty::BytesToInt16(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
uint16 dty::BaseType<_Size>::ToUInt16(int32 startIndex)
{
    uint16 valueResult = 0;
    bool convertResult = dty::BytesToUInt16(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
int32 dty::BaseType<_Size>::ToInt32(int32 startIndex)
{
    int32 valueResult = 0;
    bool convertResult = dty::BytesToInt32(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
uint32 dty::BaseType<_Size>::ToUInt32(int32 startIndex)
{
    uint32 valueResult = 0;
    bool convertResult = dty::BytesToUInt32(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
int64 dty::BaseType<_Size>::ToInt64(int32 startIndex)
{
    int64 valueResult = 0;
    bool convertResult = dty::BytesToInt64(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
uint64 dty::BaseType<_Size>::ToUInt64(int32 startIndex)
{
    uint64 valueResult = 0;
    bool convertResult = dty::BytesToUInt64(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
float dty::BaseType<_Size>::ToFloat(int32 startIndex)
{
    float valueResult = 0;
    bool convertResult = dty::BytesToFloat(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
double dty::BaseType<_Size>::ToDouble(int32 startIndex)
{
    double valueResult = 0;
    bool convertResult = dty::BytesToDouble(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
char dty::BaseType<_Size>::ToChar(int32 startIndex)
{
    char valueResult = 0;
    bool convertResult = dty::BytesToChar(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
uchar dty::BaseType<_Size>::ToUChar(int32 startIndex)
{
    uchar valueResult = 0;
    bool convertResult = dty::BytesToUChar(this->_Obj, _Size, valueResult, startIndex);
    return convertResult ? valueResult : 0;
}
template <int32 _Size>
string dty::BaseType<_Size>::ToString(int32 startIndex) const
{
    return BaseTypeString;
}
template <int32 _Size>
object dty::BaseType<_Size>::ToObject(int32 startIndex)
{
    if (startIndex >= _Size)
        return null;

    return (object __VARIABLE__)((this->_Obj) + startIndex);
}
template <int32 _Size>
object dty::BaseType<_Size>::ToObject(int32 startIndex, dty::IBaseTypeConverter& converter)
{
    return converter.TryConvert(this->_Obj, _Size, startIndex);
}

template <int32 _Size>
dty::BaseType<_Size>& dty::BaseType<_Size>::operator=(dty::BaseType<_Size>& other)
{
    this->_Destroy();

    this->_Obj = other._Obj;
    this->_Ref = other._Ref;

    __PTR_TO_VAR__(this->_Ref) += 1;
}

#pragma endregion


dty::Byte::Byte() : BaseType<1>()
{
    this->_Obj[0] = 0x00;
}
dty::Byte::Byte(byte value) : BaseType<1>()
{
    this->_Obj[0] = value;
}
dty::Byte::Byte(Byte __REFERENCE__ other) : BaseType<1>(other)
{

}
dty::Byte::~Byte()
{

}
dty::Byte::operator byte()
{
    return this->ToByte();
}
byte dty::Byte::operator=(byte other)
{
    this->_Obj[0] = other;

    return this->ToByte();
}




