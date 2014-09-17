#pragma once

#include "IPermutationTable.h"
/*
	�û���ľ�̬ʵ��
	�����е�ֵ�ڱ��ʱָ��
*/
class PmtTableStatic :public IPermutationTable {
private:
	std::vector<int> table;
public:
	PmtTableStatic();
	PmtTableStatic(std::initializer_list<int> lst);
	virtual ~PmtTableStatic();

	// �û�����Ԫ�ظ���
	virtual int Size();

	// ��ȡ���е�pos��Ԫ��
	// pos��0��ʼ����
	virtual int Get(int pos);
};

