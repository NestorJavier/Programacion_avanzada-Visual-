// GrafoOptimoAleatorioView.cpp : implementation of the CGrafoOptimoAleatorioView class
//

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"

#include "GrafoOptimoAleatorioDoc.h"
#include "GrafoOptimoAleatorioView.h"
#include <time.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView

IMPLEMENT_DYNCREATE(CGrafoOptimoAleatorioView, CView)

BEGIN_MESSAGE_MAP(CGrafoOptimoAleatorioView, CView)
	//{{AFX_MSG_MAP(CGrafoOptimoAleatorioView)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDM_CREA, IDM_LIST, OnGrafoOptimoAleatorio)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView construction/destruction

CGrafoOptimoAleatorioView::CGrafoOptimoAleatorioView()
{
	// TODO: add construction code here
	band = FALSE;
	bandCG = FALSE;
	name = 'A';
	opcion = 0;
}

CGrafoOptimoAleatorioView::~CGrafoOptimoAleatorioView()
{
}

BOOL CGrafoOptimoAleatorioView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView drawing

void CGrafoOptimoAleatorioView::OnDraw(CDC* pDC)
{
	CGrafoOptimoAleatorioDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(band)
	{
		switch(opcion)
		{
			case 1:
				CGrafoOptimoAleatorioView::Destructor();
				srand( (unsigned)time( NULL ) );//Semilla del random
				numeros = 3;//rand()%5+2;
				CGrafoOptimoAleatorioView::CreaGrafo(numeros);
			break;
			case 2:
				if(bandCG)
					CGrafoOptimoAleatorioView::ImprimeGrafo(pDC);
			break;
			case 3:
				if(bandCG)
				{
					dlgCaja.gDlg.AddHead(&g);
					dlgCaja.DoModal();
					dlgCaja.gDlg.RemoveAll();
				}
			break;
		}
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView diagnostics

#ifdef _DEBUG
void CGrafoOptimoAleatorioView::AssertValid() const
{
	CView::AssertValid();
}

void CGrafoOptimoAleatorioView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGrafoOptimoAleatorioDoc* CGrafoOptimoAleatorioView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGrafoOptimoAleatorioDoc)));
	return (CGrafoOptimoAleatorioDoc*)m_pDocument;
}
#endif //_DEBUG


void CGrafoOptimoAleatorioView::Inserta(CNodoP *np, CNodoR *nr)
{
	np->abajo.AddTail(nr);
}

void CGrafoOptimoAleatorioView::Inserta(CNodoP *c1)
{
	g.AddTail(c1);
}
/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView message handlers
void CGrafoOptimoAleatorioView::OnGrafoOptimoAleatorio( UINT nID )
{
	int nButton = nID - IDM_CREA;
    ASSERT( nButton >= 0 && nButton < 3 );

	switch(nButton)
	{
		case 0:
			opcion = 1;
		break;
		case 1:
			opcion = 2;
			band = TRUE;
			Invalidate();
		break;
		case 2:
			opcion = 3;
			band = TRUE;
			Invalidate(FALSE);
		break;
	}
	band = TRUE;
	Invalidate(FALSE);

}

void CGrafoOptimoAleatorioView::CreaGrafo(int n)
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

void CGrafoOptimoAleatorioView::ImprimeGrafo(CDC *pDC)
{
	CNodoP *c2;
	CNodoR *c3;
	POSITION pos3, pos2;
	int x = 100, y = 100;
	CString cad;


	pos2 = g.GetHeadPosition();//pos1 se posiciona en A
	c2 = (CNodoP*)g.GetAt(pos2);//C1 se posiciona en B
	while(c2 && pos2)
	{
		cad = (char)c2->nombre;
		cad += ": ";
		pDC->TextOut(x, y, cad);
		x -= 30;
		pos3 = c2->abajo.GetHeadPosition();//pos1 se posiciona en A
		if(pos3)
		{
			c3 = (CNodoR*)c2->abajo.GetHead();//c2 se posiciona en A
			while(c3 && pos3)
			{
				cad.Format("%d", c3->peso);
				cad += "_";
				cad += (char)c3->arriba->nombre;
				cad += "->";
				x = x+cad.GetLength()*10;
				pDC->TextOut(x, y, cad);
				
				c3 = (CNodoR*)c2->abajo.GetNext(pos3);
				if(pos3)
				{
					c3 = (CNodoR*)c2->abajo.GetAt(pos3);
				}
			}
			x = x+cad.GetLength()*10;
			pDC->TextOut(x, y, "NULL");
		}
		else
		{
			pDC->TextOut(x+50, y, "-> NULL");
		}
		y+=20;
		x=100;

		c2 = (CNodoP*)g.GetNext(pos2);
		if(pos2)
		{
			c2 = (CNodoP*)g.GetAt(pos2);
		}
	}
	pDC->TextOut(x+3, y, "|");
	pDC->TextOut(x, y+=10, 92);
	pDC->TextOut(x+4, y, "/");
	pDC->TextOut(x, y+=20, "NULL");

}

void CGrafoOptimoAleatorioView::Destructor()
{
	CNodoP *c2;
	CNodoR *c3;
	POSITION pos3, pos2;

	pos2 = g.GetTailPosition();
	if(pos2)
	{
		while(pos2)
		{
			c2 = (CNodoP*)g.GetAt(pos2);
			pos3 = c2->abajo.GetTailPosition();
			while(pos3)
			{
				c3 = (CNodoR*)c2->abajo.GetPrev(pos3);
				c2->abajo.RemoveTail();
				delete c3;
			}
			c2->abajo.RemoveAll();

			c2 = (CNodoP*)g.GetPrev(pos2);
			g.RemoveTail();
			delete c2;
		}
		g.RemoveAll();
	}
}
