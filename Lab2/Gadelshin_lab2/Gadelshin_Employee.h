#pragma once
#include "framework.h"
using namespace std;

class Gadelshin_Employee: public CObject
{
private:
	CString firstname;
	CString secondname;
	long long phone_number;
	CString login;
public:
	DECLARE_SERIAL(Gadelshin_Employee)
	Gadelshin_Employee();
	virtual ~Gadelshin_Employee() = default;

	virtual void init_employee();
	virtual void print_info();

	virtual void Serialize(CArchive& ar);
};


