#pragma once

#include "stdafx.h"
#include "Bit.h"
class IKeyManager {
protected:
	IKeyManager() {}
	IKeyManager(const IKeyManager&);
	IKeyManager& operator=(const IKeyManager&);
public:
	virtual void Reset(Bit MasterKey) = 0;
	virtual Bit GetNextKey() = 0;
};