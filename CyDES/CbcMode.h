#pragma once

#include "IMode.h"

class CbcMode :public IMode {
public:
	CbcMode();
	virtual ~CbcMode();

	// 加密二进制串
	virtual std::vector<unsigned char> EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// 解密二进制串
	virtual std::vector<unsigned char> DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// 获取单例句柄
	static CbcMode* Instance();
};

