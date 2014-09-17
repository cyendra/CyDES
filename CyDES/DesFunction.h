#pragma once
#include "IFunction.h"
#include "IPermutationManager.h"
#include "IPmtTableManager.h"
#include "ISBoxManager.h"

/*
	DES�����е�f����
	����ģʽ
*/
class DesFunction :public IFunction {
private:
	IPermutationManager* pManager;
	IPmtTableManager* tbManager;
	ISBoxManager* bxManager;
public:
	DesFunction();
	virtual ~DesFunction();
	
	// f����
	// bitΪ32λ��R_{i-1}��KeyΪ48λ��K_i
	virtual Bit ProcessKey(Bit bit, Bit Key);
	
	// ��ȡ�������
	static DesFunction* Instance();
};

