//{{AFX_INCLUDES()
#include "monthview.h"
//}}AFX_INCLUDES
#if !defined(AFX_CALENDARIO_H__D9ECA981_0D31_4931_9D6D_646C779CF24A__INCLUDED_)
#define AFX_CALENDARIO_H__D9ECA981_0D31_4931_9D6D_646C779CF24A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Calendario.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCalendario dialog

class CCalendario : public CDialog
{
// Construction
public:
	CString fecha;
	CCalendario(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCalendario)
	enum { IDD = IDD_CAL };
	CMonthView	m_Cal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalendario)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCalendario)
	afx_msg void OnDateClickMonthview1(DATE DateClicked);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALENDARIO_H__D9ECA981_0D31_4931_9D6D_646C779CF24A__INCLUDED_)
