#pragma once

#include "Gadelshin_Employee.h"
#include "Gadelshin_Manager.h"


class Gadelshin_Staff
{

private:
	std::vector<std::shared_ptr<Gadelshin_Employee>> employees;
public:
	bool to_file(CArchive& ar);
	bool from_file(CArchive& ar);
	void delete_employee(int idx);
	int get_size();
	void add_employee(std::shared_ptr<Gadelshin_Employee> p_member);
	std::shared_ptr<Gadelshin_Employee> get(int i);
};