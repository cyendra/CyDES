CyDES
=====

高内聚低耦合可复用的DES加密系统  
  
  
![类视图](ClassDiagram.png)  
  
Bit类是最基本的类，它表示一组64位以下的数据。
IPermutationTable接口提供了置换表的表示方法，ISBox接口提供了S-Box的表示方法。  
而IPmtTableManager接口用来管理所有置换表，ISBoxManager接口用于管理S-Box。  
IPermutationManager接口提供了用一个置换表置换一组数据的方法。  
IKeyManager接口与IFunction接口表示了DES加密中的两个重要过程，子密钥生成以及f函数。  
IDes接口封装了DES内部的实现，它在内部封装了加密的具体步骤，提供了直接的加密方法供外界调用。  
IEncryptor接口则是最后一层外壳，它是整个程序与外界交互的唯一平台。 