#include "stdafx.h"
#include "DesPmtTableManager.h"
#include "PmtTableDynamic.h"
#include "PmtTableStatic.h"

DesPmtTableManager::DesPmtTableManager() {}
DesPmtTableManager::~DesPmtTableManager() {}

IPermutationTable* DesPmtTableManager::GetIPTable() {
	static DesIpTable ipTable;
	return &ipTable;
}

IPermutationTable* DesPmtTableManager::GetIPRevTable() {
	static DesIpRevTable ipRevTable;
	return &ipRevTable;
}

IPermutationTable* DesPmtTableManager::GetETable() {
	static DesETable eTable;
	return &eTable;
}

IPermutationTable* DesPmtTableManager::GetPTable() {
	static PmtTableStatic pTable = { 16, 17, 20, 21, 29, 12, 28, 17,
		1, 15, 23, 26, 5, 18, 31, 10,
		2, 8, 24, 14, 32, 27, 3, 9,
		19, 13, 30, 6, 22, 11, 4, 25 };
	return &pTable;
}

IPermutationTable* DesPmtTableManager::GetPC1Table() {
	static PmtTableStatic pc1Table = { 57, 49, 41, 33, 25, 17, 9,
		1, 58, 50, 42, 34, 26, 18,
		10, 2, 59, 51, 43, 35, 27,
		19, 11, 3, 60, 52, 44, 36,
		63, 55, 47, 39, 31, 23, 15,
		7, 62, 54, 46, 38, 30, 22,
		14, 6, 61, 53, 45, 37, 29,
		21, 13, 5, 28, 20, 12, 4 };
	return &pc1Table;
}

IPermutationTable* DesPmtTableManager::GetPC2Table() {
	static PmtTableStatic pc2Table = { 14, 17, 11, 24, 1, 5, 3,
		15, 6, 21, 10, 23, 19, 12,
		26, 8, 16, 7, 27, 20, 13,
		41, 52, 31, 37, 47, 55, 30,
		51, 45, 33, 48, 44, 49, 39,
		34, 33, 46, 42, 50, 36, 29 };
	return &pc2Table;
}

DesPmtTableManager* DesPmtTableManager::Instance() {
	static DesPmtTableManager pmtTableManager;
	return &pmtTableManager;
}