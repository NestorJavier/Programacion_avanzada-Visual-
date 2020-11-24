// BD1View.cpp : implementation of the CBD1View class
//

#include "stdafx.h"
#include "BD1.h"

#include "BD1Doc.h"
#include "BD1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBD1View

IMPLEMENT_DYNCREATE(CBD1View, CScrollView)

BEGIN_MESSAGE_MAP(CBD1View, CScrollView)
	//{{AFX_MSG_MAP(CBD1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBD1View construction/destruction

CBD1View::CBD1View()
{
	// TODO: add construction code here

}

CBD1View::~CBD1View()
{
}

BOOL CBD1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBD1View drawing

void CBD1View::OnDraw(CDC* pDC)
{
	CBD1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	TEXTMETRIC tm;
	int altoLinea;
	CPoint pText(0,0);
	CString str;

	pDC->GetTextMetrics(&tm);
	altoLinea = tm.tmHeight + tm.tmExternalLeading;
	
	if(m_ptabla->IsBOF())
		return;

	m_ptabla->MoveFirst();
	pDC->TextOut(pText.x, pText.y, "ID");

	pDC->TextOut(pText.x+1000, pText.y, "Nombre");

	pDC->TextOut(pText.x+2000, pText.y, "Clave");

	pDC->TextOut(pText.x+3000, pText.y, "Calificacion 1");

	pDC->TextOut(pText.x+4000, pText.y, "Calificacion 2");

	pDC->TextOut(pText.x+5000, pText.y, "Semestre");


	pText.y -= altoLinea*2;


	while(!m_ptabla->IsEOF())
	{
		str.Format("%d", m_ptabla->m_Id);
		pDC->TextOut(pText.x, pText.y, str);

		str.Format("%d", m_ptabla->m_Clave);
		pDC->TextOut(pText.x+2000, pText.y, str);

		pDC->TextOut(pText.x+1000, pText.y, m_ptabla->m_Nombre);

		str.Format("%d", m_ptabla->m_Calif_1);
		pDC->TextOut(pText.x+3000, pText.y, str);

		str.Format("%d", m_ptabla->m_Calif_2);
		pDC->TextOut(pText.x+4000, pText.y, str);

		str.Format("%d", m_ptabla->m_Grado);
		pDC->TextOut(pText.x+5000, pText.y, str);


		m_ptabla->MoveNext();
		pText.y -= altoLinea;

	}




	// TODO: add draw code for native data here
}

void CBD1View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal(8000, 10500);
	// TODO: calculate the total size of this view
	//sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_HIENGLISH, sizeTotal);
	m_ptabla = &GetDocument()->m_Tabla;
	if(m_ptabla->IsOpen())
		m_ptabla->Close();
	m_ptabla->m_strFilter = "[Calificaciones].[Id] = [Grado].[Id]";
	m_ptabla->Open();
}

/////////////////////////////////////////////////////////////////////////////
// CBD1View diagnostics

#ifdef _DEBUG
void CBD1View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBD1View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBD1Doc* CBD1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBD1Doc)));
	return (CBD1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBD1View message handlers
