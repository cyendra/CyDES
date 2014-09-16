#pragma once

#include "common.h"
#include "bit.h"

class IFunction :public Uncopyable {
public:
	virtual Bit ProcessKey(Bit bit, Bit Key) = 0;
};