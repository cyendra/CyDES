#pragma once

#include "IPmtTableManager.h"

/*
	DES���û���Ĺ�����
	����ģʽ
	����������DES��Ҫ�õ����û���
*/
class DesPmtTableManager :public IPmtTableManager {
public:
	DesPmtTableManager();
	virtual ~DesPmtTableManager();

	// ��ȡ��ʼ�û���IP
	virtual IPermutationTable* GetIPTable();

	// ��ȡ���ʼ�û���IP-1
	virtual IPermutationTable* GetIPRevTable();

	// ��ȡ�������б�E
	virtual IPermutationTable* GetETable();

	// ��ȡ�������б�P
	virtual IPermutationTable* GetPTable();

	// ��ȡ��Կ����PC-1
	virtual IPermutationTable* GetPC1Table();

	// ��ȡ��Կ����PC-2
	virtual IPermutationTable* GetPC2Table();

	// ��ȡ�������
	static DesPmtTableManager* Instance();
};

