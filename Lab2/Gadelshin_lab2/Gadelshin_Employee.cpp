#include "Gadelshin_Employee.h"

Gadelshin_Employee::Gadelshin_Employee() {
    firstname = _T("");
    secondname = _T("");
    phone_number = -1;
    login = _T("");
};

IMPLEMENT_SERIAL(Gadelshin_Employee, CObject, 0)

bool isValidPhoneNumber(long long number) {
    return number >= 0 && to_string(number).length() == 11;
}

long long getValidPhoneNumber() {
    long long number;
    while ((cin >> number).fail() || (cin.peek() != '\n') || !isValidPhoneNumber(number)) {
        cout << "Invalid input. Please input a number with 11 digits. Try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}

void Gadelshin_Employee::init_employee()
{
    string inp_firstname, inp_secondname, inp_login;
    cout << "Input first name:\n";
    cin.ignore();
    getline(cin, inp_firstname);
    firstname = inp_firstname.c_str();
    cout << "Input second name:\n";
    getline(cin, inp_secondname);
    secondname = inp_secondname.c_str();
    cout << "Input login:\n";
    getline(cin, inp_login);
    login = inp_login.c_str();
    cout << "Input phone number:\n";
    phone_number = getValidPhoneNumber();
}

string CString_to_string(CString example) {
    string result(example.GetString());
    return result;
}

void Gadelshin_Employee::print_info() {
    cout << "\nfirst name: " << CString_to_string(firstname) <<
        "\nsecond name: " << CString_to_string(secondname) << "\nsystem login: " << CString_to_string(login) <<
        "\nphone number: " << phone_number << endl;
}

void Gadelshin_Employee::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        ar << firstname;
        ar << secondname;
        ar << login;
        ar << phone_number;
    }
    else
    {
        ar >> firstname;
        ar >> secondname;
        ar >> login;
        ar >> phone_number;
    }
}

