#pragma once
#include "framework.h" 
#include "Gadelshin_Employee.h"
#include "Gadelshin_Manager.h"

class Staff
{
private:
    vector<std::shared_ptr<Gadelshin_Employee>> employees;
public:
    Staff();
    ~Staff() {
        clear();
    }
    void input_person();
    void input_manager();
    int size_staff();
    void print_all();
    void write_to_file(string way_to_file);
    void read_from_file(string way_to_file);
    void clear();
};