#include "stdafx.h"
#include "KeyManager.h"
#include "PermutationManager.h"
#include "DesPmtTableManager.h"
#include "IPermutationTable.h"

KeyManager::KeyManager() :cnt(0) {
	pManager = PermutationManager::Instance();
	tbManager = DesPmtTableManager::Instance();
}
KeyManager::~KeyManager(){}

std::shared_ptr<IKeyManager> KeyManager::Instance() {
	auto keyManager = std::shared_ptr<IKeyManager>(new KeyManager());
	return keyManager;
}

void KeyManager::Reset(Bit MasterKey) {
	cnt = 0;
	auto pc1 = tbManager->GetPC1Table();
	Bit bit = pManager->Permutation(MasterKey, pc1);
	auto pir = Bit::Split(bit);
	Ci = pir.first;
	Di = pir.second;
}

Bit KeyManager::GetNextKey() {
	cnt %= 16;
	Ci.LeftRotate(LsTable[cnt]);
	Di.LeftRotate(LsTable[cnt]);
	Bit Key = Bit::Merge(Ci, Di);
	auto pc2 = tbManager->GetPC2Table();
	Key = pManager->Permutation(Key, pc2);
	cnt++;
	return Key;
}

std::vector<int> KeyManager::LsTable = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };