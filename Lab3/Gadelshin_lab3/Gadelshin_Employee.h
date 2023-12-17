#pragma once
#include "framework.h"
using namespace std;

class Gadelshin_Employee : public CObject
{
private:
	CString firstname;
	CString secondname;
	long long int phone_number;
	CString login;
public:
	DECLARE_SERIAL(Gadelshin_Employee)
	Gadelshin_Employee();
	virtual ~Gadelshin_Employee() = default;

	virtual vector<int> get_extents(CDC* pDC, int num);

	virtual void draw(CDC* pDC, vector<int> x_coordinates, int& top, int y_height);

	virtual void Serialize(CArchive& ar);

	virtual CString get_firstname();
	virtual CString get_secondname();
	virtual long long int get_phone_number();
	virtual CString get_login();
	virtual size_t get_teamSize();
	virtual size_t get_expYears();

	virtual void set_firstname(CString firstname);
	virtual void set_secondname(CString firstname);
	virtual void set_phone_number(long long int phone_number);
	virtual void set_login(CString login);
	virtual void set_teamSize(size_t&);
	virtual void set_expYears(size_t&);
};