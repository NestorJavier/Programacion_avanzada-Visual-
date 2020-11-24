// Lista_ComboView.cpp : implementation of the CLista_ComboView class
//

#include "stdafx.h"
#include "Lista_Combo.h"

#include "Lista_ComboDoc.h"
#include "Lista_ComboView.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView

IMPLEMENT_DYNCREATE(CLista_ComboView, CView)

BEGIN_MESSAGE_MAP(CLista_ComboView, CView)
	//{{AFX_MSG_MAP(CLista_ComboView)
	ON_COMMAND(IDM_CREAR, OnCrear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView construction/destruction

CLista_ComboView::CLista_ComboView()
{
	// TODO: add construction code here
	band = FALSE;
}

CLista_ComboView::~CLista_ComboView()
{

}

BOOL CLista_ComboView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView drawing

void CLista_ComboView::OnDraw(CDC* pDC)
{
	CLista_ComboDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	POSITION pos;
	CString cad;
	int x = 100;

	if(band)
	{
		pos = lista.GetHeadPosition();
		while(pos)
		{
			//Me regresa el primer nodo y avanza al siguiente
			nodo = (CNodo*)lista.GetNext(pos);
			cad.Format("%d", nodo->numero);
			pDC->TextOut(x+=20, 100, cad);
		}
		dlgNumeros.DoModal();
		dlgNumeros.lista_Combo.RemoveAll();

		CLista_ComboView::Destructor();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView diagnostics

#ifdef _DEBUG
void CLista_ComboView::AssertValid() const
{
	CView::AssertValid();
}

void CLista_ComboView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLista_ComboDoc* CLista_ComboView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLista_ComboDoc)));
	return (CLista_ComboDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView message handlers

void CLista_ComboView::OnCrear() 
{
	int num, numeros;
	POSITION pos;
	CNodo *aux;
	int ya = 0;

	srand( (unsigned)time( NULL ) );//Semilla del random
	numeros = rand()%5+10;
	while(numeros--)
	{
		num = rand()%100;
		nodo = new CNodo(num);

		if(lista.IsEmpty())
			lista.AddHead(nodo);
		else
		{
			pos = lista.GetHeadPosition();
			aux = (CNodo*)lista.GetAt(pos);
			if(aux->numero > nodo->numero && aux->numero != nodo->numero)
				lista.AddHead(nodo);
			else
			{
				if(aux->numero < nodo->numero && aux->numero != nodo->numero)
				{
					while(pos)
					{
						aux = (CNodo*)lista.GetAt(pos);
						if(aux->numero > nodo->numero)
							break;
						lista.GetNext(pos);
					}
				}
				if(!pos)
					lista.AddTail(nodo);
				else
				{
					lista.InsertBefore(pos, nodo);
				}

			}
		}
	}
	dlgNumeros.lista_Combo.AddHead(&lista);

	band = TRUE;
	Invalidate();
}

void CLista_ComboView::Destructor()
{
	POSITION pos;
	CNodo *aux;

	pos = lista.GetTailPosition();
	while(pos)
	{
		aux = (CNodo*)lista.GetPrev(pos);
		lista.RemoveTail();
		delete aux;
	}
	lista.RemoveAll();
}
