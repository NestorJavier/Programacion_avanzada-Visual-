// GrafoOptimoAleatorioDoc.h : interface of the CGrafoOptimoAleatorioDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAFOOPTIMOALEATORIODOC_H__404E4797_C675_47A0_9DAE_10102E7172C5__INCLUDED_)
#define AFX_GRAFOOPTIMOALEATORIODOC_H__404E4797_C675_47A0_9DAE_10102E7172C5__INCLUDED_

#include "NodoP.h"
#include "NodoR.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGrafoOptimoAleatorioDoc : public CDocument
{
protected: // create from serialization only
	CGrafoOptimoAleatorioDoc();
	DECLARE_DYNCREATE(CGrafoOptimoAleatorioDoc)

// Attributes
public:
	CNodoR* nr;
	CNodoP* np;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrafoOptimoAleatorioDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL bandCG;
	CObList g;
	void Inserta(CNodoP* np);
	void Inserta(CNodoP* np, CNodoR* nr);
	int num;
	int quieres;
	int numeros;
	char name;
	void CreaGrafo(int);
	virtual ~CGrafoOptimoAleatorioDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGrafoOptimoAleatorioDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAFOOPTIMOALEATORIODOC_H__404E4797_C675_47A0_9DAE_10102E7172C5__INCLUDED_)
