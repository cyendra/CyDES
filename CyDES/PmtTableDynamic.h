#pragma once

#include "IPermutationTable.h"

/*
	��ʼ�û���IP
*/
class DesIpTable :public IPermutationTable {
public:
	// �û�����Ԫ�ظ���
	int Size();

	// ��ȡ���е�pos��Ԫ��
	// pos��0��ʼ����
	int Get(int pos);
};

/*
	���ʼ�û���IP-1
*/
class DesIpRevTable :public IPermutationTable {
public:
	// �û�����Ԫ�ظ���
	int Size();

	// ��ȡ���е�pos��Ԫ��
	// pos��0��ʼ����
	int Get(int pos);
};

/*
	�������б�E
*/
class DesETable :public IPermutationTable {
public:
	// �û�����Ԫ�ظ���
	int Size();

	// ��ȡ���е�pos��Ԫ��
	// pos��0��ʼ����
	int Get(int pos);
};