// CajaInter.cpp : implementation file
//

#include "stdafx.h"
#include "Conjuntos.h"
#include "CajaInter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCajaInter dialog


CCajaInter::CCajaInter(CWnd* pParent /*=NULL*/)
	: CDialog(CCajaInter::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCajaInter)
	//}}AFX_DATA_INIT
}


void CCajaInter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCajaInter)
	DDX_Control(pDX, IDC_COMBO3, m_ConjC);
	DDX_Control(pDX, IDC_COMBO1, m_ConjB);
	DDX_Control(pDX, IDC_COMBO2, m_ConjA);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCajaInter, CDialog)
	//{{AFX_MSG_MAP(CCajaInter)
	ON_BN_CLICKED(IDC_INTER, OnInter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCajaInter message handlers

BOOL CCajaInter::OnInitDialog() 
{
	CDialog::OnInitDialog();

	POSITION pos = setDlgCA.GetHeadPosition();
	CNodo* nodo;
	CString cad;
	while(pos)
	{
		nodo = (CNodo*)setDlgCA.GetNext(pos);
		cad.Format("%d", nodo->numero);
		m_ConjA.AddString(cad);
	}
	m_ConjA.SetCurSel(0);
	////////////////////////////////////////////////////////

	pos = setDlgCB.GetHeadPosition();
	while(pos)
	{
		nodo = (CNodo*)setDlgCB.GetNext(pos);
		cad.Format("%d", nodo->numero);
		m_ConjB.AddString(cad);
	}
	m_ConjB.SetCurSel(0);

	return TRUE; // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FAL
}

void CCajaInter::OnInter() 
{
	POSITION pos = setInter.GetHeadPosition();
	CNodo* nodo;
	CString cad;
	while(pos)
	{
		nodo = (CNodo*)setInter.GetNext(pos);
		cad.Format("%d", nodo->numero);
		m_ConjC.AddString(cad);
	}
	m_ConjC.SetCurSel(0);

}
