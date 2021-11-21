#include"../generic.h"
#include"../utilize.h"
#include<string>

using namespace dty::except;

Exception::Exception()
    : std::exception(),
    collection::IEquatable<Exception>(),
    _Msg(null)
{
    
}
Exception::Exception(const string msg)
    : std::exception(),
    collection::IEquatable<Exception>()
{
    int32 length = strlen(msg);
    this->_Msg = new char[length + 1];
    strncpy(this->_Msg, msg, length);
    this->_Msg[length] = '\0';
}
Exception::~Exception()
{
    if (null != this->_Msg)
        delete[] this->_Msg;
}

uint64 Exception::GetExceptionId()
{
    return DTY_Generic_Exception;
}

const char* Exception::what() const noexcept
{
    return (const char __POINTER__)(this->_Msg);
}

string Exception::ToString() noexcept
{
    return this->_Msg;
}

bool Exception::Equals(Exception& other)
{
    return (__PTR_TO_REF__ this) == other;
}

bool Exception::operator==(Exception& other)
{
    return this->GetExceptionId() == other.GetExceptionId();
}

bool Exception::operator!=(Exception& other)
{
    return this->GetExceptionId() != other.GetExceptionId();
}