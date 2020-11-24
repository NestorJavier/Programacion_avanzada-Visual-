
#if !defined(AFX_PREEX21_COMBO_DEC_H__A998B74A_7329_4716_8503_17513DF824AB__INCLUDED_)
#define AFX_PREEX21_COMBO_DEC_H__A998B74A_7329_4716_8503_17513DF824AB__INCLUDED_

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


#endif // !defined(AFX_PREEX21_COMBO_DEC_H__A998B74A_7329_4716_8503_17513DF824AB__INCLUDED_)
