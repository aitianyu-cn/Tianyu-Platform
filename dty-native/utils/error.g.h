/**
 * @file error.h(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-17
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_ERROR_G_H__
#define __DTY_NATIVE_UTILS_ERROR_G_H__

#include "./interface.g.h"
#include <exception>

namespace dty::except
{
#pragma region Exception ID Macros

    constexpr uint64 __VARIABLE__ DTY_Generic_Exception = 0x0000000000000001ULL;
    constexpr uint64 __VARIABLE__ DTY_Generic_NullPointerException = 0x0000000000000002ULL;
    constexpr uint64 __VARIABLE__ DTY_Generic_ArithmeticException = 0x0000000000000003ULL;
    constexpr uint64 __VARIABLE__ DTY_Generic_IndexOutOfRangeException = 0x0000000000000004ULL;

    constexpr uint64 __VARIABLE__ DTY_Generic_ArgumentException = 0x1000000000000001ULL;
    constexpr uint64 __VARIABLE__ DTY_Generic_ArgumentNullException = 0x1000000000000002ULL;
    constexpr uint64 __VARIABLE__ DTY_Generic_ArgumentOutOfRangeException = 0x1000000000000003ULL;
#pragma endregion

    class Exception : public std::exception,
        public virtual collection::IEquatable<Exception>
    {
        __PRI__ string __VARIABLE__ _Msg;

        __PUB__ Exception();
        __PUB__ Exception(const string __VARIABLE__ msg);

        __PUB__ virtual ~Exception() override;

        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId();
        __PUB__ virtual const char __POINTER__ what() const noexcept override;

        __PUB__ virtual string __VARIABLE__ ToString() noexcept;

#pragma region Tianyu IEquatable Interface
        __PUB__ virtual bool __VARIABLE__ Equals(Exception __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator==(Exception __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator!=(Exception __REFERENCE__ other) override;
#pragma endregion
    };

    class NullPointerException : public Exception
    {
        __PUB__ NullPointerException();
        __PUB__ NullPointerException(const string __VARIABLE__ msg);

        __PUB__ virtual ~NullPointerException() override;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() override;
        __PUB__ virtual const char __POINTER__ what() const noexcept override;

        __PUB__ virtual string __VARIABLE__ ToString() noexcept override;
#pragma endregion
    };

    class ArithmeticException : public Exception
    {
        __PUB__ ArithmeticException();
        __PUB__ ArithmeticException(const string __VARIABLE__ msg);

        __PUB__ virtual ~ArithmeticException() override;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() override;
        __PUB__ virtual const char __POINTER__ what() const noexcept override;

        __PUB__ virtual string __VARIABLE__ ToString() noexcept override;
#pragma endregion
    };

    class IndexOutOfRangeException : public Exception
    {
        __PUB__ IndexOutOfRangeException();
        __PUB__ IndexOutOfRangeException(const string __VARIABLE__ msg);

        __PUB__ virtual ~IndexOutOfRangeException() override;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() override;
        __PUB__ virtual const char __POINTER__ what() const noexcept override;

        __PUB__ virtual string __VARIABLE__ ToString() noexcept override;
#pragma endregion
    };

    class ArgumentException : public Exception
    {
        __PUB__ ArgumentException();
        __PUB__ ArgumentException(const string __VARIABLE__ msg);

        __PUB__ virtual ~ArgumentException() override;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() override;
        __PUB__ virtual const char __POINTER__ what() const noexcept override;

        __PUB__ virtual string __VARIABLE__ ToString() noexcept override;
#pragma endregion
    };

    class ArgumentNullException : public ArgumentException
    {
        __PUB__ ArgumentNullException();
        __PUB__ ArgumentNullException(const string __VARIABLE__ msg);

        __PUB__ virtual ~ArgumentNullException() override;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() override;
        __PUB__ virtual const char __POINTER__ what() const noexcept override;

        __PUB__ virtual string __VARIABLE__ ToString() noexcept override;
#pragma endregion
    };

    class ArgumentOutOfRangeException : public ArgumentException
    {
        __PUB__ ArgumentOutOfRangeException();
        __PUB__ ArgumentOutOfRangeException(const string __VARIABLE__ msg);

        __PUB__ virtual ~ArgumentOutOfRangeException() override;

#pragma region Tianyu Exception Base Function
        __PUB__ virtual uint64 __VARIABLE__ GetExceptionId() override;
        __PUB__ virtual const char __POINTER__ what() const noexcept override;

        __PUB__ virtual string __VARIABLE__ ToString() noexcept override;
#pragma endregion
    };
}

#endif // !__DTY_NATIVE_UTILS_ERROR_G_H__
