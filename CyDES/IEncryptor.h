#pragma once

#include "stdafx.h"
#include "Bit.h"
#include "IDes.h"

/*
	�������ӿ�
*/
class IEncryptor {
public:
	// �����������
	enum Type {
		ECB, CBC, CFB, OFB
	};

	// �����ַ��� 
	virtual std::vector<unsigned char> EncryptString(const std::string& string, Bit MasterKey, Type type) = 0;
	
	// �����ַ���
	virtual std::string DecryptString(const std::vector<unsigned char>& bins, Bit MasterKey, Type type) = 0;
	
	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> EncryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type) = 0;
	
	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> DecryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type) = 0;
	
	// �����ļ�
	virtual std::vector<unsigned char> EncryptFile(char *filename, Bit MasterKey, Type type) = 0;
	
	// �����ļ�
	virtual std::vector<unsigned char> DecryptFile(char *filename, Bit MasterKey, Type type) = 0;
	
	// ��������ƴ����ļ�
	virtual void SaveBinaryAsFile(const std::vector<unsigned char>& bins, char *filename) = 0;
};