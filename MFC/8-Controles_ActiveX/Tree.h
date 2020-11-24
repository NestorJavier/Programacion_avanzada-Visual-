#if !defined(AFX_TREE_H__F32317EA_6C26_4464_A27F_5C2CF33C6336__INCLUDED_)
#define AFX_TREE_H__F32317EA_6C26_4464_A27F_5C2CF33C6336__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTree dialog

class CTree : public CDialog
{
// Construction
public:
	CTree(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTree)
	enum { IDD = IDD_TREE };
	CTreeCtrl	m_Tree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTree)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTree)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREE_H__F32317EA_6C26_4464_A27F_5C2CF33C6336__INCLUDED_)
