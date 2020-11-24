// CajaUnion.cpp : implementation file
//

#include "stdafx.h"
#include "Conjuntos.h"
#include "CajaUnion.h"
#include "Nodo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCajaUnion dialog


CCajaUnion::CCajaUnion(CWnd* pParent /*=NULL*/)
	: CDialog(CCajaUnion::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCajaUnion)
	//}}AFX_DATA_INIT
}


void CCajaUnion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCajaUnion)
	DDX_Control(pDX, IDC_COMBO4, m_ConjC);
	DDX_Control(pDX, IDC_COMBO2, m_ConjB);
	DDX_Control(pDX, IDC_COMBO1, m_ConjA);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCajaUnion, CDialog)
	//{{AFX_MSG_MAP(CCajaUnion)
	ON_BN_CLICKED(IDC_UNION, OnUnion)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCajaUnion message handlers

BOOL CCajaUnion::OnInitDialog() 
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
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCajaUnion::OnUnion() 
{
	POSITION pos = setUnion.GetHeadPosition();
	CNodo* nodo;
	CString cad;
	while(pos)
	{
		nodo = (CNodo*)setUnion.GetNext(pos);
		cad.Format("%d", nodo->numero);
		m_ConjC.AddString(cad);
	}
	m_ConjC.SetCurSel(0);
}
