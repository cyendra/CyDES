#pragma once

#include "stdafx.h"
#include "common.h"
#include "Bit.h"
#include "IDes.h"

/*
	������ܷ��Ĳ���ģʽ�ӿ�
*/
class IMode :public Uncopyable {
public:
	virtual std::vector<unsigned char> EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) = 0;
	virtual std::vector<unsigned char> DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) = 0;
};