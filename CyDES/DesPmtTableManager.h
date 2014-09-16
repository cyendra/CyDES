#pragma once
#include "IPmtTableManager.h"
class DesPmtTableManager :public IPmtTableManager {
public:
	DesPmtTableManager();
	virtual ~DesPmtTableManager();
	virtual IPermutationTable* GetIPTable();
	virtual IPermutationTable* GetIPRevTable();
	virtual IPermutationTable* GetETable();
	virtual IPermutationTable* GetPTable();
	virtual IPermutationTable* GetPC1Table();
	virtual IPermutationTable* GetPC2Table();
	static DesPmtTableManager* Instance();
};

