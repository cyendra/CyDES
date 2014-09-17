#pragma once

#include "stdafx.h"
#include "Bit.h"
class IKeyManager {
public:
	virtual void Reset(Bit MasterKey) = 0;
	virtual Bit GetNextKey() = 0;
};