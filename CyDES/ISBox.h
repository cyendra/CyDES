#pragma once
#include "Bit.h"
class ISBox {
	virtual Bit Get(Bit pos) = 0;
	virtual unsigned long long Get(int i, int j) = 0;
	virtual ~ISBox() = 0;
};

ISBox::~ISBox() {}