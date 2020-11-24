// Numeros.cpp : implementation file
//

#include "stdafx.h"
#include "Lista_Combo.h"
#include "Numeros.h"
#include "Nodo.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumeros dialog


CNumeros::CNumeros(CWnd* pParent /*=NULL*/)
	: CDialog(CNumeros::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNumeros)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

}


void CNumeros::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNumeros)
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNumeros, CDialog)
	//{{AFX_MSG_MAP(CNumeros)
	ON_BN_CLICKED(IDC_ACCION, OnAccion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumeros message handlers

void CNumeros::OnAccion() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnInitDialog();

	POSITION pos = lista_Combo.GetHeadPosition();
	CNodo* nodo;
	CString cad;
	while(pos)
	{
		nodo = (CNodo*)lista_Combo.GetNext(pos);
		cad.Format("%d", nodo->numero);
		m_Combo.AddString(cad);
	}
	m_Combo.SetCurSel(0);	
}

BOOL CNumeros::OnInitDialog() 
{
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
