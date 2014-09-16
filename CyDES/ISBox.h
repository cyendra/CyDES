#pragma once

#include "Bit.h"
class ISBox {
public:
	virtual int Get(Bit pos) = 0;
	virtual int Get(int i, int j) = 0;
};
