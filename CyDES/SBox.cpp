#include "stdafx.h"
#include "SBox.h"

SBox::SBox() {}
SBox::SBox(std::initializer_list<std::initializer_list<int>> lst) {
	for (auto it = lst.begin(); it != lst.end(); it++) 	box.push_back(*it);
}

Bit SBox::Get(int i, int j){
	if (i < 0 || i >= (int)box.size()) return -1;
	if (j < 0 || j >= (int)box[0].size()) return -1;
	Bit res(box[i][j], 4);
	return res;
}

Bit SBox::Get(Bit pos) {
	int x = 0, y = 0;
	x |= (int)pos[0];
	x <<= 1;
	x |= (int)pos[5];
	for (int i = 1; i <= 4; i++) {
		y <<= 1;
		y |= (int)pos[i];
	}
	return Get(x, y);
}