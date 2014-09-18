#include "stdafx.h"
#include "CfbMode.h"

CfbMode::CfbMode() {}
CfbMode::~CfbMode() {}

std::vector<unsigned char> CfbMode::EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	return bins;
}

std::vector<unsigned char> CfbMode::DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	return bins;
}

CfbMode* CfbMode::Instance() {
	static CfbMode mode;
	return &mode;
}
