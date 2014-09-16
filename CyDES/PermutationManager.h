#pragma once
#include "IPermutationManager.h"
class PermutationManager :public IPermutationManager {
public:
	PermutationManager();
	virtual ~PermutationManager();
	virtual Bit Permutation(Bit bit, IPermutationTable* table);
	virtual Bit InversePermutation(Bit bit, IPermutationTable* table);
	static PermutationManager* Instance();
};

