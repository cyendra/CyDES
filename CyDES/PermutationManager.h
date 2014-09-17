#pragma once

#include "IPermutationManager.h"

/*
	�û�������ʵ��
	����ģʽ
*/
class PermutationManager :public IPermutationManager {
public:
	PermutationManager();
	virtual ~PermutationManager();

	// ���û���table������bit�����û�
	virtual Bit Permutation(Bit bit, IPermutationTable* table);

	// ���û���table������bit�������û�
	virtual Bit InversePermutation(Bit bit, IPermutationTable* table);

	// �������
	static PermutationManager* Instance();
};

