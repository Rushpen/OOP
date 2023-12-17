#include "Gadelshin_Staff.h"

Staff::Staff() {
    vector<Employee*> employees = {};
}

void Staff::input_person(Employee* person) {
    employees.push_back(person);
}

int Staff::size_staff() {
    return (int)employees.size();
}

void Staff::print_all() {
    if (employees.size() == 0) {
        cout << "\nThere is nothing to output!\n";
    }
    else
        cout << "\nAll employees: " << endl;
    for (size_t i = 0; i < employees.size(); ++i) {
        employees[i]->print_info();
    };
}

void Staff::write_from_file(string way_to_file) {
    for (Employee* person : employees) {
        person->from_file(way_to_file);
    };
}

void Staff::clear() {
    for (Employee* person : employees) {
        delete person;
    }
    employees.clear();
}
