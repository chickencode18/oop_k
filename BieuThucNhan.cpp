#include "BieuThucNhan.h"

BieuThucNhan::BieuThucNhan(int capDo) : BieuThucSoHoc(capDo)
{
    setPheptoan('*');
}

float BieuThucNhan::tinhKetQua() const
{
    return geta() * getb();
}
