// Slider.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_Comunes.h"
#include "Slider.h"

#define IDT_TIMER1 1

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSlider dialog


CSlider::CSlider(CWnd* pParent /*=NULL*/)
	: CDialog(CSlider::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSlider)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	band_Accion = FALSE;
}


void CSlider::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSlider)
	DDX_Control(pDX, IDC_SLIDER2, m_Slider2);
	DDX_Control(pDX, IDC_SLIDER1, m_Slider1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSlider, CDialog)
	//{{AFX_MSG_MAP(CSlider)
	ON_BN_CLICKED(IDC_ACCION, OnAccion)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSlider message handlers

void CSlider::OnAccion() 
{
	band_Accion = TRUE;
	
}

BOOL CSlider::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetTimer(IDT_TIMER1, 20, NULL);
	m_Slider1.SetRange(0, 100);
	m_Slider2.SetRange(0, 100);
	
	
	m_Slider1.SetPos(0);
	m_Slider2.SetPos(0);	

	m_Slider1.SetTicFreq(10);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSlider::OnTimer(UINT nIDEvent) 
{
	static int pos1 = 0, pos2 = 0;
	CString cad1, cad2;

	if(band_Accion)
	{
		if(pos1<=100)
		{
			m_Slider1.SetPos(pos1++);
		}
		else
			pos1 = 0;
		
		
		cad1.Format("%d", pos1);
		SetDlgItemText(IDC_EDIT1, cad1);

		pos2 = m_Slider2.GetPos();
		cad2.Format("%d", pos2);
		SetDlgItemText(IDC_EDIT2, cad2);
	}
	

	CDialog::OnTimer(nIDEvent);
}
