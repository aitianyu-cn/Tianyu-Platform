

/**
 * @brief 该文件所定义的所有部分均为用于高级语言实现的接口, 使用时需要注意
 * @brief All of the definitions here are implemented by high-level language
 * please pay attention to using these APIs.
 *
 * @author TY0529
 * @date 2021-11-9
 */

#ifndef __DTY_NATIVE_EXTERNAL_APIS_H__
#define __DTY_NATIVE_EXTERNAL_APIS_H__

#include"utilize.h"

namespace dty
{
    /**
     * @brief 基于高级语言实现的异步、多线程等操作接口、封装
     * @brief Operation API implementation and data structure package based on high-level language implementation.
     */
    namespace extAPI
    {
        namespace com
        {

        }

        namespace io
        {

        }

        namespace thread
        {
            class Mutex
            {
                __PUB__ 
            };

            Mutex* AllocMutex(object obj);
            void DestroyMutex(object obj, Mutex* mutex);
        }

        namespace net
        {
            _interface TianyuNet
            {

            };
        }
    }
}

#endif // !__DTY_NATIVE_EXTERNAL_APIS_H__