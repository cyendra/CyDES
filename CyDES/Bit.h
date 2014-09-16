#pragma once
/*
	表示64位以下的数据
	可以做常见的位运算
*/
class Bit {
private:
	unsigned long long bit;
	int size;
public:
	Bit();
	Bit(unsigned long long _bit);
	Bit(unsigned long long _bit, int n);
	Bit(const Bit& b);
	Bit& operator=(Bit& b);
	void LeftShift(int d);
	void LeftRotate(int d);
	void Set(int pos);
	void Set();
	void Reset(int pos);
	void Reset();
	void Flip(int pos);
	void Flip();
	bool None();
	bool Any();
	int Count();
	int Size();
	bool operator[](int pos);
	unsigned long long ToULL();
	std::string ToString();
	static std::pair<Bit, Bit> Split(Bit bit);
	static Bit Merge(Bit L, Bit R);
	static Bit Merge(Bit b[], int L, int R);
	static Bit Xor(Bit x, Bit y);
};

