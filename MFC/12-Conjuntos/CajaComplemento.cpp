// CajaComplemento.cpp : implementation file
//

#include "stdafx.h"
#include "Conjuntos.h"
#include "CajaComplemento.h"
#include "Nodo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCajaComplemento dialog


CCajaComplemento::CCajaComplemento(CWnd* pParent /*=NULL*/)
	: CDialog(CCajaComplemento::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCajaComplemento)
	//}}AFX_DATA_INIT
}


void CCajaComplemento::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCajaComplemento)
	DDX_Control(pDX, IDC_COMBO2, m_ComboCp);
	DDX_Control(pDX, IDC_COMBO1, m_ComboC);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCajaComplemento, CDialog)
	//{{AFX_MSG_MAP(CCajaComplemento)
	ON_BN_CLICKED(IDC_COMP, OnComp)
	ON_BN_CLICKED(IDC_ACCION, OnAccion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCajaComplemento message handlers

void CCajaComplemento::OnComp() 
{
	// TODO: Add your control notification handler code here

	CDialog::OnInitDialog();
	
	POSITION pos = setComple.GetHeadPosition();
	CNodo* nodo;
	CString cad;
	while(pos)
	{
		nodo = (CNodo*)setComple.GetNext(pos);
		cad.Format("%d", nodo->numero);
		m_ComboCp.AddString(cad);
	}
	m_ComboCp.SetCurSel(0);
	
}

void CCajaComplemento::OnAccion() 
{
	// TODO: Add your control notification handler code here

	CDialog::OnInitDialog();

	POSITION pos = setDlg.GetHeadPosition();
	CNodo* nodo;
	CString cad;
	while(pos)
	{
		nodo = (CNodo*)setDlg.GetNext(pos);
		cad.Format("%d", nodo->numero);
		m_ComboC.AddString(cad);
	}
	m_ComboC.SetCurSel(0);

}

BOOL CCajaComplemento::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
