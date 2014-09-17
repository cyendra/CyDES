#pragma once

#include "common.h"
#include "IPermutationTable.h"

/*
	DES中置换表的管理器接口
	单例模式
	它管理所有DES中要用到的置换表
*/
class IPmtTableManager :public Uncopyable {
public:
	// 获取初始置换表IP
	virtual IPermutationTable* GetIPTable() = 0;

	// 获取逆初始置换表IP-1
	virtual IPermutationTable* GetIPRevTable() = 0;
	
	// 获取扩增排列表E
	virtual IPermutationTable* GetETable() = 0;
	
	// 获取缩减排列表P
	virtual IPermutationTable* GetPTable() = 0;
	
	// 获取密钥排列PC-1
	virtual IPermutationTable* GetPC1Table() = 0;
	
	// 获取密钥排列PC-2
	virtual IPermutationTable* GetPC2Table() = 0;
};