#pragma once
#include "BieuThucSoHoc.h"

class BieuThucNhan : public BieuThucSoHoc
{
public:
	BieuThucNhan(int capDo);
	float tinhKetQua() const;
};