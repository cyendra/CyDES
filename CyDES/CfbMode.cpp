#include "stdafx.h"
#include "CfbMode.h"

CfbMode::CfbMode() {}
CfbMode::~CfbMode() {}

std::vector<unsigned char> CfbMode::EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	std::vector<unsigned char> ans;
	des->SetMasterKey(MasterKey);
	int n = bins.size();
	Bit iv;
	for (int i = 0; i < n; i++) {
		iv = des->Decryption(iv);
		Bit b = iv;
		b.RightShift(64 - 8);
		b = Bit::Xor(b, bins[i]);
		ans.push_back((unsigned char)b.ToULL());
		iv.LeftShift(8);
		iv = Bit::Or(iv, b);
	}
	return ans;
}

std::vector<unsigned char> CfbMode::DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	std::vector<unsigned char> ans;
	des->SetMasterKey(MasterKey);
	int n = bins.size();
	Bit iv;
	for (int i = 0; i < n; i++) {
		iv = des->Decryption(iv);
		Bit b = iv;
		b.RightShift(64 - 8);
		b = Bit::Xor(b, bins[i]);
		ans.push_back((unsigned char)b.ToULL());
		iv.LeftShift(8);
		iv = Bit::Or(iv, bins[i]);
	}
	return ans;
}

CfbMode* CfbMode::Instance() {
	static CfbMode mode;
	return &mode;
}
