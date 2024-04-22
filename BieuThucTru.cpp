#include "BieuThucTru.h"

BieuThucTru::BieuThucTru(int capDo) : BieuThucSoHoc(capDo)
{
    setPheptoan('-');
}

float BieuThucTru::tinhKetQua() const
{
    return geta() - getb();
}
