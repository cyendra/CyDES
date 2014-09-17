#pragma once

#include "ISBoxManager.h"

/*
	S-Box������
	����ģʽ
	���ܹ�����ָ����ŵ�S-Box
*/
class DesSBoxManager :public ISBoxManager {
public:
	DesSBoxManager();
	virtual ~DesSBoxManager();

	// ����ָ����Ϊi��S-Box��ָ��
	virtual SBox* GetSBox(int i);

	// ��ȡ�������
	static DesSBoxManager* Instance();
};

