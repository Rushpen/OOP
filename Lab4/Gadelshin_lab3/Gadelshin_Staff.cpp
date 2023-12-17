#include "pch.h"
#include "Gadelshin_Staff.h"

bool Staff::to_file(CArchive& ar) {
    ar << (int)employees.size();

    for_each(employees.begin(), employees.end(), [&](auto employee) 
    {
        ar << employee.get(); });
    return true;
}

bool Staff::from_file(CArchive& ar) {

    employees.clear();

    int size = 0;
    ar >> size;

    for (int i = 0; i < size; i++) {
        Gadelshin_Employee* p_employee;
        ar >> p_employee;
        employees.push_back(shared_ptr<Gadelshin_Employee>(p_employee));
    }
    return true;
}

void Staff::add_new_employee() {
	shared_ptr<Gadelshin_Employee> employee = make_shared<Gadelshin_Employee>();
	employees.push_back(employee);
}
void Staff::add_manager() {
	shared_ptr<Gadelshin_Manager> manager = make_shared<Gadelshin_Manager>();
	employees.push_back(manager);
}

void draw_columns(CDC* pDC, vector<CString> columns, vector<int> x_coordinates, int top) {
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	_tcscpy_s(lf.lfFaceName, _T("Arial"));
	lf.lfHeight = -MulDiv(12, GetDeviceCaps(pDC->m_hDC, LOGPIXELSY), 72);
	lf.lfWeight = FW_BOLD;

	CFont boldFont;
	boldFont.CreateFontIndirect(&lf);

	CFont* pOldFont = pDC->SelectObject(&boldFont);

	for (int i = 0; i < columns.size(); ++i)
		pDC->TextOut(x_coordinates[i], top, columns[i]);
	pDC->SelectObject(pOldFont);
}


CSize Staff::draw_employees(CDC* pDC) 
{
	vector<CString> columns = {
		_T("Firstname"),
		_T("Secondname"),
		_T("Phone"),
		_T("Login"),
		_T("TeamSize"),
		_T("ExpYears")
	};

	int x_inter = 30; //////////////////////////
	int y_inter = 30; ///////////////////////////
	int top = 0;
	vector<int> coordinates = get_x_coordinates(pDC, x_inter, columns);

	draw_columns(pDC, columns, coordinates, top);

	sort(employees.begin(), employees.end(), [](const auto& a, const auto& b) {
		return a->get_firstname() < b->get_firstname();
	});

	for_each(employees.begin(), employees.end(),
		bind(&Gadelshin_Employee::draw, placeholders::_1, pDC, coordinates, ref(top), y_inter));

	POINT total_size;
	total_size.x = coordinates[coordinates.size() - 1];
	total_size.y = top + y_inter;
	return total_size;
}

vector<int> Staff::get_max_extents(CDC* pDC, vector<CString> columns) 
{

	vector<int> max_extents;

	for_each(columns.cbegin(), columns.cend(), [&](CString column_name) {
		max_extents.push_back(pDC->GetTextExtent(column_name).cx); });

	for (auto& employee : employees) {
		vector<int> employee_extents = employee->get_extents(pDC, columns.size());
		for (int i = 0; i < columns.size(); ++i)
			max_extents[i] = max(max_extents[i], employee_extents[i]);
	}

	return max_extents;
}

vector<int> Staff::get_x_coordinates(CDC* pDC, int x_inter, vector<CString> columns) 
{
	vector<int> x_coordinates;
	vector<int> max_extents = get_max_extents(pDC, columns);

	x_coordinates.push_back(x_inter);

	for (int i = 0; i < max_extents.size(); ++i)
		x_coordinates.push_back(max_extents[i] + x_coordinates[i] + x_inter);

	return x_coordinates;
}

int Staff::GetList(CListBox& list) 
{
	int i = 0;
	for_each(employees.begin(), employees.end(), [&list](shared_ptr<Gadelshin_Employee> employee) {
		list.AddString(employee.get()->get_firstname());
		}
	);
	return employees.size();
}

shared_ptr<Gadelshin_Employee> Staff::GetEmployee(int index) {
	if (employees.size() == 0) return *employees.begin();
	return employees[index];
}

void Staff::EmployeeDelete(int index) {
	employees.erase(employees.begin() + index);
}

void Staff::clear() {
	employees.clear();
}

size_t Staff::get_size() 
{
	return employees.size();
}