#include <iostream>
#include <fstream>
#include "Gadelshin_Employee.h"
#include "Utils.h"
#include "Gadelshin_Staff.h"

using namespace std;

int main()
{
    int choice, id = 0;
    bool flag_stop = 0;
    Staff staff;
    while (!flag_stop) {
        cout << "\nChoose key: \n1.Input new employee"<<
            "\n2.Print employees.\n3.Input employees from file" <<
            "\n4.Print employees to file.\n5.Clear.\n0.Exit" << endl;
        choice = get_num_value(0,5);
        switch (choice) {
        case 1: {
            Employee* ptr = new Employee ();
            ptr->id = ++id;
            cin >> *ptr;
            staff.input_person(ptr);
            break;
        }
        case 2: {
            staff.print_all();
            break;
        }
        case 3: {
            string way_to_file;
            cout << "Input way to file:\n";
            cin >> way_to_file;
            ifstream file(way_to_file);
            if (!file.is_open()) {
                cerr << "Can`t open file.\n";
                break;
            }

            Employee* ptr = new Employee();
            while (file >> *ptr) {
                id = check_uniq_id(ptr->id, staff.size_staff());
                ptr->id = ++id;
                staff.input_person(ptr);
                ptr = new Employee();
            }
            file.close();
            cout << "Data was successfully written to the file\n";
            break;
        }
        case 4: {
            string way_to_file;
            cout << "Input way from file:\n";
            cin >> way_to_file;
            ofstream file(way_to_file);
            if (!file.is_open()) {
                cerr << "Can`t open file.\n";
                break;
            }
            staff.write_from_file(way_to_file);
            file.close();
            cout << "Data was successfully read from the file\n";
            break;
        }
        case 5: {
            id = 0;
            staff.clear();
            cout << "Employee data has been deleted\n";
            break;
        }
        case 0: {
            flag_stop = 1;
            cout << "\nExit..." << endl;
            break;
        }
        default: {
            cout << "Choose correct number! \n";
            break;
        }
        }
    }
    return 0;
}
