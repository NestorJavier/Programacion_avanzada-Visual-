// DesplazamientoVerticalView.cpp : implementation of the CDesplazamientoVerticalView class
//

#include "stdafx.h"
#include "DesplazamientoVertical.h"

#include "DesplazamientoVerticalDoc.h"
#include "DesplazamientoVerticalView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDesplazamientoVerticalView

IMPLEMENT_DYNCREATE(CDesplazamientoVerticalView, CScrollView)

BEGIN_MESSAGE_MAP(CDesplazamientoVerticalView, CScrollView)
	//{{AFX_MSG_MAP(CDesplazamientoVerticalView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesplazamientoVerticalView construction/destruction

CDesplazamientoVerticalView::CDesplazamientoVerticalView()
{
	// TODO: add construction code here

}

CDesplazamientoVerticalView::~CDesplazamientoVerticalView()
{
}

BOOL CDesplazamientoVerticalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDesplazamientoVerticalView drawing

void CDesplazamientoVerticalView::OnDraw(CDC* pDC)
{
	CDesplazamientoVerticalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int i, y=100;
	CString cad;

	for(i=0;i<MAXREN;i++)
	{
		cad.Format("%d", i);
		pDC->TextOut(100, y , cad);
		y+=20;
	}
	// TODO: add draw code for native data here
}

void CDesplazamientoVerticalView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = 100;
	sizeTotal.cy = 1000*20+100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CDesplazamientoVerticalView diagnostics

#ifdef _DEBUG
void CDesplazamientoVerticalView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDesplazamientoVerticalView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDesplazamientoVerticalDoc* CDesplazamientoVerticalView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDesplazamientoVerticalDoc)));
	return (CDesplazamientoVerticalDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDesplazamientoVerticalView message handlers
