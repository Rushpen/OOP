#include "Gadelshin_Staff.h"

Staff::Staff() {
}

void Staff::input_person() {
    shared_ptr<Gadelshin_Employee> p_person = make_shared<Gadelshin_Employee>();
    p_person->init_employee();
    employees.push_back(p_person);
}

void Staff::input_manager() {
    shared_ptr<Gadelshin_Employee> p_person = make_shared<Gadelshin_Manager>();
    p_person->init_employee();
    employees.push_back(p_person);
}

int Staff::size_staff() {
    return (int)employees.size();
}

void Staff::print_all() {
    if (employees.size() == 0) {
        cout << "\nThere is nothing to output!\n";
    }
    else {
        cout << "\nAll employees: " << endl;
        for (auto p_person : employees)
            p_person->print_info();
    }
}

void Staff::write_to_file(string way_to_file) {
    CString name(way_to_file.c_str());
    CFile f;

    if (f.Open(name, CFile::modeCreate | CFile::modeWrite)) {
        CArchive ar(&f, CArchive::store);
        ar << (int)employees.size();
        for (auto& employ : employees) {
            ar << employ.get();
        }
        ar.Close();
        f.Close();
        cout << "\nData was written to the file!" << endl;
    }
    else {
        cout << "\nFailed to create/open the file!" << endl;
    }
}

void Staff::read_from_file(string way_to_file) {
    employees.clear();
    CString name(way_to_file.c_str());
    CFile f;

    if (f.Open(name, CFile::modeRead)) {
        if (f.GetLength() == 0) {
            cout << "\nThe file is empty." << endl;
            f.Close();
            return;
        }
        CArchive ar(&f, CArchive::load);

        int size = 0;
        ar >> size;

        for (int i = 0; i < size; i++) {
            Gadelshin_Employee* p_person;
            ar >> p_person;
            employees.push_back(shared_ptr<Gadelshin_Employee>(p_person));
        }
        f.Close();
        cout << "\nData was read from the file!" << endl;
    }
    else {
        cout << "\nFailed to open the file!" << endl;
    }
}


void Staff::clear() {
    employees.clear();
}
