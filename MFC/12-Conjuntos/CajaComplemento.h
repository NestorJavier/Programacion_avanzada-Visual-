#if !defined(AFX_CAJACOMPLEMENTO_H__D1D33500_70E5_4318_AED7_C4FB49849FDA__INCLUDED_)
#define AFX_CAJACOMPLEMENTO_H__D1D33500_70E5_4318_AED7_C4FB49849FDA__INCLUDED_

#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CajaComplemento.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCajaComplemento dialog

class CCajaComplemento : public CDialog
{
// Construction
public:
	CSet setComple;
	CSet setDlg;
	CCajaComplemento(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCajaComplemento)
	enum { IDD = IDD_COMPLEMENTO };
	CComboBox	m_ComboCp;
	CComboBox	m_ComboC;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCajaComplemento)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCajaComplemento)
	afx_msg void OnComp();
	afx_msg void OnAccion();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAJACOMPLEMENTO_H__D1D33500_70E5_4318_AED7_C4FB49849FDA__INCLUDED_)
