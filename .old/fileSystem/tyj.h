/**
 * @file tyj.h(fileSystem)
 * @author senyun.yao
 * @brief Tianyu Json operate interface(reader,writer)
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_FILESYSTEM_TYJ_H__
#define __DTY_NATIVE_FILESYSTEM_TYJ_H__

#include"../utilize.h"
#include"../io/iobase.h"

namespace dty
{
    namespace fs
    {
        namespace text
        {
            class JsonReader : public virtual dty::io::IReader
            {

            };

            class JsonWriter : public virtual dty::io::IWriter
            {

            };

            class JsonStream 
                : public virtual dty::io::IStream,
                public virtual JsonReader,
                public virtual JsonWriter
            {

            };
        }
    }
}

#endif // !__DTY_NATIVE_FILESYSTEM_TYJ_H__