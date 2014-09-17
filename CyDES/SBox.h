#pragma once

#include "ISBox.h"

// S-Box的实现
class SBox :public ISBox {
private:
	std::vector<std::vector<int>> box;
public:
	SBox();

	// 初始化成员列表
	SBox(std::initializer_list<std::initializer_list<int>> lst);

	// 通过6位数据pos获取S-Box中的值
	Bit Get(int i, int j);

	// 通过指定的坐标(i,j)获取S-Box中的值
	Bit Get(Bit pos);
};

