/**************************************************************
*Nombre: Nestor Javier Mendez Gutierres
*Fecha: 26 Septiembre 2017
*proyecto: CascaronMFC_Clases
*Funcionalidad: Implementa Clases
*Metodos: OnPaint, OnChar, OnLButtonDown
*Handles:
*Mensages:
*Tipo:
*Estructuras:
**************************************************************/

#include <afxwin.h>

int x = 100, y = 100;
BOOL band = FALSE;

class CCascaron_Frame: public CFrameWnd
{
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT);

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CCascaron_Frame, CFrameWnd)//clase Marco
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

void CCascaron_Frame::OnPaint()
{
	CPaintDC dc(this);

	if(band)
	{
		//dc.TextOut(x, y, "Hola");
	}
}

void CCascaron_Frame::OnChar(UINT nChar)
{
	CDC *pDC = GetDC();

	switch(nChar)
	{
		case '\r':
			x = 100;
			y = y + 20;
		break;
		default:
			pDC->TextOut(x+=8, y, nChar);

	}
}

void CCascaron_Frame::OnLButtonDown(UINT f, CPoint p)
{
	CClientDC pDC(this);
	
	x = p.x;
	y = p.y;
	band = TRUE;
	Invalidate();//parametros por default
}

class CCascaron_MFC: public CWinApp//Clase Aplicacion
{
	virtual BOOL InitInstance()
	{
		//AfxMessageBox("Hola MFC");
		CCascaron_Frame* pMarco = new CCascaron_Frame;
		pMarco->Create(NULL, (CString)"Cascaron MFC");
		m_pMainWnd = pMarco;
		m_pMainWnd->ShowWindow(SW_SHOWNORMAL);

		return TRUE;
	}
};

CCascaron_MFC theApp;