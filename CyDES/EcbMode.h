#pragma once

#include "IMode.h"

/*
	Electronic CodeBook mode ECBģʽ
	����ģʽ
	���ڶ����ݼ���ʱ�ǳ�����
	���ڳ���Ϣʱ������ȫ
*/
class EcbMode : public IMode {
public:
	EcbMode();
	virtual ~EcbMode();

	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// ���ܶ����ƴ�
	virtual std::vector<unsigned char> DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// ��ȡ�������
	static EcbMode* Instance();
};

