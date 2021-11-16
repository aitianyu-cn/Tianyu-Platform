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

 /**
  * @brief Tianyu document models
  *
  */
namespace dty::model::doc
{
    enum TianyuDOMNodeType
    {
        UNDEFINED = -1,
        BOOL = 2,
        INT = 3,
        FLOAT = 4,
        OBJECT = 10,
        ARRAY = 11,
        STRING = 12,
    };

    class DOMKey final
        : public collection::IEquatable<DOMKey>,
        public collection::ICompareable<DOMKey>
    {
        __PRI__ DOMKey(string __VARIABLE__ key);
        __PRI__ DOMKey(const string __VARIABLE__ key);

        __PUB__ ~DOMKey();

        __PUB__ string __VARIABLE__ GetKey();
        __PUB__ string __VARIABLE__ ToString();

        __PUB__ virtual bool __VARIABLE__ Equals(DOMKey __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(DOMKey __REFERENCE__ other) override;

        __PUB__ virtual collection::CompareResult __VARIABLE__ CompareTo(DOMKey __REFERENCE__ other) override;

        __PUB__ static DOMKey __REFERENCE__ GetDOMKey(string __VARIABLE__ key);
        __PUB__ static DOMKey __REFERENCE__ GetDOMKey(const string __VARIABLE__ key);
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
        __PUB__ virtual ~TianyuDOMNode();

#pragma region Tianyu DOM node function
        __PUB__ virtual TianyuDOMNodeType __VARIABLE__ GetDOMType() override;

        __PUB__ virtual bool __VARIABLE__ IsNull() override;
        __PUB__ virtual bool __VARIABLE__ IsArray() override;

        __PUB__ virtual bool   __VARIABLE__ ToBool() override;
        __PUB__ virtual int32  __VARIABLE__ ToInt() override;
        __PUB__ virtual float  __VARIABLE__ ToFloat() override;
        __PUB__ virtual string __VARIABLE__ ToString() override;

        __PRO__ virtual void   __VARIABLE__ GetText(string __REFERENCE__ text, int32 __REFERENCE__ length) = 0;
#pragma endregion

#pragma region DOM node creator
        __PUB__ static IDOMNode __REFERENCE__ NewNullNode();
        __PUB__ static IDOMNode __REFERENCE__ NewArrayNode();
        __PUB__ static IDOMNode __REFERENCE__ NewObjectNode();
        __PUB__ static IDOMNode __REFERENCE__ NewNode(bool   __VARIABLE__ value);
        __PUB__ static IDOMNode __REFERENCE__ NewNode(int32  __VARIABLE__ value);
        __PUB__ static IDOMNode __REFERENCE__ NewNode(float  __VARIABLE__ value);
        __PUB__ static IDOMNode __REFERENCE__ NewNode(string __VARIABLE__ value);
#pragma endregion

        __PUB__ friend class TianyuDocument;
    };

    class TianyuDOMString final : public TianyuDOMNode
    {
        __PRI__ string __VARIABLE__ _Value;
        __PRI__ int32  __VARIABLE__ _Length;

        __PRI__ TianyuDOMString(string __VARIABLE__ str);
        __PRI__ TianyuDOMString(const string __VARIABLE__ str);
        __PUB__ virtual ~TianyuDOMString() override;

        __PUB__ int32 __VARIABLE__ Length();
        __PUB__ void  __VARIABLE__ SetString(string __VARIABLE__ newStr);
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

    class TianyuDOMArray final : public TianyuDOMNode,
        public collection::ICollection<IDOMNode>
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
        __PUB__ virtual bool  __VARIABLE__  AddRange(ICollection<IDOMNode> __REFERENCE__ range) = 0;
        __PUB__ virtual bool  __VARIABLE__  Remove(IDOMNode __REFERENCE__ elem) = 0;
        __PUB__ virtual bool  __VARIABLE__  Contains(IDOMNode __REFERENCE__ elem) = 0;
        __PUB__ virtual int32 __VARIABLE__  IndexOf(IDOMNode __REFERENCE__ elem) = 0;

        __PUB__ virtual IDOMNode  __REFERENCE__ operator[](int32 __VARIABLE__ index) = 0;
#pragma endregion

        __PUB__ friend class TianyuDOMNode;
    };

    class TianyuDOMObject final : public TianyuDOMNode,
        public collection::IDictionary<DOMKey, IDOMNode>
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
        __PUB__ virtual bool __VARIABLE__ Add(DOMKey __REFERENCE__ key, IDOMNode __REFERENCE__ value) override;
        __PUB__ virtual bool __VARIABLE__ Remove(DOMKey __REFERENCE__ key) override;
        __PUB__ virtual bool __VARIABLE__ Update(DOMKey __REFERENCE__ key, IDOMNode __REFERENCE__ value) override;
        __PUB__ virtual void __VARIABLE__ AddOrUpdate(DOMKey __REFERENCE__ key, IDOMNode __REFERENCE__ value) override;
        __PUB__ virtual bool __VARIABLE__ ContainsKey(DOMKey __REFERENCE__ key) override;

        __PUB__ virtual IDOMNode __REFERENCE__ operator[](DOMKey __REFERENCE__ key) override;

        __PUB__ virtual collection::Iterator<DOMKey>   __REFERENCE__ GetKeyIterator() override;
        __PUB__ virtual collection::Iterator<IDOMNode> __REFERENCE__ GetValueIterator() override;
#pragma endregion

#pragma region Tianyu Collection Interface Function
        __PUB__ virtual int32       __VARIABLE__  Count() override;
        __PUB__ virtual bool        __VARIABLE__  IsEmpty() override;
        __PUB__ virtual collection::Array<collection::KeyValuePair<DOMKey, IDOMNode>> __REFERENCE__ ToArray() override;

        __PUB__ virtual void  __VARIABLE__  Clear() override;
        __PUB__ virtual bool  __VARIABLE__  Add(collection::KeyValuePair<DOMKey, IDOMNode> __REFERENCE__ elem) override;
        __PUB__ virtual bool  __VARIABLE__  AddRange(ICollection<collection::KeyValuePair<DOMKey, IDOMNode>> __REFERENCE__ range) override;
        __PUB__ virtual bool  __VARIABLE__  Remove(collection::KeyValuePair<DOMKey, IDOMNode> __REFERENCE__ elem) override;
        __PUB__ virtual bool  __VARIABLE__  Contains(collection::KeyValuePair<DOMKey, IDOMNode> __REFERENCE__ elem) override;
        __PUB__ virtual int32 __VARIABLE__  IndexOf(collection::KeyValuePair<DOMKey, IDOMNode> __REFERENCE__ elem) override;

        __PUB__ virtual collection::KeyValuePair<DOMKey, IDOMNode>  __REFERENCE__ operator[](int32 __VARIABLE__ index) override;
#pragma endregion

        __PUB__ friend class TianyuDOMNode;
    };
}

#endif // !__DTY_NATIVE_MODEL_DOM_H__