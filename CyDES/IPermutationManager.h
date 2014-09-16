#pragma once

#include "stdafx.h"
#include "Bit.h"
#include "IPermutationTable.h"
#include "common.h"

class IPermutationManager :public Uncopyable {
public:
	virtual Bit Permutation(Bit bit, IPermutationTable* table) = 0;
	virtual Bit InversePermutation(Bit bit, IPermutationTable* table) = 0;
};

