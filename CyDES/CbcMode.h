#pragma once

#include "IMode.h"

class CbcMode :public IMode {
public:
	CbcMode();
	virtual ~CbcMode();

	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// ��ȡ�������
	static CbcMode* Instance();
};

