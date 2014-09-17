#pragma once

#include "IPmtTableManager.h"

/*
	DES中置换表的管理器
	单例模式
	它管理所有DES中要用到的置换表
*/
class DesPmtTableManager :public IPmtTableManager {
public:
	DesPmtTableManager();
	virtual ~DesPmtTableManager();

	// 获取初始置换表IP
	virtual IPermutationTable* GetIPTable();

	// 获取逆初始置换表IP-1
	virtual IPermutationTable* GetIPRevTable();

	// 获取扩增排列表E
	virtual IPermutationTable* GetETable();

	// 获取缩减排列表P
	virtual IPermutationTable* GetPTable();

	// 获取密钥排列PC-1
	virtual IPermutationTable* GetPC1Table();

	// 获取密钥排列PC-2
	virtual IPermutationTable* GetPC2Table();

	// 获取单例句柄
	static DesPmtTableManager* Instance();
};

