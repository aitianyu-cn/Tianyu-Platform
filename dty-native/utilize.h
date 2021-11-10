/**
 * @file utilize.h
 * @author senyun.yao
 * @brief 用于天宇平台的公用组件核心
 * @brief AiTianyu Platform Public Common Core
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_UTILIZE_H__
#define __DTY_NATIVE_UTILIZE_H__

#ifndef __cplusplus
#error only develop for C++
#endif // !__cplusplus

// 字符类型有符号数最小值
#define __SIGNED_CHAR_MIN__ (-128)
// 字符类型有符号数最大值
#define __SIGNED_CHAR_MAX__ 127
// 字符类型无符号数最小值
#define __UNSIGNED_CHAR_MIN__ 0
// 字符类型无符号数最大值
#define __UNSIGNED_CHAR_MAX__ 0xFF

// 8位整数类型有符号数最小值
#define __SIGNED_INT8_MIN__ (-128)
// 8位整数类型有符号数最大值
#define __SIGNED_INT8_MAX__ 127
// 8位整数类型无符号数最小值
#define __UNSIGNED_INT8_MIN__ 0
// 8位整数类型无符号数最大值
#define __UNSIGNED_INT8_MAX__ 0xFF

// 16位整数类型有符号数最小值
#define __SIGNED_INT16_MIN__ (-32768)
// 16位整数类型无符号数最小值
#define __SIGNED_INT16_MAX__ 32767
// 16位整数类型无符号数最小值
#define __UNSIGNED_INT16_MIN__ 0
// 16位整数类型无符号数最大值
#define __UNSIGNED_INT16_MAX__ 0xFFFF

// 32位整数类型有符号数最小值
#define __SIGNED_INT32_MIN__ (-2147483647 - 1)
// 32位整数类型无符号数最小值
#define __SIGNED_INT32_MAX__ 2147483647
// 32位整数类型无符号数最小值
#define __UNSIGNED_INT32_MIN__ 0
// 32位整数类型无符号数最大值
#define __UNSIGNED_INT32_MAX__ 0xFFFFFFFF

// 64位整数类型有符号数最小值
#define __SIGNED_INT64_MIN__ (-9223372036854775807 - 1)
// 64位整数类型无符号数最小值
#define __SIGNED_INT64_MAX__ 9223372036854775807
// 64位整数类型无符号数最小值
#define __UNSIGNED_INT64_MIN__ 0
// 64位整数类型无符号数最大值
#define __UNSIGNED_INT64_MAX__ 0xFFFFFFFFFFFFFFFF

// 前向引用 标志 用于标识未定义实体的方法、结构体、类等元素
#define __PREDEFINE__
// 默认实现 标志 用于标识可重载函数和拓展类型、数据的默认实现
#define __DEFAULT__
// 构造函数 标志 用于标识类的构造函数（包含模拟OO）
#define __CONSTRUCTOR__
// 析构函数 标志 用于标识类的析构函数（包含模拟OO）
#define __DESTRUCTOR__
// 复制构造函数 标志 用于标识类的复制构造函数（包含模拟OO）
#define __COPYSTRUCTOR__
// 值类型 标志 用于标识以值类型保存、传递的属性、变量和参数
#define __VARIABLE__
// 数组类型 后缀 用于标识当前值类型保存为数组
#define __ARRAY__ []
// 名    称：指针类型 标志 用于标识以指针类型保存、传递的属性、变量和参数
#define __POINTER__ *
// 指针→值类型转换 标志 用于标识指针类型到值类型的转换
#define __PTR_TO_VAR__ *
// 值→指针类型转换 标志 用于标识值类型到指针类型的转换
#define __VAR_TO_PTR__ &
// 方法/函数纯输入参数 标志 用于标识方法与函数的参数类型为输入
#define __INPUT__
// 方法/函数纯输出参数 标志 用于标识方法与函数的参数类型为输出
#define __OTPUT__
// 方法/函数输入输出参数 标志 用于标识方法与函数的参数类型既可以进行输入也可作为返回
#define __INOUT__
// 传入实例标志 标志 用于标识方法的传入参数为当前操作的实例（用于C语言的模拟OO）
#define __INSTE__

#pragma region 基础数据类型重定义
// 无符号字符 数据类型
typedef unsigned char __VARIABLE__ uchar;
// 有符号字节 数据类型
typedef signed char __VARIABLE__ sbyte;
// 无符号字节 数据类型
typedef unsigned char __VARIABLE__ byte;
// 有符号8位整数 数据类型
typedef signed char __VARIABLE__ int8;
// 无符号8位整数 数据类型
typedef unsigned char __VARIABLE__ uint8;
// 有符号16位整数 数据类型
typedef signed short __VARIABLE__ int16;
// 无符号16位整数 数据类型
typedef unsigned short __VARIABLE__ uint16;
// 有符号32位整数 数据类型
typedef signed int __VARIABLE__ int32;
// 无符号32位整数 数据类型
typedef unsigned int __VARIABLE__ uint32;
// 有符号64位整数 数据类型
typedef signed long long __VARIABLE__ int64;
// 无符号64位整数 数据类型
typedef unsigned long long __VARIABLE__ uint64;
// 对象类型（任意类型） 数据类型 指针类型
typedef void __POINTER__ object;
// 字符串类型 数据类型 指针类型
typedef char __POINTER__ string;
// 有符号天宇字符 数据类型
typedef signed short __VARIABLE__ tychar;
// 无符号天宇字符 数据类型
typedef unsigned short __VARIABLE__ tyuchar;
// 错误类型 数据类型
typedef char __VARIABLE__ error;

#pragma endregion

// 公有访问权标志 指示修饰的函数与属性外部可访问
#define __PUB__ public:
// 私有访问权标志 指示修饰的函数与属性外部不可访问
#define __PRI__ private:
// 继承访问权标志 指示修饰的函数与属性子类可访问
#define __PRO__ protected:

// 引用类型 标志 用于标识以引用类型保存、传递的属性、变量和参数
#define __REFERENCE__ &
// 指针引用类型 标志 用于标识以指针引用类型保存、传递的属性、变量和参数
#define __PTRREFER__ *&

// 指针→引用类型转换 标志 用于标识指针类型到引用类型的转换
#define __PTR_TO_REF__ *
// 引用→指针类型转换 标志 用于标识引用类型到指针类型的转换
#define __REF_TO_PTR__ &
// 引用→值类型转换 标志 用于标识引用类型到值类型的转换
#define __REF_TO_VAR__
// 值→引用类型转换 标志 用于标识值类型到引用类型的转换
#define __VAR_TO_REF__

//
#define abstract
//
#define _interface abstract class

// C语言编译模式 标志 用于标识所修饰的元素以C语言的方式进行编译
#define __CMODE__ extern "C"

constexpr auto null = nullptr;

namespace dty
{
    bool __VARIABLE__ BytesToByte(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, byte __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToSByte(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, sbyte __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToInt16(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, int16 __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToUInt16(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, uint16 __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToInt32(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, int32 __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToUInt32(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, uint32 __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToInt64(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, int64 __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToUInt64(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, uint64 __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToFloat(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, float __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToDouble(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, double __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToChar(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, char __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToUChar(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, uchar __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToTYChar(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, tychar __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ BytesToTYUChar(byte __POINTER__ _pointer, int32 __VARIABLE__ _length, tyuchar __REFERENCE__ _outValue, int32 __VARIABLE__ _startIndex = 0);

    bool __VARIABLE__ GetBytes(byte __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(sbyte __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(int16 __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(uint16 __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(int32 __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(uint32 __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(int64 __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(uint64 __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(char __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(uchar __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(tychar __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(tyuchar __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(float __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);
    bool __VARIABLE__ GetBytes(double __VARIABLE__ _value, byte __POINTER__ _buffer, int32 __VARIABLE__ _bufferLength, int32 __VARIABLE__ _startIndex = 0);

    _interface IBaseTypeConverter
    {
        __PUB__ virtual object __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize) = 0;
        __PUB__ virtual object __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize, int32 __VARIABLE__ startIndex) = 0;
    };

    template <int32 _Size>
    class BaseType
    {
        __PRI__ int32 __POINTER__ _Ref;

        __PRO__ byte __POINTER__ _Obj;

        __PUB__ BaseType();
        __PUB__ explicit BaseType(BaseType<_Size> __REFERENCE__ other);
        __PUB__ virtual ~BaseType();

        __PRI__ void _Destroy();

        __PUB__ int32 __VARIABLE__ Size();

        __PUB__ virtual byte __VARIABLE__ ToByte();
        __PUB__ virtual sbyte __VARIABLE__ ToSByte();
        __PUB__ virtual int16 __VARIABLE__ ToInt16();
        __PUB__ virtual uint16 __VARIABLE__ ToUInt16();
        __PUB__ virtual int32 __VARIABLE__ ToInt32();
        __PUB__ virtual uint32 __VARIABLE__ ToUInt32();
        __PUB__ virtual int64 __VARIABLE__ ToInt64();
        __PUB__ virtual uint64 __VARIABLE__ ToUInt64();
        __PUB__ virtual float __VARIABLE__ ToFloat();
        __PUB__ virtual double __VARIABLE__ ToDouble();
        __PUB__ virtual char __VARIABLE__ ToChar();
        __PUB__ virtual uchar __VARIABLE__ ToUChar();
        __PUB__ virtual string __VARIABLE__ ToString() const;
        __PUB__ virtual object __VARIABLE__ ToObject();

        __PUB__ virtual byte __VARIABLE__ ToByte(int32 __VARIABLE__ startIndex);
        __PUB__ virtual sbyte __VARIABLE__ ToSByte(int32 __VARIABLE__ startIndex);
        __PUB__ virtual int16 __VARIABLE__ ToInt16(int32 __VARIABLE__ startIndex);
        __PUB__ virtual uint16 __VARIABLE__ ToUInt16(int32 __VARIABLE__ startIndex);
        __PUB__ virtual int32 __VARIABLE__ ToInt32(int32 __VARIABLE__ startIndex);
        __PUB__ virtual uint32 __VARIABLE__ ToUInt32(int32 __VARIABLE__ startIndex);
        __PUB__ virtual int64 __VARIABLE__ ToInt64(int32 __VARIABLE__ startIndex);
        __PUB__ virtual uint64 __VARIABLE__ ToUInt64(int32 __VARIABLE__ startIndex);
        __PUB__ virtual float __VARIABLE__ ToFloat(int32 __VARIABLE__ startIndex);
        __PUB__ virtual double __VARIABLE__ ToDouble(int32 __VARIABLE__ startIndex);
        __PUB__ virtual char __VARIABLE__ ToChar(int32 __VARIABLE__ startIndex);
        __PUB__ virtual uchar __VARIABLE__ ToUChar(int32 __VARIABLE__ startIndex);
        __PUB__ virtual string __VARIABLE__ ToString(int32 __VARIABLE__ startIndex) const;
        __PUB__ virtual object __VARIABLE__ ToObject(int32 __VARIABLE__ startIndex);
        __PUB__ virtual object __VARIABLE__ ToObject(int32 __VARIABLE__ startIndex, IBaseTypeConverter __REFERENCE__ converter);

        __PUB__ BaseType __REFERENCE__ operator=(BaseType<_Size> __REFERENCE__ other);
    };

    class Byte final : public BaseType<1>
    {
        __PUB__ Byte();
        __PUB__ explicit Byte(byte __VARIABLE__ value);
        __PUB__ explicit Byte(Byte __REFERENCE__ other);
        __PUB__ virtual ~Byte();

        __PUB__ operator byte();
        __PUB__ byte __VARIABLE__ operator=(byte __VARIABLE__ other);

        __PUB__ static byte __VARIABLE__ Max;
        __PUB__ static byte __VARIABLE__ Min;
    };
    class SByte final : public BaseType<1>
    {
        __PUB__ SByte();
        __PUB__ explicit SByte(byte __VARIABLE__ value);
        __PUB__ explicit SByte(Byte __REFERENCE__ other);
        __PUB__ virtual ~SByte();

        __PUB__ operator sbyte();
        __PUB__ sbyte __VARIABLE__ operator=(sbyte __VARIABLE__ other);

        __PUB__ static sbyte __VARIABLE__ Max;
        __PUB__ static sbyte __VARIABLE__ Min;
    };

    class Int16 final : public BaseType<2>
    {
        __PUB__ Int16();
        __PUB__ explicit Int16(int16 __VARIABLE__ value);
        __PUB__ explicit Int16(Int16 __REFERENCE__ other);
        __PUB__ virtual ~Int16();

        __PUB__ operator int16();
        __PUB__ int16 __VARIABLE__ operator=(int16 __VARIABLE__ other);

        __PUB__ static int16 __VARIABLE__ Max;
        __PUB__ static int16 __VARIABLE__ Min;
    };
    class UInt16 final : public BaseType<2>
    {
        __PUB__ UInt16();
        __PUB__ explicit UInt16(uint16 __VARIABLE__ value);
        __PUB__ explicit UInt16(UInt16 __REFERENCE__ other);
        __PUB__ virtual ~UInt16();

        __PUB__ operator uint16();
        __PUB__ uint16 __VARIABLE__ operator=(uint16 __VARIABLE__ other);

        __PUB__ static uint16 __VARIABLE__ Max;
        __PUB__ static uint16 __VARIABLE__ Min;
    };

    class Int32 final : public BaseType<4>
    {
        __PUB__ Int32();
        __PUB__ explicit Int32(int32 __VARIABLE__ value);
        __PUB__ explicit Int32(Int32 __REFERENCE__ other);
        __PUB__ virtual ~Int32();

        __PUB__ operator int32();
        __PUB__ int32 __VARIABLE__ operator=(int32 __VARIABLE__ other);

        __PUB__ static int32 __VARIABLE__ Max;
        __PUB__ static int32 __VARIABLE__ Min;
    };
    class UInt32 final : public BaseType<4>
    {
        __PUB__ UInt32();
        __PUB__ explicit UInt32(uint32 __VARIABLE__ value);
        __PUB__ explicit UInt32(UInt32 __REFERENCE__ other);
        __PUB__ virtual ~UInt32();

        __PUB__ operator uint32();
        __PUB__ uint32 __VARIABLE__ operator=(uint32 __VARIABLE__ other);

        __PUB__ static uint32 __VARIABLE__ Max;
        __PUB__ static uint32 __VARIABLE__ Min;
    };

    class Int64 final : public BaseType<8>
    {
        __PUB__ Int64();
        __PUB__ explicit Int64(int64 __VARIABLE__ value);
        __PUB__ explicit Int64(Int64 __REFERENCE__ other);
        __PUB__ virtual ~Int64();

        __PUB__ operator int64();
        __PUB__ int64 __VARIABLE__ operator=(int64 __VARIABLE__ other);

        __PUB__ static int64 __VARIABLE__ Max;
        __PUB__ static int64 __VARIABLE__ Min;
    };
    class UInt64 final : public BaseType<8>
    {
        __PUB__ UInt64();
        __PUB__ explicit UInt64(uint64 __VARIABLE__ value);
        __PUB__ explicit UInt64(UInt64 __REFERENCE__ other);
        __PUB__ virtual ~UInt64();

        __PUB__ operator uint64();
        __PUB__ uint64 __VARIABLE__ operator=(uint64 __VARIABLE__ other);

        __PUB__ static uint64 __VARIABLE__ Max;
        __PUB__ static uint64 __VARIABLE__ Min;
    };

    class Float final : public BaseType<4>
    {
        __PUB__ Float();
        __PUB__ explicit Float(float __VARIABLE__ value);
        __PUB__ explicit Float(Float __REFERENCE__ other);
        __PUB__ virtual ~Float();

        __PUB__ operator float();
        __PUB__ float __VARIABLE__ operator=(float __VARIABLE__ other);
    };
    class Double final : public BaseType<8>
    {
        __PUB__ Double();
        __PUB__ explicit Double(double __VARIABLE__ value);
        __PUB__ explicit Double(Double __REFERENCE__ other);
        __PUB__ virtual ~Double();

        __PUB__ operator double();
        __PUB__ double __VARIABLE__ operator=(double __VARIABLE__ other);
    };

    class TYChar final : public BaseType<2>
    {
        __PUB__ TYChar();
        __PUB__ explicit TYChar(int16 __VARIABLE__ value);
        __PUB__ explicit TYChar(TYChar __REFERENCE__ other);
        __PUB__ virtual ~TYChar();

        __PUB__ operator int16();
        __PUB__ tychar __VARIABLE__ operator=(tychar __VARIABLE__ other);

        __PUB__ static tychar __VARIABLE__ Max;
        __PUB__ static tychar __VARIABLE__ Min;
    };
    class TYUChar final : public BaseType<2>
    {
        __PUB__ TYUChar();
        __PUB__ explicit TYUChar(uint16 __VARIABLE__ value);
        __PUB__ explicit TYUChar(TYUChar __REFERENCE__ other);
        __PUB__ virtual ~TYUChar();

        __PUB__ operator uint16();
        __PUB__ tyuchar __VARIABLE__ operator=(tyuchar __VARIABLE__ other);

        __PUB__ static tyuchar __VARIABLE__ Max;
        __PUB__ static tyuchar __VARIABLE__ Min;
    };
}

#endif // !__DTY_NATIVE_UTILIZE_H__