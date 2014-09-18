#pragma once
#include "IMode.h"
class OfbMode : public IMode {
public:
	OfbMode();
	virtual ~OfbMode();

	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// ��ȡ�������
	static OfbMode* Instance();
};

