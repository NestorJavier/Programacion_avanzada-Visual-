// ShortCutView.h : interface of the CShortCutView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHORTCUTVIEW_H__577C015D_4A6F_4A39_BB84_157101D79202__INCLUDED_)
#define AFX_SHORTCUTVIEW_H__577C015D_4A6F_4A39_BB84_157101D79202__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShortCutView : public CView
{
protected: // create from serialization only
	CShortCutView();
	DECLARE_DYNCREATE(CShortCutView)

// Attributes
public:
	CShortCutDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShortCutView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL bandFF;
	HCURSOR cursor;
	int pintar;
	BOOL bandFinal;
	CPoint pt2;
	CPoint pt1;
	BOOL band;
	COLORREF colorPluma;
	CPen* NewPen;
	CPen* OldPen;
	virtual ~CShortCutView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShortCutView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnLinea();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShortCutView.cpp
inline CShortCutDoc* CShortCutView::GetDocument()
   { return (CShortCutDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORTCUTVIEW_H__577C015D_4A6F_4A39_BB84_157101D79202__INCLUDED_)
