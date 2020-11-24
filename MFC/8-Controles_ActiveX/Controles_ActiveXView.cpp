// Controles_ActiveXView.cpp : implementation of the CControles_ActiveXView class
//

#include "stdafx.h"
#include "Controles_ActiveX.h"

#include "Controles_ActiveXDoc.h"
#include "Controles_ActiveXView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXView

IMPLEMENT_DYNCREATE(CControles_ActiveXView, CView)

BEGIN_MESSAGE_MAP(CControles_ActiveXView, CView)
	//{{AFX_MSG_MAP(CControles_ActiveXView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDM_VIDEO, IDM_TREE, OnControles_ActiveX)
	ON_UPDATE_COMMAND_UI_RANGE(IDM_VIDEO, IDM_TREE, OnComunesUpdateX)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXView construction/destruction

CControles_ActiveXView::CControles_ActiveXView()
{
	// TODO: add construction code here
	band = FALSE;
	opcion = 0;

}

CControles_ActiveXView::~CControles_ActiveXView()
{
}

BOOL CControles_ActiveXView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXView drawing

void CControles_ActiveXView::OnDraw(CDC* pDC)
{
	CControles_ActiveXDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(band)
		pDC->TextOut(100, 100, dlgCal.fecha);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXView diagnostics

#ifdef _DEBUG
void CControles_ActiveXView::AssertValid() const
{
	CView::AssertValid();
}

void CControles_ActiveXView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CControles_ActiveXDoc* CControles_ActiveXView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControles_ActiveXDoc)));
	return (CControles_ActiveXDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXView message handlers
void CControles_ActiveXView::OnControles_ActiveX( UINT nID )
{
    int nButton = nID - IDM_VIDEO;
    ASSERT( nButton >= 0 && nButton < 3 );
    
	switch(nButton)
	{
		case 0:
			dlgVideo.DoModal();
		break;
		case 1:
			dlgCal.DoModal();
			Invalidate();
			band = TRUE;
		break;
		case 2:
			dlgTree.DoModal();
			opcion = 3;
		break;
	}
	m_ID = nID;
	Invalidate(FALSE);
}

void CControles_ActiveXView::OnComunesUpdateX(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID==m_ID);
	pCmdUI->Enable(pCmdUI->m_nID!=m_ID);

}