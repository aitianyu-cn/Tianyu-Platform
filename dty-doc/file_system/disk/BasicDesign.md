# 天宇文件系统-系统设计（概述）

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  

# 目录
## [编写目的](First)
## &nbsp;
## [系统设计](Second)
## &nbsp;
### [接口](Second-1)
### [运行环境](Second-2)
### [设计概述](Second-3)
### [静态数据](Second-4)
## &nbsp;
## [错误处理](Third)
## &nbsp;
## [语言规范](Forth)
&nbsp;  
&nbsp;  
&nbsp;  
&nbsp;  
&nbsp;  
&nbsp;
## <span id="First">编写目的</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;本文档用于指出TYFS系统的**整体结构**、**数据设计**，同时对本项目开发过程中所出现的**异常**与**开发语言规范**进行约定。  

## <span id="Second">系统设计</span>
### <span id="Second-1">接口</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;TYFS库用于为其他程序提供操作TYFS系列分区的接口，接口信息如下所示。根据项目开发进程，库接口可能产生变动。  
> **磁盘**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;磁盘部分的操作接口主要用于获取磁盘，并对磁盘进行相应的操作，同时提供磁盘初始化的能力。  
> |方法名|参数|说明|
> |:-:|:-:|:--|
> |tyLoadDisk|-|用于扫描系统挂载的所有磁盘并完成自动扫描加载|
> |tyLoadDiskWithID|uint64|用于使用指定的句柄加载磁盘|
> |tyUnloadDisk|-|用于卸载所有的TYFS磁盘|
> |tyUnloadDiskWithID|uint64|使用指定的句柄卸载磁盘|
> |tyReqDiskInfor|uint64|获取指定磁盘句柄的磁盘信息|
> |tyReqDiskInforAll|-|获取所有磁盘的磁盘信息|
> |tyEditDiskInfor|uint64,uint32,void*|修改指定磁盘的指定信息|
> |tyInitDisk|uint64|初始化指定磁盘为TYPT磁盘|
> |tyClearDisk|uint64|删除指定磁盘的分区表（清空MBR、TYPT信息表）|  
> 
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  

> **卷与分区**  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;TYFS中，所有TYPT分区表中的每一项都称为一个分区，而可以被显示的分区以及联合分区组成的新的分区（可现实）称为卷。卷为用户可以操作的分区单位。以下为针对卷/分区的操作方法（需要注意的是，在小项中所有的操作都是以分区为单位）。  
> |方法名|参数|说明|
> |:-:|:-:|:--|
> |tyReqPartition|uint64|从指定磁盘请求分区|
> |tyFormat|uint64,void*|在指定磁盘完成分区|
> |tyPartitionDel|uint64,byte|在指定磁盘删除分区|
> |tyReqVolume|uint64|从指定磁盘请求卷（可被用户操作的卷，联合分区将会验证分区的其他分区是否完整）|
> |tyReqPartitionInfor|uint64,byte|从指定磁盘请求指定分区的信息（分区只有128个/磁盘，因此使用byte）|
> |tyReqPartitionProp|uint64,byte|从指定磁盘请求指定分区的属性|
> |tyReqPartitionUsers|uint64,byte|从指定磁盘请求指定分区的用户表|
> |tyReqPartitionAccess|uint64,byte|从指定磁盘请求指定分区的访问列表|
> |tyEditPartitionUsers|uint64,byte|向指定磁盘的指定分区写入用户表|
> |tyEditPartitionAccess|uint64,byte|向指定磁盘的指定分区写入访问列表|
> |tyReqAssociated|-|从所有挂载的磁盘中扫描可用的联合分区（如果联合分区不完整缺少子分区，则不返回）|
> |tyReqAssociatedInfor|byte\[16\]|获取指定的联合分区|
> |tyAssociatedDrop|byte\[16\],uint64,byte|从指定的联合分区中移除指定磁盘的指定分区（此操作会阻塞磁盘IO操作）|
> |tyAssociatedAdd|byte\[16\],uint64,byte|向指定的联合分区中加入指定的磁盘分区（此操作不会阻塞磁盘IO操作）|
> |tyAssociatedDel|byte\[16\]|删除指定的联合分区（此操作会造成磁盘IO阻塞，并且不保证分区信息完整）|
> 
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  

> **文件**  
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;文件部分接口用于提供文件的基本操作，并针对文件的属性进行修改。以下为文件操作的基本方法（所有文件的读取都以卷为单位）。  
> |方法名|参数|说明|
> |:-:|:-:|:--|
> |tyReqFiles|byte\[16\]|请求指定卷的MFR表（该请求只返回所有项目的基本索引和父索引）|
> |tyReqFileInfor|byte\[16\],uint64\[\],byte|从指定的卷请求指定的文件信息，可以批量查询，数组最大为64项|
> |tyFileCreate|byte\[16\],uint64,void*|向指定的卷中添加子文件，并绑定到指定的父目录|
> |tyDirectoryCreate|byte\[16\],uint64,void*|向指定的卷中添加子文件夹，并绑定到指定的父目录|
> |tyFileCopy|byte\[16\],uint64,byte\[16\],uint64|将指定卷的文件拷贝至指定卷的指定目录下|
> |tyDirectoryCopy|byte\[16\],uint64,byte\[16\],uint64|将指定卷的文件夹拷贝至指定卷的指定目录下（将会拷贝目录下的所有文件）|
> |tyFileMove|byte\[16\],uint64,byte\[16\],uint64|将指定卷的文件移动至指定卷的指定目录下（同卷只修改MFR记录项父目录）|
> |tyDirectoryMove|byte\[16\],uint64,byte\[16\],uint64|将指定卷的文件夹移动至指定卷的指定目录下（将会移动目录下的所有文件，同卷只修改MFR记录项父目录）|
> |tyFileDelete|byte\[16\],uint64|从指定卷下删除指定文件|
> |tyDirectoryDelete|byte\[16\],uint64|从指定卷下删除指定文件夹（只会删除文件夹，文件夹内的数据不受影响，由上层程序完成递归的删除）|
> |tyfput|byte\[16\],uint64,uint64,byte|向指定卷下的指定文件位置写入一个字节|
> |tyfget|byte\[16\],uint64,uint64,byte|从指定卷下的指定文件位置读取一个字节|
> |tyfwrite|byte\[16\],uint64,uint64,byte[],uint32|向指定卷下的指定文件位置写入二进制流|
> |tyfread|byte\[16\],uint64,uint64,uint32|从指定卷下的指定文件位置读取指定长度的二进制流|
> |tyfcut|byte\[16\],uint64,uint64|将指定卷下的指定文件调整为新的大小|
> 
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  

### <span id="Second-2">运行环境</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;TYFS库开发完成后，需要能为所有的平台提供读写TYFS的能力，因此TYFS库需要能够在现有已知的主流操作系统运行的能力。现有主流操作系统主要包括：Windows（微软视窗操作系统）、Linux（及所有使用Linux内核的系统）。
### <span id="Second-3">设计概述</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;为了让TYFS能够有在现有的主流操作系统都能运行的能力，因此TYFS库的开发全部使用**标准的C语言**进行，并通过Java、.Net Standard、Python等语言接口为用户提供操作空间。  
<b>注：***编写规范见<a harf="Forth">语言规范</a>。***</b>  
&nbsp;  
#### **核心模块**
#### **工具模块**
#### **扩展模块**

### <span id="Second-4">静态数据</span>

## <span id="Third">错误处理</span>


## <span id="Forth">语言规范</span>