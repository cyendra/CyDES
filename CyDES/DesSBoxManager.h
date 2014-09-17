#pragma once

#include "ISBoxManager.h"

/*
	S-Box管理器
	单例模式
	它能够返回指定编号的S-Box
*/
class DesSBoxManager :public ISBoxManager {
public:
	DesSBoxManager();
	virtual ~DesSBoxManager();

	// 返回指向编号为i的S-Box的指针
	virtual SBox* GetSBox(int i);

	// 获取单例句柄
	static DesSBoxManager* Instance();
};

