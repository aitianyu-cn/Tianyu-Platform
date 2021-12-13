/**
 * @file utilize.hpp(utils)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-06
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_UTILIZE_H_PLUS_PLUS__
#define __DTY_NATIVE_UTILS_UTILIZE_H_PLUS_PLUS__

#include "../commons/native/core/utilize.hpp"
#include<type_traits>
#include<cassert>

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

    class EventArgs : public virtual dty::collection::IEquatable<EventArgs>
    {
        __PUB__ EventArgs();
        __PUB__ EventArgs(EventArgs __REFERENCE__ args);
        __PUB__ virtual ~EventArgs();

        __PUB__ virtual bool __VARIABLE__ Equals(EventArgs __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(EventArgs __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(EventArgs __REFERENCE__ other) override;

        __PUB__ static dty::EventArgs __VARIABLE__ Empty;
    };

    template<class E>
    class EventHandler
    {
        __PUB__ void __VARIABLE__(__POINTER__ fnEventHandlerDelegation)(object __VARIABLE__ sender, E __VARIABLE__ e);

        __PUB__ EventHandler()
        {
            static_assert(std::is_base_of<dty::EventArgs, E>, "EventHandler template shoud be base of EventArges");
        }
        __PUB__ virtual ~EventHandler()
        {

        }

        __PUB__ void Trigger(object __VARIABLE__ sender, E __VARIABLE__ e)
        {

        }

        __PUB__ void  __VARIABLE__ AddHandler(dty::EventHandler<E>::fnEventHandlerDelegation __VARIABLE__ handler)
        {

        }
        __PUB__ void  __VARIABLE__ Clear()
        {

        }
        __PUB__ int32 __VARIABLE__ Count()
        {

        }
        __PUB__ void  __VARIABLE__ RemoveHandler(dty::EventHandler<E>::fnEventHandlerDelegation __VARIABLE__ handler)
        {

        }

        __PUB__ dty::EventHandler<E> __REFERENCE__ operator +=(dty::EventHandler<E>::fnEventHandlerDelegation __VARIABLE__ handler)
        {

        }
        __PUB__ dty::EventHandler<E> __REFERENCE__ operator -=(dty::EventHandler<E>::fnEventHandlerDelegation __VARIABLE__ handler)
        {

        }
    };
}

#endif // !__DTY_NATIVE_UTILS_UTILIZE_H_PLUS_PLUS__