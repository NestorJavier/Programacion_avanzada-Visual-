/**************************************************************
*Nombre: Nestor Javier Mendez Gutierres
*Fecha: 26 Septiembre 2017
*proyecto: Cascaron_MFC
*Funcionalidad: Crea un cuadro de Dialogo
*Metodos: 
*Handles:
*Mensages:
*Tipo:
*Estructuras:
**************************************************************/
#include <afxwin.h>

class CCascaron_MFC: public CWinApp
{
	virtual BOOL InitInstance()
	{
		AfxMessageBox("Hola MFC");
		return TRUE;
	}
};

CCascaron_MFC theApp;