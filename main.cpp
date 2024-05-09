#include "BieuThucSoHoc.h"
#include "BieuThucCong.h"
#include "BieuThucTru.h"
#include "BieuThucNhan.h"
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
	if (socaudunglientiep == 5) {
		capdo++;
		socaudunglientiep = 0;
	}
}

/*int menu()
{
	int chon;
	cout << "================= MENU ==================" << endl;
	cout << "* 1. Sinh ngau nhien                    *" << endl;
	cout << "* 2. Nhap tu ban phim                   *" << endl;
	cout << "* 0. Thoat                              *" << endl;
	cout << "=========================================" << endl;
	cin >> chon;
	return chon;
}*/

void hienthi(int& capdo, int& diem)
{
	cout << "Cap do hien tai: " << capdo << endl;
	cout << "So diem hien tai: " << diem << endl;
}
int main() 
{
	srand(time(NULL));
	
/*	int chon;
	do
	{
		chon = menu();
		switch (chon)
		{
		case 1:
			cout << sh;
			kiemtrakq(sh);
			break;
		case 2:
			cin >> sh;
			cout << sh;
			kiemtrakq(sh);
			break;
		case 0:
			break;
		}
	} while (chon != 0);*/

	vector<BieuThucSoHoc*> ds;

	int capdo = 1;
	int diem = 0;
	int socaudunglientiep = 0;
	char tieptuc;
	
	BieuThucSoHoc* sh = nullptr;
	do {
		
		if (sh != nullptr) {
			delete sh;
			sh = nullptr;
		}
		// Random chon loai bieu thuc

		if (capdo == 1) sh = new BieuThucCong(capdo);
		else if (capdo == 2 || capdo == 4)
		{
			int loaibieuthuc = rand() % 2;
			if (loaibieuthuc == 0) sh = new BieuThucCong(capdo);
			else sh = new BieuThucTru(capdo);
		}
		else if (capdo == 3 || capdo > 4)
		{
			int loaibieuthuc = rand() % 3;
			if (loaibieuthuc == 0) sh = new BieuThucCong(capdo);
			else if(loaibieuthuc == 1) sh = new BieuThucTru(capdo);
			else sh = new BieuThucNhan(capdo);
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
	return 0;
}