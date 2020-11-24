// ConjuntosView.h : interface of the CConjuntosView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONJUNTOSVIEW_H__0E08AC8B_3D08_4793_A1DB_8682878FEAC0__INCLUDED_)
#define AFX_CONJUNTOSVIEW_H__0E08AC8B_3D08_4793_A1DB_8682878FEAC0__INCLUDED_

#include "CajaInter.h"	// Added by ClassView
#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Nodo.h"	// Added by ClassView
#include "CajaComplemento.h"	// Added by ClassView
#include "CajaUnion.h"	// Added by ClassView

class CConjuntosView : public CView
{
protected: // create from serialization only
	CConjuntosView();
	DECLARE_DYNCREATE(CConjuntosView)

// Attributes
public:
	CConjuntosDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConjuntosView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	CCajaUnion dlgUnion;
	CCajaInter dlgInterseccion;
	CCajaComplemento dlgComplemento;
	CNodo* nodo;
	BOOL band;
	int opcion;
	CSet set;
	virtual ~CConjuntosView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CConjuntosView)
	afx_msg void OnComp();
	afx_msg void OnInter();
	afx_msg void OnUnion();
	afx_msg void OnImprimir();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ConjuntosView.cpp
inline CConjuntosDoc* CConjuntosView::GetDocument()
   { return (CConjuntosDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONJUNTOSVIEW_H__0E08AC8B_3D08_4793_A1DB_8682878FEAC0__INCLUDED_)
