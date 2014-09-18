#pragma once

#include "IEncryptor.h"
#include "IDes.h"
/*
	加密器外壳
*/
class DesEncryptor :public IEncryptor {
private:
	std::shared_ptr<IDes> des;
public:
	DesEncryptor();
	virtual ~DesEncryptor();

	// 加密字符串 
	virtual std::vector<unsigned char> EncryptString(const std::string& string, Bit MasterKey, Type type);

	// 解密字符串
	virtual std::string DecryptString(const std::vector<unsigned char>& bins, Bit MasterKey, Type type);

	// 加密二进制串
	virtual std::vector<unsigned char> EncryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type);

	// 解密二进制串
	virtual std::vector<unsigned char> DecryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type);

	// 加密文件
	virtual std::vector<unsigned char> EncryptFile(char *filename, Bit MasterKey, Type type);

	// 解密文件
	virtual std::vector<unsigned char> DecryptFile(char *filename, Bit MasterKey, Type type);

	// 保存二进制串到文件
	virtual void SaveBinaryAsFile(const std::vector<unsigned char>& bins, char *filename);
};

