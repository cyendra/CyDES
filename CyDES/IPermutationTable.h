#pragma once

/*
	�û���ӿ�
*/
class IPermutationTable {
public:
	// �û�����Ԫ�ظ���
	virtual int Size() = 0;

	// ��ȡ���е�pos��Ԫ��
	// pos��0��ʼ����
	virtual int Get(int pos) = 0;
};
