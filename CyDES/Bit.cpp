#include "stdafx.h"
#include "Bit.h"


#pragma region 构造函数

Bit::Bit() : size(64), bit(0) {}
Bit::Bit(unsigned long long _bit) : size(64), bit(_bit) {}
Bit::Bit(unsigned long long _bit, int n) {
	n = std::min(64, n);
	n = std::max(1, n);
	unsigned long long mask = (1LL << size) - 1;
	bit = _bit & mask;
	size = n;
}
Bit::Bit(const Bit& b) {
	bit = b.bit;
	size = b.size;
}
Bit& Bit::operator = (Bit& b) {
	bit = b.bit;
	size = b.size;
}

#pragma endregion

#pragma region 实现接口 IBitwise

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

std::pair<Bit, Bit> Bit::Split(Bit bit) {
	int n = bit.size / 2;
	unsigned long long mask = (1LL << n) - 1;
	unsigned long long R = bit.bit & mask;
	unsigned long long L = bit.bit >> n;
	Bit bitL(L, n);
	Bit bitR(R, n);
	return std::make_pair(bitL, bitR);
}

Bit Bit::Merge(Bit L, Bit R) {
	int n = L.size;
	int m = R.size;
	unsigned long long t = L.size << n;
	Bit bit(t, n + m);
	return bit;
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

Bit Bit::Merge(Bit b[], int L, int R) {
	if (L == R) return b[L];
	int mid = (L + R) / 2;
	Bit bL = Merge(b, L, mid);
	Bit bR = Merge(b, mid + 1, R);
	Bit res = Merge(bL, bR);
	return res;
}

Bit Bit::Xor(Bit x, Bit y) {
	int n = std::max(x.size, y.size);
	unsigned long long t = x.bit ^ y.bit;
	Bit ans(t, n);
	return ans;
}

#pragma endregion
