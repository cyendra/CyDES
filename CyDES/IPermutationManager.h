#pragma once

#include "Bit.h"
#include "IPermutationTable.h"
#include "common.h"

/*
	�û������Ľӿ�
	����ģʽ
*/
class IPermutationManager :public Uncopyable {
public:
	// ���û���table������bit�����û�
	virtual Bit Permutation(Bit bit, IPermutationTable* table) = 0;
	// ���û���table������bit�������û�
	virtual Bit InversePermutation(Bit bit, IPermutationTable* table) = 0;
};

