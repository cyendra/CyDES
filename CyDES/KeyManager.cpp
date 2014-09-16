#include "stdafx.h"
#include "KeyManager.h"


KeyManager::KeyManager() :cnt(0) {}
KeyManager::~KeyManager(){}

KeyManager* KeyManager::Instance() {
	static KeyManager keyManager;
	return &keyManager;
}

void KeyManager::Reset(Bit MasterKey) {
	cnt = 0;

}

Bit KeyManager::GetNextKey() {

}

std::vector<int> KeyManager::LsTable = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };