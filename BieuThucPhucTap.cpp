#include "BieuThucPhucTap.h"

BieuThucPhucTap::BieuThucPhucTap()
{
	l = nullptr;
	r = nullptr;
    int loaiPhepToan1 = rand() % 3;
    int loaiPhepToan2 = rand() % 3;

    if (loaiPhepToan1 == 0) l = new BieuThucCong();
    else if (loaiPhepToan1 == 1) l = new BieuThucTru();
    else l = new BieuThucNhan();

    if (loaiPhepToan2 == 0) r = new BieuThucCong();
    else if (loaiPhepToan2 == 1) r = new BieuThucTru();
    else r = new BieuThucNhan();
}

BieuThucPhucTap::~BieuThucPhucTap()
{
    delete l;
    delete r;
}

float BieuThucPhucTap::tinhKetQua() const
{
    switch (getPheptoan())
    {
    case '+': return l->tinhKetQua() + r->tinhKetQua();
    case '-': return l->tinhKetQua() - r->tinhKetQua();
    case '*': return l->tinhKetQua() * r->tinhKetQua();
    }
}
bool BieuThucPhucTap::kiemtra(float ketqua) const
{
    return ketqua == tinhKetQua();
}

BieuThucSoHoc* BieuThucPhucTap::getL() const
{
    return l;
}

BieuThucSoHoc* BieuThucPhucTap::getR() const
{
    return r;
}
