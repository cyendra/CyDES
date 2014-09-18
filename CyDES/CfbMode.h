#pragma once

#include "IMode.h"

class CfbMode : public IMode {
public:
	CfbMode();
	virtual ~CfbMode();

	// 加密二进制串
	virtual std::vector<unsigned char> EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// 解密二进制串
	virtual std::vector<unsigned char> DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// 获取单例句柄
	static CfbMode* Instance();
};

