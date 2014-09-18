#pragma once

#include "stdafx.h"
#include "Bit.h"
#include "IDes.h"

/*
	加密器接口
*/
class IEncryptor {
public:
	// 分组操作方案
	enum Type {
		ECB, CBC, CFB, OFB
	};

	// 加密字符串 
	virtual std::vector<unsigned char> EncryptString(const std::string& string, Bit MasterKey, Type type) = 0;
	
	// 解密字符串
	virtual std::vector<unsigned char> DecryptString(const std::string& string, Bit MasterKey, Type type) = 0;
	
	// 加密二进制串
	virtual std::vector<unsigned char> EncryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type) = 0;
	
	// 解密二进制串
	virtual std::vector<unsigned char> DecryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type) = 0;
	
	// 加密文件
	virtual std::vector<unsigned char> EncryptFile(char *filename, Bit MasterKey, Type type) = 0;
	
	// 解密文件
	virtual std::vector<unsigned char> DecryptFile(char *filename, Bit MasterKey, Type type) = 0;
	
	// 保存二进制串到文件
	virtual void SaveBinaryAsFile(const std::vector<unsigned char>& bins, char *filename) = 0;
};