
#if !defined(AFX_COMBO_DECENAS_H__3AE6DCA4_915E_4EC5_A57A_6AE1138B0D04__INCLUDED_)
#define AFX_COMBO_DECENAS_H__3AE6DCA4_915E_4EC5_A57A_6AE1138B0D04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

typedef struct reg NP;
typedef struct reg1 NR;


struct reg
{
	char nombre;
	NP *sig;
	NR *abajo;
	HWND hCombo;
};

struct reg1
{
	int num;
	NR *sig;
	NP *arriba;
};

#endif // !defined(AFX_COMBO_DECENAS_H__3AE6DCA4_915E_4EC5_A57A_6AE1138B0D04__INCLUDED_)