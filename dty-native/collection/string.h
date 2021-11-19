/**
 * @file string.h(collection)
 * @author senyun.yao
 * @brief 
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_COLLECTION_STRING_H__
#define __DTY_NATIVE_COLLECTION_STRING_H__

#include"./collections.h"
#include"./clone.h"
#include<string>
#if __cplusplus >= 201103
#include<initializer_list>
#endif // !__cplusplus >= 201103

namespace dty::collection
{
    class String : public virtual IEquatable<String>,
        public virtual ICompareable<String>,
        public virtual ICloneable<String>
    {
        __PUB__ String();
        __PUB__ String(const char   __VARIABLE__ item, int32 __VARIABLE__ repeat);
        __PUB__ String(const string __VARIABLE__ str,  int32 __VARIABLE__ length);
        __PUB__ String(const string __VARIABLE__ str,  int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);

        __PUB__ explicit String(String __REFERENCE__ str);
        __PUB__ explicit String(const string __VARIABLE__ str);

        __PUB__ virtual ~String() override;

#pragma region Tianyu String Function
        __PUB__ int32                __VARIABLE__ Lenght();
        __PUB__ bool                 __VARIABLE__ IsEmpty();
        __PUB__ bool                 __VARIABLE__ InsertAt(int32 __VARIABLE__ index, char __REFERENCE__ obj);
        __PUB__ bool                 __VARIABLE__ RemoveAt(int32 __VARIABLE__ index);
        __PUB__ void                 __VARIABLE__ Clear();
        __PUB__ char                 __VARIABLE__ operator[](int32 __VARIABLE__ index);

        __PUB__ bool                 __VARIABLE__ EndWith(char __REFERENCE__ ch);
        __PUB__ bool                 __VARIABLE__ EndWith(String __REFERENCE__ str);
        __PUB__ bool                 __VARIABLE__ Contains(String __REFERENCE__ str);
        __PUB__ int32                __VARIABLE__ IndexOf(char __REFERENCE__ ch);
        __PUB__ int32                __VARIABLE__ IndexOf(char __REFERENCE__ ch, int32 __VARIABLE__ startIndex);
        __PUB__ int32                __VARIABLE__ IndexOf(char __REFERENCE__ ch, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ int32                __VARIABLE__ IndexOf(String __REFERENCE__ ch);
        __PUB__ int32                __VARIABLE__ IndexOf(String __REFERENCE__ ch, int32 __VARIABLE__ startIndex);
        __PUB__ int32                __VARIABLE__ IndexOf(String __REFERENCE__ ch, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ SmartPointer<String> __VARIABLE__ Insert(int32 __VARIABLE__ insertIndex, char __REFERENCE__ ch);
        __PUB__ SmartPointer<String> __VARIABLE__ Insert(int32 __VARIABLE__ insertIndex, string __VARIABLE__ str);
        __PUB__ SmartPointer<String> __VARIABLE__ Insert(int32 __VARIABLE__ insertIndex, String __REFERENCE__ str);
        __PUB__ int32                __VARIABLE__ LastIndexOf(char __VARIABLE__ ch);
        __PUB__ int32                __VARIABLE__ LastIndexOf(char __VARIABLE__ ch, int32 __VARIABLE__ startIndex);
        __PUB__ int32                __VARIABLE__ LastIndexOf(char __VARIABLE__ ch, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ int32                __VARIABLE__ LastIndexOf(String __REFERENCE__ str);
        __PUB__ int32                __VARIABLE__ LastIndexOf(String __REFERENCE__ str, int32 __VARIABLE__ startIndex);
        __PUB__ int32                __VARIABLE__ LastIndexOf(String __REFERENCE__ str, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ SmartPointer<String> __VARIABLE__ PadLeft(int32 __VARIABLE__ length);
        __PUB__ SmartPointer<String> __VARIABLE__ PadLeft(int32 __VARIABLE__ length, char __VARIABLE__ ch);
        __PUB__ SmartPointer<String> __VARIABLE__ PadRight(int32 __VARIABLE__ length);
        __PUB__ SmartPointer<String> __VARIABLE__ PadRight(int32 __VARIABLE__ length, char __VARIABLE__ ch);
        __PUB__ SmartPointer<String> __VARIABLE__ Remove(char __REFERENCE__ elem);
        __PUB__ SmartPointer<String> __VARIABLE__ Remove(int32 __VARIABLE__ removeIndex);
        __PUB__ SmartPointer<String> __VARIABLE__ Remove(int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ SmartPointer<String> __VARIABLE__ Replace(char __VARIABLE__ findChar, char __VARIABLE__ replaceChar);
        __PUB__ SmartPointer<String> __VARIABLE__ Replace(String __REFERENCE__ findChar, String __REFERENCE__ replaceChar);
        __PUB__ SmartPointer<String> __VARIABLE__ Split(int32 __REFERENCE__ resultLengh, char __VARIABLE__ splitChar);
        __PUB__ SmartPointer<String> __VARIABLE__ Split(int32 __REFERENCE__ resultLengh, char __VARIABLE__ splitChar, int32 __VARIABLE__ maxSplit);
        __PUB__ SmartPointer<String> __VARIABLE__ Split(int32 __REFERENCE__ resultLengh, char __VARIABLE__ splitChar, int32 __VARIABLE__ maxSplit, bool __VARIABLE__ ignoreEmpty);
        __PUB__ SmartPointer<String> __VARIABLE__ Split(int32 __REFERENCE__ resultLengh, String __REFERENCE__ splitChar, int32 __VARIABLE__ maxSplit);
        __PUB__ bool                 __VARIABLE__ StartWith(char __VARIABLE__ ch);
        __PUB__ bool                 __VARIABLE__ StartWith(String __REFERENCE__ str);
        __PUB__ SmartPointer<String> __VARIABLE__ ToLower();
        __PUB__ SmartPointer<String> __VARIABLE__ ToUpper();
        __PUB__ void                 __VARIABLE__ Trim();
        __PUB__ void                 __VARIABLE__ Trim(char __VARIABLE__ ch);
        __PUB__ void                 __VARIABLE__ Trim(char __VARIABLE__ ch[], int32 __VARIABLE__ length);
        __PUB__ void                 __VARIABLE__ TrimStart();
        __PUB__ void                 __VARIABLE__ TrimStart(char __VARIABLE__ ch);
        __PUB__ void                 __VARIABLE__ TrimStart(char __VARIABLE__ ch[], int32 __VARIABLE__ length);
        __PUB__ void                 __VARIABLE__ TrimEnd();
        __PUB__ void                 __VARIABLE__ TrimEnd(char __VARIABLE__ ch);
        __PUB__ void                 __VARIABLE__ TrimEnd(char __VARIABLE__ ch[], int32 __VARIABLE__ length);

        __PUB__ Array<char> __REFERENCE__ ToArray();
#if __cplusplus >= 201103
        __PUB__ bool   __VARIABLE__ Contains(std::initializer_list<String __REFERENCE__> strs);
#endif // !__cplusplus >= 201103

        __PUB__ String __REFERENCE__ operator =(String __REFERENCE__ source);
        __PUB__ String __REFERENCE__ operator =(const string __VARIABLE__ source);
        __PUB__ operator string();
#pragma endregion

#pragma region Tianyu IEquatable Interface
        __PUB__ virtual bool __VARIABLE__ Equals(String __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(String __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(String __REFERENCE__ other) override;
#pragma endregion

#pragma region Tianyu ICompareable Interface
        __PUB__ virtual CompareResult __VARIABLE__ CompareTo(String __REFERENCE__ other) override;
        __PUB__ virtual bool          __VARIABLE__ operator <(String __REFERENCE__ other) override;
        __PUB__ virtual bool          __VARIABLE__ operator >(String __REFERENCE__ other) override;
        __PUB__ virtual bool          __VARIABLE__ operator <=(String __REFERENCE__ other) override;
        __PUB__ virtual bool          __VARIABLE__ operator >=(String __REFERENCE__ other) override;
#pragma endregion

#pragma region Tianyu ICloneable Interface
        __PUB__ virtual SmartPointer<String> __VARIABLE__ Clone() override;
#pragma endregion

#pragma region Statics for Tianyu String
        __PUB__ static SmartPointer<String> __VARIABLE__ Empty;

#if __cplusplus >= 201103
        __PUB__ static SmartPointer<String> __VARIABLE__ Concat(std::initializer_list<String __REFERENCE__> strs);
        __PUB__ static SmartPointer<String> __VARIABLE__ Join(char __VARIABLE__ joinChar, std::initializer_list<String __REFERENCE__> strs);
        __PUB__ static SmartPointer<String> __VARIABLE__ Join(char __VARIABLE__ joinChar, std::initializer_list<string __POINTER__> strs);
#endif // !__cplusplus >= 201103
        __PUB__ static SmartPointer<String> __VARIABLE__ Concat(String __REFERENCE__ str0, String __REFERENCE__ str1);
        __PUB__ static SmartPointer<String> __VARIABLE__ Concat(String __REFERENCE__ str0, String __REFERENCE__ str1, String __REFERENCE__ str2);
        __PUB__ static SmartPointer<String> __VARIABLE__ Join(char __VARIABLE__ joinChar, SmartPointer<String> __VARIABLE__ strs, int32 __VARIABLE__ length);
        __PUB__ static SmartPointer<String> __VARIABLE__ Join(char __VARIABLE__ joinChar, string __POINTER__ strs, int32 __VARIABLE__ length);
#pragma endregion
    };
}

#endif // !__DTY_NATIVE_COLLECTION_STRING_H__
