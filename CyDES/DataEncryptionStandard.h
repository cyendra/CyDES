#pragma once
#include "IDes.h"
#include "IKeyManager.h"
#include "IFunction.h"
#include "IPermutationManager.h"
#include "IPmtTableManager.h"

class DataEncryptionStandard :public IDes {
private:
	Bit masterKey;
	Bit subKey[16];
	IKeyManager* keyManager;
	IFunction* function;
	IPermutationManager* pManager;
	IPmtTableManager* tbManager;
public:
	DataEncryptionStandard();
	virtual ~DataEncryptionStandard();
	virtual void SetMasterKey(Bit key);
	virtual Bit Encryption(Bit dat);
	virtual Bit Decryption(Bit dat);
};

