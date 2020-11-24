#if !defined(AFX_CAJAIMPRIME_H__24F1A248_8552_4B87_9BC3_7E323ADA58A6__INCLUDED_)
#define AFX_CAJAIMPRIME_H__24F1A248_8552_4B87_9BC3_7E323ADA58A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 
#include "NodoP.h"
#include "NodoR.h"

// _MSC_VER > 1000
// CajaImprime.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCajaImprime dialog

class CCajaImprime : public CDialog
{
// Construction
public:
	int i;
	int j;
	POSITION posP;
	POSITION posR;
	int maxNP;
	int maxNR;
	CObList gDlg;
	CCajaImprime(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCajaImprime)
	enum { IDD = IDD_IMPRIMIR };
	CListCtrl	m_Grafo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCajaImprime)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCajaImprime)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAJAIMPRIME_H__24F1A248_8552_4B87_9BC3_7E323ADA58A6__INCLUDED_)
