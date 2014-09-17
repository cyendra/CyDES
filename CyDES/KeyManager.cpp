#include "stdafx.h"
#include "KeyManager.h"
#include "PermutationManager.h"
#include "DesPmtTableManager.h"
#include "IPermutationTable.h"

KeyManager::KeyManager() {
	pManager = PermutationManager::Instance();
	tbManager = DesPmtTableManager::Instance();
}
KeyManager::~KeyManager(){}

KeyManager* KeyManager::Instance() {
	static KeyManager keyManager;
	return &keyManager;
}

std::vector<Bit> KeyManager::GetKeys(Bit MasterKey) {
	std::vector<Bit> keys;
	Bit Ci, Di;
	auto pc1 = tbManager->GetPC1Table();
	Bit bit = pManager->Permutation(MasterKey, pc1);
	auto pir = Bit::Split(bit);
	Ci = pir.first;
	Di = pir.second;
	for (int i = 0; i < 16; i++) {
		Ci.LeftRotate(LsTable[i]);
		Di.LeftRotate(LsTable[i]);
		Bit Key = Bit::Merge(Ci, Di);
		auto pc2 = tbManager->GetPC2Table();
		Key = pManager->Permutation(Key, pc2);
		keys.push_back(Key);
	}
	return keys;
}

std::vector<int> KeyManager::LsTable = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };