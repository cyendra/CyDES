#pragma once

#include "stdafx.h"
#include "Bit.h"
#include "PermutationManager.h"
#include "IPmtTableManager.h"
#include "DesPmtTableManager.h"
#include "IPermutationTable.h"
#include "PmtTableStatic.h"
#include "SBox.h"
#include "DesSBoxManager.h"
#include "ISBox.h"
#include "KeyManager.h"
#include "DataEncryptionStandard.h"
namespace TestPackage {
	using namespace std;
	void TestBit() {
		cout << "��ʼ����Bit��" << endl << "=====================" << endl;
		cout << endl;

		cout << "�������" << endl << "---------" << endl;
		Bit b1;
		cout << "Bit()��" << b1.ToString() << endl;
		Bit b2(233);
		cout << "Bit(233)��" << b2.ToString() << endl;
		Bit b3(123456789, 4);
		cout << "Bit(123456789, 4)��" << b3.ToString() << endl;
		auto b4(b2);
		cout << "Bit(bit)��" << b4.ToString() << endl;
		auto b5 = b3;
		cout << "operator=(b3)��" << b3.ToString() << endl;
		cout << endl;

		cout << "λ�Ʋ���" << endl << "---------" << endl;
		cout << "LeftShift(0)��" << b2.ToString() << endl << " --> ";
		b2.LeftShift(0);
		cout << b2.ToString() << endl;
		cout << "LeftShift(1)��" << b2.ToString() << endl << " --> ";
		b2.LeftShift(1);
		cout << b2.ToString() << endl;
		cout << "LeftShift(3)��" << b2.ToString() << endl << " --> ";
		b2.LeftShift(3);
		cout << b2.ToString() << endl;

		cout << "LeftShift(0)��" << b3.ToString() << endl << " --> ";
		b3.LeftShift(0);
		cout << b3.ToString() << endl;
		cout << "LeftShift(1)��" << b3.ToString() << endl << " --> ";
		b3.LeftShift(1);
		cout << b3.ToString() << endl;
		cout << "LeftShift(3)��" << b3.ToString() << endl << " --> ";
		b3.LeftShift(3);
		cout << b3.ToString() << endl;
		cout << endl;

		cout << "ѭ��λ�Ʋ���" << endl << "---------" << endl;
		cout << "LeftRotate(16)��" << b4.ToString() << endl << " --> ";
		b4.LeftRotate(16);
		cout << b4.ToString() << endl;
		cout << "LeftRotate(8)��" << b4.ToString() << endl << " --> ";
		b4.LeftRotate(8);
		cout << b4.ToString() << endl;
		cout << "LeftRotate(12)��" << b4.ToString() << endl << " --> ";
		b4.LeftRotate(12);
		cout << b4.ToString() << endl;

		cout << "LeftRotate(16)��" << b5.ToString() << endl << " --> ";
		b5.LeftRotate(16);
		cout << b5.ToString() << endl;
		cout << "LeftRotate(7)��" << b5.ToString() << endl << " --> ";
		b5.LeftRotate(7);
		cout << b5.ToString() << endl;
		cout << "LeftRotate(3)��" << b5.ToString() << endl << " --> ";
		b5.LeftRotate(3);
		cout << b5.ToString() << endl;

		cout << "λ���Ĳ���" << endl << "---------" << endl;
		b1.Reset();
		cout << "Reset()��" << b1.ToString()<< endl << endl;
		b1.Set(1);
		cout << "Set(1)��" << b1.ToString() << endl;
		b1.Set(3);
		cout << "Set(3)��" << b1.ToString() << endl;
		b1.Set(0);
		cout << "Set(0)��" << b1.ToString() << endl;
		b1.Set(3);
		cout << "Set(3)��" << b1.ToString() << endl;
		b1.Set(15);
		cout << "Set(15)��" << b1.ToString() << endl;
		b1.Set(16);
		cout << "Set(16)��" << b1.ToString() << endl;
		b1.Set(17);
		cout << "Set(17)��" << b1.ToString() << endl;
		
		b1.Set();
		cout << "Set()��" << b1.ToString() << endl;
		b1.Reset(1);
		cout << "Reset(1)��" << b1.ToString() << endl;
		b1.Reset(3);
		cout << "Reset(3)��" << b1.ToString() << endl;
		b1.Reset(0);
		cout << "Reset(0)��" << b1.ToString() << endl;
		b1.Reset(3);
		cout << "Reset(3)��" << b1.ToString() << endl;
		b1.Reset(15);
		cout << "Reset(15)��" << b1.ToString() << endl;
		b1.Reset(16);
		cout << "Reset(16)��" << b1.ToString() << endl;
		b1.Reset(17);
		cout << "Reset(17)��" << b1.ToString() << endl;

		b1.Flip();
		cout << "Flip()��" << b1.ToString() << endl;
		b1.Flip(1);
		cout << "Flip(1)��" << b1.ToString() << endl;
		b1.Flip(3);
		cout << "Flip(3)��" << b1.ToString() << endl;
		b1.Flip(0);
		cout << "Flip(0)��" << b1.ToString() << endl;
		b1.Flip(3);
		cout << "Flip(3)��" << b1.ToString() << endl;
		b1.Flip(15);
		cout << "Flip(15)��" << b1.ToString() << endl;
		b1.Flip(16);
		cout << "Flip(16)��" << b1.ToString() << endl;
		b1.Flip(17);
		cout << "Flip(17)��" << b1.ToString() << endl;
		cout << endl;

		cout << "λ���Բ���" << endl << "---------" << endl;
		cout << "Bit = " << b1.ToString() << endl;
		cout << "	Count()��" << b1.Count() << endl;
		cout << "	Size()��" << b1.Size() << endl;
		cout << "Bit = " << b5.ToString() << endl;
		cout << "	Count()��" << b5.Count() << endl;
		cout << "	Size()��" << b5.Size() << endl;

		cout << "Bit = " << b1.ToString() << endl;
		cout << "	None()��" << b1.None() << endl;
		cout << "	Any()��" << b1.Any() << endl;
		b1.Reset();
		cout << "Bit = " << b1.ToString() << endl;
		cout << "	None()��" << b1.None() << endl;
		cout << "	Any()��" << b1.Any() << endl;
		cout << endl;

		cout << "operator[]����" << endl << "---------" << endl;
		cout << "Bit=" << b5.ToString() << endl;
		for (int i = 0; i < 8; i++) {
			cout << "[" << i << "] = " << b5[i] << endl;
		}
		cout << endl;

		cout << "��������" << endl << "---------" << endl;
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

	void TestPermutation() {
		auto pManager = PermutationManager::Instance();
		auto tbManager = DesPmtTableManager::Instance();
		
		IPermutationTable* tb[6];

		tb[0] = tbManager->GetIPTable();
		tb[1] = tbManager->GetIPRevTable();
		tb[2] = tbManager->GetPC1Table();
		tb[3] = tbManager->GetPC2Table();
		tb[4] = tbManager->GetETable();
		tb[5] = tbManager->GetPTable();
		cout << "��ʼ�����û���" << endl << "=====================" << endl;
		for (int i = 0; i < 6; i++) {
			cout << "��_" << i<<"��";
			for (int j = 0; j < tb[i]->Size(); j++) {
				cout << tb[i]->Get(j) << " ";
			}
			cout << endl;
		}

		PmtTableStatic Tp{ 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };
		Bit Key(642, 10);
		cout << "Bit��   " << Key.ToString() << endl;
		Bit pk = pManager->Permutation(Key, &Tp);
		cout << "IP�û���" << pk.ToString() << endl;
		Bit rk = pManager->InversePermutation(pk, &Tp);
		cout << "���û���" << rk.ToString() << endl;

		Bit dat(12345678987654321LL);
		cout << "Bit��   " << dat.ToString() << endl;
		Bit res = pManager->Permutation(dat, tb[0]);
		cout << "IP�û���" << res.ToString() << endl;
		Bit bak = pManager->InversePermutation(res, tb[0]);
		cout << "���û���" << bak.ToString() << endl;

		Bit bit(123456789, 32);
		cout << "Bit��   " << bit.ToString() << endl;
		Bit ebit = pManager->Permutation(bit, tb[4]);
		cout << "������  " << ebit.ToString() << endl;
		cout << endl;
	}

	void TestBox() {
		cout << "��ʼ����S-Box" << endl << "=====================" << endl;
		auto bxManager = DesSBoxManager::Instance();
		ISBox* a[9];
		for (int i = 1; i <= 8; i++) {
			a[i] = bxManager->GetSBox(i);
		}
		for (int i = 1; i <= 8; i++) {
			cout << "-------- box " << i << "---------" << endl;
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 16; k++) {
					cout << a[i]->Get(j, k).ToULL() << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		Bit bit(103, 6);
		Bit res = a[1]->Get(bit);
		cout<<"Bit = " << bit.ToString() << endl;
		cout <<"Box = " << res.ToString() << endl;
		cout << res.ToULL() << endl;
		cout << endl;
	}

	void TestKey() {
		cout << "��ʼ����KeyManager" << endl << "=====================" << endl;
		auto kManager = KeyManager::Instance();
		Bit key(987654321123456798LL);
		cout << "Key = " << key.ToString() << endl;
		kManager->Reset(key);
		for (int i = 0; i < 16; i++) {
			auto k = kManager->GetNextKey();
			cout << "Key-" << i + 1 << " = " << k.ToString() << endl;
		}
		cout << endl;
	}

	void TestDES() {
		cout << "��ʼ����DataEncryptionStandard" << endl << "=====================" << endl;
		auto des = new DataEncryptionStandard();
		Bit key(12345678987654321);
		Bit txt(199311170017);
		cout << "Key = " << key.ToString() << endl;
		cout << "txt = " << txt.ToString() << endl;
		des->SetMasterKey(key);
		Bit msg = des->Encryption(txt);
		cout << "msg = " << msg.ToString() << endl;
		Bit res = des->Decryption(msg);
		cout << "res = " << res.ToString() << endl;
	}

	void TestAll() {
#ifdef TEST_BASE
		TestBit();
		TestPermutation();
		TestBox();
		TestKey();
#endif // TEST_BASE
		TestDES();

		system("pause");
	}
}