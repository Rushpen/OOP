
// Gadelshin_lab3.h : main header file for the Gadelshin_lab3 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGadelshinlab3App:
// See Gadelshin_lab3.cpp for the implementation of this class
//

class CGadelshinlab3App : public CWinApp
{
public:
	CGadelshinlab3App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGadelshinlab3App theApp;
