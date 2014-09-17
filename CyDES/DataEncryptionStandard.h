#pragma once

#include "IDes.h"
#include "IKeyManager.h"
#include "IFunction.h"
#include "IPermutationManager.h"
#include "IPmtTableManager.h"

/*
	Data Encryption Standard ��ʵ��
	�̳�IDes�ӿڣ�����������²�����
	1-����һ������Կ
	2-��һ�����ݼ���
	3-��һ�����ݽ���
*/
class DataEncryptionStandard :public IDes {
private:
	Bit masterKey;
	std::vector<Bit> keys;
	IKeyManager* keyManager;
	IFunction* function;
	IPermutationManager* pManager;
	IPmtTableManager* tbManager;
public:
	DataEncryptionStandard();
	virtual ~DataEncryptionStandard();

	// ��64λ��key����Ϊ����Կ
	virtual void SetMasterKey(Bit key);

	// ����������dat
	virtual Bit Encryption(Bit dat);

	// ����������dat
	virtual Bit Decryption(Bit dat);
};

