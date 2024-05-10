#pragma once
#include "BieuThucSoHoc.h"

class BieuThucNhan : public BieuThucSoHoc
{
public:
	BieuThucNhan();
	BieuThucNhan(int capDo);
	float tinhKetQua() const;
};