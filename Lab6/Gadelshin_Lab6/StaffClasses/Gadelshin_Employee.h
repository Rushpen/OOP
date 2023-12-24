#pragma once

#include "pch.h"
#include "class_info.h"


class Gadelshin_Employee : public CObject
{
private:
	CString firstname = _T("");
	CString secondname = _T("");
	CString login = _T("");
	unsigned int phone_number = 0;

public:
	DECLARE_SERIAL(Gadelshin_Employee)
	Gadelshin_Employee() {};
	virtual ~Gadelshin_Employee() = default;
	virtual void to_class_info(class_info& ci);
	virtual void from_class_info(class_info& ci);
	virtual void Serialize(CArchive& ar);
};
