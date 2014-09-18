#pragma once

#include "IMode.h"

/*
	Electronic CodeBook mode ECB模式
	单例模式
	用于短数据加密时非常理想
	用于长消息时不够安全
*/
class EcbMode : public IMode {
public:
	EcbMode();
	virtual ~EcbMode();

	// 加密二进制串
	virtual std::vector<unsigned char> EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// 解密二进制串
	virtual std::vector<unsigned char> DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey);

	// 获取单例句柄
	static EcbMode* Instance();
};

