#pragma once
#include "common.h"
#include "IPermutationTable.h"
class IPmtTableManager :public Uncopyable {
public:
	virtual IPermutationTable* GetIPTable() = 0;
	virtual IPermutationTable* GetIPRevTable() = 0;
	virtual IPermutationTable* GetETable() = 0;
	virtual IPermutationTable* GetPTable() = 0;
	virtual IPermutationTable* GetPC1Table() = 0;
	virtual IPermutationTable* GetPC2Table() = 0;
};