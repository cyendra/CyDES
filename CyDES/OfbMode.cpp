#include "stdafx.h"
#include "OfbMode.h"

OfbMode::OfbMode() {}
OfbMode::~OfbMode() {}

std::vector<unsigned char> OfbMode::EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	std::vector<unsigned char> ans;
	des->SetMasterKey(MasterKey);
	int n = bins.size();
	Bit iv;
	for (int i = 0; i < n; i++) {
		iv = des->Decryption(iv);
		Bit b = iv;
		b.RightShift(64 - 8);
		iv.LeftShift(8);
		iv = Bit::Or(iv, b);
		b = Bit::Xor(b, bins[i]);
		ans.push_back((unsigned char)b.ToULL());
	}
	return ans;
}

std::vector<unsigned char> OfbMode::DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	std::vector<unsigned char> ans;
	des->SetMasterKey(MasterKey);
	int n = bins.size();
	Bit iv;
	for (int i = 0; i < n; i++) {
		iv = des->Decryption(iv);
		Bit b = iv;
		b.RightShift(64 - 8);
		iv.LeftShift(8);
		iv = Bit::Or(iv, b);
		b = Bit::Xor(b, bins[i]);
		ans.push_back((unsigned char)b.ToULL());
	}
	return ans;
}

OfbMode* OfbMode::Instance() {
	static OfbMode mode;
	return &mode;
}
