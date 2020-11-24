// Base_DLGDlg.h : header file
//

#if !defined(AFX_BASE_DLGDLG_H__DEA7FD78_3842_40A9_94C8_195EB279B649__INCLUDED_)
#define AFX_BASE_DLGDLG_H__DEA7FD78_3842_40A9_94C8_195EB279B649__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBase_DLGDlg dialog

class CBase_DLGDlg : public CDialog
{
// Construction
public:
	CWnd* pCombos;
	//CWind* pCombo;
	CBase_DLGDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBase_DLGDlg)
	enum { IDD = IDD_BASE_DLG_DIALOG };
	CComboBox	m_Combo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBase_DLGDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBase_DLGDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAccion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASE_DLGDLG_H__DEA7FD78_3842_40A9_94C8_195EB279B649__INCLUDED_)
