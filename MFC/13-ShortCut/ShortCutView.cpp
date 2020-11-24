// ShortCutView.cpp : implementation of the CShortCutView class
//

#include "stdafx.h"
#include "ShortCut.h"

#include "ShortCutDoc.h"
#include "ShortCutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShortCutView

IMPLEMENT_DYNCREATE(CShortCutView, CView)

BEGIN_MESSAGE_MAP(CShortCutView, CView)
	//{{AFX_MSG_MAP(CShortCutView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(IDM_LINEA, OnLinea)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShortCutView construction/destruction

CShortCutView::CShortCutView()
{
	// TODO: add construction code here
	bandFF = FALSE;
	bandFinal = FALSE;
	band = FALSE;
}

CShortCutView::~CShortCutView()
{
}

BOOL CShortCutView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShortCutView drawing

void CShortCutView::OnDraw(CDC* pDC)
{
	CShortCutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	NewPen = new CPen();

    pDC->SetROP2(R2_NOTXORPEN);
    if(bandFF)
	{
        if(band)
		{
        
            NewPen->CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
            OldPen = pDC->SelectObject(NewPen);

            pDC->MoveTo(pt1);
            pDC->LineTo(pt2);
            Sleep(20);
            pDC->MoveTo(pt1);
            pDC->LineTo(pt2);
            pDC->SelectObject(OldPen);
            NewPen->DeleteObject();
        }   
        else
		{
            if(bandFinal)
			{
                NewPen->CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
                OldPen = pDC->SelectObject(NewPen);
                pDC->MoveTo(pt1);
                pDC->LineTo(pt2);
                pDC->SelectObject(OldPen);
                NewPen->DeleteObject();
            }
        }
    }
    

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CShortCutView diagnostics

#ifdef _DEBUG
void CShortCutView::AssertValid() const
{
	CView::AssertValid();
}

void CShortCutView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShortCutDoc* CShortCutView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShortCutDoc)));
	return (CShortCutDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShortCutView message handlers

void CShortCutView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(nFlags)
	{
        pt2 = point;
        Invalidate(FALSE);
	}
	CView::OnMouseMove(nFlags, point);
}


void CShortCutView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	band = FALSE;
	bandFinal = TRUE;
	Invalidate(FALSE);


	CView::OnLButtonUp(nFlags, point);
}

void CShortCutView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	pt1 = point;
	band = TRUE;


	//::AfxGetApp()->LoadStandardCursor(IDC_ARROW);
    Invalidate(FALSE);

//	cursor = SetCursor(IDC_CROSS);
//	::AfxGetApp()->loadLoadCursor(IDC_CROSS);

	CView::OnLButtonDown(nFlags, point);
}

void CShortCutView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// Despliega un submenu
	CMenu* menu;
	menu = new CMenu();
	menu->LoadMenu(IDR_MENU1);
	menu->GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	menu->DestroyMenu();
}

void CShortCutView::OnLinea() 
{
	// TODO: Add your command handler code here
    bandFF = !bandFF;
}
