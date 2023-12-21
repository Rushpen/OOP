
// Gadelshin_lab3View.cpp : implementation of the CGadelshinlab3View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Gadelshin_lab3.h"
#endif

#include "Gadelshin_lab3Doc.h"
#include "Gadelshin_lab3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGadelshinlab3View

IMPLEMENT_DYNCREATE(CGadelshinlab3View, CScrollView)

BEGIN_MESSAGE_MAP(CGadelshinlab3View, CScrollView)
END_MESSAGE_MAP()

// CGadelshinlab3View construction/destruction

CGadelshinlab3View::CGadelshinlab3View() noexcept
{
	// TODO: add construction code here

}

CGadelshinlab3View::~CGadelshinlab3View()
{
}

BOOL CGadelshinlab3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CGadelshinlab3View drawing

void CGadelshinlab3View::OnDraw(CDC* pDC)
{
	CGadelshinlab3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	LOGFONT lf;
	CFont font;
	font.CreatePointFont(120, _T("Arial Bold")); // Создание шрифта с размером 12

	CFont* pOldFont = pDC->SelectObject(&font);

	// Ваш остальной код отрисовки
	CSize total_size = pDoc->staff.draw_employees(pDC);

	SetScrollSizes(MM_TEXT, total_size);

	pDC->SelectObject(pOldFont);
	// TODO: add draw code for native data here
}

void CGadelshinlab3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 1000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CGadelshinlab3View diagnostics

#ifdef _DEBUG
void CGadelshinlab3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CGadelshinlab3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CGadelshinlab3Doc* CGadelshinlab3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGadelshinlab3Doc)));
	return (CGadelshinlab3Doc*)m_pDocument;
}
#endif //_DEBUG


// CGadelshinlab3View message handlers
