#if !defined(AFX_PROGRESS_H__F4E178BB_4CB3_4F6D_880B_7A20A0A72A76__INCLUDED_)
#define AFX_PROGRESS_H__F4E178BB_4CB3_4F6D_880B_7A20A0A72A76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Progress.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgress dialog

class CProgress : public CDialog
{
// Construction
public:
	BOOL band_accion;
	CProgress(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProgress)
	enum { IDD = IDD_PROGRESS };
	CProgressCtrl	m_Progress1;
	CProgressCtrl	m_Progress2;
	CProgressCtrl	m_Progress3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProgress)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnAccion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESS_H__F4E178BB_4CB3_4F6D_880B_7A20A0A72A76__INCLUDED_)
