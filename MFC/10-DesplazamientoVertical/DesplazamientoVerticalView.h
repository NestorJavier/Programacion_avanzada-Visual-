// DesplazamientoVerticalView.h : interface of the CDesplazamientoVerticalView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESPLAZAMIENTOVERTICALVIEW_H__7AFB509E_4483_4A97_A491_7513CA9726CA__INCLUDED_)
#define AFX_DESPLAZAMIENTOVERTICALVIEW_H__7AFB509E_4483_4A97_A491_7513CA9726CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MAXREN 1000

class CDesplazamientoVerticalView : public CScrollView
{
protected: // create from serialization only
	CDesplazamientoVerticalView();
	DECLARE_DYNCREATE(CDesplazamientoVerticalView)

// Attributes
public:
	CDesplazamientoVerticalDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesplazamientoVerticalView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDesplazamientoVerticalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDesplazamientoVerticalView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DesplazamientoVerticalView.cpp
inline CDesplazamientoVerticalDoc* CDesplazamientoVerticalView::GetDocument()
   { return (CDesplazamientoVerticalDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPLAZAMIENTOVERTICALVIEW_H__7AFB509E_4483_4A97_A491_7513CA9726CA__INCLUDED_)
