#pragma once

#include "SBox.h"
#include "common.h"

/*
	S-Box管理器的接口
	单例模式
	它能够返回指定编号的S-Box
*/
class ISBoxManager :public Uncopyable {
public:
	// 返回指向编号为i的S-Box的指针
	virtual SBox* GetSBox(int i) = 0;
};