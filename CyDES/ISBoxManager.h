#pragma once

#include "SBox.h"
#include "common.h"

class ISBoxManager :public Uncopyable {
public:
	virtual SBox* GetSBox(int i) = 0;
};