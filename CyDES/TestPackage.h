#pragma once

#include "stdafx.h"
#include "Bit.h"
namespace TestPackage {
	using namespace std;
	void TestBit() {
		cout << "开始测试Bit类" << endl << "=====================" << endl;
		cout << endl;

		cout << "构造测试" << endl << "---------" << endl;
		Bit b1;
		cout << "Bit()：" << b1.ToString() << endl;
		Bit b2(233);
		cout << "Bit(233)：" << b2.ToString() << endl;
		Bit b3(123456789, 4);
		cout << "Bit(123456789, 4)：" << b3.ToString() << endl;
		auto b4(b2);
		cout << "Bit(bit)：" << b4.ToString() << endl;
		auto b5 = b3;
		cout << "operator=(b3)：" << b3.ToString() << endl;
		cout << endl;

		cout << "位移测试" << endl << "---------" << endl;
		cout << "LeftShift(0)：" << b2.ToString() << endl << " --> ";
		b2.LeftShift(0);
		cout << b2.ToString() << endl;
		cout << "LeftShift(1)：" << b2.ToString() << endl << " --> ";
		b2.LeftShift(1);
		cout << b2.ToString() << endl;
		cout << "LeftShift(3)：" << b2.ToString() << endl << " --> ";
		b2.LeftShift(3);
		cout << b2.ToString() << endl;

		cout << "LeftShift(0)：" << b3.ToString() << endl << " --> ";
		b3.LeftShift(0);
		cout << b3.ToString() << endl;
		cout << "LeftShift(1)：" << b3.ToString() << endl << " --> ";
		b3.LeftShift(1);
		cout << b3.ToString() << endl;
		cout << "LeftShift(3)：" << b3.ToString() << endl << " --> ";
		b3.LeftShift(3);
		cout << b3.ToString() << endl;
		cout << endl;

		cout << "循环位移测试" << endl << "---------" << endl;
		cout << "LeftRotate(16)：" << b4.ToString() << endl << " --> ";
		b4.LeftRotate(16);
		cout << b4.ToString() << endl;
		cout << "LeftRotate(8)：" << b4.ToString() << endl << " --> ";
		b4.LeftRotate(8);
		cout << b4.ToString() << endl;
		cout << "LeftRotate(12)：" << b4.ToString() << endl << " --> ";
		b4.LeftRotate(12);
		cout << b4.ToString() << endl;

		cout << "LeftRotate(16)：" << b5.ToString() << endl << " --> ";
		b5.LeftRotate(16);
		cout << b5.ToString() << endl;
		cout << "LeftRotate(7)：" << b5.ToString() << endl << " --> ";
		b5.LeftRotate(7);
		cout << b5.ToString() << endl;
		cout << "LeftRotate(3)：" << b5.ToString() << endl << " --> ";
		b5.LeftRotate(3);
		cout << b5.ToString() << endl;

		cout << "位更改测试" << endl << "---------" << endl;
		b1.Reset();
		cout << "Reset()：" << b1.ToString()<< endl << endl;
		b1.Set(1);
		cout << "Set(1)：" << b1.ToString() << endl;
		b1.Set(3);
		cout << "Set(3)：" << b1.ToString() << endl;
		b1.Set(0);
		cout << "Set(0)：" << b1.ToString() << endl;
		b1.Set(3);
		cout << "Set(3)：" << b1.ToString() << endl;
		b1.Set(15);
		cout << "Set(15)：" << b1.ToString() << endl;
		b1.Set(16);
		cout << "Set(16)：" << b1.ToString() << endl;
		b1.Set(17);
		cout << "Set(17)：" << b1.ToString() << endl;
		
		b1.Set();
		cout << "Set()：" << b1.ToString() << endl;
		b1.Reset(1);
		cout << "Reset(1)：" << b1.ToString() << endl;
		b1.Reset(3);
		cout << "Reset(3)：" << b1.ToString() << endl;
		b1.Reset(0);
		cout << "Reset(0)：" << b1.ToString() << endl;
		b1.Reset(3);
		cout << "Reset(3)：" << b1.ToString() << endl;
		b1.Reset(15);
		cout << "Reset(15)：" << b1.ToString() << endl;
		b1.Reset(16);
		cout << "Reset(16)：" << b1.ToString() << endl;
		b1.Reset(17);
		cout << "Reset(17)：" << b1.ToString() << endl;

		b1.Flip();
		cout << "Flip()：" << b1.ToString() << endl;
		b1.Flip(1);
		cout << "Flip(1)：" << b1.ToString() << endl;
		b1.Flip(3);
		cout << "Flip(3)：" << b1.ToString() << endl;
		b1.Flip(0);
		cout << "Flip(0)：" << b1.ToString() << endl;
		b1.Flip(3);
		cout << "Flip(3)：" << b1.ToString() << endl;
		b1.Flip(15);
		cout << "Flip(15)：" << b1.ToString() << endl;
		b1.Flip(16);
		cout << "Flip(16)：" << b1.ToString() << endl;
		b1.Flip(17);
		cout << "Flip(17)：" << b1.ToString() << endl;
		cout << endl;

		cout << "位属性测试" << endl << "---------" << endl;
		cout << "Bit = " << b1.ToString() << endl;
		cout << "	Count()：" << b1.Count() << endl;
		cout << "	Size()：" << b1.Size() << endl;
		cout << "Bit = " << b5.ToString() << endl;
		cout << "	Count()：" << b5.Count() << endl;
		cout << "	Size()：" << b5.Size() << endl;

		cout << "Bit = " << b1.ToString() << endl;
		cout << "	None()：" << b1.None() << endl;
		cout << "	Any()：" << b1.Any() << endl;
		b1.Reset();
		cout << "Bit = " << b1.ToString() << endl;
		cout << "	None()：" << b1.None() << endl;
		cout << "	Any()：" << b1.Any() << endl;
		cout << endl;

		cout << "operator[]测试" << endl << "---------" << endl;
		cout << "Bit=" << b5.ToString() << endl;
		for (int i = 0; i < 8; i++) {
			cout << "[" << i << "] = " << b5[i] << endl;
		}
		cout << endl;

		cout << "其它测试" << endl << "---------" << endl;
		Bit bit(987654324535634523LL);
		cout << "Bit(987654324535634523LL)" << endl;
		cout << "Bit = " << bit.ToString() << endl;
		cout << "ToULL = " << bit.ToULL() << endl;
		auto pir = Bit::Split(bit);
		cout << "Split = " << pir.first.ToString() << ", " << pir.second.ToString() << endl;
		cout << "Xor = " << Bit::Xor(pir.first, pir.second).ToString() << endl;
		cout << "Merge = " << Bit::Merge(pir.first, pir.second).ToString() << endl;
		Bit arr[] = { { 1, 2 }, { 2, 2 }, { 3, 2 }, { 4, 2 } };
		for (int i = 0; i < 4; i++) {
			cout << "Array[" << i << "] = " << arr[i].ToString() << endl;
		}
		cout << "Merge(Array,0,3) = " << Bit::Merge(arr, 0, 3).ToString() << endl;
		cout << endl;
	}

	void TestAll() {
		TestBit();
	}
}