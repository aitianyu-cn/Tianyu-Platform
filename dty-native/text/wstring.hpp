/**
 * @file wstring.hpp(text)
 * @author senyun.yao
 * @brief 使用utf32编码的宽字符串，主要用于非英语语言的字符处理，同时提供string和string_builder的功能
 * @brief chars are stored in wstring that use UTF32 encoding, wstring could provide the language
 *        processing not only for English (english only use 8bits but others language should use
 *        more). In the same time, wstring combines the APIs both of default string and string_builder.
 * @version 0.1
 * @date 2021-12-10
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_TEXT_WSTRING_H_PLUS_PLUS__
#define __DTY_NATIVE_TEXT_WSTRING_H_PLUS_PLUS__

#include"./utilize.hh"

namespace dty::text
{
    using wchar = uint32;
    using wstring = wchar __POINTER__;
    using wstring_sp = dty::SmartPointer<wchar>;
    using WCharArray = dty::collection::Array<wchar>;

    class WString final
        : public dty::collection::ICompareable<WString>,
        public dty::collection::IEquatable<WString>
    {
        __PRI__ wstring __VARIABLE__ _wString;
        __PRI__ int32   __VARIABLE__ _wStringLength;
        __PRI__ int32   __POINTER__  _reference;

        __PUB__ WString();
        __PUB__ WString(String       __REFERENCE__ str);
        __PUB__ WString(String       __REFERENCE__ str, EncodingBOM  __VARIABLE__ encodingBOM);
        __PUB__ WString(string_sp    __VARIABLE__  item);
        __PUB__ WString(string_sp    __VARIABLE__  item, EncodingBOM __VARIABLE__ encodingBOM);
        __PUB__ WString(wstring_sp   __VARIABLE__  item);
        __PUB__ WString(byte_ptr     __VARIABLE__  item, EncodingBOM __VARIABLE__ encodingBOM);
        __PUB__ WString(const wchar  __VARIABLE__  item, int32       __VARIABLE__ repeat);

        __PUB__ WString(const WString __REFERENCE__ str);

        __PUB__ virtual ~WString() override;

#pragma region Tianyu WString Function
        __PUB__ int32  __VARIABLE__ Length();
        __PUB__ bool   __VARIABLE__ IsEmpty();
        __PUB__ void   __VARIABLE__ Clear();
        __PUB__ wchar  __VARIABLE__ operator[](int32 __VARIABLE__ index);

        __PUB__ bool    __VARIABLE__ EndWith(const wchar    __VARIABLE__ ch);
        __PUB__ bool    __VARIABLE__ EndWith(WString        __REFERENCE__ str);
        __PUB__ bool    __VARIABLE__ Contains(const wchar   __VARIABLE__ str);
        __PUB__ bool    __VARIABLE__ Contains(const WString __REFERENCE__ str); // 需要Sunday算法
        __PUB__ int32   __VARIABLE__ IndexOf(const wchar    __VARIABLE__ ch);
        __PUB__ int32   __VARIABLE__ IndexOf(const wchar    __VARIABLE__ ch, int32 __VARIABLE__ startIndex);
        __PUB__ int32   __VARIABLE__ IndexOf(const wchar    __VARIABLE__ ch, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ int32   __VARIABLE__ IndexOf(WString        __REFERENCE__ str); // 需要Sunday算法
        __PUB__ int32   __VARIABLE__ IndexOf(WString        __REFERENCE__ str, int32 __VARIABLE__ startIndex); // 需要Sunday算法
        __PUB__ int32   __VARIABLE__ IndexOf(WString        __REFERENCE__ str, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex); // 需要Sunday算法

        __PUB__ int32   __VARIABLE__ LastIndexOf(const wchar __VARIABLE__ ch);
        __PUB__ int32   __VARIABLE__ LastIndexOf(const wchar __VARIABLE__ ch, int32 __VARIABLE__ startIndex);
        __PUB__ int32   __VARIABLE__ LastIndexOf(const wchar __VARIABLE__ ch, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ int32   __VARIABLE__ LastIndexOf(WString     __REFERENCE__ str); // 需要Sunday算法
        __PUB__ int32   __VARIABLE__ LastIndexOf(WString     __REFERENCE__ str, int32 __VARIABLE__ startIndex); // 需要Sunday算法
        __PUB__ int32   __VARIABLE__ LastIndexOf(WString     __REFERENCE__ str, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex); // 需要Sunday算法

        __PUB__ WString __VARIABLE__ PadLeft(int32  __VARIABLE__ length);
        __PUB__ WString __VARIABLE__ PadLeft(int32  __VARIABLE__ length, const wchar __VARIABLE__ ch);
        __PUB__ WString __VARIABLE__ PadRight(int32 __VARIABLE__ length);
        __PUB__ WString __VARIABLE__ PadRight(int32 __VARIABLE__ length, const wchar __VARIABLE__ ch);

        __PUB__ WString __VARIABLE__ Remove(const wchar __VARIABLE__ elem);
        __PUB__ WString __VARIABLE__ Remove(int32       __VARIABLE__ removeIndex);
        __PUB__ WString __VARIABLE__ Remove(int32       __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);

        __PUB__ bool    __VARIABLE__ StartWith(const wchar __VARIABLE__ ch);
        __PUB__ bool    __VARIABLE__ StartWith(WString     __REFERENCE__ str);
        __PUB__ WString __VARIABLE__ ToLower();
        __PUB__ WString __VARIABLE__ ToUpper();
        __PUB__ void    __VARIABLE__ Trim();
        __PUB__ void    __VARIABLE__ Trim(const wchar __VARIABLE__ ch);
        __PUB__ void    __VARIABLE__ Trim(const wchar __VARIABLE__ ch [], int32 __VARIABLE__ length);
        __PUB__ void    __VARIABLE__ TrimStart();
        __PUB__ void    __VARIABLE__ TrimStart(const wchar __VARIABLE__ ch);
        __PUB__ void    __VARIABLE__ TrimStart(const wchar __VARIABLE__ ch [], int32 __VARIABLE__ length);
        __PUB__ void    __VARIABLE__ TrimEnd();
        __PUB__ void    __VARIABLE__ TrimEnd(const wchar __VARIABLE__ ch);
        __PUB__ void    __VARIABLE__ TrimEnd(const wchar __VARIABLE__ ch [], int32 __VARIABLE__ length);

        __PUB__ wstring    __VARIABLE__ ToCStr();
        __PUB__ wstring_sp __VARIABLE__ ToSafeCStr();
        __PUB__ byte_ptr   __VARIABLE__ ToBytes();
        __PUB__ byte_ptr   __VARIABLE__ ToBytes(EncodingBytesSequence __VARIABLE__ byteSeq);
        __PUB__ String     __VARIABLE__ ToString();
        __PUB__ String     __VARIABLE__ ToString(EncodingBOM __VARIABLE__ encodingBOM);
        __PUB__ String     __VARIABLE__ ToString(EncodingType __VARIABLE__ encodingType, EncodingBytesSequence __VARIABLE__ bytesSeq);

        __PUB__ WCharArray                 __VARIABLE__ ToArray();
        __PUB__ collection::Array<WString> __VARIABLE__ Split(const wchar __VARIABLE__ splitChar);
        __PUB__ collection::Array<WString> __VARIABLE__ Split(const wchar __VARIABLE__ splitChar, bool __VARIABLE__ ignoreEmpty);
        __PUB__ collection::Array<WString> __VARIABLE__ Split(const wchar __VARIABLE__ splitChar, int32 __VARIABLE__ maxSplit);
        __PUB__ collection::Array<WString> __VARIABLE__ Split(const wchar __VARIABLE__ splitChar, int32 __VARIABLE__ maxSplit, bool __VARIABLE__ ignoreEmpty);
        __PUB__ collection::Array<WString> __VARIABLE__ Split(WString __REFERENCE__ splitStr, int32 __VARIABLE__ maxSplit); // 需要Sunday算法
        __PUB__ collection::Array<WString> __VARIABLE__ Split(WString __REFERENCE__ splitStr, int32 __VARIABLE__ maxSplit, bool __VARIABLE__ ignoreEmpty); // 需要Sunday算法

        __PUB__ WString __VARIABLE__ operator+(WString     __REFERENCE__ str);
        __PUB__ WString __VARIABLE__ operator+(string      __VARIABLE__  str);
        __PUB__ WString __VARIABLE__ operator+(const wchar __VARIABLE__  ch);

#pragma region WString Builder Component
        __PUB__ void __VARIABLE__ Append(bool         __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(byte         __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(const char   __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(const char   __VARIABLE__  value, int32 __VARIABLE__ repeat);
        __PUB__ void __VARIABLE__ Append(const wchar  __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(const wchar  __VARIABLE__  value, int32 __VARIABLE__ repeat);
        __PUB__ void __VARIABLE__ Append(const string __VARIABLE__  value, int32 __VARIABLE__ length);
        __PUB__ void __VARIABLE__ Append(const string __VARIABLE__  value, int32 __VARIABLE__ length, EncodingBOM __VARIABLE__ encodingBOM);
        __PUB__ void __VARIABLE__ Append(double       __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(float        __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(int16        __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(int32        __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(int64        __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(uint16       __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(uint32       __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(uint64       __VARIABLE__  value);
        __PUB__ void __VARIABLE__ Append(WString      __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Append(String       __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Append(String       __REFERENCE__ value, EncodingBOM __VARIABLE__ encodingBOM);

        __PUB__ void __VARIABLE__ AppendLine();
        __PUB__ void __VARIABLE__ AppendLine(bool         __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(byte         __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(const char   __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(const char   __VARIABLE__  value, int32 __VARIABLE__ repeat);
        __PUB__ void __VARIABLE__ AppendLine(const wchar  __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(const wchar  __VARIABLE__  value, int32 __VARIABLE__ repeat);
        __PUB__ void __VARIABLE__ AppendLine(const string __VARIABLE__  value, int32 __VARIABLE__ length);
        __PUB__ void __VARIABLE__ AppendLine(const string __VARIABLE__  value, int32 __VARIABLE__ length, EncodingBOM __VARIABLE__ encodingBOM);
        __PUB__ void __VARIABLE__ AppendLine(double       __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(float        __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(int16        __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(int32        __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(int64        __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(uint16       __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(uint32       __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(uint64       __VARIABLE__  value);
        __PUB__ void __VARIABLE__ AppendLine(WString      __REFERENCE__ value);
        __PUB__ void __VARIABLE__ AppendLine(String       __REFERENCE__ value);
        __PUB__ void __VARIABLE__ AppendLine(String       __REFERENCE__ value, EncodingBOM __VARIABLE__ encodingBOM);

        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, bool __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, byte __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, wchar __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, char __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, wchar __VARIABLE__ value, int32 __VARIABLE__ repeat);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, char __VARIABLE__ value, int32 __VARIABLE__ repeat);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, string __VARIABLE__ value, int32 __VARIABLE__ length);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, const string __VARIABLE__ value, int32 __VARIABLE__ length);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, string __VARIABLE__ value, int32 __VARIABLE__ length, EncodingBOM __VARIABLE__ encodingBOM);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, const string __VARIABLE__ value, int32 __VARIABLE__ length, EncodingBOM __VARIABLE__ encodingBOM);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, double __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, float __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, int16 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, int32 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, int64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, uint16 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, uint64 __VARIABLE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, WString __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, String __REFERENCE__ value);
        __PUB__ void __VARIABLE__ Insert(int32 __VARIABLE__ index, String __REFERENCE__ value, EncodingBOM __VARIABLE__ encodingBOM);

        __PUB__ void __VARIABLE__ Remove(const char __VARIABLE__ index);
        __PUB__ void __VARIABLE__ RemoveAt(int32    __VARIABLE__ index);
        __PUB__ void __VARIABLE__ RemoveRange(int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);

        __PUB__ void __VARIABLE__ Replace(const char  __VARIABLE__  findCh, const wchar __VARIABLE__  replaceCh);
        __PUB__ void __VARIABLE__ Replace(const char  __VARIABLE__  findCh, const wchar __VARIABLE__  replaceCh, int32  __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ void __VARIABLE__ Replace(const wchar __VARIABLE__  findCh, const wchar __VARIABLE__  replaceCh);
        __PUB__ void __VARIABLE__ Replace(WString     __REFERENCE__ findStr, WString    __REFERENCE__ replaceStr); // 需要Sunday算法

        __PUB__ String __VARIABLE__ ToString();
        __PUB__ string __VARIABLE__ ToCString() const;

        __PUB__ dty::collection::IteratorBase<wchar> __VARIABLE__ GetIterator();
#pragma endregion

#if __cplusplus >= 201103
        __PUB__ bool   __VARIABLE__ Contains(std::initializer_list<WString> strs);
#endif // !__cplusplus >= 201103

        __PUB__ WString __VARIABLE__ operator =(WString __REFERENCE__ source);
        __PUB__ WString __VARIABLE__ operator =(const wstring __VARIABLE__ source);
        __PUB__ operator wstring();
        __PUB__ operator wstring_sp();
#pragma endregion

#pragma region Tianyu IEquatable Interface
        __PUB__ virtual bool __VARIABLE__ Equals(WString __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(WString __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(WString __REFERENCE__ other) override;
#pragma endregion

#pragma region Tianyu ICompareable Interface
        __PUB__ virtual collection::CompareResult __VARIABLE__ CompareTo(WString __REFERENCE__ other) override;

        __PUB__ virtual bool          __VARIABLE__ operator <(WString __REFERENCE__ other) override;
        __PUB__ virtual bool          __VARIABLE__ operator >(WString __REFERENCE__ other) override;
        __PUB__ virtual bool          __VARIABLE__ operator <=(WString __REFERENCE__ other) override;
        __PUB__ virtual bool          __VARIABLE__ operator >=(WString __REFERENCE__ other) override;
#pragma endregion

#pragma region Statics for Tianyu WString
        __PUB__ static WString __VARIABLE__ Empty;

#if __cplusplus >= 201103
        __PUB__ static WString __VARIABLE__ Concat(std::initializer_list<WString> __VARIABLE__ strs);
        __PUB__ static WString __VARIABLE__ Join(const wchar __VARIABLE__ joinChar, std::initializer_list<WString> strs);
        __PUB__ static WString __VARIABLE__ Join(const wchar __VARIABLE__ joinChar, std::initializer_list<wstring> strs);
        __PUB__ static WString __VARIABLE__ Join(const wchar __VARIABLE__ joinChar, std::initializer_list<WString> strs, bool __VARIABLE__ forceEmpty);
        __PUB__ static WString __VARIABLE__ Join(const wchar __VARIABLE__ joinChar, std::initializer_list<wstring> strs, bool __VARIABLE__ forceEmpty);
#endif // !__cplusplus >= 201103
        __PUB__ static WString __VARIABLE__ Concat(WString __REFERENCE__ str0, WString __REFERENCE__ str1);
        __PUB__ static WString __VARIABLE__ Concat(WString __REFERENCE__ str0, WString __REFERENCE__ str1, WString __REFERENCE__ str2);
        __PUB__ static WString __VARIABLE__ Join(const wchar __VARIABLE__ joinChar, WString __REFERENCE__ str1, WString __REFERENCE__ str2);
        __PUB__ static WString __VARIABLE__ Join(const wchar __VARIABLE__ joinChar, WString __REFERENCE__ str1, WString __REFERENCE__ str2, bool __VARIABLE__ forceEmpty);
        __PUB__ static WString __VARIABLE__ Join(const wchar __VARIABLE__ joinChar, wstring __VARIABLE__ str1, int32 __VARIABLE__ length1, wstring __VARIABLE__ str2, int32 __VARIABLE__ length2);
#pragma endregion
    };
}

#endif // !__DTY_NATIVE_TEXT_WSTRING_H_PLUS_PLUS__