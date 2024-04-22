#include "BieuThucCong.h"

BieuThucCong::BieuThucCong(int capDo) : BieuThucSoHoc(capDo)
{
    setPheptoan('+');
}

float BieuThucCong::tinhKetQua() const 
{
    return geta() + getb();
}
