// OleDBView.cpp : implementation of the COleDBView class
//

#include "stdafx.h"
#include "OleDB.h"

#include "OleDBSet.h"
#include "OleDBDoc.h"
#include "OleDBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleDBView

IMPLEMENT_DYNCREATE(COleDBView, COleDBRecordView)

BEGIN_MESSAGE_MAP(COleDBView, COleDBRecordView)
	//{{AFX_MSG_MAP(COleDBView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COleDBView construction/destruction

COleDBView::COleDBView()
	: COleDBRecordView(COleDBView::IDD)
{
	//{{AFX_DATA_INIT(COleDBView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COleDBView::~COleDBView()
{
}

void COleDBView::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COleDBView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL COleDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return COleDBRecordView::PreCreateWindow(cs);
}

void COleDBView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_oleDBSet;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->Open();
		if (hr != S_OK)
		{
			AfxMessageBox(_T("Record set failed to open."), MB_OK);
			// Disable the Next and Previous record commands,
			// since attempting to change the current record without an
			// open RecordSet will cause a crash.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}				
	}
	COleDBRecordView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// COleDBView diagnostics

#ifdef _DEBUG
void COleDBView::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void COleDBView::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

COleDBDoc* COleDBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COleDBDoc)));
	return (COleDBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COleDBView database support
CRowset* COleDBView::OnGetRowset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// COleDBView message handlers
