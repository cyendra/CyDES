#pragma once
#include "IPermutationTable.h"

/*
	初始置换表IP
*/
class DesIpTable :public IPermutationTable {
public:
	int Size();
	int Get(int pos);
};

/*
	逆初始置换表IP-1
*/
class DesIpRevTable :public IPermutationTable {
public:
	int Size();
	int Get(int pos);
};

/*
	扩增排列表E
*/
class DesETable :public IPermutationTable {
public:
	int Size();
	int Get(int pos);
};