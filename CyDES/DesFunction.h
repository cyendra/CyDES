#pragma once
#include "IFunction.h"
class DesFunction :public IFunction {
private:
	IPermutationManager* pManager;
	IPmtTableManager* tbManager;
	ISBoxManager* bxManager;
public:
	DesFunction();
	virtual ~DesFunction();
	virtual Bit ProcessKey(Bit bit, Bit Key);
	static DesFunction* Instance();
};

