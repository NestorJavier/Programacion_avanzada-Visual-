// BD1.h : main header file for the BD1 application
//

#if !defined(AFX_BD1_H__5C2C439F_F718_43AB_9FD7_2F5939864DB3__INCLUDED_)
#define AFX_BD1_H__5C2C439F_F718_43AB_9FD7_2F5939864DB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBD1App:
// See BD1.cpp for the implementation of this class
//

class CBD1App : public CWinApp
{
public:
	CBD1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBD1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBD1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BD1_H__5C2C439F_F718_43AB_9FD7_2F5939864DB3__INCLUDED_)
