// Controles_ComunesView.cpp : implementation of the CControles_ComunesView class
//

#include "stdafx.h"
#include "Controles_Comunes.h"

#include "Controles_ComunesDoc.h"
#include "Controles_ComunesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesView

IMPLEMENT_DYNCREATE(CControles_ComunesView, CView)

BEGIN_MESSAGE_MAP(CControles_ComunesView, CView)
	//{{AFX_MSG_MAP(CControles_ComunesView)
	ON_COMMAND(IDM_PROGRESS, OnProgress)
	ON_COMMAND(IDM_SLIDER, OnSlider)
	ON_COMMAND(IDM_SPIN, OnSpin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesView construction/destruction

CControles_ComunesView::CControles_ComunesView()
{
	// TODO: add construction code here

}

CControles_ComunesView::~CControles_ComunesView()
{
}

BOOL CControles_ComunesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs


	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesView drawing

void CControles_ComunesView::OnDraw(CDC* pDC)
{
	CControles_ComunesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

}

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesView diagnostics

#ifdef _DEBUG
void CControles_ComunesView::AssertValid() const
{
	CView::AssertValid();
}

void CControles_ComunesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CControles_ComunesDoc* CControles_ComunesView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControles_ComunesDoc)));
	return (CControles_ComunesDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CControles_ComunesView message handlers

void CControles_ComunesView::OnProgress() 
{
	//llama al dialogo
	dlgProgress.DoModal(); 
}

void CControles_ComunesView::OnSlider() 
{
	dlgSlider.DoModal();
}

void CControles_ComunesView::OnSpin() 
{
	dlgSpin.DoModal();
}
