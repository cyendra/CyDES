#include "stdafx.h"
#include "CbcMode.h"

CbcMode::CbcMode() {}
CbcMode::~CbcMode() {}

std::vector<unsigned char> CbcMode::EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	std::vector<unsigned char> ans;
	des->SetMasterKey(MasterKey);
	int n = bins.size();
	Bit bits[8];
	Bit lst;
	int sp = n % 8;
	for (int i = 0; i < n; i += 8) {
		for (int j = 0; j < 8; j++) {
			if (i + j >= n) bits[j].Byte(0);
			else bits[j].Byte(bins[i + j]);
		}
		Bit b = Bit::Merge(bits, 0, 7);
		b = Bit::Xor(lst, b);
		b = des->Encryption(b);
		lst = b;
		auto res = Bit::Split(b, 8);
		for each (Bit var in res) {
			ans.push_back((unsigned char)var.ToULL());
		}
	}
	return ans;
}

std::vector<unsigned char> CbcMode::DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	std::vector<unsigned char> ans;
	des->SetMasterKey(MasterKey);
	int n = bins.size();
	Bit bits[8];
	Bit lst;
	Bit tmp;
	int sp = n % 8;
	for (int i = 0; i < n; i += 8) {
		for (int j = 0; j < 8; j++) {
			if (i + j >= n) bits[j].Byte(0);
			else bits[j].Byte(bins[i + j]);
		}
		Bit b = Bit::Merge(bits, 0, 7);
		tmp = b;
		b = des->Decryption(b);
		b = Bit::Xor(lst, b);
		lst = tmp;
		auto res = Bit::Split(b, 8);
		for each (Bit var in res) {
			ans.push_back((unsigned char)var.ToULL());
		}
	}
	return ans;
}

CbcMode* CbcMode::Instance() {
	static CbcMode mode;
	return &mode;
}
