/**
 * @file utilize.hpp(io)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-01
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_IO_UTILIZE_H_PLUS_PLUS__
#define __DTY_NATIVE_IO_UTILIZE_H_PLUS_PLUS__

#include"../utilize.hpp"
#include"./utilize.h"

namespace dty::io
{
    enum class IOSourceType
    {
        UnKnown = 0,
        File = 1,
        Disk = 2,
        Folder = 3
    };

    enum class IOAccessType
    {
        ReadWrite = 3,
        ReadOnly = 2,
        WriteOnly = 1,
        None = 0
    };

    enum class FileAttributes : uint32
    {
        Archive = 0x20,
        Compressed = 0x800,
        Device = 0x40,
        Directory = 0x10,
        Encrypted = 0x4000,
        Hidden = 0x2,
        IntegrityStream = 0x8000,
        Normal = 0x80,
        NoScrubData = 0x20000,
        NotContentIndexed = 0x2000,
        Offline = 0x1000,
        ReadOnly = 0x01,
        ReparsePoint = 0x400,
        SparseFile = 0x200,
        System = 0x4,
        Temporary = 0x100
    };

    abstract class FileSystemInfo
    {
        __PUB__ FileSystemInfo();
        __PUB__ virtual ~FileSystemInfo();

#pragma region Properties
        __PUB__ virtual string __VARIABLE__ FullPath() = 0;
        __PUB__ virtual string __VARIABLE__ FullPath() const = 0;
        __PUB__ virtual string __VARIABLE__ OriginalPath() = 0;
        __PUB__ virtual string __VARIABLE__ OriginalPath() const = 0;

        __PUB__ virtual FileAttributes __VARIABLE__ GetAttributes() = 0;
        __PUB__ virtual void           __VARIABLE__ SetAttributes(FileAttributes __VARIABLE__ attributes) = 0;
        __PUB__ virtual uint64         __VARIABLE__ CreationTime() = 0;
        __PUB__ virtual uint64         __VARIABLE__ LastAccessTime() = 0;
        __PUB__ virtual uint64         __VARIABLE__ LastWriteTime() = 0;
        __PUB__ virtual bool           __VARIABLE__ Exist() = 0;
        __PUB__ virtual string         __VARIABLE__ Extension() = 0;
        __PUB__ virtual string         __VARIABLE__ Extension() const = 0;
        __PUB__ virtual string         __VARIABLE__ Name() = 0;
        __PUB__ virtual string         __VARIABLE__ Name() const = 0;
        __PUB__ virtual string         __VARIABLE__ PureName() = 0;
        __PUB__ virtual string         __VARIABLE__ PureName() const = 0;
#pragma endregion

#pragma region Methods
        __PUB__ virtual void __VARIABLE__ Delete() = 0;
        __PUB__ virtual void __VARIABLE__ Refresh() = 0;
#pragma endregion
    };

    class FileInfo : FileSystemInfo
    {
        __PUB__ FileInfo(const string __VARIABLE__ fileName);
        __PUB__ virtual ~FileInfo() override;

        __PUB__ string __VARIABLE__ Directory();
        __PUB__ string __VARIABLE__ Directory() const;
        __PUB__ string __VARIABLE__ DirectoryName();
        __PUB__ string __VARIABLE__ DirectoryName() const;

        __PUB__ bool   __VARIABLE__ IsReadOnly();
        __PUB__ uint64 __VARIABLE__ Length();

#pragma region FileSystemInfo Base
        __PUB__ virtual string __VARIABLE__ FullPath() override;
        __PUB__ virtual string __VARIABLE__ FullPath() const override;
        __PUB__ virtual string __VARIABLE__ OriginalPath() override;
        __PUB__ virtual string __VARIABLE__ OriginalPath() const override;

        __PUB__ virtual FileAttributes __VARIABLE__ GetAttributes() override;
        __PUB__ virtual void           __VARIABLE__ SetAttributes(FileAttributes __VARIABLE__ attributes) override;
        __PUB__ virtual uint64         __VARIABLE__ CreationTime() override;
        __PUB__ virtual uint64         __VARIABLE__ LastAccessTime() override;
        __PUB__ virtual uint64         __VARIABLE__ LastWriteTime() override;
        __PUB__ virtual bool           __VARIABLE__ Exist() override;
        __PUB__ virtual string         __VARIABLE__ Extension() override;
        __PUB__ virtual string         __VARIABLE__ Extension() const override;
        __PUB__ virtual string         __VARIABLE__ Name() override;
        __PUB__ virtual string         __VARIABLE__ Name() const override;
        __PUB__ virtual string         __VARIABLE__ PureName() override;
        __PUB__ virtual string         __VARIABLE__ PureName() const override;

        __PUB__ virtual void __VARIABLE__ Delete() override;
        __PUB__ virtual void __VARIABLE__ Refresh() override;
#pragma endregion
    };

    class DirectoryInfo : FileSystemInfo
    {
#pragma region FileSystemInfo Base
        __PUB__ virtual string __VARIABLE__ FullPath();
        __PUB__ virtual string __VARIABLE__ FullPath() const;
        __PUB__ virtual string __VARIABLE__ OriginalPath();
        __PUB__ virtual string __VARIABLE__ OriginalPath() const;

        __PUB__ virtual FileAttributes __VARIABLE__ GetAttributes();
        __PUB__ virtual void           __VARIABLE__ SetAttributes(FileAttributes __VARIABLE__ attributes);
        __PUB__ virtual uint64         __VARIABLE__ CreationTime();
        __PUB__ virtual uint64         __VARIABLE__ LastAccessTime();
        __PUB__ virtual uint64         __VARIABLE__ LastWriteTime();
        __PUB__ virtual bool           __VARIABLE__ Exist();
        __PUB__ virtual string         __VARIABLE__ Extension();
        __PUB__ virtual string         __VARIABLE__ Extension() const;
        __PUB__ virtual string         __VARIABLE__ Name();
        __PUB__ virtual string         __VARIABLE__ Name() const;
        __PUB__ virtual string         __VARIABLE__ PureName();
        __PUB__ virtual string         __VARIABLE__ PureName() const;

        __PUB__ virtual void __VARIABLE__ Delete();
        __PUB__ virtual void __VARIABLE__ Refresh();
#pragma endregion
    };

    class DiskInfo : FileSystemInfo
    {
#pragma region FileSystemInfo Base
        __PUB__ virtual string __VARIABLE__ FullPath();
        __PUB__ virtual string __VARIABLE__ FullPath() const;
        __PUB__ virtual string __VARIABLE__ OriginalPath();
        __PUB__ virtual string __VARIABLE__ OriginalPath() const;

        __PUB__ virtual FileAttributes __VARIABLE__ GetAttributes();
        __PUB__ virtual void           __VARIABLE__ SetAttributes(FileAttributes __VARIABLE__ attributes);
        __PUB__ virtual uint64         __VARIABLE__ CreationTime();
        __PUB__ virtual uint64         __VARIABLE__ LastAccessTime();
        __PUB__ virtual uint64         __VARIABLE__ LastWriteTime();
        __PUB__ virtual bool           __VARIABLE__ Exist();
        __PUB__ virtual string         __VARIABLE__ Extension();
        __PUB__ virtual string         __VARIABLE__ Extension() const;
        __PUB__ virtual string         __VARIABLE__ Name();
        __PUB__ virtual string         __VARIABLE__ Name() const;
        __PUB__ virtual string         __VARIABLE__ PureName();
        __PUB__ virtual string         __VARIABLE__ PureName() const;

        __PUB__ virtual void __VARIABLE__ Delete();
        __PUB__ virtual void __VARIABLE__ Refresh();
#pragma endregion
    };

    class IO final
    {

    };
}

#endif // !__DTY_NATIVE_IO_UTILIZE_H_PLUS_PLUS__