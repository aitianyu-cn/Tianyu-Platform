/**
 * @file iobase.h
 * @author senyun.yao
 * @brief 
 * @version 0.1
 * @date 2021-11-11
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_IO_FILESTREAM_H__
#define __DTY_NATIVE_IO_FILESTREAM_H__

#include "../utilize.h"

namespace dty
{
    namespace io
    {
        _interface IDispose
        {
            __PUB__ virtual void Dispose() = 0;
        };

        _interface IReader : public virtual IDispose
        {
            __PUB__ virtual bool __VARIABLE__ Open(string __VARIABLE__ filePath) = 0;
        };
        _interface IWriter : public virtual IDispose
        {
            __PUB__ virtual bool __VARIABLE__ Flush() = 0;
            __PUB__ virtual bool __VARIABLE__ Close() = 0;
        };

        _interface IStream : public IReader, public IWriter
        {

        };
    }
}

#endif // !__DTY_NATIVE_IO_FILESTREAM_H__