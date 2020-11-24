// Nodo.h: interface for the CNodo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODO_H__990A0207_B833_47A3_9ACD_2BBDA5F5E4EF__INCLUDED_)
#define AFX_NODO_H__990A0207_B833_47A3_9ACD_2BBDA5F5E4EF__INCLUDED_

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

#endif // !defined(AFX_NODO_H__990A0207_B833_47A3_9ACD_2BBDA5F5E4EF__INCLUDED_)
