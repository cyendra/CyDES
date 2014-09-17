#pragma once

#include "ISBox.h"

// S-Box��ʵ��
class SBox :public ISBox {
private:
	std::vector<std::vector<int>> box;
public:
	SBox();

	// ��ʼ����Ա�б�
	SBox(std::initializer_list<std::initializer_list<int>> lst);

	// ͨ��6λ����pos��ȡS-Box�е�ֵ
	Bit Get(int i, int j);

	// ͨ��ָ��������(i,j)��ȡS-Box�е�ֵ
	Bit Get(Bit pos);
};

