#pragma once
#include "ISBoxManager.h"
class DesSBoxManager :public ISBoxManager {
public:
	DesSBoxManager();
	virtual ~DesSBoxManager();
	virtual SBox* GetSBox(int i);
	static DesSBoxManager* Instance();
};

