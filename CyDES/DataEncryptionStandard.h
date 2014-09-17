#pragma once

#include "IDes.h"
#include "IKeyManager.h"
#include "IFunction.h"
#include "IPermutationManager.h"
#include "IPmtTableManager.h"

/*
	Data Encryption Standard 的实现
	继承IDes接口，可以完成以下操作：
	1-接受一个主密钥
	2-对一组数据加密
	3-对一组数据解密
*/
class DataEncryptionStandard :public IDes {
private:
	Bit masterKey;
	std::vector<Bit> keys;
	IKeyManager* keyManager;
	IFunction* function;
	IPermutationManager* pManager;
	IPmtTableManager* tbManager;
public:
	DataEncryptionStandard();
	virtual ~DataEncryptionStandard();

	// 将64位的key设置为主密钥
	virtual void SetMasterKey(Bit key);

	// 加密明文组dat
	virtual Bit Encryption(Bit dat);

	// 解密密文组dat
	virtual Bit Decryption(Bit dat);
};

