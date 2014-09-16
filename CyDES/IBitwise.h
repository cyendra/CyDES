#pragma once

/*
	位运算接口
	实际用于处理数据，因此按照size从左向右编号
*/
class IBitwise {
public:
	virtual void LeftShift(int d) = 0;
	virtual void Set(int pos) = 0;
	virtual void Set() = 0;
	virtual void Reset(int pos) = 0;
	virtual void Reset() = 0;
	virtual void Flip(int pos) = 0;
	virtual void Flip() = 0;
	virtual bool None() = 0;
	virtual bool Any() = 0;
	virtual int Count() = 0;
	virtual int Size() = 0;
	virtual bool operator[](int pos) = 0;
	virtual unsigned long long ToULL() = 0;
	virtual std::string ToString() = 0;
};
