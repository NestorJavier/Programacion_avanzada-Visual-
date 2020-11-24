// CajaImprime.cpp : implementation file
//

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"
#include "CajaImprime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCajaImprime dialog


CCajaImprime::CCajaImprime(CWnd* pParent /*=NULL*/)
	: CDialog(CCajaImprime::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCajaImprime)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCajaImprime::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCajaImprime)
	DDX_Control(pDX, IDC_LIST1, m_Grafo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCajaImprime, CDialog)
	//{{AFX_MSG_MAP(CCajaImprime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCajaImprime message handlers

BOOL CCajaImprime::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//Generacion en la corrida

	CNodoP* np;
	CNodoR* nr;
	char name = 'A';
	CString peso;

	maxNP = gDlg.GetCount()+1;//Numero de nodos Principales

	//Esquuina 0,0
	m_Grafo.InsertColumn(0, "R/P",LVCFMT_LEFT, 100, -1);

	for(i = 1; i < maxNP; i++)
	{
		m_Grafo.InsertColumn(i, (CString)name, LVCFMT_LEFT, 60, -1);
		m_Grafo.InsertItem(i, (CString)name++);
	}

	i=0;
	j=1;

	//Llenado del control de acuerdo al grafo
	name = 'A';
	posP = gDlg.GetHeadPosition();
	while(posP)
	{
		np = (CNodoP*)gDlg.GetNext(posP);
		posR = np->abajo.GetHeadPosition();
		if(posR)
		{
			maxNP = gDlg.GetCount();
			while(posR)
			{
				nr = (CNodoR*)np->abajo.GetNext(posR);
				peso.Format("%d", nr->peso);
				if(nr->arriba->nombre == name)
				{
					name++;
					m_Grafo.SetItemText(i, j++, peso);
					maxNP--;
				}
				else
				{
					while(nr->arriba->nombre != name)
					{
						name++;
						m_Grafo.SetItemText(i, j++, "NULL");
						maxNP--;
					}
					if(nr->arriba->nombre == name)
					{
						name++;
						m_Grafo.SetItemText(i, j++, peso);
						maxNP--;
					}
				}
			}
			if(maxNP--)
			{
				m_Grafo.SetItemText(i, j++, "NULL");
			}
			i+=1;
			j=1;
		}
		else
		{
			maxNP = gDlg.GetCount();
			while(maxNP--)
			{
				m_Grafo.SetItemText(i, j++, "NULL");
			}
			i+=1;
			j=1;
		}
		name = 'A';
	}
	return TRUE;
}
