#pragma once
#include "IPermutationTable.h"
#include <initializer_list>
class PTableStatic :public IPermutationTable {
private:
	std::vector<int> table;
public:
	PTableStatic();
	PTableStatic(std::initializer_list<int> lst);
	virtual ~PTableStatic();
	virtual int Size();
	virtual int Get(int pos);
};

