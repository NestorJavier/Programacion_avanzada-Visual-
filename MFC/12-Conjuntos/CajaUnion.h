#if !defined(AFX_CAJAUNION_H__4FCF12D9_86FB_464E_82D2_DF60CE87CD4E__INCLUDED_)
#define AFX_CAJAUNION_H__4FCF12D9_86FB_464E_82D2_DF60CE87CD4E__INCLUDED_

#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CajaUnion.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCajaUnion dialog

class CCajaUnion : public CDialog
{
// Construction
public:
	CSet setUnion;
	CSet setDlgCB;
	CSet setDlgCA;
	CCajaUnion(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCajaUnion)
	enum { IDD = IDD_UNION };
	CComboBox	m_ConjC;
	CComboBox	m_ConjB;
	CComboBox	m_ConjA;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCajaUnion)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCajaUnion)
	virtual BOOL OnInitDialog();
	afx_msg void OnUnion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAJAUNION_H__4FCF12D9_86FB_464E_82D2_DF60CE87CD4E__INCLUDED_)
