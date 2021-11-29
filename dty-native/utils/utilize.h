/**
 * @file utilize.h(utils)
 * @author senyun.yao
 * @brief 用于天宇平台的公用组件核心
 * @brief AiTianyu Platform Public Common Core
 * @version 0.1
 * @date 2021-11-09
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_UTILIZE_H__
#define __DTY_NATIVE_UTILS_UTILIZE_H__

#ifndef __cplusplus
#error only develop for C++
#endif // !__cplusplus

#if __cplusplus < 201700
#error library needs C++17 or later
#endif

 // 天宇开发模式标志
#define __DTY_DEV_MODE__    1

#ifdef __DTY_DEV_MODE__
 /**
  * @brief 该标识指示当前天库是否可以支持不安全的内存操作 
  * @brief The flag that allow unsafe memory operations in Tianyu Library when it is defined
  */
  // #define __DTY_UNSAFE_MODE__ "Tianyu Library Unsafe Mode"
    // #define __DTY_DEEP_LEARNING_MODE__
      // #define __DTY_SMART_POINTER_COPY_WEAK_MODE__
#endif // !__DTY_DEV_MODE__

  // 字符类型有符号数最小值
#define __SIGNED_CHAR_MIN__     (-128)
// 字符类型有符号数最大值
#define __SIGNED_CHAR_MAX__     127
// 字符类型无符号数最小值
#define __UNSIGNED_CHAR_MIN__   0
// 字符类型无符号数最大值
#define __UNSIGNED_CHAR_MAX__   0xFF

// 8位整数类型有符号数最小值
#define __SIGNED_INT8_MIN__     (-128)
// 8位整数类型有符号数最大值
#define __SIGNED_INT8_MAX__     127
// 8位整数类型无符号数最小值
#define __UNSIGNED_INT8_MIN__   0
// 8位整数类型无符号数最大值
#define __UNSIGNED_INT8_MAX__   0xFF

// 16位整数类型有符号数最小值
#define __SIGNED_INT16_MIN__    (-32768)
// 16位整数类型无符号数最小值
#define __SIGNED_INT16_MAX__    32767
// 16位整数类型无符号数最小值
#define __UNSIGNED_INT16_MIN__  0
// 16位整数类型无符号数最大值
#define __UNSIGNED_INT16_MAX__  0xFFFF

// 32位整数类型有符号数最小值
#define __SIGNED_INT32_MIN__    (-2147483647 - 1)
// 32位整数类型无符号数最小值
#define __SIGNED_INT32_MAX__    2147483647
// 32位整数类型无符号数最小值
#define __UNSIGNED_INT32_MIN__  0
// 32位整数类型无符号数最大值
#define __UNSIGNED_INT32_MAX__  0xFFFFFFFF

// 64位整数类型有符号数最小值
#define __SIGNED_INT64_MIN__    (-9223372036854775807 - 1)
// 64位整数类型无符号数最小值
#define __SIGNED_INT64_MAX__    9223372036854775807
// 64位整数类型无符号数最小值
#define __UNSIGNED_INT64_MIN__  0
// 64位整数类型无符号数最大值
#define __UNSIGNED_INT64_MAX__  0xFFFFFFFFFFFFFFFF

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
#define __DPOINTER__ **
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
typedef      unsigned char __VARIABLE__ uchar;
// 有符号字节 数据类型
typedef        signed char __VARIABLE__ sbyte;
// 无符号字节 数据类型
typedef      unsigned char __VARIABLE__ byte;
// 有符号8位整数 数据类型
typedef        signed char __VARIABLE__ int8;
// 无符号8位整数 数据类型
typedef      unsigned char __VARIABLE__ uint8;
// 有符号16位整数 数据类型
typedef       signed short __VARIABLE__ int16;
// 无符号16位整数 数据类型
typedef     unsigned short __VARIABLE__ uint16;
// 有符号32位整数 数据类型
typedef         signed int __VARIABLE__ int32;
// 无符号32位整数 数据类型
typedef       unsigned int __VARIABLE__ uint32;
// 有符号64位整数 数据类型
typedef   signed long long __VARIABLE__ int64;
// 无符号64位整数 数据类型
typedef unsigned long long __VARIABLE__ uint64;
// 对象类型（任意类型） 数据类型 指针类型
typedef               void __POINTER__  object;
// 字符串类型 数据类型 指针类型
typedef               char __POINTER__  string;
// 有符号天宇字符 数据类型
typedef       signed short __VARIABLE__ tychar;
// 无符号天宇字符 数据类型
typedef     unsigned short __VARIABLE__ tyuchar;
// 错误类型 数据类型
typedef               char __VARIABLE__ error;

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
    _interface IObjectConverter
    {
        __PUB__ virtual object __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize) = 0;
        __PUB__ virtual object __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize, int32 __VARIABLE__ startIndex) = 0;
    };
    _interface IStringConverter
    {
        __PUB__ virtual string __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize) const = 0;
        __PUB__ virtual string __VARIABLE__ TryConvert(byte __POINTER__ obj, int32 __VARIABLE__ objSize, int32 __VARIABLE__ startIndex) const = 0;
    };

    template<typename _Key, typename _Val>
    class KeyValuePair final
    {
        __PUB__ _Key __VARIABLE__ Key;
        __PUB__ _Val __VARIABLE__ Value;

        __PUB__ KeyValuePair(_Key key, _Val val)
            : Key(key), Value(val)
        {

        }
        __PUB__ ~KeyValuePair() { }
    };

    namespace collection
    {
        enum class CompareResult : int32
        {
            LESS = -1,
            EQUAL = 0,
            GREAT = 1
        };

        template<class Elem>
        _interface IEquatable
        {
            __PUB__ virtual ~IEquatable() { };

            __PUB__ virtual bool __VARIABLE__ Equals(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
        };

        template<class Elem>
        _interface ICompareable
        {
            __PUB__ virtual ~ICompareable() { };

            __PUB__ virtual CompareResult __VARIABLE__ CompareTo(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator ==(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator !=(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator <(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator >(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator <=(Elem __REFERENCE__ other) = 0;
            __PUB__ virtual bool __VARIABLE__ operator >=(Elem __REFERENCE__ other) = 0;
        };
    }
}

#endif // !__DTY_NATIVE_UTILS_UTILIZE_H__
