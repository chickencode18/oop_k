#pragma once
#include "BieuThucSoHoc.h"

class BieuThucTru : public BieuThucSoHoc
{
public:
	BieuThucTru();
	BieuThucTru(int capDo);
	float tinhKetQua() const;
};