#pragma once

#include "Bit.h"

// S-Box�Ľӿ�
class ISBox {
public:
	// ͨ��6λ����pos��ȡS-Box�е�ֵ
	virtual Bit Get(Bit pos) = 0;

	// ͨ��ָ��������(i,j)��ȡS-Box�е�ֵ
	virtual Bit Get(int i, int j) = 0;
};
