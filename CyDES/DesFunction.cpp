#include "stdafx.h"
#include "DesFunction.h"
#include "PermutationManager.h"
#include "DesPmtTableManager.h"
#include "IPermutationTable.h"
#include "DesSBoxManager.h"
#include "ISBox.h"

DesFunction::DesFunction() {
	pManager = PermutationManager::Instance();
	tbManager = DesPmtTableManager::Instance();
	bxManager = DesSBoxManager::Instance();
}
DesFunction::~DesFunction() {}

Bit DesFunction::ProcessKey(Bit bit, Bit key) {
	IPermutationTable* ex = tbManager->GetETable();
	Bit base = pManager->Permutation(bit, ex);
	base = Bit::Xor(base, key);
	auto pir_1to4_5to8 = Bit::Split(base);
	auto pir_1to2_3to4 = Bit::Split(pir_1to4_5to8.first);
	auto pir_5to6_7to8 = Bit::Split(pir_1to4_5to8.second);
	auto pir_1_2 = Bit::Split(pir_1to2_3to4.first);
	auto pir_3_4 = Bit::Split(pir_1to2_3to4.second);
	auto pir_5_6 = Bit::Split(pir_5to6_7to8.first);
	auto pir_7_8 = Bit::Split(pir_5to6_7to8.second);
	Bit b[9];
	b[1] = pir_1_2.first;
	b[2] = pir_1_2.second;
	b[3] = pir_3_4.first;
	b[4] = pir_3_4.second;
	b[5] = pir_5_6.first;
	b[6] = pir_5_6.second;
	b[7] = pir_7_8.first;
	b[8] = pir_7_8.second;
	Bit a[9];
	for (int i = 1; i <= 8; i++) {
		a[i] = bxManager->GetSBox(i)->Get(b[i]);
	}
	Bit res = Bit::Merge(a, 1, 8);
	IPermutationTable* px = tbManager->GetPTable();
	res = pManager->Permutation(res, px);
	return res;
}

DesFunction* DesFunction::Instance() {
	static DesFunction func;
	return &func;
}

