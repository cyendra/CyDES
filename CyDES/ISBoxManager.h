#pragma once

#include "SBox.h"

class ISBoxManager {
protected:
	ISBoxManager() {}
	ISBoxManager(const ISBoxManager&);
	ISBoxManager& operator=(const ISBoxManager&);
public:
	virtual SBox* GetSBox(int i) = 0;
};