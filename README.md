CyDES
=====

高内聚低耦合可复用的DES加密系统  
  
  
![类视图](ClassDiagram.png)  
  
Bit类是最基本的类，它表示一组不超过64位的数据。  

IPermutationTable接口提供了置换表的表示方法，ISBox接口提供了S-Box的表示方法。  

而IPmtTableManager接口用来管理所有置换表，ISBoxManager接口用于管理S-Box。  

IPermutationManager接口提供了用一个置换表置换一组数据的方法。  

IKeyManager接口与IFunction接口表示了DES加密中的两个重要过程，子密钥生成以及f函数。  

IDes接口封装了DES内部的实现，它在内部实现加密的具体步骤，提供了直接的加密方法供外界调用。  

IEncryptor接口则是最后一层外壳，它是整个程序与外界交互的唯一平台。它提供四种可选操作模式。   
   
IMode操作模式的接口，将数据分组加密。  
  
   
使用示例  
----  
测试代码：  
		`string str("Des Encryptor Text");`  
		`auto encryptor = new DesEncryptor();`  
		`unsigned long long Key = 12345678987654321LL;`  
		`auto dat = encryptor->EncryptString(str, Key, DesEncryptor::ECB);`  
		`cout << "密文：";`  
		`for each (unsigned char var in dat) cout << (int)var << " ";`  
		`cout << endl;`  
		`auto txt = encryptor->DecryptString(dat, Key, DesEncryptor::ECB);`  
		`cout << "明文：";`  
		`for each (unsigned char var in txt) cout << (int)var << " ";`
		`cout << endl;`  
		`cout << txt << endl;`  

测试结果：  
密文：202 250 224 84 181 245 248 81 100 101 37 19 213 47 121 157 225 208 149 137 196 45 68 176  
明文：68 101 115 32 69 110 99 114 121 112 116 111 114 32 84 101 120 116 0 0 0 0 0 0  
Des Encryptor Text    
