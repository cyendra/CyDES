#pragma once

#include "Bit.h"
#include "common.h"

/*
	主密钥产生子密钥的接口
	单例模式
*/
class IKeyManager :public Uncopyable {
public:
	// 通过主密钥产生子密钥
	virtual std::vector<Bit> GetKeys(Bit MasterKey) = 0;
};