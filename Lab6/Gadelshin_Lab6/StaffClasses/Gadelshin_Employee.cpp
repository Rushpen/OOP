#include "pch.h"
#include "Gadelshin_Employee.h"

IMPLEMENT_SERIAL(Gadelshin_Employee, CObject, 0)

void Gadelshin_Employee::to_class_info(class_info& ci) {
	strcpy_s(ci.firstname, CStringA(firstname).GetString());
	strcpy_s(ci.secondname, CStringA(secondname).GetString());
	strcpy_s(ci.login, CStringA(login).GetString());
	ci.phone_number = phone_number;
	ci.is_base_class = 1;
}

void Gadelshin_Employee::from_class_info(class_info& ci) {
	firstname = ci.firstname;
	secondname = ci.secondname;
	login = ci.login;
	phone_number = ci.phone_number;
}

void Gadelshin_Employee::Serialize(CArchive& ar) {

	if (ar.IsStoring()) {
		ar << firstname
			<< secondname
			<< login
			<< phone_number;
	}
	else {
		ar >> firstname
			>> secondname
			>> login
			>> phone_number;

	}
}
