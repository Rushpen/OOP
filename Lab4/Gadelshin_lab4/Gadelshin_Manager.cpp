#include "pch.h"
#include "Gadelshin_Manager.h"
#include "Gadelshin_Employee.h"

IMPLEMENT_SERIAL(Gadelshin_Manager, Gadelshin_Employee, VERSIONABLE_SCHEMA | 0)

Gadelshin_Manager::Gadelshin_Manager() {
	teamSize = 0;
	expYears = 0;
}

CString to_cstring(int num) {
	CString str_num;
	str_num.Format(_T("%d"), num);
	return str_num;
}

vector<int> Gadelshin_Manager::get_extents(CDC* pDC, int num) {
	std::vector<int> extents = Gadelshin_Employee::get_extents(pDC, num);
	extents[4] = pDC->GetTextExtent(to_cstring(teamSize)).cx;
	extents[5] = pDC->GetTextExtent(to_cstring(expYears)).cx;
	return extents;
}

void Gadelshin_Manager::draw(CDC* pDC, std::vector<int> x_coordinates, int& top, int y_height) {
	Gadelshin_Employee::draw(pDC, x_coordinates, top, y_height);
	pDC->TextOut(x_coordinates[4], top, to_cstring(teamSize));
	pDC->TextOut(x_coordinates[5], top, to_cstring(expYears));
}

void Gadelshin_Manager::Serialize(CArchive& ar) {
	Gadelshin_Employee::Serialize(ar);

	if (ar.IsStoring()) {
		ar << teamSize;
		ar << expYears;
	}
	else {
		ar >> teamSize;
		ar >> expYears;
	}
}

size_t  Gadelshin_Manager::get_teamSize() { return teamSize; }
size_t Gadelshin_Manager::get_expYears(){ return expYears; }

void  Gadelshin_Manager::set_teamSize(size_t teamSize) {
	this->teamSize = teamSize;
}
void  Gadelshin_Manager::set_expYears(size_t expYears) {
	this->expYears = expYears;
}
