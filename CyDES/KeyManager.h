#pragma once
#include "IKeyManager.h"
#include "IPermutationManager.h"
#include "IPmtTableManager.h"
class KeyManager :public IKeyManager {
private:
	static std::vector<int> LsTable;
	int cnt;
	Bit Ci, Di;
	IPermutationManager* pManager;
	IPmtTableManager* tbManager;
public:
	KeyManager();
	virtual ~KeyManager();
	virtual void Reset(Bit MasterKey);
	virtual Bit GetNextKey();
	static KeyManager* Instance();
};

