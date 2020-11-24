// NodoR.cpp: implementation of the CNodoR class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"
#include "NodoR.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CNodoR,CObject,1)

CNodoR::CNodoR()
{

}

CNodoR::~CNodoR()
{

}

CNodoR::CNodoR(int p)
{
	peso = p;
}

void CNodoR::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        ar << peso;
		ar << arriba;
    }
    else
    {
        ar >> peso;
		ar >> arriba;
    }
}