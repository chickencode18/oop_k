#include "BieuThucSoHoc.h"
#include "BieuThucCong.h"
#include "BieuThucTru.h"
#include "BieuThucNhan.h"
#pragma once
class BieuThucPhucTap : public BieuThucSoHoc
{
protected:
	BieuThucSoHoc* l;
	BieuThucSoHoc* r;
public:
	BieuThucPhucTap();
	~BieuThucPhucTap();
	float tinhKetQua() const override;
	bool kiemtra(float ketqua) const override;

	BieuThucSoHoc* getL() const;
	BieuThucSoHoc* getR() const;
};

