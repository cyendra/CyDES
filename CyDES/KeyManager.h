#pragma once
#include "IKeyManager.h"
#include "IPermutationManager.h"
#include "IPmtTableManager.h"

/*
	����Կ��������Կ����
	����ģʽ
*/
class KeyManager :public IKeyManager {
private:
	static std::vector<int> LsTable; // λ�Ʊ�LS
	IPermutationManager* pManager;
	IPmtTableManager* tbManager;
public:
	KeyManager();
	virtual ~KeyManager();

	// ͨ������Կ��������Կ
	virtual std::vector<Bit> GetKeys(Bit MasterKey);

	// ��ȡ�������
	static KeyManager* Instance();
};

