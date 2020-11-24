// Tree.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_ActiveX.h"
#include "Tree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTree dialog


CTree::CTree(CWnd* pParent /*=NULL*/)
	: CDialog(CTree::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTree)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}


void CTree::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTree)
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTree, CDialog)
	//{{AFX_MSG_MAP(CTree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTree message handlers

BOOL CTree::OnInitDialog() 
{
	CDialog::OnInitDialog();

	HTREEITEM hItem, sub, sub2;
   hItem = m_Tree.InsertItem("Los Simpson", TVI_ROOT);

   sub = m_Tree.InsertItem("Abraham Simpson", hItem);
			m_Tree.InsertItem("Herbert Powell", sub);
			sub2 = m_Tree.InsertItem("Homero Simson", sub);
				m_Tree.InsertItem("Bart Simson", sub2);
				m_Tree.InsertItem("Lisa Simson", sub2);
				m_Tree.InsertItem("Maggie Simson", sub2);


   sub = m_Tree.InsertItem("Jacqueline Bouvier", hItem);
		   sub2 = m_Tree.InsertItem("Marge Simson", sub);
				m_Tree.InsertItem("Bart Simson", sub2);
				m_Tree.InsertItem("Lisa Simson", sub2);
				m_Tree.InsertItem("Maggie Simson", sub2);

		   m_Tree.InsertItem("Paty Bouvier", sub);
		   sub2 = m_Tree.InsertItem("Selma Bouvier", sub);
		   		m_Tree.InsertItem("Ling Bouvier", sub2);


	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
