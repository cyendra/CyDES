#include "stdafx.h"
#include "DesEncryptor.h"
#include "EcbMode.h"
#include "CbcMode.h"
#include "CfbMode.h"
#include "OfbMode.h"
#include "IMode.h"
#include "DataEncryptionStandard.h"
DesEncryptor::DesEncryptor() {
	des = std::shared_ptr<IDes>(new DataEncryptionStandard());
}
DesEncryptor::~DesEncryptor() {}

std::vector<unsigned char> DesEncryptor::EncryptString(const std::string& string, Bit MasterKey, Type type) {
	std::vector<unsigned char> input;
	std::vector<unsigned char> res;
	int n = string.length();
	for (int i = 0; i < n; i++) input.push_back((unsigned char)string[i]);
	res = EncryptBinary(input, MasterKey, type);
	return res;
}

std::string DesEncryptor::DecryptString(const std::vector<unsigned char>& bins, Bit MasterKey, Type type) {
	std::vector<unsigned char> res;
	std::string str;
	res = DecryptBinary(bins, MasterKey, type);
	int n = res.size();
	for (int i = 0; i < n; i++) str.push_back((char)res[i]);
	return str;
}

std::vector<unsigned char> DesEncryptor::EncryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type) {
	std::vector<unsigned char> res;
	IMode* mode;
	switch (type) {
	case IEncryptor::ECB:
		mode = EcbMode::Instance();
		res = mode->EncryptBinary(des.get(), bins, MasterKey);
		break;
	case IEncryptor::CBC:
		mode = CbcMode::Instance();
		res = mode->EncryptBinary(des.get(), bins, MasterKey);
		break;
	case IEncryptor::CFB:
		mode = CfbMode::Instance();
		res = mode->EncryptBinary(des.get(), bins, MasterKey);
		break;
	case IEncryptor::OFB:
		mode = OfbMode::Instance();
		res = mode->EncryptBinary(des.get(), bins, MasterKey);
		break;
	default:
		break;
	}
	return res;
}

std::vector<unsigned char> DesEncryptor::DecryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type) {
	std::vector<unsigned char> res;
	IMode* mode;
	switch (type) {
	case IEncryptor::ECB:
		mode = EcbMode::Instance();
		res = mode->DecryptBinary(des.get(), bins, MasterKey);
		break;
	case IEncryptor::CBC:
		mode = CbcMode::Instance();
		res = mode->DecryptBinary(des.get(), bins, MasterKey);
		break;
	case IEncryptor::CFB:
		mode = CfbMode::Instance();
		res = mode->DecryptBinary(des.get(), bins, MasterKey);
		break;
	case IEncryptor::OFB:
		mode = OfbMode::Instance();
		res = mode->DecryptBinary(des.get(), bins, MasterKey);
		break;
	default:
		break;
	}
	return res;
}

std::vector<unsigned char> DesEncryptor::EncryptFile(char *filename, Bit MasterKey, Type type) {
	std::vector<unsigned char> res;
	std::vector<unsigned char> input;
	std::ifstream fin(filename, std::ios::binary);
	if (!fin.is_open()) return res;
	char byte;
	while (fin.read(&byte, sizeof(byte))) {
		input.push_back((unsigned char)byte);
	}
	res = EncryptBinary(input, MasterKey, type);
	return res;
}

std::vector<unsigned char> DesEncryptor::DecryptFile(char *filename, Bit MasterKey, Type type) {
	std::vector<unsigned char> res;
	std::vector<unsigned char> input;
	std::ifstream fin(filename, std::ios::binary);
	if (!fin.is_open()) return res;
	char byte;
	while (fin.read(&byte, sizeof(byte))) {
		input.push_back((unsigned char)byte);
	}
	res = DecryptBinary(input, MasterKey, type);
	return res;
}

void DesEncryptor::SaveBinaryAsFile(const std::vector<unsigned char>& bins, char *filename) {
	std::ofstream fout(filename, std::ios::binary);
	if (!fout.is_open()) return;
	char byte;
	int n = bins.size();
	for (int i = 0; i < n; i++) {
		byte = bins[i];
		fout.write(&byte, sizeof(byte));
	}
	std::cout << std::endl;
}
