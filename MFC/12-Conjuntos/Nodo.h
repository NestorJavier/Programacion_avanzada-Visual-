// Nodo.h: interface for the CNodo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODO_H__BF4E51E8_7496_4AEE_AFC4_D4E50AFA6347__INCLUDED_)
#define AFX_NODO_H__BF4E51E8_7496_4AEE_AFC4_D4E50AFA6347__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNodo : public CObject  
{
public:
	int numero;
	CNodo(int n);
	CNodo();
	virtual ~CNodo();

};

#endif // !defined(AFX_NODO_H__BF4E51E8_7496_4AEE_AFC4_D4E50AFA6347__INCLUDED_)
