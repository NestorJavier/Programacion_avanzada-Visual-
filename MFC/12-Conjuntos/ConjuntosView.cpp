// ConjuntosView.cpp : implementation of the CConjuntosView class
//

#include "stdafx.h"
#include "Conjuntos.h"

#include "ConjuntosDoc.h"
#include "ConjuntosView.h"
#include <time.h>
#include "Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView

IMPLEMENT_DYNCREATE(CConjuntosView, CView)

BEGIN_MESSAGE_MAP(CConjuntosView, CView)
	//{{AFX_MSG_MAP(CConjuntosView)
	ON_COMMAND(IDM_COMP, OnComp)
	ON_COMMAND(IDM_INTER, OnInter)
	ON_COMMAND(IDM_UNION, OnUnion)
	ON_COMMAND(IDM_IMPRIMIR, OnImprimir)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView construction/destruction

CConjuntosView::CConjuntosView()
{
	// TODO: add construction code here
	opcion = 0;
	band = FALSE;
}

CConjuntosView::~CConjuntosView()
{
}

BOOL CConjuntosView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView drawing

void CConjuntosView::OnDraw(CDC* pDC)
{
	CConjuntosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	POSITION pos;
	CString cad;
	int x = 100;
	
	if(band)
	{
		pDC->TextOut(100, 80, "Lista Complemento");
		pos = (pDoc->set).GetHeadPosition();
		while(pos)
		{
			//Me regresa el primer nodo y avanza al siguiente
			nodo = (CNodo*)(pDoc->set).GetNext(pos);
			cad.Format("%d", nodo->numero);
			pDC->TextOut(x+=20, 100, cad);
		}
		
		x = 100;
		pDC->TextOut(100, 180, "Listas Interseccion");
		pos = (pDoc->ConjA).GetHeadPosition();
		while(pos)
		{
			//Me regresa el primer nodo y avanza al siguiente
			nodo = (CNodo*)(pDoc->ConjA).GetNext(pos);
			cad.Format("%d", nodo->numero);
			pDC->TextOut(x+=20, 200, cad);
		}
		x = 100;
		pos = (pDoc->ConjB).GetHeadPosition();
		while(pos)
		{
			//Me regresa el primer nodo y avanza al siguiente
			nodo = (CNodo*)(pDoc->ConjB).GetNext(pos);
			cad.Format("%d", nodo->numero);
			pDC->TextOut(x+=20, 230, cad);
		}

		x = 100;
		pDC->TextOut(100, 280, "Listas Union");
		pos = (pDoc->ConjAa).GetHeadPosition();
		while(pos)
		{
			//Me regresa el primer nodo y avanza al siguiente
			nodo = (CNodo*)(pDoc->ConjAa).GetNext(pos);
			cad.Format("%d", nodo->numero);
			pDC->TextOut(x+=20, 300, cad);
		}
		x = 100;
		pos = (pDoc->ConjBb).GetHeadPosition();
		while(pos)
		{
			//Me regresa el primer nodo y avanza al siguiente
			nodo = (CNodo*)(pDoc->ConjBb).GetNext(pos);
			cad.Format("%d", nodo->numero);
			pDC->TextOut(x+=20, 330, cad);
		}

	}
}

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView diagnostics

#ifdef _DEBUG
void CConjuntosView::AssertValid() const
{
	CView::AssertValid();
}

void CConjuntosView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CConjuntosDoc* CConjuntosView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CConjuntosDoc)));
	return (CConjuntosDoc*)m_pDocument;
}
#endif //_DEBUG

void CConjuntosView::OnComp() 
{
	CConjuntosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	dlgComplemento.setDlg = pDoc->set;
	dlgComplemento.setComple = !(dlgComplemento.setDlg);
	dlgComplemento.DoModal();
	
	dlgComplemento.setDlg.RemoveAll();
	dlgComplemento.setComple.RemoveAll();
}

void CConjuntosView::OnInter() 
{
	CConjuntosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


	dlgInterseccion.setDlgCA = pDoc->ConjA;
	dlgInterseccion.setDlgCB = pDoc->ConjB;

	dlgInterseccion.setInter = dlgInterseccion.setDlgCA ^dlgInterseccion.setDlgCB;
	dlgInterseccion.DoModal();

	dlgInterseccion.setDlgCA.RemoveAll();
	dlgInterseccion.setDlgCB.RemoveAll();
	dlgInterseccion.setInter.RemoveAll();	

}

void CConjuntosView::OnUnion() 
{
	// TODO: Add your command handler code here
	CConjuntosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


	dlgUnion.setDlgCA = pDoc->ConjAa;
	dlgUnion.setDlgCB = pDoc->ConjBb;

	dlgUnion.setUnion = pDoc->ConjAa + pDoc->ConjBb;
	dlgUnion.DoModal();

	dlgUnion.setDlgCA.RemoveAll();
	dlgUnion.setDlgCB.RemoveAll();
	dlgUnion.setUnion.RemoveAll();	
}

void CConjuntosView::OnImprimir() 
{
	// TODO: Add your command handler code here
	band = TRUE;
	Invalidate();
}
