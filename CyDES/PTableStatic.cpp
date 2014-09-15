#include "stdafx.h"
#include "PTableStatic.h"


PTableStatic::PTableStatic() {}
PTableStatic::PTableStatic(std::initializer_list<int> lst) :table(lst) {}
PTableStatic::~PTableStatic() {}

int PTableStatic::Size() {
	return table.size();
}

int PTableStatic::Get(int pos) {
	
	return table[pos];
}
