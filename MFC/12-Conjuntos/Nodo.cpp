// Nodo.cpp: implementation of the CNodo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Conjuntos.h"
#include "Nodo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNodo::CNodo()
{

}

CNodo::~CNodo()
{

}

CNodo::CNodo(int n)
{
	numero = n;
}
