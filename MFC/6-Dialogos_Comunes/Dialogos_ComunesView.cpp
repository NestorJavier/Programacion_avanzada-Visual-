// Dialogos_ComunesView.cpp : implementation of the CDialogos_ComunesView class
//

#include "stdafx.h"
#include "Dialogos_Comunes.h"

#include "Dialogos_ComunesDoc.h"
#include "Dialogos_ComunesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView

IMPLEMENT_DYNCREATE(CDialogos_ComunesView, CView)

BEGIN_MESSAGE_MAP(CDialogos_ComunesView, CView)
	//{{AFX_MSG_MAP(CDialogos_ComunesView)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDM_COLOR, IDM_FONT, OnComunes)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView construction/destruction
static char BASED_CODE szFilter[] = "C++ Files (*.cpp)|*.cpp| Header Files (*.h)|*.h| C++ and Header Files (*.cpp;*.h)| *.cpp;*.h | All Files (*.*)|*.*||";

CDialogos_ComunesView::CDialogos_ComunesView()
{
	file = new CFileDialog( FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);


	band = FALSE;
	bandFont = FALSE;
}

CDialogos_ComunesView::~CDialogos_ComunesView()
{
}

BOOL CDialogos_ComunesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView drawing

void CDialogos_ComunesView::OnDraw(CDC* pDC)
{
	CDialogos_ComunesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CFont Newfont, *oldF = pDC->GetCurrentFont();//oldF es un apuntador a la funte por default que tiene
	LOGFONT lfNew;

	if(band)
	{
		switch(opcion)
		{
			case 1:
				pDC->FillSolidRect(100, 100, 100, 100, color);
			break;
			case 2:
				//FileDiaog
			break;
			case 3:
				dlgFont.GetCurrentFont(&lfNew);//en lfNew se guarda la estrctura de la funte seleccionada en el CFontDialog
				Newfont.CreateFontIndirect(&lfNew);//CreateFontIndirect Crea la funete apartir de la estructura 
				pDC->SelectObject(&Newfont);//se selecciona la funete recien creada
				pDC->SetTextColor(dlgFont.GetColor());//dlgFont.GetColor() Obtiene el color seleccionado en el dialogo SetTextColor pintar el texto del color indicado
				pDC->TextOut(50, 50, "Mama Soy Paquito");
				pDC->SelectObject(oldF);//se selecciona la funete Default
				Newfont.DeleteObject();
			break;

		}
	}
	else
	{
		pDC->Rectangle(100, 100, 200, 200);
	}

}

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView diagnostics

#ifdef _DEBUG
void CDialogos_ComunesView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogos_ComunesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogos_ComunesDoc* CDialogos_ComunesView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogos_ComunesDoc)));
	return (CDialogos_ComunesDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView message handlers
void CDialogos_ComunesView::OnComunes( UINT nID )
{

    int nButton = nID - IDM_COLOR;
    ASSERT( nButton >= 0 && nButton < 3 );
	
	char* pszFileName = "Colores.txt";
	CFileException fileException;
	int i;


	switch(nButton)
	{
		case 0://Color

				if ( !myFile.Open( pszFileName, CFile::modeRead), &fileException )
				{
					TRACE( "Can't open file %s, error = %u\n", pszFileName, fileException.m_cause);
				}
				for(i = 0; i<16;i++)
						myFile.Read(&dlgColor.m_cc.lpCustColors[i], sizeof(dlgColor.m_cc.lpCustColors));

				if(dlgColor.DoModal() == IDOK)
				{
					color = dlgColor.GetColor();
					band = TRUE;
					Invalidate();
				}
				myFile.Close();
		break;
		case 1:
			file->DoModal();
			Invalidate();
		break;
		case 2:
			if(dlgFont.DoModal() == IDOK)
				band = TRUE;
			Invalidate();
		break;
	}
	opcion = nButton+1;
}
		//Guerdar
	/*	if ( !myFile.Open(pszFileName, CFile::modeCreate | CFile::modeReadWrite ), &fileException )
		{
			TRACE( "Can't open file %s, error = %u\n", pszFileName, fileException.m_cause);
		}
		
		for(i = 0; i<16;i++)
			myFile.Write(&dlgColor.m_cc.lpCustColors[i], sizeof(dlgColor.m_cc.lpCustColors));*/
		
		//Leer
	/*	*/
