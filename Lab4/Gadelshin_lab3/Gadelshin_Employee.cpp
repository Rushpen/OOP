#include "pch.h"
#include "Gadelshin_Employee.h"

Gadelshin_Employee::Gadelshin_Employee() {
    firstname = _T("");
    secondname = _T("");
    phone_number = -1;
    login = _T("");
};

IMPLEMENT_SERIAL(Gadelshin_Employee, CObject, 0)

CString to_cstring(long long int num) {
    CString str_num;
    str_num.Format(_T("%lld"), num);
    return str_num;
}

vector<int> Gadelshin_Employee::get_extents(CDC* pDC, int num) {

    vector<int> extents(num, 0);
    extents[0] = pDC->GetTextExtent(firstname).cx;
    extents[1] = pDC->GetTextExtent(secondname).cx;

    extents[2] = pDC->GetTextExtent(to_cstring(phone_number)).cx;

    extents[3] = pDC->GetTextExtent(login).cx;

    return extents;
}

void Gadelshin_Employee::draw(CDC* pDC, std::vector<int> x_coordinates, int& top, int y_height) {

    CString str_phone = to_cstring(phone_number);
    top += y_height;
    pDC->TextOut(x_coordinates[0], top, firstname);
    pDC->TextOut(x_coordinates[1], top, secondname);
    pDC->TextOut(x_coordinates[2], top, str_phone.GetBuffer());
    pDC->TextOut(x_coordinates[3], top, login);
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

CString Gadelshin_Employee::get_firstname() { return firstname; }
CString Gadelshin_Employee::get_secondname() { return secondname; }
long long int Gadelshin_Employee::get_phone_number() { return phone_number; }
CString Gadelshin_Employee::get_login() { return login; }

size_t Gadelshin_Employee::get_teamSize() { return NULL; };
size_t Gadelshin_Employee::get_expYears() { return NULL; };


void Gadelshin_Employee::set_firstname(CString firstname) {
    if (firstname.GetLength() == 0)
        firstname = _T("null");
    this->firstname = firstname;
}
void Gadelshin_Employee::set_secondname(CString secondname) {
    if (secondname.GetLength() == 0)
        secondname = _T("null");
    this->secondname = secondname;
}
void Gadelshin_Employee::set_phone_number(long long int phone_number) {
    this->phone_number = phone_number;
}
void Gadelshin_Employee::set_login(CString login) {
    if (login.GetLength() == 0)
        login = _T("null");
    this->login = login;
}
void Gadelshin_Employee::set_teamSize(size_t&) {};
void Gadelshin_Employee::set_expYears(size_t&) {};