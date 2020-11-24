// DesplazamientoVerticalDoc.cpp : implementation of the CDesplazamientoVerticalDoc class
//

#include "stdafx.h"
#include "DesplazamientoVertical.h"

#include "DesplazamientoVerticalDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDesplazamientoVerticalDoc

IMPLEMENT_DYNCREATE(CDesplazamientoVerticalDoc, CDocument)

BEGIN_MESSAGE_MAP(CDesplazamientoVerticalDoc, CDocument)
	//{{AFX_MSG_MAP(CDesplazamientoVerticalDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesplazamientoVerticalDoc construction/destruction

CDesplazamientoVerticalDoc::CDesplazamientoVerticalDoc()
{
	// TODO: add one-time construction code here

}

CDesplazamientoVerticalDoc::~CDesplazamientoVerticalDoc()
{
}

BOOL CDesplazamientoVerticalDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDesplazamientoVerticalDoc serialization

void CDesplazamientoVerticalDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDesplazamientoVerticalDoc diagnostics

#ifdef _DEBUG
void CDesplazamientoVerticalDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDesplazamientoVerticalDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDesplazamientoVerticalDoc commands
