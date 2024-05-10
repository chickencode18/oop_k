#include "BieuThucSoHoc.h"
#include "BieuThucCong.h"
#include "BieuThucTru.h"
#include "BieuThucNhan.h"
#include "BieuThucPhucTap.h"
#include <iostream>
#include <vector>
using namespace std;

void kiemtrakq(BieuThucSoHoc& sh,int& capdo,int& diem,int& socaudunglientiep)
{
	float kq;
	cout << "Ket qua cua ban: "; cin >> kq;
	if (sh.kiemtra(kq))
	{
		cout << "Chinh xac!" << endl << endl << endl;
		diem++;
		socaudunglientiep++;
	}
	else
	{
		cout << "Sai" << endl << endl << endl;
		socaudunglientiep = 0;
		if (capdo > 1) capdo--;
		if (diem > 0) diem--;
	}
	if (socaudunglientiep == 1) {
		capdo++;
		socaudunglientiep = 0;
	}
}

void hienthi(int& capdo, int& diem)
{
	cout << "Cap do hien tai: " << capdo << endl;
	cout << "So diem hien tai: " << diem << endl;
}

void chaytrochoi(int& capdo, int& diem, int& socaudunglientiep)
{
	BieuThucSoHoc* sh = nullptr;
	char tieptuc;
	do {
		if (sh != nullptr) {
			delete sh;
			sh = nullptr;
		}

		if (capdo == 1) sh = new BieuThucCong(capdo);
		else if (capdo == 2 || capdo == 4)
		{
			int loaibieuthuc = rand() % 2;
			if (loaibieuthuc == 0) sh = new BieuThucCong(capdo);
			else sh = new BieuThucTru(capdo);
		}
		else if (capdo == 3 || (capdo > 4 && capdo<7))
		{
			int loaibieuthuc = rand() % 3;
			if (loaibieuthuc == 0) sh = new BieuThucCong(capdo);
			else if (loaibieuthuc == 1) sh = new BieuThucTru(capdo);
			else sh = new BieuThucNhan(capdo);
		}
		else if (capdo >= 7)
		{
			sh = new BieuThucPhucTap();
		}

		hienthi(capdo, diem);

		cout << *sh;
		kiemtrakq(*sh, capdo, diem, socaudunglientiep);

		cout << "Ban muon tiep tuc khong? (y/n): ";
		cin >> tieptuc;
		if (tieptuc != 'y' && tieptuc != 'Y') {
			delete sh;
			break;
		}

	} while (true);
}

void deThi(int& diem)
{	
	vector<BieuThucSoHoc*> ds;
	int n1, n2, n3 ,n4;
	cout << "Nhap so luong bieu thuc chi gom phep cong: ";
	cin >> n1;
	cout << "Nhap so luong bieu thuc chi gom phep tru: ";
	cin >> n2;
	cout << "Nhap so luong bieu thuc chi gom phep nhan: ";
	cin >> n3;
	cout << "Nhap so luong bieu thuc phuc tap: ";
	cin >> n4;

	cout << endl;

	cout << "----------" << endl;
	cout << "* DE THI *" << endl;
	cout << "----------" << endl;

	for (int i = 0; i < n1; i++) 
	{
		ds.push_back(new BieuThucCong());
	}

	for (int i = 0; i < n2; i++) 
	{
		ds.push_back(new BieuThucTru());
	}

	for (int i = 0; i < n3; i++) 
	{
		ds.push_back(new BieuThucNhan());
	}
	for (int i = 0; i < n4; i++)
	{
		ds.push_back(new BieuThucPhucTap());
	}
	for (BieuThucSoHoc* bt : ds) 
	{
		cout << *bt;
		float ketqua;
		cout << "ket qua: ";
		cin >> ketqua;
		if (bt->kiemtra(ketqua)) diem += 1;
	}

	for (BieuThucSoHoc* bt : ds) 
	{
		delete bt;
	}
	ds.clear();

	cout << "Tong so diem: " << diem << endl;
}


int menu()
{
	int chon;
	cout << "================= MENU ==================" << endl;
	cout << "* 1. Tro choi                           *" << endl;
	cout << "* 2. De thi                             *" << endl;
	cout << "* 3. Nhap tu ban phim                   *" << endl;
	cout << "* 0. Thoat                              *" << endl;
	cout << "=========================================" << endl;
	cin >> chon;
	return chon;
}


int main() 
{
	srand(time(NULL));
	int capdo = 1;
	int diem = 0;
	int socaudunglientiep = 0;
	BieuThucSoHoc *sh;

	/*int chon;
	do
	{
		chon = menu();
		switch (chon)
		{
		case 1:
			chaytrochoi(capdo, diem, socaudunglientiep);
			break;
		case 2:
			deThi(diem);
			break;
		case 3:
			cin >> sh;
			cout << sh;
			kiemtrakq(sh, capdo, diem, socaudunglientiep);
			break;
		case 0:
			break;
		}
	} while (chon != 0);*/
	sh = new BieuThucPhucTap();
	cout << *sh;

	return 0;
}