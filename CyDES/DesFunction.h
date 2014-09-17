#pragma once
#include "IFunction.h"
#include "IPermutationManager.h"
#include "IPmtTableManager.h"
#include "ISBoxManager.h"

/*
	DES过程中的f函数
	单例模式
*/
class DesFunction :public IFunction {
private:
	IPermutationManager* pManager;
	IPmtTableManager* tbManager;
	ISBoxManager* bxManager;
public:
	DesFunction();
	virtual ~DesFunction();
	
	// f函数
	// bit为32位的R_{i-1}，Key为48位的K_i
	virtual Bit ProcessKey(Bit bit, Bit Key);
	
	// 获取单例句柄
	static DesFunction* Instance();
};

