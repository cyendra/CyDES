#pragma once

#include "common.h"
#include "bit.h"

/*
	DES中f函数的接口
	单例模式
	其值通过32位的数据与48位的子密钥计算而来
*/
class IFunction :public Uncopyable {
public:
	// f函数
	// bit为32位的R_{i-1}，Key为48位的K_i
	virtual Bit ProcessKey(Bit bit, Bit Key) = 0;
};