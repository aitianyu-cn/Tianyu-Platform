/**
 * @file string_builder.hpp(text)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-04
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_TEXT_STRING_BUILDER_H_PLUS_PLUS__
#define __DTY_NATIVE_TEXT_STRING_BUILDER_H_PLUS_PLUS__

#include"./utilize.hh"

namespace dty::text
{
    class StringBuilder final
    {
#pragma region String Builder Internal Structure
        __PRI__ class _Iterator final : public dty::collection::IteratorBase<char>
        {
            using CharFilterResult = dty::collection::FilterResult<char>;

            __PUB__ _Iterator();
            __PUB__ virtual ~_Iterator() override;

            __PUB__ virtual int32              __VARIABLE__ Size() override;

            __PUB__ virtual void               __VARIABLE__ Reset() override;
            __PUB__ virtual SmartPointer<char> __VARIABLE__ Current() override;
            __PUB__ virtual SmartPointer<char> __VARIABLE__ Next() override;
            __PUB__ virtual SmartPointer<char> __VARIABLE__ End() override;

            __PUB__ virtual void             __VARIABLE__ ForEach(IteratorBase<char>::fnItemMap __VARIABLE__ fnForEach) override;
            __PUB__ virtual char             __POINTER__  Some(IteratorBase<char>::fnItemCheck __VARIABLE__ fnForEach) override;
            __PUB__ virtual CharFilterResult __VARIABLE__ Filter(IteratorBase<char>::fnItemCheck __VARIABLE__ fnForEach) override;
            __PUB__ virtual CharFilterResult __VARIABLE__ Every(IteratorBase<char>::fnItemCheck __VARIABLE__ fnForEach) override;
            __PUB__ virtual char             __POINTER__  Find(IteratorBase<char>::fnItemCheck __VARIABLE__ fnForEach) override;
            __PUB__ virtual int32            __VARIABLE__ FindIndex(IteratorBase<char>::fnItemCheck __VARIABLE__ fnForEach) override;
        };
#pragma endregion

        __PUB__ StringBuilder();
        __PUB__ StringBuilder(int32 __VARIABLE__ capacity);
        __PUB__ StringBuilder(int32 __VARIABLE__ capacity, int32 __VARIABLE__ maximum);
        __PUB__ StringBuilder(String __VARIABLE__ str);
        __PUB__ StringBuilder(const StringBuilder __REFERENCE__ strBuilder);
        __PUB__ ~StringBuilder();

        __PUB__ int32 __VARIABLE__  Capacity();
        __PUB__ int32 __VARIABLE__  MaxCapacity();
        __PUB__ int32 __VARIABLE__  Length();
        __PUB__ int32 __REFERENCE__ operator[](int32 __VARIABLE__ index);

        __PUB__ void __VARIABLE__ Append(bool __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(byte __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(char __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(char __VARIABLE__ value, int32 __VARIABLE__ repeat);
        __PUB__ void __VARIABLE__ Append(string __VARIABLE__ value, int32 __VARIABLE__ length);
        __PUB__ void __VARIABLE__ Append(const string __VARIABLE__ value, int32 __VARIABLE__ length);
        __PUB__ void __VARIABLE__ Append(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(float __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(int16 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(uint16 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Append(StringBuilder __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Append(String __REFERENCE__ value);

        __PUB__ void __VARIABLE__ AppendLine();
        __PUB__ void __VARIABLE__ AppendLine(bool __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(byte __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(char __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(char __VARIABLE__ value, int32 __VARIABLE__ repeat);
        __PUB__ void __VARIABLE__ AppendLine(string __VARIABLE__ value, int32 __VARIABLE__ length);
        __PUB__ void __VARIABLE__ AppendLine(const string __VARIABLE__ value, int32 __VARIABLE__ length);
        __PUB__ void __VARIABLE__ AppendLine(double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(float __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(int16 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(uint16 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ AppendLine(StringBuilder __REFERENCE__ value);
        __PUB__ void __VARIABLE__ AppendLine(String __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, bool __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, byte __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, char __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, char __VARIABLE__ value, int32 __VARIABLE__ repeat);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, string __VARIABLE__ value, int32 __VARIABLE__ length);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, const string __VARIABLE__ value, int32 __VARIABLE__ length);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, float __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, int16 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, uint16 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, uint32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, StringBuilder __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, String __REFERENCE__ value);

        __PUB__ void __VARIABLE__ Remove(char __VARIABLE__ index);
        __PUB__ void __VARIABLE__ RemoveAt(int32 __VARIABLE__ index);
        __PUB__ void __VARIABLE__ RemoveRange(int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);

        __PUB__ void __VARIABLE__ Replace(char __VARIABLE__ findCh, char __VARIABLE__ replaceCh);
        __PUB__ void __VARIABLE__ Replace(char __VARIABLE__ findCh, char __VARIABLE__ replaceCh, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ void __VARIABLE__ Replace(const string __VARIABLE__ findStr, const string __VARIABLE__ replaceStr);
        __PUB__ void __VARIABLE__ Replace(const string __REFERENCE__ findStr, const String __REFERENCE__ replaceStr);
        __PUB__ void __VARIABLE__ Replace(const string __VARIABLE__ findStr, const String __REFERENCE__ replaceStr);
        __PUB__ void __VARIABLE__ Replace(const String __REFERENCE__ findStr, const String __REFERENCE__ replaceStr);
        __PUB__ void __VARIABLE__ Replace(const string __VARIABLE__ findStr, const string __VARIABLE__ replaceStr, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ void __VARIABLE__ Replace(const string __REFERENCE__ findStr, const String __REFERENCE__ replaceStr, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ void __VARIABLE__ Replace(const string __VARIABLE__ findStr, const String __REFERENCE__ replaceStr, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ void __VARIABLE__ Replace(const String __REFERENCE__ findStr, const String __REFERENCE__ replaceStr, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);

        __PUB__ String __VARIABLE__ ToString();
        __PUB__ string __VARIABLE__ ToCString() const;

        __PUB__ dty::collection::IteratorBase<char> __VARIABLE__ GetIterator();
    };
}

#endif // !__DTY_NATIVE_TEXT_STRING_BUILDER_H_PLUS_PLUS__