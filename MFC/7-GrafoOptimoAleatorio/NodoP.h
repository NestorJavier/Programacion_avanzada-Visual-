// NodoP.h: interface for the CNodoP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODOP_H__A525C5A0_CC25_428D_B6DC_04EA68CA0740__INCLUDED_)
#define AFX_NODOP_H__A525C5A0_CC25_428D_B6DC_04EA68CA0740__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNodoP : public CObject  
{
public:
	CObList abajo;
	CNodoP(char n);
	char nombre;
	CNodoP();
	virtual ~CNodoP();

};

#endif // !defined(AFX_NODOP_H__A525C5A0_CC25_428D_B6DC_04EA68CA0740__INCLUDED_)
