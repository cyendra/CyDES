#pragma once
#include "IKeyManager.h"
#include "IPermutationManager.h"
#include "IPmtTableManager.h"

/*
	主密钥产生子密钥的类
	单例模式
*/
class KeyManager :public IKeyManager {
private:
	static std::vector<int> LsTable; // 位移表LS
	IPermutationManager* pManager;
	IPmtTableManager* tbManager;
public:
	KeyManager();
	virtual ~KeyManager();

	// 通过主密钥产生子密钥
	virtual std::vector<Bit> GetKeys(Bit MasterKey);

	// 获取单例句柄
	static KeyManager* Instance();
};

