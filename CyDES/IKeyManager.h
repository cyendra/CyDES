#pragma once

#include "Bit.h"
#include "common.h"

/*
	����Կ��������Կ�Ľӿ�
	����ģʽ
*/
class IKeyManager :public Uncopyable {
public:
	// ͨ������Կ��������Կ
	virtual std::vector<Bit> GetKeys(Bit MasterKey) = 0;
};