// Coordenadas_Mouse.h : main header file for the COORDENADAS_MOUSE application
//

#if !defined(AFX_COORDENADAS_MOUSE_H__35D21336_AC16_4AF2_8023_DAAED6D2AF8C__INCLUDED_)
#define AFX_COORDENADAS_MOUSE_H__35D21336_AC16_4AF2_8023_DAAED6D2AF8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseApp:
// See Coordenadas_Mouse.cpp for the implementation of this class
//

class CCoordenadas_MouseApp : public CWinApp
{
public:
	CCoordenadas_MouseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoordenadas_MouseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCoordenadas_MouseApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDENADAS_MOUSE_H__35D21336_AC16_4AF2_8023_DAAED6D2AF8C__INCLUDED_)
