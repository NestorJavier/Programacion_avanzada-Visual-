// Set.h: interface for the CSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SET_H__9A838537_5AAC_4BDB_B5BE_C45627EFDD17__INCLUDED_)
#define AFX_SET_H__9A838537_5AAC_4BDB_B5BE_C45627EFDD17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Nodo.h"	// Added by ClassView

class CSet : public CObList  
{
public:
	CSet& operator +(CSet &s);
	
	void Destructor();
	CSet& operator !();
	int num;
	CNodo* np;
	void CrearLista(int i);
	CSet& operator =(CSet &l);
    CSet& operator ^(CSet &s);
	CSet();
	virtual ~CSet();

};

#endif // !defined(AFX_SET_H__9A838537_5AAC_4BDB_B5BE_C45627EFDD17__INCLUDED_)
