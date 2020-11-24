#include <afxwin.h>

int x = 88, y = 100, iEsp_x = 8;//La variable iEsp_x es el  espacio que existe entre caracteres
RECT rWrk;
BOOL band = FALSE;




class CCascaron_Frame: public CFrameWnd
{
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT);
	void Txt();

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
		dc.TextOut(50, 50, "Editor de texto");
		dc.Rectangle(95, 99, 322, 200);
	}	
}

void CCascaron_Frame::OnChar(UINT nChar)
{
	CDC *pDC = GetDC();

	rWrk.top = 100;
	rWrk.bottom = 198;
	rWrk.left = 96;
	rWrk.right = 320;

	if(y < rWrk.bottom)
	{
		if(x < rWrk.right-iEsp_x)
		{
			if(y<rWrk.top)
				y = 100;

			switch(nChar)
			{
				case '\r':
					x = 88;
					y += 20;
				break;
				case '\b':		
					if(x == rWrk.left-iEsp_x)
					{
						y -= 20;
						x = rWrk.right-iEsp_x*2;
						pDC->TextOut(rWrk.right-iEsp_x, y, "  ");
					}
					else
					{
						pDC->TextOut(x, y, "  ");
						x-=iEsp_x;
					}
				break;
				default:
					pDC->TextOut(x+=iEsp_x, y, nChar);
			}
		}
		else
		{
			x = 88;
			y = y + 20;
			if(y<rWrk.bottom && nChar != '\b')
				pDC->TextOut(x+=iEsp_x, y, nChar);
		}
	}
	else
	{
		x = 88;
		y = 100;
		InvalidateRect(&rWrk, TRUE);
	}
}

	
void CCascaron_Frame::OnLButtonDown(UINT f, CPoint p)
{
	CClientDC pDC(this);
	
	//x = p.x;
	//y = p.y;

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