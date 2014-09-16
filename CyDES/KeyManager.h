#pragma once
#include "IKeyManager.h"
class KeyManager :public IKeyManager {
private:
	static std::vector<int> LsTable;
	int cnt;
	Bit Ci, Di;
public:
	KeyManager();
	virtual ~KeyManager();
	virtual void Reset(Bit MasterKey);
	virtual Bit GetNextKey();
	static KeyManager* Instance();
};

