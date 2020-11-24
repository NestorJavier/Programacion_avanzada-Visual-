// BD1Doc.h : interface of the CBD1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BD1DOC_H__AEDC9259_5164_44F9_9493_7FB5C2C45431__INCLUDED_)
#define AFX_BD1DOC_H__AEDC9259_5164_44F9_9493_7FB5C2C45431__INCLUDED_

#include "Tabla.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBD1Doc : public CDocument
{
protected: // create from serialization only
	CBD1Doc();
	DECLARE_DYNCREATE(CBD1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBD1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CTabla m_Tabla;
	virtual ~CBD1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBD1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BD1DOC_H__AEDC9259_5164_44F9_9493_7FB5C2C45431__INCLUDED_)
