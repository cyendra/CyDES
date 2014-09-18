CyDES 项目概述
========================================================================
  
本文件概要介绍组成 CyDES 应用程序的每个文件的内容。  
  
CyDES.vcxproj  
    这是使用应用程序向导生成的 VC++ 项目的主项目文件，其中包含生成该文件的 Visual C++ 的版本信息，以及有关使用应用程序向导选择的平台、配置和项目功能的信息。

CyDES.vcxproj.filters   
    这是使用“应用程序向导”生成的 VC++ 项目筛选器文件。它包含有关项目文件与筛选器之间的关联信息。在 IDE 中，通过这种关联，在特定节点下以分组形式显示具有相似扩展名的文件。例如，“.cpp”文件与“源文件”筛选器关联。

CyDES.cpp  
    这是主应用程序源文件。  


------  
其他标准文件:  
  
StdAfx.h, StdAfx.cpp  
    这些文件用于生成名为 CyDES.pch 的预编译头 (PCH) 文件和名为 StdAfx.obj 的预编译类型文件。  
	 
------  
其他注释:  
  
应用程序向导使用“TODO:”注释来指示应添加或自定义的源代码部分。  
  
------  
Bit包:  
  
Bit.h, Bit.cpp   
	Bit类的声明与实现。  
	表示64位以下的数据，可以做常见的位运算。  
	  
------  
Common包:  
  
common.h   
	常用工具集合。  
	Uncopyable类在这里声明。    
	  
------   
Debug包:  
	TestPackage.h  
	含有全部测试代码。  
	  
------  
DES包:  
  
IDes.h  
	Data Encryption Standard 接口  
	  
DataEncryptionStandard.h, DataEncryptionStandard.cpp  
	Data Encryption Standard 的实现。  
	继承IDes接口，可以完成以下操作：  
	1-接受一个主密钥。  
	2-对一组数据加密。  
	3-对一组数据解密。  
	  
------  
Funtion包:  
  
IFunction.h  
	DES中f函数的接口。  
	  
DesFunction.h, DesFunction.cpp  
	DES过程中的f函数。  
	  
------  
Key包:  
  
IKeyManager.h  
	主密钥产生子密钥的接口。  
	  
KeyManager.h, KeyManager.cpp   
	主密钥产生子密钥的类。  
	  
------  
Encryptor包:  
  
IEncryptor.h  
	加密器接口。  
	  
DesEncryptor.h, DesEncryptor.cpp  
	加密器的实现，可选四种模式。
	  
IMode.h  
	区块加密法的操作模式接口。  

EcbMode.h, EcbMode.cpp  
	Electronic CodeBook mode。用于短数据加密时非常理想，用于长消息时不够安全。

CbcMode.h, CbcMode.cpp  
	CBC模式。

CfbMode.h, CfbMode.cpp  
	CFB模式，尚未实现。  
	  
OfbMode.h, OfbMode.cpp   
	OFB模式，尚未实现。  
	  
------  
Permutation包:    
  
IPermutationManager.h  
	置换操作的接口。    
	  
PermutationManager.h, PermutationManager.cpp  
	实现置换操作的类。  
	  
------  
PmtTable包:   
    
IPermutationTable.h  
	置换表接口。   
	 
PmtTableStatic.h, PmtTableStatic.cpp  
	静态实现置换表的类，表中的值在编程时指定。  
	  
PmtTableDynamic.h  
	动态实现置换表，表中的值通过相应的类动态指定。  
	其中含有三个类：DesIpTable, DesIpRevTable, DesETable。  
	  
IPmtTableManager.h  
	DES中置换表的管理器接口。  
	  
DesPmtTableManager.h, DesPmtTableManager.cpp  
	DES中置换表的管理器类。  
	它管理所有DES中要用到的置换表。  
	  
------  
SBox包:  
  
ISBox.h   
	S-Box的接口。  
	  
SBox.h, SBox.cpp  
	实现S-Box的类。  
	  
ISBoxManager.h  
	S-Box管理器的接口。  
	  
DesSBoxManager.h, DesSBoxManager.cpp  
	S-Box管理器类。  
	它能够返回指定编号的S-Box  
	  