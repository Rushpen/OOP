#include "framework.h"
#include "Utils.h"
#include "Gadelshin_Employee.h"
#include "Gadelshin_Staff.h"
#include "Gadelshin_Manager.h"

using namespace std;

int main()
{

    int choice;
    bool flag_stop = 0;
    Staff staff;
    while (!flag_stop) {
        cout << "\nChoose key: \n1. Input new employee" << "\n2. Input manager" <<
            "\n3. Print employees.\n4. Input employees from file" <<
            "\n5. Print employees to file.\n6. Clear.\n0. Exit" << endl;
        choice = get_num_value(0, 6);
        switch (choice) {
        case 1: {
            staff.input_person();
            break;
        }
        case 2: {
            staff.input_manager();
            break;
        }
        case 3: {
            staff.print_all();
            break;
        }
        case 4: {
            string way_to_file;
            cout << "Input way from file:\n";
            cin >> way_to_file;
            staff.read_from_file(way_to_file);
            break;
        }
        case 5: {
            string way_to_file;
            cout << "Input way to file:\n";
            cin >> way_to_file;
            staff.write_to_file(way_to_file);
            break;
        }
        case 6: {
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
