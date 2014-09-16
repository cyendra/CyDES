#pragma once
#include "IBitwise.h"

/*
	ʵ�ֽӿ�IBitwise
	��ʾ64λ���µ�����
	������������λ����
*/
class Bit :public IBitwise {
private:
	unsigned long long bit;
	int size;
public:
	Bit();
	Bit(unsigned long long _bit);
	Bit(unsigned long long _bit, int n);
	virtual ~Bit();
	virtual void LeftShift(int d);
	virtual void LeftRotate(int d);
	virtual void Set(int pos);
	virtual void Set();
	virtual void Reset(int pos);
	virtual void Reset();
	virtual void Flip(int pos);
	virtual void Flip();
	virtual bool None();
	virtual bool Any();
	virtual int Count();
	virtual int Size();
	virtual bool operator[](int pos);
	virtual unsigned long long ToULL();
	virtual std::string ToString();
};

