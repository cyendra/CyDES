#pragma once

/*
	置换表接口
*/
class IPermutationTable {
public:
	// 置换表中元素个数
	virtual int Size() = 0;

	// 获取表中第pos个元素
	// pos从0开始计数
	virtual int Get(int pos) = 0;
};
