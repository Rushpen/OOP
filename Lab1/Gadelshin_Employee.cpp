#include "Gadelshin_Employee.h"

Employee::Employee() {
    firstname = "";
    secondname = "";
    phone_number = -1;
    login = "";
    position = "";
}

istream& operator >> (istream& in, Employee& emp)
{
    cout << "Input first name:\n";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, emp.firstname, '\n');
    cout << "Input second name:\n";
    getline(cin, emp.secondname, '\n');
    cout << "Input positon:\n";
    getline(cin, emp.position, '\n');
    cout << "Input phone number:\n";
    while (true) {
        if (!(cin >> emp.phone_number) || emp.phone_number < 0 || to_string(emp.phone_number).length() != 11) {
            cout << "Invalid input. Please input number with 11 digits. Try again..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            continue;
        };
        break;
    }
    return in;
}

void Employee::print_info() {
    cout << "\nid: " << id << "\nfirst name: " << firstname <<
        "\nsecond name: " << secondname << "\nposition: " << position <<
        "\nphone number:  " << phone_number << endl;
}

ifstream& operator>>(ifstream& input, Employee& employee) {
    input >> employee.id >> employee.firstname >> employee.secondname >> employee.position >> employee.phone_number;
    return input;
}

ofstream& operator<<(ofstream& output, Employee& employee) {
    output << employee.id << endl << employee.firstname << endl
        << employee.secondname << endl << employee.position << endl << employee.phone_number << endl;
    return output;
}

void Employee::from_file(string filename) {
    ofstream output(filename, ios::app);
    if (!output) {
        cerr << "\nError!. Please try open again\n" << endl;
        return;
    }
    output << *this;
    output.close();
}

