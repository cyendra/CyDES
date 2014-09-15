#pragma once

/*
	ÖÃ»»±í½Ó¿Ú
*/
class IPermutationTable {
public:
	virtual int Size() = 0;
	virtual int Get(int pos) = 0;
	virtual ~IPermutationTable() = 0;
};

IPermutationTable::~IPermutationTable() {}