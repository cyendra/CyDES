#pragma once
#include "IPermutationTable.h"

/*
	��ʼ�û���IP
*/
class DesIpTable :public IPermutationTable {
public:
	int Size();
	int Get(int pos);
};

/*
	���ʼ�û���IP-1
*/
class DesIpRevTable :public IPermutationTable {
public:
	int Size();
	int Get(int pos);
};

/*
	�������б�E
*/
class DesETable :public IPermutationTable {
public:
	int Size();
	int Get(int pos);
};