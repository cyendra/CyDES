#pragma once

#include "IEncryptor.h"
#include "IDes.h"
/*
	���������
*/
class DesEncryptor :public IEncryptor {
private:
	std::shared_ptr<IDes> des;
public:
	DesEncryptor();
	virtual ~DesEncryptor();

	// �����ַ��� 
	virtual std::vector<unsigned char> EncryptString(const std::string& string, Bit MasterKey, Type type);

	// �����ַ���
	virtual std::string DecryptString(const std::vector<unsigned char>& bins, Bit MasterKey, Type type);

	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> EncryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type);

	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> DecryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type);

	// �����ļ�
	virtual std::vector<unsigned char> EncryptFile(char *filename, Bit MasterKey, Type type);

	// �����ļ�
	virtual std::vector<unsigned char> DecryptFile(char *filename, Bit MasterKey, Type type);

	// ��������ƴ����ļ�
	virtual void SaveBinaryAsFile(const std::vector<unsigned char>& bins, char *filename);
};
