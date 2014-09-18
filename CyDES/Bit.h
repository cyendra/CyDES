#pragma once

/*
	��ʾ64λ���µ�����
	������������λ����
*/
class Bit {
private:
	unsigned long long bit;// ��ʾ���ݣ����64λ
	int size;// ��ʾ���ݵ�λ����������64λ
public:
	// ֵΪ0��64λ����
	Bit();

	// ֵΪ_bit��64λ����
	Bit(unsigned long long _bit);

	// ֵΪ_bit��nλ���ݣ���n>64λʱ�ض�
	Bit(unsigned long long _bit, int n);

	Bit(const Bit& b);
	Bit& operator=(Bit& b);
	Bit& operator=(unsigned char num);

	// ֱ������dλ
	void LeftShift(int d);

	// ѭ������dλ
	void LeftRotate(int d);

	// ����posλ����Ϊ1
	// pos�������Ҵ�0��ʼ����������sizeλʱ��Ч
	void Set(int pos);

	// ������λ������Ϊ1
	void Set();

	// ����posλ����Ϊ0
	// pos�������Ҵ�0��ʼ����������sizeλʱ��Ч
	void Reset(int pos);

	// ������λ������Ϊ0
	void Reset();

	// ����posλȡ��
	// pos�������Ҵ�0��ʼ����������sizeλʱ��Ч
	void Flip(int pos);

	// ������λ��ȡ��
	void Flip();

	// ������λ��Ϊ0ʱ����true
	bool None();

	// ������λΪ1ʱ����true
	bool Any();

	// ͳ������λ��1�ĸ���
	int Count();

	// ���ݵ���Чλ��
	int Size();

	// ����posλ��ֵΪ1ʱ����true
	// pos�������Ҵ�0��ʼ����������sizeλʱ��Ч
	bool operator[](int pos);

	// ��������unsigned long long����ʽ����
	unsigned long long ToULL();

	// �����ж�����λ�Զ����ƴ���ʽ����
	std::string ToString();

	// ��̬������������bit���м�ָ�Ϊ��������
	static std::pair<Bit, Bit> Split(Bit bit);

	// ��̬������������bitƽ��Ϊn�ݣ����뱣֤bit�ɷ�
	static std::vector<Bit> Split(Bit bit, int n);

	// ��̬���������������ݺϲ�Ϊһ������
	static Bit Merge(Bit L, Bit R);

	// ��̬��������Bit�����д�L��R֮������ݺϲ�Ϊһ������
	static Bit Merge(Bit b[], int L, int R);

	// ��̬���������������ݵ����ֵ
	static Bit Xor(Bit x, Bit y);
};

