#include "BieuThucTru.h"

BieuThucTru::BieuThucTru(int capDo) : BieuThucSoHoc(capDo)
{
    //if (capDo != 1)
    //{
        setPheptoan('-');
    //}
}

float BieuThucTru::tinhKetQua() const
{
    return geta() - getb();
}
