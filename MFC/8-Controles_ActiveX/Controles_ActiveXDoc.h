// Controles_ActiveXDoc.h : interface of the CControles_ActiveXDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLES_ACTIVEXDOC_H__5C3810FC_32A5_46C8_972B_703B15E268F9__INCLUDED_)
#define AFX_CONTROLES_ACTIVEXDOC_H__5C3810FC_32A5_46C8_972B_703B15E268F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CControles_ActiveXDoc : public CDocument
{
protected: // create from serialization only
	CControles_ActiveXDoc();
	DECLARE_DYNCREATE(CControles_ActiveXDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControles_ActiveXDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CControles_ActiveXDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CControles_ActiveXDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLES_ACTIVEXDOC_H__5C3810FC_32A5_46C8_972B_703B15E268F9__INCLUDED_)
