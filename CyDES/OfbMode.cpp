#include "stdafx.h"
#include "OfbMode.h"

OfbMode::OfbMode() {}
OfbMode::~OfbMode() {}

std::vector<unsigned char> OfbMode::EncryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	return bins;
}

std::vector<unsigned char> OfbMode::DecryptBinary(IDes* des, const std::vector<unsigned char>& bins, Bit MasterKey) {
	return bins;
}

OfbMode* OfbMode::Instance() {
	static OfbMode mode;
	return &mode;
}
