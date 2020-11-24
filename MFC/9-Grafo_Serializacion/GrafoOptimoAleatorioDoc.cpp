// GrafoOptimoAleatorioDoc.cpp : implementation of the CGrafoOptimoAleatorioDoc class
//

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"

#include "GrafoOptimoAleatorioDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioDoc

IMPLEMENT_DYNCREATE(CGrafoOptimoAleatorioDoc, CDocument)

BEGIN_MESSAGE_MAP(CGrafoOptimoAleatorioDoc, CDocument)
	//{{AFX_MSG_MAP(CGrafoOptimoAleatorioDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioDoc construction/destruction

CGrafoOptimoAleatorioDoc::CGrafoOptimoAleatorioDoc()
{
	// TODO: add one-time construction code here
	bandCG = FALSE;
}

CGrafoOptimoAleatorioDoc::~CGrafoOptimoAleatorioDoc()
{
}

BOOL CGrafoOptimoAleatorioDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioDoc serialization

void CGrafoOptimoAleatorioDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
	g.Serialize(ar);
	bandCG = TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioDoc diagnostics

#ifdef _DEBUG
void CGrafoOptimoAleatorioDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGrafoOptimoAleatorioDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioDoc commands

void CGrafoOptimoAleatorioDoc::CreaGrafo(int)
{
	CNodoP *c1, *c2;
	POSITION pos1, pos2;
	name = 'A';

	srand( (unsigned)time( NULL ) );//Semilla del random
	np = new CNodoP(name);
	c1 = np;
	while(numeros--)//Relaciones de A
	{
		quieres = rand()%2;
		if(quieres)
		{
			num = rand()%100;
			nr = new CNodoR(num);
			nr->arriba = c1;
			Inserta(np, nr);
		}
		Inserta(c1);
		c1 = new CNodoP(++name);//Nodos Principales
	}
	pos1 = g.GetHeadPosition();//pos1 se posiciona en A
	c1 = (CNodoP*)g.GetNext(pos1);//C1 se posiciona en A
	c1 = (CNodoP*)g.GetAt(pos1);//C1 se posiciona en B
	while(c1 && pos1)//Relaciones de B en adelante
	{
		pos2 = g.GetHeadPosition();//pos1 se posiciona en A
		c2 = (CNodoP*)g.GetAt(pos2);//c2 se posiciona en A
		while(c2 && pos2)
		{
			quieres = rand()%2;
			if(quieres)
			{
				num = rand()%100;
				nr = new CNodoR(num);
				nr->arriba = c2;
				Inserta(c1, nr);
			}
			c2 = (CNodoP*)g.GetNext(pos2);
			if(pos2)
			{
				c2 = (CNodoP*)g.GetAt(pos2);
			}
		}
		c1 = (CNodoP*)g.GetNext(pos1);
		if(pos1)
		{
			c1 = (CNodoP*)g.GetAt(pos1);
		}
	}
	bandCG = TRUE;
}

void CGrafoOptimoAleatorioDoc::Inserta(CNodoP *np, CNodoR *nr)
{
	np->abajo.AddTail(nr);

}

void CGrafoOptimoAleatorioDoc::Inserta(CNodoP *np)
{
	g.AddTail(np);
}
