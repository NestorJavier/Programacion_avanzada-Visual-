// Spin.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_Comunes.h"
#include "Spin.h"

#define IDT_TIMER1 1

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpin dialog


CSpin::CSpin(CWnd* pParent /*=NULL*/)
	: CDialog(CSpin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpin)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	band_Accion = FALSE;
}


void CSpin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpin)
	DDX_Control(pDX, IDC_SPIN1, m_Spin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpin, CDialog)
	//{{AFX_MSG_MAP(CSpin)
	ON_BN_CLICKED(IDC_ACCION, OnAccion)
	ON_WM_TIMER()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpin message handlers

void CSpin::OnAccion() 
{
	band_Accion = TRUE;
	
}

void CSpin::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnTimer(nIDEvent);
}

BOOL CSpin::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_Spin.SetRange(0,100);
	m_Spin.SetPos(0);
	SetDlgItemInt(IDC_EDIT1, 0);
	m_Spin.SetBuddy(GetDlgItem(IDC_EDIT1));


	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSpin::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int i=0;
	
	SetDlgItemInt(IDC_EDIT1, nPos+2);

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
