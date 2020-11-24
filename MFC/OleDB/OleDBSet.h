// OleDBSet.h : interface of the COleDBSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBSET_H__98585C9B_1689_4FE5_AB86_B9D11FFBDF05__INCLUDED_)
#define AFX_OLEDBSET_H__98585C9B_1689_4FE5_AB86_B9D11FFBDF05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCalificaciones
{
public:
	CCalificaciones()
	{
		memset( (void*)this, 0, sizeof(*this) );
	};

	int m_Calif_1;
	int m_Calif_2;
	int m_Clave;
	int m_Id;
	wchar_t m_Nombre[128];


BEGIN_COLUMN_MAP(CCalificaciones)
		COLUMN_ENTRY_TYPE(4, DBTYPE_I4, m_Calif_1)
		COLUMN_ENTRY_TYPE(5, DBTYPE_I4, m_Calif_2)
		COLUMN_ENTRY_TYPE(2, DBTYPE_I4, m_Clave)
		COLUMN_ENTRY_TYPE(1, DBTYPE_I4, m_Id)
		COLUMN_ENTRY_TYPE(3, DBTYPE_WSTR, m_Nombre)
END_COLUMN_MAP()

};

class COleDBSet : public CCommand<CAccessor<CCalificaciones> >
{
public:

	HRESULT Open()
	{
		CDataSource db;
		CSession	session;
		HRESULT		hr;

		CDBPropSet	dbinit(DBPROPSET_DBINIT);
		dbinit.AddProperty(DBPROP_AUTH_CACHE_AUTHINFO, true);
		dbinit.AddProperty(DBPROP_AUTH_ENCRYPT_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_MASK_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_PASSWORD, "");
		dbinit.AddProperty(DBPROP_AUTH_USERID, "Admin");//C:\Users\User\Desktop\Nestor Javier Mendez Gutierrez\Visual 2017\MFC\18-OleDB
		dbinit.AddProperty(DBPROP_INIT_DATASOURCE, "C:\\Users\\User\\Desktop\\Nestor Javier Mendez Gutierrez\\Visual 2017\\MFC\\OleDB\\Estudiantes.mdb");
		dbinit.AddProperty(DBPROP_INIT_MODE, (long)16);
		dbinit.AddProperty(DBPROP_INIT_PROMPT, (short)4);
		dbinit.AddProperty(DBPROP_INIT_PROVIDERSTRING, "");
		dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);
		dbinit.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);

		hr = db.OpenWithServiceComponents("Microsoft.Jet.OLEDB.4.0", &dbinit);
		if (FAILED(hr))
			return hr;

		hr = session.Open(db);
		if (FAILED(hr))
			return hr;

		CDBPropSet	propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
		propset.AddProperty(DBPROP_IRowsetScroll, true);
		propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE );

		hr = CCommand<CAccessor<CCalificaciones> >::Open(session, "SELECT * FROM Calificaciones", &propset);
		if (FAILED(hr))
			return hr;

		return MoveNext();
	}

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBSET_H__98585C9B_1689_4FE5_AB86_B9D11FFBDF05__INCLUDED_)

