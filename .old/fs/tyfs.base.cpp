#include"./tyfs.base.h"
#include"./error.h"

using namespace dty::fs;

// #pragma region Variable Bitmap Realization
// VariableBitmap::VariableBitmap(int32 bandSize, int32 itemCount)
// {
//     if (1 > bandSize)
//         throw dty::fs::except::ErrorFileSystemBandException();

//     if (0 > itemCount)
//         throw dty::except::ArgumentOutOfRangeException();

//     this->_BandSize = bandSize;
//     this->_ItemCount = itemCount;

//     int32 bytesLength = VariableBitmap::__GetTotalLength(bandSize, itemCount);
//     byte __POINTER__ bytes = new byte[bytesLength];
//     VariableBitmap::__FillBytes(bytes, bytesLength);

//     byte_ptr bitmap(bytes, bytesLength);
//     if (!this->_Bitmap.Move(bitmap))
//         throw dty::except::OperationFailedException();
// }
// VariableBitmap::VariableBitmap(int32 bandSize, byte_ptr sources, int32 itemCount)
// {
//     if (1 > bandSize)
//         throw dty::fs::except::ErrorFileSystemBandException();

//     if (sources.IsNull())
//         throw dty::except::ArgumentNullException();

//     if (0 > itemCount)
//         throw dty::except::ArgumentOutOfRangeException();

//     int32 bytesLength = VariableBitmap::__GetTotalLength(bandSize, itemCount);
//     if (bytesLength > sources.Size())
//         throw dty::except::ArgumentOutOfRangeException();

//     this->_BandSize = bandSize;
//     this->_ItemCount = itemCount;
//     if (!this->_Bitmap.Move(sources))
//         throw dty::except::OperationFailedException();
// }
// VariableBitmap::VariableBitmap(VariableBitmap& bitmap)
//     : _BandSize(bitmap._BandSize), _ItemCount(bitmap._ItemCount), _Bitmap(bitmap._Bitmap)
// { }
// VariableBitmap::~VariableBitmap()
// { }
// void VariableBitmap::SetStatus(int32 index, BitmapStatus& status)
// {
//     if (0 > index || index >= this->_ItemCount)
//         throw dty::except::ArgumentOutOfRangeException();

//     if (status.IsNull())
//         throw dty::except::ArgumentNullException();

//     VariableBitmap::BitmapItemPoint point = VariableBitmap::__CalculateBitmapItem(this->_BandSize, index);
//     int32 statusIndex = 0;
//     int32 bitmapIndex = point.BitmapStartIndex;
//     int32 bitmapOffset = point.BitmapOffset;
// }
// #pragma endregion

#pragma region Single Bitmap Realization
SingleBitmap::SingleBitmap(int64 itemCount)
    : _ItemCount(0), _BitmapLength(0), _Bitmap()
{
    if (0 > itemCount)
        throw dty::except::ArgumentOutOfRangeException();

    this->_ItemCount = itemCount;
    this->_BitmapLength = (itemCount >> 3) + ((itemCount & 0b111) == 0 ? 0 : 1);
    byte __POINTER__ bytes = new byte[this->_BitmapLength];
    for (int32 i = 0; i < this->_BitmapLength; ++i)
        bytes[i] = (byte)0x00;

    byte_ptr bitmap(bytes, this->_BitmapLength);
    this->_Bitmap.Move(bitmap);
}
SingleBitmap::SingleBitmap(byte_ptr sources, int64 itemCount)
    : _ItemCount(0), _BitmapLength(0), _Bitmap()
{
    if (0 > itemCount)
        throw dty::except::ArgumentOutOfRangeException();

    if (sources.IsNull())
        throw dty::except::ArgumentNullException();

    this->_BitmapLength = (itemCount >> 3) + ((itemCount && 0b111) == 0 ? 0 : 1);
    if (this->_BitmapLength > sources.Size())
        throw dty::except::ArgumentOutOfRangeException();

    this->_ItemCount = itemCount;
    this->_Bitmap.Move(sources);
}
SingleBitmap::SingleBitmap(const SingleBitmap& bitmap)
    : _ItemCount(bitmap._ItemCount), _BitmapLength(bitmap._BitmapLength), _Bitmap()
{
    int64 bytesLength = bitmap._Bitmap.Size();
    byte __POINTER__ bytes = new byte[bytesLength];
    for (int64 i = 0; i < bytesLength; ++i)
        bytes[i] = bitmap._Bitmap[i];

    byte_ptr newBitmap(bytes, bytesLength);
    this->_Bitmap.Move(newBitmap);
}
SingleBitmap::~SingleBitmap()
{ }

void SingleBitmap::SetStatus(int64 index, bool status)
{
    if (0 > index || index >= this->_ItemCount)
        throw dty::except::ArgumentOutOfRangeException();

    int32 bitmapIndex = index >> 3;
    int32 bitmapItem = 0b00000001 << (index & 0b111);

    if (status)
        this->_Bitmap[index] |= bitmapItem;
    else
        this->_Bitmap[index] &= (!bitmapItem);
}
bool SingleBitmap::GetStatus(int64 index)
{
    if (0 > index || index >= this->_ItemCount)
        throw dty::except::ArgumentOutOfRangeException();

    int32 bitmapIndex = index >> 3;
    int32 bitmapItem = 0b00000001 << (index & 0b111);

    return ((this->_Bitmap[index]) && bitmapItem) != 0;
}
bool SingleBitmap::operator[](int64 index)
{
    if (0 > index || index >= this->_ItemCount)
        throw dty::except::ArgumentOutOfRangeException();

    int32 bitmapIndex = index >> 3;
    int32 bitmapItem = 0b00000001 << (index & 0b111);

    return ((this->_Bitmap[index]) && bitmapItem) != 0;
}
dty::byte_ptr SingleBitmap::ToBytes()
{
    return this->_Bitmap.GetWeak();
}
#pragma endregion

#pragma region Double Bitmap Realization

#pragma endregion

