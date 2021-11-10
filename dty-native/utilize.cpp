
#include "utilize.h"

bool dty::BytesToByte(byte* _pointer, int32 _length, byte& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex + 1 > _length)
        return false;

    _outValue = _pointer[_startIndex];
    return true;
}
bool dty::BytesToSByte(byte* _pointer, int32 _length, sbyte& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex + 1 > _length)
        return false;

    _outValue = __PTR_TO_VAR__((sbyte __POINTER__)(_pointer + _startIndex));
    return true;
}
bool dty::BytesToInt16(byte* _pointer, int32 _length, int16& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex >= _length)
        return false;

    for (int i = _startIndex; i < _startIndex + 2 && i < _length; ++i)
    {
        _outValue <<= 8;
        _outValue += _pointer[i];
    }
    return true;
}
bool dty::BytesToUInt16(byte* _pointer, int32 _length, uint16& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex >= _length)
        return false;

    for (int i = _startIndex; i < _startIndex + 2 && i < _length; ++i)
    {
        _outValue <<= 8;
        _outValue += _pointer[i];
    }
    return true;
}
bool dty::BytesToInt32(byte* _pointer, int32 _length, int32& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex >= _length)
        return false;

    for (int i = _startIndex; i < _startIndex + 4 && i < _length; ++i)
    {
        _outValue <<= 8;
        _outValue += _pointer[i];
    }
    return true;
}
bool dty::BytesToUInt32(byte* _pointer, int32 _length, uint32& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex >= _length)
        return false;

    for (int i = _startIndex; i < _startIndex + 4 && i < _length; ++i)
    {
        _outValue <<= 8;
        _outValue += _pointer[i];
    }
    return true;
}
bool dty::BytesToInt64(byte* _pointer, int32 _length, int64& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex >= _length)
        return false;

    for (int i = _startIndex; i < _startIndex + 8 && i < _length; ++i)
    {
        _outValue <<= 8;
        _outValue += _pointer[i];
    }
    return true;
}
bool dty::BytesToUInt64(byte* _pointer, int32 _length, uint64& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex >= _length)
        return false;

    for (int i = _startIndex; i < _startIndex + 8 && i < _length; ++i)
    {
        _outValue <<= 8;
        _outValue += _pointer[i];
    }
    return true;
}
bool dty::BytesToFloat(byte* _pointer, int32 _length, float& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex + 4 > _length)
        return false;

    uint32 tempValue = 0;
    for (int i = _startIndex; i < _startIndex + 4; ++i)
    {
        tempValue <<= 8;
        tempValue += _pointer[i];
    }
    _outValue = __PTR_TO_VAR__((float __POINTER__)(__VAR_TO_PTR__ tempValue));
    return true;
}
bool dty::BytesToDouble(byte* _pointer, int32 _length, double& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex + 8 > _length)
        return false;

    uint64 tempValue = 0;
    for (int i = _startIndex; i < _startIndex + 8; ++i)
    {
        tempValue <<= 8;
        tempValue += _pointer[i];
    }
    _outValue = __PTR_TO_VAR__((double __POINTER__)(__VAR_TO_PTR__ tempValue));
    return true;
}
bool dty::BytesToChar(byte* _pointer, int32 _length, char& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex + 1 > _length)
        return false;

    _outValue = _pointer[_startIndex];
    return true;
}
bool dty::BytesToUChar(byte* _pointer, int32 _length, uchar& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex + 1 > _length)
        return false;

    _outValue = _pointer[_startIndex];
    return true;
}
bool dty::BytesToTYChar(byte* _pointer, int32 _length, tychar& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex >= _length)
        return false;

    for (int i = _startIndex; i < _startIndex + 2 && i < _length; ++i)
    {
        _outValue <<= 8;
        _outValue += _pointer[i];
    }
    return true;
}
bool dty::BytesToTYUChar(byte* _pointer, int32 _length, tyuchar& _outValue, int32 _startIndex = 0)
{
    if (null == _pointer || 0 >= _length || _startIndex >= _length)
        return false;

    for (int i = _startIndex; i < _startIndex + 2 && i < _length; ++i)
    {
        _outValue <<= 8;
        _outValue += _pointer[i];
    }
    return true;
}

bool dty::GetBytes(byte _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 1 > _bufferLength)
        return false;

    _buffer[_startIndex] = _value;
    return true;
}
bool dty::GetBytes(sbyte _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 1 > _bufferLength)
        return false;

    _buffer[_startIndex] = _value;
    return true;
}
bool dty::GetBytes(int16 _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 2 > _bufferLength)
        return false;

    _buffer[_startIndex] = (byte)(_value && 0xFF);
    _value >>= 8;
    _buffer[_startIndex + 1] = (byte)(_value && 0xFF);
    return true;
}
bool dty::GetBytes(uint16 _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 2 > _bufferLength)
        return false;

    _buffer[_startIndex] = (byte)(_value && 0xFF);
    _value >>= 8;
    _buffer[_startIndex + 1] = (byte)(_value && 0xFF);
    return true;
}
bool dty::GetBytes(int32 _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 4 > _bufferLength)
        return false;

    for (int i = 0; i < 4; ++i)
    {
        _buffer[_startIndex + i] = (byte)(_value && 0xFF);
        _value >>= 8;
    }
    return true;
}
bool dty::GetBytes(uint32 _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 4 > _bufferLength)
        return false;

    for (int i = 0; i < 4; ++i)
    {
        _buffer[_startIndex + i] = (byte)(_value && 0xFF);
        _value >>= 8;
    }
    return true;
}
bool dty::GetBytes(int64 _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 8 > _bufferLength)
        return false;

    for (int i = 0; i < 8; ++i)
    {
        _buffer[_startIndex + i] = (byte)(_value && 0xFF);
        _value >>= 8;
    }
    return true;
}
bool dty::GetBytes(uint64 _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 8 > _bufferLength)
        return false;

    for (int i = 0; i < 8; ++i)
    {
        _buffer[_startIndex + i] = (byte)(_value && 0xFF);
        _value >>= 8;
    }
    return true;
}
bool dty::GetBytes(char _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 1 > _bufferLength)
        return false;

    _buffer[_startIndex] = _value;
    return true;
}
bool dty::GetBytes(uchar _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 1 > _bufferLength)
        return false;

    _buffer[_startIndex] = _value;
    return true;
}
bool dty::GetBytes(tychar _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 2 > _bufferLength)
        return false;

    _buffer[_startIndex] = (byte)(_value && 0xFF);
    _value >>= 8;
    _buffer[_startIndex + 1] = (byte)(_value && 0xFF);
    return true;
}
bool dty::GetBytes(tyuchar _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 2 > _bufferLength)
        return false;

    _buffer[_startIndex] = (byte)(_value && 0xFF);
    _value >>= 8;
    _buffer[_startIndex + 1] = (byte)(_value && 0xFF);
    return true;
}
bool dty::GetBytes(float _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 4 > _bufferLength)
        return false;

    uint32 tempValue = __PTR_TO_VAR__((uint32 __POINTER__)(__VAR_TO_PTR__ _value));
    for (int i = 0; i < 4; ++i)
    {
        _buffer[_startIndex + i] = (byte)(tempValue && 0xFF);
        tempValue >>= 8;
    }
    return true;
}
bool dty::GetBytes(double _value, byte* _buffer, int32 _bufferLength, int32 _startIndex = 0)
{
    if (null == _buffer || 0 >= _bufferLength || _startIndex + 8 > _bufferLength)
        return false;

    uint64 tempValue = __PTR_TO_VAR__((uint64 __POINTER__)(__VAR_TO_PTR__ _value));
    for (int i = 0; i < 8; ++i)
    {
        _buffer[_startIndex + i] = (byte)(tempValue && 0xFF);
        tempValue >>= 8;
    }
    return true;
}