// Dialogos_Comunes.h : main header file for the DIALOGOS_COMUNES application
//

#if !defined(AFX_DIALOGOS_COMUNES_H__805F5537_7B99_4EAF_81E5_417C1090283D__INCLUDED_)
#define AFX_DIALOGOS_COMUNES_H__805F5537_7B99_4EAF_81E5_417C1090283D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesApp:
// See Dialogos_Comunes.cpp for the implementation of this class
//

class CDialogos_ComunesApp : public CWinApp
{
public:
	CDialogos_ComunesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogos_ComunesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDialogos_ComunesApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGOS_COMUNES_H__805F5537_7B99_4EAF_81E5_417C1090283D__INCLUDED_)
