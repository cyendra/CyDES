#include "stdafx.h"
#include "DataEncryptionStandard.h"
#include "KeyManager.h"
#include "DesFunction.h"
#include "DesPmtTableManager.h"
#include "PermutationManager.h"

DataEncryptionStandard::DataEncryptionStandard() {
	keyManager = KeyManager::Instance();
	function = DesFunction::Instance();
	pManager = PermutationManager::Instance();
	tbManager = DesPmtTableManager::Instance();
}
DataEncryptionStandard::~DataEncryptionStandard() {}

void DataEncryptionStandard::SetMasterKey(Bit key) {
	masterKey = key;
	keyManager->Reset(key);
	for (int i = 0; i < 16; i++) {
		subKey[i] = keyManager->GetNextKey();
	}
}

Bit DataEncryptionStandard::Encryption(Bit dat) {
	auto ip = tbManager->GetIPTable();
	dat = pManager->Permutation(dat, ip);
	auto pir = Bit::Split(dat);
	Bit L = pir.first;
	Bit R = pir.second;
	for (int i = 0; i < 16; i++) {
		L = R;
		R = Bit::Xor(L, function->ProcessKey(R, subKey[i]));
	}
	Bit res = Bit::Merge(R, L);
	auto ip_1 = tbManager->GetIPRevTable();
	res = pManager->Permutation(res, ip_1);
	return res;
}

Bit DataEncryptionStandard::Decryption(Bit dat) {
	auto ip_1 = tbManager->GetIPRevTable();
	dat = pManager->InversePermutation(dat, ip_1);
	auto pir = Bit::Split(dat);
	Bit L = pir.second;
	Bit R = pir.first;
	for (int i = 15; i >= 0; i--) {
		Bit t = L;
		L = Bit::Xor(R, function->ProcessKey(L, subKey[i]));
		R = t;
	}
	Bit res = Bit::Merge(L, R);
	auto ip = tbManager->GetIPTable();
	res = pManager->InversePermutation(res, ip);
	return res;
}
