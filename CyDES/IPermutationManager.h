#pragma once

#include "stdafx.h"
#include "Bit.h"
#include "IPermutationTable.h"
class IPermutationManager {
protected:
	IPermutationManager() {}
	IPermutationManager(const IPermutationManager&);
	IPermutationManager& operator=(const IPermutationManager&);
public:
	virtual Bit Permutation(Bit bit, IPermutationTable* table) = 0;
	virtual Bit InversePermutation(Bit bit, IPermutationTable* table) = 0;
};

