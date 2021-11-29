#include"./error.h"

using namespace dty::collection::except;

#pragma region Tianyu Operation Not Support Exception
CollectionReadOnlyException::CollectionReadOnlyException()
    : dty::except::OperationNotSupportException()
{

}
CollectionReadOnlyException::~CollectionReadOnlyException()
{

}
uint64 CollectionReadOnlyException::GetExceptionId()
{
    return DTY_Generic_CollectionReadOnlyException;
}
#pragma endregion

#pragma region Tianyu Operation Over Max Size Exception
CollectionOverMaxSizeException::CollectionOverMaxSizeException()
    : dty::except::OperationNotSupportException()
{

}
CollectionOverMaxSizeException::~CollectionOverMaxSizeException()
{

}
uint64 CollectionOverMaxSizeException::GetExceptionId()
{
    return DTY_Generic_CollectionOverMaxSizeException;
}
#pragma endregion