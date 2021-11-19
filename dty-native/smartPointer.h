/**
 * @file smartPointer.h
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-18
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_SMARTPOINTER_H__
#define __DTY_NATIVE_SMARTPOINTER_H__

#include"./utilize.h"

namespace dty
{
    template<typename T>
    class SmartPointer
    {
#pragma region Tianyu SmartPointer Internal Block
        __PRI__ enum SPType
        {
            STRONG,
            WEAK
        };

        __PRI__ SPType __VARIABLE__ _SmartPointerType;

        __PRI__ void __VARIABLE__ Move(SmartPointer<T> __REFERENCE__ sp)
        {
            this->_Pointer = sp._Pointer;
            this->_Size = sp._Size;

            sp._Pointer = null;
            sp._Size = 0;
        }
        __PRI__ void __VARIABLE__ Release()
        {
            if (null == this->_Pointer)
                return;

            if (1 == this->_Size)
                delete this->_Pointer;
            else
                delete [] this->_Pointer;
        }
        __PRI__ bool __VARIABLE__ IsSame(SmartPointer<T> __REFERENCE__ sp)
        {
            if (this->_Pointer == sp._Pointer)
                return true;

            if (this->operator&() + this->_Size > &sp && this->operator&() < &sp)
                return true;

            if (&sp + sp._Size > this->operator&() && &sp < this->operator&())
                return true;

            return false;
        }
#pragma endregion

        __PRI__ T     __POINTER__  _Pointer;
        __PRI__ int32 __VARIABLE__ _Size;

        __PUB__ explicit SmartPointer()
            : _SmartPointerType(SPType::STRONG),
            _Pointer(null),
            _Size(0)
        { }
        __PUB__ explicit SmartPointer(T __POINTER__ pointer)
        {
            if (null == pointer)
                throw new dty::except::NullPointerException();

            this->_SmartPointerType = SPType::STRONG;
            this->_Pointer = pointer;
            this->_Size = 1;
        }
        __PUB__ explicit SmartPointer(T __POINTER__ pointer, int32 __VARIABLE__ size)
        {
            if (null == pointer)
                throw new dty::except::NullPointerException();

            if (0 >= size)
                throw new dty::except::IndexOutOfRangeException();

            this->_SmartPointerType = SPType::STRONG;
            this->_Pointer = pointer;
            this->_Size = size;
        }
        __PUB__ explicit SmartPointer(SmartPointer<T> __REFERENCE__ sp)
            : _SmartPointerType(sp._SmartPointerType),
            _Pointer(null),
            _Size(0)
        {
            if (SPType::STRONG == this->_SmartPointerType)
                this->Move(sp);
            else
            {
                _Pointer = sp._Pointer;
                _Size = sp.size;
            }
        }

        __PUB__ virtual ~SmartPointer()
        {
            if (SPType::STRONG == this->_SmartPointerType)
                this->Release();
        }

        __PUB__ bool __VARIABLE__ IsNull()
        {
            return null == this->_Pointer;
        }

        __PUB__ uint64 __VARIABLE__  operator __REFERENCE__()
        {
            if (this->IsNull())
                return 0ULL;

            return (uint64)(this->_Pointer);
        }
        __PUB__ T      __REFERENCE__ operator __POINTER__()
        {
            if (null == this->_Pointer)
                throw new dty::except::NullPointerException();

            return __PTR_TO_REF__(this->_Pointer);
        }
        __PUB__ T      __POINTER__   operator ->()
        {
            if (null == this->_Pointer)
                throw new dty::except::NullPointerException();

            return this->_Pointer;
        }
        __PUB__ T      __POINTER__   operator ->() const
        {
            if (null == this->_Pointer)
                throw new dty::except::NullPointerException();

            return this->_Pointer;
        }
        __PUB__ T      __REFERENCE__ operator[] (int32 __VARIABLE__ index)
        {
            if (null == this->_Pointer)
                throw new dty::except::NullPointerException();

            if (0 > index || this->_Size <= index)
                throw new dty::except::ArgumentOutOfRangeException();

            return (this->_Pointer)[index];
        }

        __PUB__ SmartPointer<T> __REFERENCE__ operator=(SmartPointer<T> __REFERENCE__ source)
        {
            if (!this->IsSame(source))
            {
                if (SPType::WEAK == this->_SmartPointerType)
                {
                    this->_Pointer = source._Pointer;
                    this->_Size = source._Size;
                }
                else
                {
                    this->Release();
                    this->_SmartPointerType = source._SmartPointerType;
                    if (SPType::STRONG == this->_SmartPointerType)
                        this->Move(source);
                    else
                    {
                        this->_Pointer = source._Pointer;
                        this->_Size = source._Size;
                    }
                }
            }

            return (__PTR_TO_REF__ this);
        }
        __PUB__ SmartPointer<T> __VARIABLE__  GetWeak()
        {
            SmartPointer<T> weakPointer;
            weakPointer._SmartPointerType = SPType::WEAK;
            weakPointer._Pointer = this->_Pointer;
            weakPointer._SmartPointerType = this->_Size;

            return weakPointer;
        }

        __PUB__ bool __VARIABLE__ operator ==(SmartPointer<T> __REFERENCE__ other)
        {
            try
            {
                return (__PTR_TO_REF__ this->_Pointer) == (__PTR_TO_REF__ other._Pointer);
            }
            catch (const std::exception& e)
            {
                return this->_Pointer == other._Pointer;
            }

        }
        __PUB__ bool __VARIABLE__ operator !=(SmartPointer<T> __REFERENCE__ other)
        {
            try
            {
                return (__PTR_TO_REF__ this->_Pointer) != (__PTR_TO_REF__ other._Pointer);
            }
            catch (const std::exception& e)
            {
                return this->_Pointer != other._Pointer;
            }

        }
    };
}

#endif // !__DTY_NATIVE_SMARTPOINTER_H__