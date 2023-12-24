#include "pch.h"
#include "Gadelshin_Staff.h"

void Gadelshin_Staff::add_employee(std::shared_ptr<Gadelshin_Employee> p_employee) {

	employees.push_back(p_employee);
}


bool Gadelshin_Staff::to_file(CArchive& ar) {


	ar << (int)employees.size();
	for (auto& employee : employees) {
		ar << employee.get();
	}
	return true;
}


bool Gadelshin_Staff::from_file(CArchive& ar) {

	employees.clear();


	int size = 0;
	ar >> size;

	for (int i = 0; i < size; i++) {
		Gadelshin_Employee* p_employee;
		ar >> p_employee;
		employees.push_back(std::shared_ptr<Gadelshin_Employee>(p_employee));
	}
	return true;
}


std::shared_ptr<Gadelshin_Employee> Gadelshin_Staff::get(int i) {
	return employees[i];
}


void Gadelshin_Staff::delete_employee(int idx) {
	employees.erase(employees.begin() + idx, employees.begin() + idx + 1);
}


int Gadelshin_Staff::get_size() {
	return (int)employees.size();
}
