#pragma once
#include "Gadelshin_lab3Doc.h"

// CEmployeeDialog dialog

class CEmployeeDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployeeDialog)

public:
	CEmployeeDialog(CGadelshinlab3Doc* pDc, CWnd* pParent = nullptr);   // standard constructor
	CGadelshinlab3Doc* pDoc;
	virtual ~CEmployeeDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	void ShowUIElements();
	void PrintData(int index);
	BOOL OnInitDialog();
	int current_index = 0;
	CListBox list_box;
	afx_msg void OnLbnSelchangeListBox();
	CEdit edit_firstname;
	CEdit edit_secondname;
	CEdit edit_login;
	CEdit edit_phone_number;
	CEdit edit_teamSize;
	CEdit edit_expYears;
	afx_msg void OnEnKillfocusEditFirstname();
	afx_msg void OnEnKillfocusEditSecondname();
	afx_msg void OnEnKillfocusEditLogin();
	afx_msg void OnEnKillfocusEditPhoneNumber();
	afx_msg void OnEnKillfocusEditTeamSize();
	afx_msg void OnEnKillfocusEditExpYears();
	afx_msg void OnBnClickedBtnAddEmployee();
	afx_msg void OnBnClickedBtnAddManager();
	afx_msg void OnBnClickedBtnDltEmployee();
};
