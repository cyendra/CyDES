#pragma once
/*
	��ʾ64λ���µ�����
	������������λ����
*/
class Bit {
private:
	unsigned long long bit;
	int size;
public:
	Bit();
	Bit(unsigned long long _bit);
	Bit(unsigned long long _bit, int n);
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
};

