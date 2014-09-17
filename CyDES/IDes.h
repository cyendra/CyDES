#pragma once

#include "Bit.h"
/*
	Data Encryption Standard �ӿ�
	�̳д˽ӿڵ����������������²�����
	1-����һ������Կ
	2-��һ�����ݼ���
	3-��һ�����ݽ���
*/
class IDes {
public:
	// ��64λ��key����Ϊ����Կ
	virtual void SetMasterKey(Bit key) = 0;
	
	// ����������dat
	virtual Bit Encryption(Bit dat) = 0;
	
	// ����������dat
	virtual Bit Decryption(Bit dat) = 0;
};