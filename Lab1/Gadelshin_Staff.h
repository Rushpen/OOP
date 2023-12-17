#pragma once
#include "Gadelshin_Employee.h"
#include <vector>
#include <algorithm>

class Staff
{
private:
	vector<Employee*> employees;
public:
	Staff();
    ~Staff() {
        clear();
    };
    void input_person(Employee* person);
    int size_staff();
    void print_all();
    void write_from_file(string way_to_file);
    void clear();

};

