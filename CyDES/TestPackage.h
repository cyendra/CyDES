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
		cout << "¿ªÊ¼²âÊÔBitÀà" << endl << "=====================" << endl;
		cout << endl;

		cout << "¹¹Ôì²âÊÔ" << endl << "---------" << endl;
		Bit b1;
		cout << "Bit()£º" << b1.ToString() << endl;
		Bit b2(233);
		cout << "Bit(233)£º" << b2.ToString() << endl;
		Bit b3(123456789, 4);
		cout << "Bit(123456789, 4)£º" << b3.ToString() << endl;
		auto b4(b2);
		cout << "Bit(bit)£º" << b4.ToString() << endl;
		auto b5 = b3;
		cout << "operator=(b3)£º" << b3.ToString() << endl;
		cout << endl;

		cout << "Î»ÒÆ²âÊÔ" << endl << "---------" << endl;
		cout << "LeftShift(0)£º" << b2.ToString() << endl << " --> ";
		b2.LeftShift(0);
		cout << b2.ToString() << endl;
		cout << "LeftShift(1)£º" << b2.ToString() << endl << " --> ";
		b2.LeftShift(1);
		cout << b2.ToString() << endl;
		cout << "LeftShift(3)£º" << b2.ToString() << endl << " --> ";
		b2.LeftShift(3);
		cout << b2.ToString() << endl;

		cout << "LeftShift(0)£º" << b3.ToString() << endl << " --> ";
		b3.LeftShift(0);
		cout << b3.ToString() << endl;
		cout << "LeftShift(1)£º" << b3.ToString() << endl << " --> ";
		b3.LeftShift(1);
		cout << b3.ToString() << endl;
		cout << "LeftShift(3)£º" << b3.ToString() << endl << " --> ";
		b3.LeftShift(3);
		cout << b3.ToString() << endl;
		cout << endl;

		cout << "Ñ­»·Î»ÒÆ²âÊÔ" << endl << "---------" << endl;
		cout << "LeftRotate(16)£º" << b4.ToString() << endl << " --> ";
		b4.LeftRotate(16);
		cout << b4.ToString() << endl;
		cout << "LeftRotate(8)£º" << b4.ToString() << endl << " --> ";
		b4.LeftRotate(8);
		cout << b4.ToString() << endl;
		cout << "LeftRotate(12)£º" << b4.ToString() << endl << " --> ";
		b4.LeftRotate(12);
		cout << b4.ToString() << endl;

		cout << "LeftRotate(16)£º" << b5.ToString() << endl << " --> ";
		b5.LeftRotate(16);
		cout << b5.ToString() << endl;
		cout << "LeftRotate(7)£º" << b5.ToString() << endl << " --> ";
		b5.LeftRotate(7);
		cout << b5.ToString() << endl;
		cout << "LeftRotate(3)£º" << b5.ToString() << endl << " --> ";
		b5.LeftRotate(3);
		cout << b5.ToString() << endl;

		cout << "Î»¸ü¸Ä²âÊÔ" << endl << "---------" << endl;
		b1.Reset();
		cout << "Reset()£º" << b1.ToString()<< endl << endl;
		b1.Set(1);
		cout << "Set(1)£º" << b1.ToString() << endl;
		b1.Set(3);
		cout << "Set(3)£º" << b1.ToString() << endl;
		b1.Set(0);
		cout << "Set(0)£º" << b1.ToString() << endl;
		b1.Set(3);
		cout << "Set(3)£º" << b1.ToString() << endl;
		b1.Set(15);
		cout << "Set(15)£º" << b1.ToString() << endl;
		b1.Set(16);
		cout << "Set(16)£º" << b1.ToString() << endl;
		b1.Set(17);
		cout << "Set(17)£º" << b1.ToString() << endl;
		
		b1.Set();
		cout << "Set()£º" << b1.ToString() << endl;
		b1.Reset(1);
		cout << "Reset(1)£º" << b1.ToString() << endl;
		b1.Reset(3);
		cout << "Reset(3)£º" << b1.ToString() << endl;
		b1.Reset(0);
		cout << "Reset(0)£º" << b1.ToString() << endl;
		b1.Reset(3);
		cout << "Reset(3)£º" << b1.ToString() << endl;
		b1.Reset(15);
		cout << "Reset(15)£º" << b1.ToString() << endl;
		b1.Reset(16);
		cout << "Reset(16)£º" << b1.ToString() << endl;
		b1.Reset(17);
		cout << "Reset(17)£º" << b1.ToString() << endl;

		b1.Flip();
		cout << "Flip()£º" << b1.ToString() << endl;
		b1.Flip(1);
		cout << "Flip(1)£º" << b1.ToString() << endl;
		b1.Flip(3);
		cout << "Flip(3)£º" << b1.ToString() << endl;
		b1.Flip(0);
		cout << "Flip(0)£º" << b1.ToString() << endl;
		b1.Flip(3);
		cout << "Flip(3)£º" << b1.ToString() << endl;
		b1.Flip(15);
		cout << "Flip(15)£º" << b1.ToString() << endl;
		b1.Flip(16);
		cout << "Flip(16)£º" << b1.ToString() << endl;
		b1.Flip(17);
		cout << "Flip(17)£º" << b1.ToString() << endl;
		cout << endl;

		cout << "Î»ÊôÐÔ²âÊÔ" << endl << "---------" << endl;
		cout << "Bit = " << b1.ToString() << endl;
		cout << "	Count()£º" << b1.Count() << endl;
		cout << "	Size()£º" << b1.Size() << endl;
		cout << "Bit = " << b5.ToString() << endl;
		cout << "	Count()£º" << b5.Count() << endl;
		cout << "	Size()£º" << b5.Size() << endl;

		cout << "Bit = " << b1.ToString() << endl;
		cout << "	None()£º" << b1.None() << endl;
		cout << "	Any()£º" << b1.Any() << endl;
		b1.Reset();
		cout << "Bit = " << b1.ToString() << endl;
		cout << "	None()£º" << b1.None() << endl;
		cout << "	Any()£º" << b1.Any() << endl;
		cout << endl;

		cout << "operator[]²âÊÔ" << endl << "---------" << endl;
		cout << "Bit=" << b5.ToString() << endl;
		for (int i = 0; i < 8; i++) {
			cout << "[" << i << "] = " << b5[i] << endl;
		}
		cout << endl;

		cout << "ÆäËü²âÊÔ" << endl << "---------" << endl;
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
		cout << "¿ªÊ¼²âÊÔÖÃ»»±í" << endl << "=====================" << endl;
		for (int i = 0; i < 6; i++) {
			cout << "±í_" << i<<"£º";
			for (int j = 0; j < tb[i]->Size(); j++) {
				cout << tb[i]->Get(j) << " ";
			}
			cout << endl;
		}

		PmtTableStatic Tp{ 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };
		Bit Key(642, 10);
		cout << "Bit£º   " << Key.ToString() << endl;
		Bit pk = pManager->Permutation(Key, &Tp);
		cout << "IPÖÃ»»£º" << pk.ToString() << endl;
		Bit rk = pManager->InversePermutation(pk, &Tp);
		cout << "ÄæÖÃ»»£º" << rk.ToString() << endl;

		Bit dat(12345678987654321LL);
		cout << "Bit£º   " << dat.ToString() << endl;
		Bit res = pManager->Permutation(dat, tb[0]);
		cout << "IPÖÃ»»£º" << res.ToString() << endl;
		Bit bak = pManager->InversePermutation(res, tb[0]);
		cout << "ÄæÖÃ»»£º" << bak.ToString() << endl;

		Bit bit(123456789, 32);
		cout << "Bit£º   " << bit.ToString() << endl;
		Bit ebit = pManager->Permutation(bit, tb[4]);
		cout << "À©Ôö£º  " << ebit.ToString() << endl;
		cout << endl;
	}

	void TestBox() {
		cout << "¿ªÊ¼²âÊÔS-Box" << endl << "=====================" << endl;
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
		cout << "¿ªÊ¼²âÊÔKeyManager" << endl << "=====================" << endl;
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
		cout << "¿ªÊ¼²âÊÔDataEncryptionStandard" << endl << "=====================" << endl;
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