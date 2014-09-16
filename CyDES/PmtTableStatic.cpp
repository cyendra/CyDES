#include "stdafx.h"
#include "PmtTableStatic.h"

PmtTableStatic::PmtTableStatic() {}
PmtTableStatic::PmtTableStatic(std::initializer_list<int> lst) :table(lst) {}
PmtTableStatic::~PmtTableStatic() {}

int PmtTableStatic::Size() {
	return table.size();
}

int PmtTableStatic::Get(int pos) {
	
	return table[pos];
}
