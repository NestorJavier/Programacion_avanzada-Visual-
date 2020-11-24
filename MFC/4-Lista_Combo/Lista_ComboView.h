// Lista_ComboView.h : interface of the CLista_ComboView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTA_COMBOVIEW_H__6B253177_922C_46A6_B146_3565B3A8D850__INCLUDED_)
#define AFX_LISTA_COMBOVIEW_H__6B253177_922C_46A6_B146_3565B3A8D850__INCLUDED_

#include "Numeros.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Nodo.h"	// Added by ClassView


class CLista_ComboView : public CView
{
protected: // create from serialization only
	CLista_ComboView();
	DECLARE_DYNCREATE(CLista_ComboView)

// Attributes
public:
	CLista_ComboDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLista_ComboView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	void Destructor();
	CNodo* nodo;
	CObList lista;
	BOOL band;
	CNumeros dlgNumeros;
	virtual ~CLista_ComboView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLista_ComboView)
	afx_msg void OnCrear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Lista_ComboView.cpp
inline CLista_ComboDoc* CLista_ComboView::GetDocument()
   { return (CLista_ComboDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTA_COMBOVIEW_H__6B253177_922C_46A6_B146_3565B3A8D850__INCLUDED_)
