#include "BieuThucNhan.h"

BieuThucNhan::BieuThucNhan(int capDo) : BieuThucSoHoc(capDo)
{
    //if (capDo == 3 || capDo > 4)
    //{
       setPheptoan('*');
    //}
   
}

float BieuThucNhan::tinhKetQua() const
{
    return geta() * getb();
}
