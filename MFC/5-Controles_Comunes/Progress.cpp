// Progress.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_Comunes.h"
#include "Progress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDT_TIMER1 1

/////////////////////////////////////////////////////////////////////////////
// CProgress dialog


CProgress::CProgress(CWnd* pParent /*=NULL*/)
	: CDialog(CProgress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgress)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	band_accion = FALSE;
}


void CProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgress)
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress1);
	DDX_Control(pDX, IDC_PROGRESS2, m_Progress2);
	DDX_Control(pDX, IDC_PROGRESS3, m_Progress3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgress, CDialog)
	//{{AFX_MSG_MAP(CProgress)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_ACCION, OnAccion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgress message handlers

BOOL CProgress::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetTimer(IDT_TIMER1, 20, NULL);
	//m_Progress1.SetRange(0, 100);
	m_Progress1.SetPos(100);
	m_Progress1.SetStep(-2);

	m_Progress2.SetPos(100);
	m_Progress2.SetStep(-2);

	m_Progress3.SetPos(0);
	m_Progress3.SetStep(1);
	band_accion = FALSE;
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CProgress::OnTimer(UINT nIDEvent) 
{
	int paso, paso2, paso3;

	if(band_accion & nIDEvent)
	{
		paso = m_Progress1.StepIt();
		if(paso <= 0)
		{
			m_Progress1.SetPos(0);
			m_Progress1.SetStep(0);
		}
		if(paso >= 0)
		{
			paso3 = m_Progress3.StepIt();
			if(paso3 == 100)
					m_Progress3.OffsetPos(100);
		}
		if(paso3 >= 50)
		{
			paso2 = m_Progress2.StepIt();
			if(paso2 <= 0)
			{
				m_Progress2.SetPos(0);
				m_Progress2.SetStep(0);
			}
		
		}
		
	}

	CDialog::OnTimer(nIDEvent);
}

void CProgress::OnAccion() 
{
	band_accion = TRUE;
	
}
