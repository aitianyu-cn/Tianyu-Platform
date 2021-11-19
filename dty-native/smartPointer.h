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
#include"./exception/generic.h"

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
        __PUB__ explicit SmartPointer(T __POINTER__ pointer, bool __VARIABLE__ weak)
            : SmartPointer<T>(pointer)
        {
            if (weak)
                this->_SmartPointerType = SPType::WEAK;
        }
        __PUB__ explicit SmartPointer(T __POINTER__ pointer, int32 __VARIABLE__ size, bool __VARIABLE__ weak)
            : SmartPointer<T>(pointer, size)
        {
            if (weak)
                this->_SmartPointerType = SPType::WEAK;
        }
        __PUB__ SmartPointer(const SmartPointer<T> __REFERENCE__ sp)
            : _SmartPointerType(sp._SmartPointerType),
            _Pointer(sp._Pointer),
            _Size(sp._Size)
        {
            if (SPType::STRONG == sp._SmartPointerType)
            {
                // --dty-cpp-lint: unsafe-convert-constRef_to_Ref
                SmartPointer<T>& spMove = (SmartPointer<T> __REFERENCE__)sp;
                spMove._Pointer = null;
                spMove._Size = 0;
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

        __PUB__ int32  __VARIABLE__  Size()
        {
            return this->_Size;
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

        __PUB__ SmartPointer<T> __VARIABLE__ GetWeak()
        {
            return __PTR_TO_VAR__ this;
        }
        __PUB__ bool            __VARIABLE__ Move(SmartPointer<T> __REFERENCE__ sp)
        {
            if (SPType::STRONG != sp._SmartPointerType)
                return false;

            if (SPType::STRONG == this->_SmartPointerType && null != this-> _Pointer)
            {
                if (1 < this->_Size)
                    delete[] this->_Pointer;
                else
                    delete this->_Pointer;
            }

            this->_SmartPointerType = sp._SmartPointerType;
            this->_Pointer = sp._Pointer;
            this->_Size = sp._Size;

            sp._Pointer = null;
            sp._Size = 0;

            return true;
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