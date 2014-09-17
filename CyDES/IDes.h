#pragma once
#include "common.h"
#include "Bit.h"
class IDes {
public:
	virtual void SetMasterKey(Bit key) = 0;
	virtual Bit Encryption(Bit dat) = 0;
	virtual Bit Decryption(Bit dat) = 0;
};