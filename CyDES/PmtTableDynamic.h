#pragma once

#include "IPermutationTable.h"

/*
	初始置换表IP
*/
class DesIpTable :public IPermutationTable {
public:
	// 置换表中元素个数
	int Size();

	// 获取表中第pos个元素
	// pos从0开始计数
	int Get(int pos);
};

/*
	逆初始置换表IP-1
*/
class DesIpRevTable :public IPermutationTable {
public:
	// 置换表中元素个数
	int Size();

	// 获取表中第pos个元素
	// pos从0开始计数
	int Get(int pos);
};

/*
	扩增排列表E
*/
class DesETable :public IPermutationTable {
public:
	// 置换表中元素个数
	int Size();

	// 获取表中第pos个元素
	// pos从0开始计数
	int Get(int pos);
};