#pragma once

#include "common.h"
#include "IPermutationTable.h"

/*
	DES���û���Ĺ������ӿ�
	����ģʽ
	����������DES��Ҫ�õ����û���
*/
class IPmtTableManager :public Uncopyable {
public:
	// ��ȡ��ʼ�û���IP
	virtual IPermutationTable* GetIPTable() = 0;

	// ��ȡ���ʼ�û���IP-1
	virtual IPermutationTable* GetIPRevTable() = 0;
	
	// ��ȡ�������б�E
	virtual IPermutationTable* GetETable() = 0;
	
	// ��ȡ�������б�P
	virtual IPermutationTable* GetPTable() = 0;
	
	// ��ȡ��Կ����PC-1
	virtual IPermutationTable* GetPC1Table() = 0;
	
	// ��ȡ��Կ����PC-2
	virtual IPermutationTable* GetPC2Table() = 0;
};