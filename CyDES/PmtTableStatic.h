#pragma once

#include "IPermutationTable.h"
/*
	置换表的静态实现
	即表中的值在编程时指定
*/
class PmtTableStatic :public IPermutationTable {
private:
	std::vector<int> table;
public:
	PmtTableStatic();
	PmtTableStatic(std::initializer_list<int> lst);
	virtual ~PmtTableStatic();

	// 置换表中元素个数
	virtual int Size();

	// 获取表中第pos个元素
	// pos从0开始计数
	virtual int Get(int pos);
};

