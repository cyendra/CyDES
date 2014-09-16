#pragma once

#include "Bit.h"
class ISBox {
public:
	virtual Bit Get(Bit pos) = 0;
	virtual Bit Get(int i, int j) = 0;
};
