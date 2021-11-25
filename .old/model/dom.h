/**
 * @file dom.h(model)
 * @author senyun.yao
 * @brief Tianyu Document Object Model for tianyu platform
 * @version 0.1
 * @date 2021-11-15
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_MODEL_DOM_H__
#define __DTY_NATIVE_MODEL_DOM_H__

#include"../utilize.h"
#include"../collection/dictionary.h"
#include"../collection/string.h"

 /**
  * @brief Tianyu document models
  *
  */
namespace dty::model::doc
{
    enum class TianyuDOMNodeType : int32
    {
        UNDEFINED = -1,
        BOOL = 2,
        INT = 3,
        FLOAT = 4,
        OBJECT = 10,
        ARRAY = 11,
        STRING = 12,
    };

    _interface IDOMNode
    {
        __PUB__ virtual TianyuDOMNodeType __VARIABLE__ GetDOMType() = 0;

        __PUB__ virtual bool __VARIABLE__ IsNull() = 0;
        __PUB__ virtual bool __VARIABLE__ IsArray() = 0;

        __PUB__ virtual bool   __VARIABLE__ ToBool() = 0;
        __PUB__ virtual int32  __VARIABLE__ ToInt() = 0;
        __PUB__ virtual float  __VARIABLE__ ToFloat() = 0;
        __PUB__ virtual string __VARIABLE__ ToString() = 0;
    };

    abstract class TianyuDocument
    {

    };

    abstract class TianyuDOMNode : public IDOMNode
    {
        __PRO__ TianyuDOMNode();
        __PUB__ virtual ~TianyuDOMNode();

#pragma region Tianyu DOM node function
        __PUB__ virtual TianyuDOMNodeType __VARIABLE__ GetDOMType() override;

        __PUB__ virtual bool __VARIABLE__ IsNull() override;
        __PUB__ virtual bool __VARIABLE__ IsArray() override;

        __PUB__ virtual bool   __VARIABLE__ ToBool() override;
        __PUB__ virtual int32  __VARIABLE__ ToInt() override;
        __PUB__ virtual float  __VARIABLE__ ToFloat() override;
        __PUB__ virtual string __VARIABLE__ ToString() override;

        __PRO__ virtual void   __VARIABLE__ GetText(string __REFERENCE__ text, int32 __REFERENCE__ length);
#pragma endregion

#pragma region DOM node creator
        __PUB__ static SmartPointer<IDOMNode> __VARIABLE__ NewNullNode();
        __PUB__ static SmartPointer<IDOMNode> __VARIABLE__ NewArrayNode();
        __PUB__ static SmartPointer<IDOMNode> __VARIABLE__ NewObjectNode();
        __PUB__ static SmartPointer<IDOMNode> __VARIABLE__ NewNode(bool   __VARIABLE__ value);
        __PUB__ static SmartPointer<IDOMNode> __VARIABLE__ NewNode(int32  __VARIABLE__ value);
        __PUB__ static SmartPointer<IDOMNode> __VARIABLE__ NewNode(float  __VARIABLE__ value);
        __PUB__ static SmartPointer<IDOMNode> __VARIABLE__ NewNode(string __VARIABLE__ value);
#pragma endregion

        __PUB__ friend class TianyuDocument;
    };

    class TianyuDOMString final : public TianyuDOMNode
    {
        __PRI__ string __VARIABLE__ _Value;
        __PRI__ int32  __VARIABLE__ _Length;

        __PRI__ TianyuDOMString(const string __VARIABLE__ str);
        __PUB__ virtual ~TianyuDOMString() override;

        __PUB__ int32 __VARIABLE__ Length();
        __PUB__ void  __VARIABLE__ SetString(const string __VARIABLE__ newStr);

#pragma region Tianyu DOM node base
        __PUB__ virtual TianyuDOMNodeType __VARIABLE__ GetDOMType() override;

        __PUB__ virtual bool __VARIABLE__ IsNull() override;
        __PUB__ virtual bool __VARIABLE__ IsArray() override;

        __PUB__ virtual bool   __VARIABLE__ ToBool() override;
        __PUB__ virtual int32  __VARIABLE__ ToInt() override;
        __PUB__ virtual float  __VARIABLE__ ToFloat() override;
        __PUB__ virtual string __VARIABLE__ ToString() override;

        __PRO__ virtual void   __VARIABLE__ GetText(string __REFERENCE__ text, int32 __REFERENCE__ length) override;
#pragma endregion

        __PUB__ friend class TianyuDOMNode;
    };

    class TianyuDOMBool final : public TianyuDOMNode
    {
        __PRI__ bool __VARIABLE__ _Value;

        __PRI__ TianyuDOMBool(bool __VARIABLE__ value);
        __PUB__ virtual ~TianyuDOMBool() override;

        __PUB__ void __VARIABLE__ SetValue(bool __VARIABLE__ value);

#pragma region Tianyu DOM node base
        __PUB__ virtual TianyuDOMNodeType __VARIABLE__ GetDOMType() override;

        __PUB__ virtual bool __VARIABLE__ IsNull() override;
        __PUB__ virtual bool __VARIABLE__ IsArray() override;

        __PUB__ virtual bool   __VARIABLE__ ToBool() override;
        __PUB__ virtual int32  __VARIABLE__ ToInt() override;
        __PUB__ virtual float  __VARIABLE__ ToFloat() override;
        __PUB__ virtual string __VARIABLE__ ToString() override;

        __PRO__ virtual void   __VARIABLE__ GetText(string __REFERENCE__ text, int32 __REFERENCE__ length) override;
#pragma endregion

        __PUB__ friend class TianyuDOMNode;
    };

    class TianyuDOMInteger final : public TianyuDOMNode
    {
        __PRI__ int32 __VARIABLE__ _Value;

        __PRI__ TianyuDOMInteger(int32 __VARIABLE__ value);
        __PUB__ virtual ~TianyuDOMInteger() override;

        __PUB__ void __VARIABLE__ SetValue(int32 __VARIABLE__ value);

#pragma region Tianyu DOM node base
        __PUB__ virtual TianyuDOMNodeType __VARIABLE__ GetDOMType() override;

        __PUB__ virtual bool __VARIABLE__ IsNull() override;
        __PUB__ virtual bool __VARIABLE__ IsArray() override;

        __PUB__ virtual bool   __VARIABLE__ ToBool() override;
        __PUB__ virtual int32  __VARIABLE__ ToInt() override;
        __PUB__ virtual float  __VARIABLE__ ToFloat() override;
        __PUB__ virtual string __VARIABLE__ ToString() override;

        __PRO__ virtual void   __VARIABLE__ GetText(string __REFERENCE__ text, int32 __REFERENCE__ length) override;
#pragma endregion

        __PUB__ friend class TianyuDOMNode;
    };

    class TianyuDOMFloat final : public TianyuDOMNode
    {
        __PRI__ float __VARIABLE__ _Value;

        __PRI__ TianyuDOMFloat(float __VARIABLE__ value);
        __PUB__ virtual ~TianyuDOMFloat() override;

        __PUB__ void __VARIABLE__ SetValue(float __VARIABLE__ value);

#pragma region Tianyu DOM node base
        __PUB__ virtual TianyuDOMNodeType __VARIABLE__ GetDOMType() override;

        __PUB__ virtual bool __VARIABLE__ IsNull() override;
        __PUB__ virtual bool __VARIABLE__ IsArray() override;

        __PUB__ virtual bool   __VARIABLE__ ToBool() override;
        __PUB__ virtual int32  __VARIABLE__ ToInt() override;
        __PUB__ virtual float  __VARIABLE__ ToFloat() override;
        __PUB__ virtual string __VARIABLE__ ToString() override;

        __PRO__ virtual void   __VARIABLE__ GetText(string __REFERENCE__ text, int32 __REFERENCE__ length) override;
#pragma endregion

        __PUB__ friend class TianyuDOMNode;
    };

    class TianyuDOMArray final : public TianyuDOMNode
    {
#pragma region Tianyu DOM node base
        __PUB__ virtual TianyuDOMNodeType __VARIABLE__ GetDOMType() override;

        __PUB__ virtual bool __VARIABLE__ IsNull() override;
        __PUB__ virtual bool __VARIABLE__ IsArray() override;

        __PUB__ virtual bool   __VARIABLE__ ToBool() override;
        __PUB__ virtual int32  __VARIABLE__ ToInt() override;
        __PUB__ virtual float  __VARIABLE__ ToFloat() override;
        __PUB__ virtual string __VARIABLE__ ToString() override;

        __PRO__ virtual void   __VARIABLE__ GetText(string __REFERENCE__ text, int32 __REFERENCE__ length) override;
#pragma endregion

#pragma region Tianyu ICollection interface function
        __PUB__ virtual int32                       __VARIABLE__  Count() = 0;
        __PUB__ virtual bool                        __VARIABLE__  IsEmpty() = 0;
        __PUB__ virtual collection::Array<IDOMNode> __REFERENCE__ ToArray() = 0;

        __PUB__ virtual void  __VARIABLE__  Clear() = 0;
        __PUB__ virtual bool  __VARIABLE__  Add(IDOMNode __REFERENCE__ elem) = 0;
        __PUB__ virtual bool  __VARIABLE__  AddRange(dty::collection::Array<IDOMNode> __REFERENCE__ range) = 0;
        __PUB__ virtual bool  __VARIABLE__  Remove(IDOMNode __REFERENCE__ elem) = 0;
        __PUB__ virtual bool  __VARIABLE__  Contains(IDOMNode __REFERENCE__ elem) = 0;
        __PUB__ virtual int32 __VARIABLE__  IndexOf(IDOMNode __REFERENCE__ elem) = 0;

        __PUB__ virtual IDOMNode  __REFERENCE__ operator[](int32 __VARIABLE__ index) = 0;
#pragma endregion

        __PUB__ friend class TianyuDOMNode;
    };

    class TianyuDOMObject final : public TianyuDOMNode
    {
#pragma region Tianyu DOM node base
        __PUB__ virtual TianyuDOMNodeType __VARIABLE__ GetDOMType() override;

        __PUB__ virtual bool __VARIABLE__ IsNull() override;
        __PUB__ virtual bool __VARIABLE__ IsArray() override;

        __PUB__ virtual bool   __VARIABLE__ ToBool() override;
        __PUB__ virtual int32  __VARIABLE__ ToInt() override;
        __PUB__ virtual float  __VARIABLE__ ToFloat() override;
        __PUB__ virtual string __VARIABLE__ ToString() override;

        __PRO__ virtual void   __VARIABLE__ GetText(string __REFERENCE__ text, int32 __REFERENCE__ length) override;
#pragma endregion

#pragma region Tianyu Dictionary Interface Function
        __PUB__ virtual bool __VARIABLE__ Add(collection::String __REFERENCE__ key, IDOMNode __REFERENCE__ value) override;
        __PUB__ virtual bool __VARIABLE__ Remove(collection::String __REFERENCE__ key) override;
        __PUB__ virtual bool __VARIABLE__ Update(collection::String __REFERENCE__ key, IDOMNode __REFERENCE__ value) override;
        __PUB__ virtual void __VARIABLE__ AddOrUpdate(collection::String __REFERENCE__ key, IDOMNode __REFERENCE__ value) override;
        __PUB__ virtual bool __VARIABLE__ ContainsKey(collection::String __REFERENCE__ key) override;

        __PUB__ virtual IDOMNode __REFERENCE__ operator[](collection::String __REFERENCE__ key) override;

        __PUB__ virtual collection::Iterator<collection::String>   __REFERENCE__ GetKeyIterator() override;
        __PUB__ virtual collection::Iterator<IDOMNode> __REFERENCE__ GetValueIterator() override;
#pragma endregion

#pragma region Tianyu Collection Interface Function
        __PUB__ virtual int32       __VARIABLE__  Count() override;
        __PUB__ virtual bool        __VARIABLE__  IsEmpty() override;
        __PUB__ virtual collection::Array<collection::KeyValuePair<collection::String, IDOMNode>> __REFERENCE__ ToArray() override;

        __PUB__ virtual void  __VARIABLE__  Clear() override;
        __PUB__ virtual bool  __VARIABLE__  Add(collection::KeyValuePair<collection::String, IDOMNode> __REFERENCE__ elem) override;
        __PUB__ virtual bool  __VARIABLE__  AddRange(ICollection<collection::KeyValuePair<collection::String, IDOMNode>> __REFERENCE__ range) override;
        __PUB__ virtual bool  __VARIABLE__  Remove(collection::KeyValuePair<collection::String, IDOMNode> __REFERENCE__ elem) override;
        __PUB__ virtual bool  __VARIABLE__  Contains(collection::KeyValuePair<collection::String, IDOMNode> __REFERENCE__ elem) override;
        __PUB__ virtual int32 __VARIABLE__  IndexOf(collection::KeyValuePair<collection::String, IDOMNode> __REFERENCE__ elem) override;

        __PUB__ virtual collection::KeyValuePair<collection::String, IDOMNode>  __REFERENCE__ operator[](int32 __VARIABLE__ index) override;
#pragma endregion

        __PUB__ friend class TianyuDOMNode;
    };
}

#endif // !__DTY_NATIVE_MODEL_DOM_H__