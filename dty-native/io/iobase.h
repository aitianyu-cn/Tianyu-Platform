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
        _interface IFileReader
        {

        };
        _interface IFileWriter
        {

        };

        _interface IFileStream : public IFileReader, public IFileWriter
        {

        };
    }
}

#endif // !__DTY_NATIVE_IO_FILESTREAM_H__