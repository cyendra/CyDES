#include "stdafx.h"
#include "PermutationManager.h"


PermutationManager::PermutationManager() {}
PermutationManager::~PermutationManager(){}

Bit PermutationManager::Permutation(Bit bit, IPermutationTable* table) {
	int n = table->Size();
	Bit res(0, n);
	for (int i = 0; i < n; i++) {
		if (bit[table->Get(i) - 1]) res.Set(i);
	}
	return res;
}

Bit PermutationManager::InversePermutation(Bit bit, IPermutationTable* table) {
	int sz = bit.Size();
	int n = table->Size();
	Bit res(0, sz);
	for (int i = 0; i < n; i++) {
		if (bit[i]) res.Set(table->Get(i) - 1);
	}
	return res;
}

PermutationManager* PermutationManager::Instance() {
	static PermutationManager manager;
	return &manager;
}