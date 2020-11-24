// Base_DLG.h : main header file for the BASE_DLG application
//

#if !defined(AFX_BASE_DLG_H__78E8CA82_6018_4B1F_9FB9_78FB826D2B63__INCLUDED_)
#define AFX_BASE_DLG_H__78E8CA82_6018_4B1F_9FB9_78FB826D2B63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBase_DLGApp:
// See Base_DLG.cpp for the implementation of this class
//

class CBase_DLGApp : public CWinApp
{
public:
	CBase_DLGApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBase_DLGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBase_DLGApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASE_DLG_H__78E8CA82_6018_4B1F_9FB9_78FB826D2B63__INCLUDED_)
