#if !defined(AFX_TABLA_H__EE13D13C_2DB0_456A_914C_4FDED63F05C7__INCLUDED_)
#define AFX_TABLA_H__EE13D13C_2DB0_456A_914C_4FDED63F05C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tabla.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabla recordset

class CTabla : public CRecordset
{
public:
	CTabla(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTabla)

// Field/Param Data
	//{{AFX_FIELD(CTabla, CRecordset)
	long	m_Id;
	long	m_Clave;
	CString	m_Nombre;
	long	m_Calif_1;
	long	m_Calif_2;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabla)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABLA_H__EE13D13C_2DB0_456A_914C_4FDED63F05C7__INCLUDED_)
