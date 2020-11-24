// DesplazamientoVerticalDoc.h : interface of the CDesplazamientoVerticalDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESPLAZAMIENTOVERTICALDOC_H__C8ED74C4_DCEE_4086_8777_D5B6A31C17E5__INCLUDED_)
#define AFX_DESPLAZAMIENTOVERTICALDOC_H__C8ED74C4_DCEE_4086_8777_D5B6A31C17E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDesplazamientoVerticalDoc : public CDocument
{
protected: // create from serialization only
	CDesplazamientoVerticalDoc();
	DECLARE_DYNCREATE(CDesplazamientoVerticalDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesplazamientoVerticalDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDesplazamientoVerticalDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDesplazamientoVerticalDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPLAZAMIENTOVERTICALDOC_H__C8ED74C4_DCEE_4086_8777_D5B6A31C17E5__INCLUDED_)
