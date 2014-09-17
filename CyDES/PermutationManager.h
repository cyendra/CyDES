#pragma once

#include "IPermutationManager.h"

/*
	置换操作的实现
	单例模式
*/
class PermutationManager :public IPermutationManager {
public:
	PermutationManager();
	virtual ~PermutationManager();

	// 用置换表table对数据bit进行置换
	virtual Bit Permutation(Bit bit, IPermutationTable* table);

	// 用置换表table对数据bit进行逆置换
	virtual Bit InversePermutation(Bit bit, IPermutationTable* table);

	// 单例句柄
	static PermutationManager* Instance();
};

