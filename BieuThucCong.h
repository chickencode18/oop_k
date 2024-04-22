#pragma once
#include "BieuThucSoHoc.h"

class BieuThucCong : public BieuThucSoHoc
{
public:
	BieuThucCong(int capDo);
	float tinhKetQua() const; 
};