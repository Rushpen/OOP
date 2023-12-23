// CEmployeeDialog.cpp : implementation file
//

#include "pch.h"
#include "Gadelshin_lab3.h"
#include "CEmployeeDialog.h"
#include "afxdialogex.h"


// CEmployeeDialog dialog

IMPLEMENT_DYNAMIC(CEmployeeDialog, CDialogEx)

CEmployeeDialog::CEmployeeDialog(CGadelshinlab3Doc* pDc, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	,pDoc(pDc)
{
}

CEmployeeDialog::~CEmployeeDialog()
{
}

void CEmployeeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_BOX, list_box);
	DDX_Control(pDX, IDC_EDIT_FIRSTNAME, edit_firstname);
	DDX_Control(pDX, IDC_EDIT_SECONDNAME, edit_secondname);
	DDX_Control(pDX, IDC_EDIT_LOGIN, edit_login);
	DDX_Control(pDX, IDC_EDIT_PHONENUMBER, edit_phone_number);
	DDX_Control(pDX, IDC_EDIT_TEAMSIZE, edit_teamSize);
	DDX_Control(pDX, IDC_EDIT_EXPYEARS, edit_expYears);
}

BOOL CEmployeeDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	pDoc->staff.GetList(list_box);
	if (list_box.GetCount() != 0) {
		list_box.SetCurSel(0);
		OnLbnSelchangeListBox();
	}
	return TRUE;
}

BEGIN_MESSAGE_MAP(CEmployeeDialog, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST_BOX, &CEmployeeDialog::OnLbnSelchangeListBox)
	ON_EN_KILLFOCUS(IDC_EDIT_FIRSTNAME, &CEmployeeDialog::OnEnKillfocusEditFirstname)
	ON_EN_KILLFOCUS(IDC_EDIT_SECONDNAME, &CEmployeeDialog::OnEnKillfocusEditSecondname)
	ON_EN_KILLFOCUS(IDC_EDIT_LOGIN, &CEmployeeDialog::OnEnKillfocusEditLogin)
	ON_EN_KILLFOCUS(IDC_EDIT_PHONENUMBER, &CEmployeeDialog::OnEnKillfocusEditPhoneNumber)
	ON_EN_KILLFOCUS(IDC_EDIT_TEAMSIZE, &CEmployeeDialog::OnEnKillfocusEditTeamSize)
	ON_EN_KILLFOCUS(IDC_EDIT_EXPYEARS, &CEmployeeDialog::OnEnKillfocusEditExpYears)
	ON_BN_CLICKED(IDC_BTN_ADD_EMPLOYEE, &CEmployeeDialog::OnBnClickedBtnAddEmployee)
	ON_BN_CLICKED(IDC_BTN_ADD_MANAGER, &CEmployeeDialog::OnBnClickedBtnAddManager)
	ON_BN_CLICKED(IDC_BTN_DLT_EMPLOYEE, &CEmployeeDialog::OnBnClickedBtnDltEmployee)
END_MESSAGE_MAP()
// CEmployeeDialog message handlers

void CEmployeeDialog::ShowUIElements()
{
	GetDlgItem(IDC_STATIC_FIRSTNAME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_SECONDNAME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_LOGIN)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_PHONENUMBER)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_FIRSTNAME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_SECONDNAME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_LOGIN)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_PHONENUMBER)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTN_DLT_EMPLOYEE)->EnableWindow(TRUE);
}

void CEmployeeDialog::PrintData(int index) {
	shared_ptr <Gadelshin_Employee> employee = pDoc->staff.GetEmployee(index);
	edit_firstname.SetWindowText(employee->get_firstname());
	edit_secondname.SetWindowText(employee->get_secondname());
	edit_login.SetWindowText(employee->get_login());
	edit_phone_number.SetWindowText(CString(to_string(employee->get_phone_number()).c_str()));
	string class_name = typeid(*employee).name();

	if (class_name == "class Gadelshin_Employee") {
		GetDlgItem(IDC_STATIC_TEAMSIZE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EXPYEARS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_TEAMSIZE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_EXPYEARS)->ShowWindow(SW_HIDE);
	}
	else
	{
		GetDlgItem(IDC_STATIC_TEAMSIZE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_EXPYEARS)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_TEAMSIZE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_EXPYEARS)->ShowWindow(SW_SHOW);

		CString teamSizeCString;
		teamSizeCString.Format(_T("%zu"), employee->get_teamSize());
		edit_teamSize.SetWindowText(teamSizeCString);

		CString expYearsCString;
		expYearsCString.Format(_T("%zu"), employee->get_expYears());
		edit_expYears.SetWindowText(expYearsCString);
	}
}

// Обработчики сообщений CEmployeeDialog

void CEmployeeDialog::OnLbnSelchangeListBox()
{
	current_index = list_box.GetCaretIndex();
	if (list_box.GetCount() != 0) {
		ShowUIElements();
		PrintData(current_index);
	}
}

void CEmployeeDialog::OnEnKillfocusEditFirstname()
{
	if (list_box.GetCount() != 0) {
		if (current_index != -1) {
			int length = edit_firstname.GetWindowTextLength();
			CString buf;
			edit_firstname.GetWindowText(buf);
			CString firstname = buf.Left(length);
			pDoc->staff.GetEmployee(current_index).get()->set_firstname(firstname.GetString());
			OnLbnSelchangeListBox();
		}
	}
}

void CEmployeeDialog::OnEnKillfocusEditSecondname()
{
	if (list_box.GetCount() != 0) {
		if (current_index != -1) {
			int length = edit_secondname.GetWindowTextLength();
			CString buf;
			edit_secondname.GetWindowText(buf);
			CString secondname = buf.Left(length);
			pDoc->staff.GetEmployee(current_index).get()->set_secondname(secondname.GetString());
		}
	}
}

void CEmployeeDialog::OnEnKillfocusEditLogin()
{
	if (list_box.GetCount() != 0) {
		if (current_index != -1) {
			int length = edit_login.GetWindowTextLength();
			CString buf;
			edit_login.GetWindowText(buf);
			CString login = buf.Left(length);
			pDoc->staff.GetEmployee(current_index).get()->set_login(login.GetString());
		}
	}
}

void CEmployeeDialog::OnEnKillfocusEditPhoneNumber()
{
	if (list_box.GetCount() != 0) {
		if (current_index != -1) {
			int length = edit_phone_number.GetWindowTextLength();
			CString buf;
			edit_phone_number.GetWindowText(buf);
			CString phone_number_str = buf.Left(length);

			long long int phone_number = _tstoi64(phone_number_str);
			pDoc->staff.GetEmployee(current_index).get()->set_phone_number(phone_number);
		}
	}
}

void CEmployeeDialog::OnEnKillfocusEditTeamSize()
{
	if (list_box.GetCount() != 0) {
		if (current_index != -1) {
			int length = edit_teamSize.GetWindowTextLength();
			CString buf;
			edit_teamSize.GetWindowText(buf);
			CString teamSize_str = buf.Left(length);

			size_t teamSize = _tstoi64(teamSize_str);

			shared_ptr<Gadelshin_Employee> employee = pDoc->staff.GetEmployee(current_index);
			string class_name = typeid(*employee).name();

			if (class_name == "class Gadelshin_Manager") {
				shared_ptr<Gadelshin_Manager> manager = std::dynamic_pointer_cast<Gadelshin_Manager>(employee);
				if (manager) {
					manager->set_teamSize(teamSize);
				}
			}
		}
	}
}

void CEmployeeDialog::OnEnKillfocusEditExpYears()
{
	if (list_box.GetCount() != 0) {
		if (current_index != -1) {
			int length = edit_expYears.GetWindowTextLength();
			CString buf;
			edit_expYears.GetWindowText(buf);
			CString expYears_str = buf.Left(length);

			size_t expYears = _tstoi64(expYears_str);

			shared_ptr<Gadelshin_Employee> employee = pDoc->staff.GetEmployee(current_index);
			string class_name = typeid(*employee).name();

			if (class_name == "class Gadelshin_Manager") {
				shared_ptr<Gadelshin_Manager> manager = std::dynamic_pointer_cast<Gadelshin_Manager>(employee);
				if (manager) {
					manager->set_expYears(expYears);
				}
			}
		}
	}
}


void CEmployeeDialog::OnBnClickedBtnAddEmployee()
{
	if (list_box.GetCount() != 0)
		while (list_box.DeleteString(0));
	pDoc->staff.add_new_employee();
	current_index = pDoc->staff.GetList(list_box);
	list_box.SetCurSel(current_index - 1);
	OnLbnSelchangeListBox();
}

void CEmployeeDialog::OnBnClickedBtnAddManager()
{
	if (list_box.GetCount() != 0)
		while (list_box.DeleteString(0));
	pDoc->staff.add_manager();
	current_index = pDoc->staff.GetList(list_box);
	list_box.SetCurSel(current_index - 1);
	OnLbnSelchangeListBox();
}

void CEmployeeDialog::OnBnClickedBtnDltEmployee()
{
	if (current_index != -1) {
		pDoc->staff.EmployeeDelete(current_index);
		if (list_box.GetCount() != 0) {
			while (list_box.DeleteString(0));
			int last = pDoc->staff.GetList(list_box) - 1;
			if (current_index > last)
				current_index = last;
			if (list_box.GetCount() != 0) {
				list_box.SetCurSel(current_index);
				OnLbnSelchangeListBox();
			}
			else {
				edit_firstname.SetWindowText(L"");
				edit_secondname.SetWindowText(L"");
				edit_login.SetWindowText(L"");
				edit_phone_number.SetWindowText(L"");
				edit_teamSize.SetWindowText(L"");
				edit_expYears.SetWindowText(L"");
				GetDlgItem(IDC_EDIT_FIRSTNAME)->ShowWindow(SW_HIDE);
				GetDlgItem(IDC_EDIT_SECONDNAME)->ShowWindow(SW_HIDE);
				GetDlgItem(IDC_EDIT_LOGIN)->ShowWindow(SW_HIDE);
				GetDlgItem(IDC_EDIT_PHONENUMBER)->ShowWindow(SW_HIDE);
				GetDlgItem(IDC_EDIT_TEAMSIZE)->ShowWindow(SW_HIDE);
				GetDlgItem(IDC_EDIT_EXPYEARS)->ShowWindow(SW_HIDE);
				GetDlgItem(IDC_STATIC_TEAMSIZE)->ShowWindow(SW_HIDE);
				GetDlgItem(IDC_STATIC_EXPYEARS)->ShowWindow(SW_HIDE);
				GetDlgItem(IDC_BTN_DLT_EMPLOYEE)->EnableWindow(FALSE);
			}
		}
	}
}