#pragma once

#include "Bit.h"
/*
	Data Encryption Standard 接口
	继承此接口的派生类可以完成以下操作：
	1-接受一个主密钥
	2-对一组数据加密
	3-对一组数据解密
*/
class IDes {
public:
	// 将64位的key设置为主密钥
	virtual void SetMasterKey(Bit key) = 0;
	
	// 加密明文组dat
	virtual Bit Encryption(Bit dat) = 0;
	
	// 解密密文组dat
	virtual Bit Decryption(Bit dat) = 0;
};