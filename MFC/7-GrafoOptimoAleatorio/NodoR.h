// NodoR.h: interface for the CNodoR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODOR_H__F4FBE971_ADEE_4192_9205_CAE35834AC41__INCLUDED_)
#define AFX_NODOR_H__F4FBE971_ADEE_4192_9205_CAE35834AC41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NodoP.h"

class CNodoR : public CObject  
{
public:
	CNodoR(int p);
	CNodoP* arriba;
	int peso;
	CNodoR();
	virtual ~CNodoR();

};

#endif // !defined(AFX_NODOR_H__F4FBE971_ADEE_4192_9205_CAE35834AC41__INCLUDED_)
