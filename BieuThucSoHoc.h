#pragma once
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class BieuThucSoHoc
{
private:
	int a, b;
	char pheptoan;
protected:
	void setPheptoan(char pheptoan);
	void seta(int a);
	void setb(int b);
	char getPheptoan() const;
	int geta() const;
	int getb() const;
public:
	BieuThucSoHoc();
	BieuThucSoHoc(int capDo);
	//void sinhNgauNhien();
	bool kiemtra(float ketqua);
	float tinhKetQua() const;
	friend istream& operator >> (istream& in, BieuThucSoHoc& x);
	friend ostream& operator << (ostream& out, BieuThucSoHoc x);	
};