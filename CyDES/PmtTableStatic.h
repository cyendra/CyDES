#pragma once
#include "stdafx.h"
#include "IPermutationTable.h"
class PmtTableStatic :public IPermutationTable {
private:
	std::vector<int> table;
public:
	PmtTableStatic();
	PmtTableStatic(std::initializer_list<int> lst);
	virtual ~PmtTableStatic();
	virtual int Size();
	virtual int Get(int pos);
};

