#pragma once

/*
	表示64位以下的数据
	可以做常见的位运算
*/
class Bit {
private:
	unsigned long long bit;// 表示数据，最多64位
	int size;// 表示数据的位数，不超过64位
public:
	// 值为0的64位数据
	Bit();

	// 值为_bit的64位数据
	Bit(unsigned long long _bit);

	// 值为_bit的n位数据，当n>64位时截断
	Bit(unsigned long long _bit, int n);

	Bit(const Bit& b);
	Bit& operator=(Bit& b);
	//Bit& operator=(unsigned char num);
	
	// 由byte构造8位Bit对象
	void Byte(unsigned char num);

	// 直接左移d位
	void LeftShift(int d);

	// 循环左移d位
	void LeftRotate(int d);

	// 将第pos位设置为1
	// pos从左向右从0开始计数，超过size位时无效
	void Set(int pos);

	// 将所有位都设置为1
	void Set();

	// 将第pos位设置为0
	// pos从左向右从0开始计数，超过size位时无效
	void Reset(int pos);

	// 将所有位都设置为0
	void Reset();

	// 将第pos位取反
	// pos从左向右从0开始计数，超过size位时无效
	void Flip(int pos);

	// 将所有位都取反
	void Flip();

	// 当所有位都为0时返回true
	bool None();

	// 当任意位为1时返回true
	bool Any();

	// 统计所有位中1的个数
	int Count();

	// 数据的有效位数
	int Size();

	// 当第pos位的值为1时返回true
	// pos从左向右从0开始计数，超过size位时无效
	bool operator[](int pos);

	// 将数据以unsigned long long的形式返回
	unsigned long long ToULL();

	// 将所有二进制位以二进制串形式返回
	std::string ToString();

	// 静态方法，将数据bit从中间分割为两份数据
	static std::pair<Bit, Bit> Split(Bit bit);

	// 静态方法，把数据bit平分为n份，n为偶数，bit的size能被n整除
	static std::vector<Bit> Split(Bit bit, int n);

	// 静态方法，将两份数据合并为一份数据
	static Bit Merge(Bit L, Bit R);

	// 静态方法，将Bit数组中从L到R之间的数据合并为一份数据
	static Bit Merge(Bit b[], int L, int R);

	// 静态方法，求两份数据的异或值
	static Bit Xor(Bit x, Bit y);
};

