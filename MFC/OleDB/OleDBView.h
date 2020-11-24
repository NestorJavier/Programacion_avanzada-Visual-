// OleDBView.h : interface of the COleDBView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBVIEW_H__A37838A8_2EDF_46A7_8B07_E74E1BFBB5E1__INCLUDED_)
#define AFX_OLEDBVIEW_H__A37838A8_2EDF_46A7_8B07_E74E1BFBB5E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COleDBSet;

class COleDBView : public COleDBRecordView
{
protected: // create from serialization only
	COleDBView();
	DECLARE_DYNCREATE(COleDBView)

public:
	//{{AFX_DATA(COleDBView)
	enum{ IDD = IDD_OLEDB_FORM };
	COleDBSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	COleDBDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDBView)
	public:
	virtual CRowset* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COleDBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COleDBView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OleDBView.cpp
inline COleDBDoc* COleDBView::GetDocument()
   { return (COleDBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBVIEW_H__A37838A8_2EDF_46A7_8B07_E74E1BFBB5E1__INCLUDED_)
