#include "stdafx.h"
#include "Bit.h"


#pragma region ���캯������������

Bit::Bit() : size(64), bit(0) {}
Bit::Bit(unsigned long long _bit) : size(64), bit(_bit) {}
Bit::Bit(unsigned long long _bit, int n) {
	n = std::min(64, n);
	n = std::max(8, n);
	bit = bit;
	size = n;
}
Bit::~Bit() {}

#pragma endregion

#pragma region ʵ�ֽӿ� IBitwise

void Bit::LeftShift(int d) {
	d %= size;
	unsigned long long mask = (1LL << size) - 1;
	bit <<= d;
	bit &= mask;
}

void Bit::LeftRotate(int d) {
	d %= size;
	unsigned long long mask = (1LL << size) - 1;
	unsigned long long right = bit >> (size - d);
	bit <<= d;
	bit &= mask;
	bit |= right;
}

void Bit::Set(int pos) {
	if (pos < 0 || pos >= size) return;
	bit |= 1LL << (size - pos - 1);
}

void Bit::Set() {
	bit = (1LL << size) - 1;
}

void Bit::Reset(int pos) {
	if (pos < 0 || pos >= size) return;
	bit &= ~(1LL << (size - pos - 1));
}

void Bit::Reset() {
	bit = 0;
}

void Bit::Flip(int pos) {
	if (pos < 0 || pos >= size) return;
	if (operator[](pos)) Reset(pos);
	else Set(pos);
}

void Bit::Flip() {
	unsigned long long mask = (1 << size) - 1;
	bit = (~bit) & mask;
}

bool Bit::None() {
	return bit == 0;
}

bool Bit::Any() {
	return bit != 0;
}

int Bit::Count() {
	int ans = 0;
	for (int i = 0; i < size; i++) {
		if (operator[](i)) ans++;
	}
	return ans;
}

int Bit::Size() {
	return size;
}

bool Bit::operator[](int pos) {
	if (pos < 0 || pos >= size) return 0;
	if (bit & 1LL << (size - pos - 1)) return true;
	return false;
}

unsigned long long Bit::ToULL() {
	return bit;
}

std::string Bit::ToString() {
	std::string res;
	for (int i = 0; i < size; i++) {
		if (operator[](i)) res.push_back('0');
		else res.push_back('1');
	}
	return res;
}

#pragma endregion
