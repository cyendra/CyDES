#include "stdafx.h"
#include "Bit.h"

#pragma region 构造函数

Bit::Bit() : size(64), bit(0) {}
Bit::Bit(unsigned long long _bit) : size(64), bit(_bit) {}
Bit::Bit(unsigned long long _bit, int n) {
	n = std::min(64, n);
	n = std::max(1, n);
	unsigned long long mask = (1LL << n) - 1;
	bit = _bit & mask;
	size = n;
}
Bit::Bit(const Bit& b) {
	bit = b.bit;
	size = b.size;
}
Bit& Bit::operator=(Bit& b) {
	bit = b.bit;
	size = b.size;
	return *this;
}

/*
Bit& Bit::operator=(unsigned char num) {
	bit = num;
	size = 8;
	return *this;
}
*/
void Bit::Byte(unsigned char num) {
	bit = num;
	size = 8;
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
	volatile unsigned long long mask = (1LL << n) - 1;
	volatile unsigned long long R = bit.bit & mask;
	volatile unsigned long long L = bit.bit >> n;
	Bit bitL(L, n);
	Bit bitR(R, n);
	auto res = std::make_pair(bitL, bitR);
	return res;
}

std::vector<Bit> Bit::Split(Bit bit, int n) {
	std::vector<Bit> res;
	if (n == 1) {
		res.push_back(bit);
		return res;
	}
	if (bit.size % n != 0 || n % 2 != 0) return res;
	auto pir = Split(bit);
	auto lv = Split(pir.first, n / 2);
	auto rv = Split(pir.second, n / 2);
	for each (Bit var in lv) res.push_back(var);
	for each (Bit var in rv) res.push_back(var);
	return res;
}

Bit Bit::Merge(Bit L, Bit R) {
	volatile int n = L.size;
	volatile int m = R.size;
	volatile unsigned long long lb = L.bit;
	volatile unsigned long long rb = R.bit;
	volatile unsigned long long t = lb << m | rb;
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
		if (operator[](i)) res.push_back('1');
		else res.push_back('0');
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
