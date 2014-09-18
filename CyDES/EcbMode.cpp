#include "stdafx.h"
#include "EcbMode.h"

EcbMode::EcbMode(){}
EcbMode::~EcbMode(){}

std::vector<unsigned char> EcbMode::EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	std::vector<unsigned char> ans;
	des->SetMasterKey(MasterKey);
	int n = bins.size();
	Bit bits[8];
	int sp = n % 8;
	for (int i = 0; i < n; i += 8) {
		for (int j = 0; j < 8; j++) {
			if (i + j >= n) bits[j] = 0;
			else bits[j] = bins[i + j];
		}
		Bit b = Bit::Merge(bits, 0, 7);
		b = des->Encryption(b);
		auto res = Bit::Split(b, 8);
		for each (Bit var in res) {
			ans.push_back((unsigned char)var.ToULL());
		}
	}
	return ans;
}

std::vector<unsigned char> EcbMode::DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	std::vector<unsigned char> ans;
	des->SetMasterKey(MasterKey);
	int n = bins.size();
	Bit bits[8];
	int sp = n % 8;
	for (int i = 0; i < n; i += 8) {
		for (int j = 0; j < 8; j++) {
			if (i + j >= n) bits[j] = 0;
			else bits[j] = bins[i + j];
		}
		Bit b = Bit::Merge(bits, 0, 7);
		b = des->Decryption(b);
		auto res = Bit::Split(b, 8);
		for each (Bit var in res) {
			ans.push_back((unsigned char)var.ToULL());
		}
	}
	return ans;
}

EcbMode* EcbMode::Instance() {
	static EcbMode ecbMode;
	return &ecbMode;
}
