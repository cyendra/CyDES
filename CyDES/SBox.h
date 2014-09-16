#pragma once

#include "ISBox.h"

class SBox :public ISBox {
private:
	std::vector<std::vector<int>> box;
public:
	SBox();
	SBox(std::initializer_list<std::initializer_list<int>> lst);
	Bit Get(int i, int j);
	Bit Get(Bit pos);
};

