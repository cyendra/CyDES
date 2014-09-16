#include "stdafx.h"
#include "PmtTableDynamic.h"

#pragma region ��ʼ�û���IP

int DesIpTable::Size() {
	return 64;
}

int DesIpTable::Get(int pos) {
	if (pos<0 || pos>Size()) return 0;
	return 58 - (pos / 32) + 2 * ((pos % 32) / 8) - 8 * (pos % 8);
}

#pragma endregion

#pragma region ���ʼ�û���IP-1

int DesIpRevTable::Size() {
	return 64;
}

int DesIpRevTable::Get(int pos) {
	if (pos<0 || pos>Size()) return 0;
	return 8 + 32 * ((pos + 1) % 2) - (pos / 8) + 4 * ((pos - pos % 2) % 8);
}

#pragma endregion

#pragma region �������б�E

int DesETable::Size() {
	return 48;
}

int DesETable::Get(int pos) {
	if (pos<0 || pos>Size()) return 0;
	return (32 + pos - 2 * (pos / 6) - 1) % 32 + 1;
}

#pragma endregion
