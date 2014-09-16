#include "stdafx.h"
#include "DesSBoxManager.h"


DesSBoxManager::DesSBoxManager() {}
DesSBoxManager::~DesSBoxManager() {}

SBox* DesSBoxManager::GetSBox(int i) {
	
	static SBox s1 = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
	{ 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
	{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
	{ 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 } };
	
	static SBox s2 = { { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
	{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
	{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
	{ 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 } };

	static SBox s3;
	static SBox s4;
	static SBox s5;
	static SBox s6;
	static SBox s7;
	static SBox s8;

	if (i <= 0 || i > 8) return nullptr;
	switch (i) {
	case 1:
		return &s1;
	case 2:
		return &s2;
	case 3:
		return &s3;
	case 4:
		return &s4;
	case 5:
		return &s5;
	case 6:
		return &s6;
	case 7:
		return &s7;
	case 8:
		return &s8;
	default:
		break;
	}
	return nullptr;
}

DesSBoxManager* DesSBoxManager::Instance() {
	static DesSBoxManager sBoxManager;
	return &sBoxManager;
}
