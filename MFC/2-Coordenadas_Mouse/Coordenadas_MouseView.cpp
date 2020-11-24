// Coordenadas_MouseView.cpp : implementation of the CCoordenadas_MouseView class
//

#include "stdafx.h"
#include "Coordenadas_Mouse.h"

#include "Coordenadas_MouseDoc.h"
#include "Coordenadas_MouseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseView

IMPLEMENT_DYNCREATE(CCoordenadas_MouseView, CView)

BEGIN_MESSAGE_MAP(CCoordenadas_MouseView, CView)
	//{{AFX_MSG_MAP(CCoordenadas_MouseView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseView construction/destruction

CCoordenadas_MouseView::CCoordenadas_MouseView()
{
	
	//Costructor
	xPos = 100;

}

CCoordenadas_MouseView::~CCoordenadas_MouseView()
{
}

BOOL CCoordenadas_MouseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseView drawing

void CCoordenadas_MouseView::OnDraw(CDC* pDC)
{
	CCoordenadas_MouseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CString cadx, cady;

	if(band)
	{
		cadx.Format("x = " "%d", xPos);
		cady.Format("y = " "%d", yPos);
		cadx+= "  " +cady;
		pDC->TextOut(100, 100, "Coordenadas Mouse");
		pDC->TextOut(xPos, yPos, cadx);

	}	
}

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseView diagnostics

#ifdef _DEBUG
void CCoordenadas_MouseView::AssertValid() const
{
	CView::AssertValid();
}

void CCoordenadas_MouseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCoordenadas_MouseDoc* CCoordenadas_MouseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCoordenadas_MouseDoc)));
	return (CCoordenadas_MouseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseView message handlers

void CCoordenadas_MouseView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	
	xPos = point.x;
	yPos = point.y;
	band = TRUE;
	Invalidate();
	
	CView::OnLButtonDown(nFlags, point);

}