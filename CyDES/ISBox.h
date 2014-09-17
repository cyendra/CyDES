#pragma once

#include "Bit.h"

// S-Box的接口
class ISBox {
public:
	// 通过6位数据pos获取S-Box中的值
	virtual Bit Get(Bit pos) = 0;

	// 通过指定的坐标(i,j)获取S-Box中的值
	virtual Bit Get(int i, int j) = 0;
};
