#include "BieuThucTru.h"

BieuThucTru::BieuThucTru() : BieuThucSoHoc()
{
    setPheptoan('-');
}

BieuThucTru::BieuThucTru(int capDo) : BieuThucSoHoc(capDo)
{
    setPheptoan('-');
}

float BieuThucTru::tinhKetQua() const
{
    return geta() - getb();
}
