#include "BieuThucSoHoc.h"

BieuThucSoHoc::BieuThucSoHoc()
{
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    pheptoan = '+';
}

BieuThucSoHoc::BieuThucSoHoc(int capDo)
{
    srand(time(nullptr));

    switch (capDo)
    {
    case 1:
        pheptoan = '+';
        break;
    case 2:
        pheptoan = (rand() % 2 == 0) ? '+' : '-';
        break;
    case 3:
        pheptoan = (rand() % 3 == 0) ? '+' : (rand() % 2 == 0) ? '-' : '*';
        break;
    case 4:
        pheptoan = (rand() % 2 == 0) ? '+' : '-';
        break;
    default:
        pheptoan = (rand() % 3 == 0) ? '+' : (rand() % 2 == 0) ? '-' : '*';
    }
    if (capDo <= 3)
    {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
    }
    else
    {
        a = rand() % 91 + 10;
        b = rand() % 91 + 10;
    }
}

bool BieuThucSoHoc::kiemtra(float ketqua)
{
    
    return ketqua == tinhKetQua();
}
float BieuThucSoHoc::tinhKetQua() const
{
    float kq = 0.0;
    switch (pheptoan) {
    case '+':
        kq = a + b;
        break;
    case '-':
        kq = a - b;
        break;
    case '*':
        kq = a * b;
        break;
    /*case '/':
        if (b != 0) {
            kq = (float)(a) / b;
            kq = static_cast<int>(kq * 100 + 0.5) / 100.0;
        }
        break;*/
    default:
        cerr << "Loi: Phep toan khong hop le" << endl;
    }
    return kq;
}

char BieuThucSoHoc::getPheptoan() const
{
    return pheptoan;
}

int BieuThucSoHoc::geta() const
{
    return a;
}

int BieuThucSoHoc::getb() const 
{
    return b;
}

void BieuThucSoHoc::setPheptoan(char pheptoan)
{
    this->pheptoan = pheptoan;
}

void BieuThucSoHoc::seta(int a)
{
    this->a = a;
}

void BieuThucSoHoc::setb(int b)
{
    this->b = b;
}

istream& operator>>(istream& in, BieuThucSoHoc& x)
{
    cout << "Nhap a: ";
    in >> x.a;
    cout << "Nhap phep toan (+, -, *, /): ";
    in >> x.pheptoan;
    cout << "Nhap b: ";
    in >> x.b;
    return in;
}

ostream& operator<<(ostream& out,BieuThucSoHoc x)
{
    out << x.a << " " << x.pheptoan << " " << x.b << " = ?" << endl;
    return out;
}
