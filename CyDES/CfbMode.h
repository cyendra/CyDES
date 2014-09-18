#pragma once

#include "IMode.h"

class CfbMode : public IMode {
public:
	CfbMode();
	virtual ~CfbMode();

	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// ��ȡ�������
	static CfbMode* Instance();
};

