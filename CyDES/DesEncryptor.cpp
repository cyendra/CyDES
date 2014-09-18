#include "stdafx.h"
#include "DesEncryptor.h"

DesEncryptor::DesEncryptor() {}
DesEncryptor::~DesEncryptor() {}

std::vector<unsigned char> DesEncryptor::EncryptString(const std::string& string, Bit MasterKey, Type type) {

}

std::vector<unsigned char> DesEncryptor::DecryptString(const std::string& string, Bit MasterKey, Type type) {

}

std::vector<unsigned char> DesEncryptor::EncryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type) {

}

std::vector<unsigned char> DesEncryptor::DecryptBinary(const std::vector<unsigned char>& bins, Bit MasterKey, Type type) {

}

std::vector<unsigned char> DesEncryptor::EncryptFile(char *filename, Bit MasterKey, Type type) {

}

std::vector<unsigned char> DesEncryptor::DecryptFile(char *filename, Bit MasterKey, Type type) {

}

void DesEncryptor::SaveBinaryAsFile(const std::vector<unsigned char>& bins, char *filename) {

}
