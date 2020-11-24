// ConjuntosDoc.cpp : implementation of the CConjuntosDoc class
//

#include "stdafx.h"
#include "Conjuntos.h"

#include "ConjuntosDoc.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc

IMPLEMENT_DYNCREATE(CConjuntosDoc, CDocument)

BEGIN_MESSAGE_MAP(CConjuntosDoc, CDocument)
	//{{AFX_MSG_MAP(CConjuntosDoc)
	ON_COMMAND(IDM_CREAR, OnCrear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc construction/destruction

CConjuntosDoc::CConjuntosDoc()
{
	// TODO: add one-time construction code here
}

CConjuntosDoc::~CConjuntosDoc()
{
}

BOOL CConjuntosDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc serialization

void CConjuntosDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc diagnostics

#ifdef _DEBUG
void CConjuntosDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CConjuntosDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc commands

void CConjuntosDoc::OnCrear() 
{
	srand( (unsigned)time( NULL ) );//Semilla del random
	int nume1, nume2, nume3;
	// var r = new Random();
	
	nume1 = rand()%5+5;
	nume2 = rand()%5+3;
	nume3 = rand()%5+5;

	if(set.IsEmpty())
		set.CrearLista(nume1);
	else
	{
		set.Destructor();
		set.CrearLista(nume1);

	}

	if(ConjA.IsEmpty())
		ConjA.CrearLista(nume2);
	else
	{
		ConjA.Destructor();
		ConjA.CrearLista(nume2);
	}

	if(ConjB.IsEmpty())	
		ConjB.CrearLista(nume3);
	else
	{
		ConjB.Destructor();
		ConjB.CrearLista(nume3);
	}

	if(ConjAa.IsEmpty())	
		ConjAa.CrearLista(nume2);
	else
	{
		ConjAa.Destructor();
		ConjAa.CrearLista(nume2);
	}

	if(ConjBb.IsEmpty())
		ConjBb.CrearLista(nume3);
	else
	{
		ConjBb.Destructor();
		ConjBb.CrearLista(nume2);
	}

}
