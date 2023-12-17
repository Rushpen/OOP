#pragma once
#include "framework.h" 
#include "Gadelshin_Employee.h"
#include "Gadelshin_Manager.h"

class Staff
{
private:

public:
    vector<shared_ptr<Gadelshin_Employee>> employees;

    bool to_file(CArchive& ar);

    bool from_file(CArchive& ar);

    void add_new_employee();

    void add_manager();

    CSize draw_employees(CDC* pDC);

    vector<int> get_max_extents(CDC* pDC, vector<CString> column_names);

    vector<int> get_x_coordinates(CDC* pDC, int x_padding, vector<CString> column_names);

    int GetList(CListBox& list);

    shared_ptr<Gadelshin_Employee> GetEmployee(int index);

    void EmployeeDelete(int index);

    void clear();

    size_t get_size();
};

