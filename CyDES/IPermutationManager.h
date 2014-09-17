#pragma once

#include "Bit.h"
#include "IPermutationTable.h"
#include "common.h"

/*
	置换操作的接口
	单例模式
*/
class IPermutationManager :public Uncopyable {
public:
	// 用置换表table对数据bit进行置换
	virtual Bit Permutation(Bit bit, IPermutationTable* table) = 0;
	// 用置换表table对数据bit进行逆置换
	virtual Bit InversePermutation(Bit bit, IPermutationTable* table) = 0;
};

