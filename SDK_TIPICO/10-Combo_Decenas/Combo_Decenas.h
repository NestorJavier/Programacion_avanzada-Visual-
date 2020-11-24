
#if !defined(AFX_COMBO_DECENAS_H__A5F08E5C_9057_40FA_8D20_18345C1B2178__INCLUDED_)
#define AFX_COMBO_DECENAS_H__A5F08E5C_9057_40FA_8D20_18345C1B2178__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

typedef struct reg NP;
typedef struct reg1 NR;

struct reg
{
	int dec;
	NP *sig;
	NR *abajo;
	HWND hCombo;
};
struct reg1
{
	int num;
	NR *sig;
};


#endif // !defined(AFX_COMBO_DECENAS_H__A5F08E5C_9057_40FA_8D20_18345C1B2178__INCLUDED_)
