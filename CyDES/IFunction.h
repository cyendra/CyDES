#pragma once

#include "common.h"
#include "bit.h"

/*
	DES��f�����Ľӿ�
	����ģʽ
	��ֵͨ��32λ��������48λ������Կ�������
*/
class IFunction :public Uncopyable {
public:
	// f����
	// bitΪ32λ��R_{i-1}��KeyΪ48λ��K_i
	virtual Bit ProcessKey(Bit bit, Bit Key) = 0;
};