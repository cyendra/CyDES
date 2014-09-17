#pragma once

#include "SBox.h"
#include "common.h"

/*
	S-Box�������Ľӿ�
	����ģʽ
	���ܹ�����ָ����ŵ�S-Box
*/
class ISBoxManager :public Uncopyable {
public:
	// ����ָ����Ϊi��S-Box��ָ��
	virtual SBox* GetSBox(int i) = 0;
};