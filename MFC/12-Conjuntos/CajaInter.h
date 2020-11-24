#if !defined(AFX_CAJAINTER_H__DBA48678_32D5_4451_8E1A_DEBCB17F5469__INCLUDED_)
#define AFX_CAJAINTER_H__DBA48678_32D5_4451_8E1A_DEBCB17F5469__INCLUDED_

#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CajaInter.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCajaInter dialog

class CCajaInter : public CDialog
{
// Construction
public:
	CSet setInter;
	CSet setDlgCB;
	CSet setDlgCA;
	CCajaInter(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCajaInter)
	enum { IDD = IDD_INTER };
	CComboBox	m_ConjC;
	CComboBox	m_ConjB;
	CComboBox	m_ConjA;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCajaInter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCajaInter)
	virtual BOOL OnInitDialog();
	afx_msg void OnInter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAJAINTER_H__DBA48678_32D5_4451_8E1A_DEBCB17F5469__INCLUDED_)
