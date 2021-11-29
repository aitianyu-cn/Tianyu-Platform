# 天宇可扩展文件(Tianyu eX File)

TXF文件基于TYFS（Tianyu File System）构建，所采用技术结构类似。

+ TXF头  
```
    {
        byte MagicNumber[16];   // TXF文件的头部包含用于标识文件的魔数：“T.Y.X.F.”，占用8字节
        byte SegmentSize;       // TXF文件的分段大小，采用固定值
        byte BlockSize;         // TXF文件的块大小，采用固定值，需与段大小成比例，加载文件时会自动校验
        bmap SegmentMap;        // TXF文件的段表
        {
            流块1：符号表
            流块2：主记录表
            ···：  最多支持256个流块
        }
    }
    (
        针对流块而言，系统默认需要保留符号表以及主记录表等，所以实际可用流块数小于256.
    )
```

+ 位图  
```
    位图包含两种：
    1. 纯位图
        纯位图中，每一个对象实例使用一个bit进行标记，应用于块的标记，用于标识对应块是否使用。
    2. 复合位图
        复合位图应用于段的标记，每一个对象实例使用两个bit进行标记，共4种状态
        {
            未分配
            完全空闲
            存在空闲
            完全分配
        }
```

+ 段  
```
    段是用于TXF文件的动态增长所创建的，每个段包含
    {
        SegmentSizeHeader
        {
            Type:  对应{流块}类型
            Usage: 对应复合位图中的三种状态
        }

        bmap BlockMap;
        {
            Blocks
        }
    }
```

+ 块  
```
    块适用于TXF文件保存实际数据的位置，大小固定，如果一个块无法保存数据，则可通过跨块的方式实现大数据的保存。
    对于数据库来说，一般块大小需要等于实际表的记录大小，保证分配、使用效率
    {
        BlockHeader：[数据块, 跳转块]
        BlockUsing： 当前正在使用的实际大小
    }
```

+ 流块
```
    流块用于保存序列化的信息，包含索引、符号信息表、主记录表等。
```