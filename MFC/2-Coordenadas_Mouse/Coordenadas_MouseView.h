// Coordenadas_MouseView.h : interface of the CCoordenadas_MouseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COORDENADAS_MOUSEVIEW_H__5F3B04E8_EC3C_4BAD_9F8F_69DBC414F0C7__INCLUDED_)
#define AFX_COORDENADAS_MOUSEVIEW_H__5F3B04E8_EC3C_4BAD_9F8F_69DBC414F0C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCoordenadas_MouseView : public CView
{
protected: // create from serialization only
	CCoordenadas_MouseView();
	DECLARE_DYNCREATE(CCoordenadas_MouseView)

// Attributes
public:
	CCoordenadas_MouseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoordenadas_MouseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	int yPos;
	int xPos;
	BOOL band;
	virtual ~CCoordenadas_MouseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCoordenadas_MouseView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Coordenadas_MouseView.cpp
inline CCoordenadas_MouseDoc* CCoordenadas_MouseView::GetDocument()
   { return (CCoordenadas_MouseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDENADAS_MOUSEVIEW_H__5F3B04E8_EC3C_4BAD_9F8F_69DBC414F0C7__INCLUDED_)
