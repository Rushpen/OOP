
// Gadelshin_lab3View.h : interface of the CGadelshinlab3View class
//

#pragma once


class CGadelshinlab3View : public CScrollView
{
protected: // create from serialization only
	CGadelshinlab3View() noexcept;
	DECLARE_DYNCREATE(CGadelshinlab3View)

// Attributes
public:
	CGadelshinlab3Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CGadelshinlab3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Gadelshin_lab3View.cpp
inline CGadelshinlab3Doc* CGadelshinlab3View::GetDocument() const
   { return reinterpret_cast<CGadelshinlab3Doc*>(m_pDocument); }
#endif

