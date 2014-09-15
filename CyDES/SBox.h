#pragma once

#include "ISBox.h"

class SBox :public ISBox {
private:
	std::vector<std::vector<int>> box;
public:
	SBox();
	SBox(std::initializer_list<std::vector<int>> lst);
	~SBox();
	unsigned long long Get(int i, int j);
	Bit Get(Bit pos);
};
