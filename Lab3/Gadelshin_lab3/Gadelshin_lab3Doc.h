
// Gadelshin_lab3Doc.h : interface of the CGadelshinlab3Doc class
//
#pragma once
#include "Gadelshin_Staff.h"
#include <vector>

class CGadelshinlab3Doc : public CDocument
{
protected: // create from serialization only
	CGadelshinlab3Doc() noexcept;
	DECLARE_DYNCREATE(CGadelshinlab3Doc)

// Attributes
public:
	Staff staff;
// Operations
public:
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CGadelshinlab3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnDialog1();
};
