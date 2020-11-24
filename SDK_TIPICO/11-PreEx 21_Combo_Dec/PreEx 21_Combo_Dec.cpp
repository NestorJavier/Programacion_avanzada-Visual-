/**************************************************************
*Nombre: Nestor Javier Mendez Gutierres
*Fecha: 22 Septiembre 2017
*proyecto: PreEx 21_Combo_Dec
*Funcionalidad: Crea una lista de Listas
*Metodos: 
*Handles:
*Mensages:
*Tipo:
*Estructuras:
**************************************************************/


#include "stdafx.h"
#include "resource.h"
#include "PreEx 21_Combo_Dec.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text
NP *lista;
BOOL band = FALSE;
NP *c1, *np;
NR *c2, *nr;
HDC hdc;
int numCombos = 0;

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	Combo(HWND, UINT, WPARAM, LPARAM);
void Inserta_OrdenadoNR(NP *np, NR *nr);
void Inserta_OrdenadoNP(NP *np);
NP* Busca_Dec(int d);
NP* CreaNodoNP(int d);
NR* CreaNodoNR(int n);
void ImprimeLL(HDC hdc);
void Ini();


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_PREEX21_COMBO_DEC, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_PREEX21_COMBO_DEC);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_PREEX21_COMBO_DEC);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_PREEX21_COMBO_DEC;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
	RECT rt;
	GetClientRect(hWnd, &rt);
	int numeros, i, nn, d;
	int x = 100, y = 10;


	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				break;
				case IDM_COMBOS:
				   DialogBox(hInst, (LPCTSTR)IDD_COMBO, hWnd, (DLGPROC)Combo);//  
				break;
				case IDM_IMPRIME:
					hdc = GetDC(hWnd);
					ImprimeLL(hdc);
					ReleaseDC(hWnd, hdc);
				break;
				case IDM_LL:
					numCombos = 0;
					srand( (unsigned)time( NULL ) );//Semilla del random
					Ini();
					numeros = rand()%20;
					for(i = 0; i < numeros; i++)
					{	
						nn = rand()%100;
						d = nn/10*10;//Division entera
						NP *aux = Busca_Dec(d);
						if(aux == NULL)
						{
							np  = CreaNodoNP(d);
							Inserta_OrdenadoNP(np);
							nr  = CreaNodoNR(nn);
							Inserta_OrdenadoNR(np, nr);
							numCombos++;
						}
						else{
							nr  = CreaNodoNR(nn);
							Inserta_OrdenadoNR(aux, nr);
						}
						
					}
					//band = TRUE;
					InvalidateRect(hWnd, &rt, TRUE);
				break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
		break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			c1 = lista;
			if(band)
			{
				//ImprimeLL(hdc);
			}
			EndPaint(hWnd, &ps);
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
		break;
	}
    return FALSE;
}


void Ini()
{
	lista = NULL;

}

NP* CreaNodoNP(int d)
{
	NP* nodo = new NP;

	nodo->dec = d;
	nodo->abajo = NULL;
	nodo->sig = NULL;

	return nodo;
}

NR* CreaNodoNR(int n)
{
	NR* nodo = new NR;

	nodo->num = n;
	nodo->sig = NULL;

	return nodo;
}



// Mesage handler for about box.
LRESULT CALLBACK Combo(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	char cad[4];
	static HWND hCombo;
	static RECT rtDLG, rtMarco, rtButt;
	static int TamDLG;
	static HWND hOK, hCan, hAcc;
	int tamCombo = 60, espCombo = 40, i, 
		IdCombo, posCombo, ancho = 75, alto = 23, pXOK, 
		pYOK, pXCan, pYCan, pXAcc, pYAcc, anchDBox;
	

	if(numCombos != 1)
		anchDBox = numCombos*60 + (numCombos+1)*40;
	else
		anchDBox = 300;
	
	
	switch (message)
	{
		case WM_INITDIALOG:
				c1 = lista;
				SetWindowPos(hDlg, HWND_TOP, 200, 200, anchDBox, 350, SWP_NOZORDER);

				GetClientRect(hDlg, &rtDLG);

				hOK = GetDlgItem(hDlg, IDOK);
				hCan = GetDlgItem(hDlg, IDCANCEL);
				hAcc = GetDlgItem(hDlg, IDC_ACCION);
				
				pXOK = rtDLG.right-ancho-7;
				pYOK = rtDLG.bottom-alto-7;
				pXCan = rtDLG.left+7;
				pYCan = rtDLG.bottom-alto-7;
				pXAcc = (rtDLG.right/2)-(ancho/2);
				pYAcc = rtDLG.bottom-alto-30;
				
				MoveWindow(hOK, pXOK, pYOK, ancho, alto, TRUE);
				MoveWindow(hCan, pXCan, pYCan, ancho, alto, TRUE);
				MoveWindow(hAcc, pXAcc, pYAcc, ancho, alto, TRUE);


				for(i = 0; i<numCombos; i++)
				{
					if(numCombos != 1)
						posCombo = (i*tamCombo+espCombo*i)+espCombo;
					else
						posCombo = (rtDLG.right/2)-(tamCombo/2);
					//Crear Ventana en la corrida
					hCombo = CreateWindow("COMBOBOX",
							0, 
							CBS_SIMPLE | WS_CHILD | WS_VISIBLE | WS_VSCROLL, 
							posCombo,
							10,								tamCombo,
							160,
							hDlg, 							,
							(HMENU)IDC_NUEVO+i,
							hInst, 
							NULL);
					c1->hCombo = hCombo;
					c1 = c1->sig;
				}
		break;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDC_ACCION:
					c1 = lista;
					while(c1)
					{
						itoa(c1->dec, cad, 10);
						IdCombo = GetDlgCtrlID(c1->hCombo);
						SetDlgItemText(hDlg, IdCombo, (LPCTSTR) cad);

						c2 = c1->abajo;
						while(c2)
						{
							itoa(c2->num, cad, 10);
							SendMessage(c1->hCombo, CB_ADDSTRING, 0,(LPARAM) (LPCTSTR) cad);//Para el numero que va en la lista del combo

							c2 = c2->sig;
						}
						c1 = c1->sig;
					}
					//SendDlgItemMessage(hDlg, IDC_NUEVO, CB_SETCURSEL, 0 ,0);	
				break;
				case IDOK:
				case IDCANCEL:
					EndDialog(hDlg, LOWORD(wParam));
			break;
			}
		break;
	}
    return FALSE;
}


void Inserta_OrdenadoNP(NP *np)
{	
	if(!lista || lista->dec > np->dec)
	{
		np->sig = lista;
		lista = np;
	}
	else
	{
		c1 = lista;
		if(c1 && c1->dec < np->dec)
		{
			while(c1->sig)
			{
				if(c1->sig->dec > np->dec)
				   break;
				c1 = c1->sig;
			}
		}
		if(!(c1->sig))
		{
			np->sig = c1->sig;
			c1->sig = np;
		}
		else
		{
				np->sig = c1->sig;
				c1->sig = np;
		}
	}
}

// np= nodo abajo para insertar el nuevo(nr) en la LiLi
void Inserta_OrdenadoNR(NP *np, NR *nr)
{

	if(!np->abajo || np->abajo->num > nr->num && np->abajo->num != nr->num)
	{
		nr->sig = np->abajo;
		np->abajo = nr;
	}
	else
	{

		c2 = (NR*)(np->abajo);
		if(c2->num < nr->num && c2->num != nr->num)
		{
			while(c2->sig)
			{
				if(c2->sig->num > nr->num)
				   break;
				c2 = c2->sig;
			}
		}
		if(c2->num != nr->num)
		{
			if(!(c2->sig))
			{
				nr->sig = c2->sig;
				c2->sig = nr;
			}
			else
			{
				nr->sig = c2->sig;
				c2->sig = nr;
			}
		}
	}
}

NP* Busca_Dec(int d)
{
	NP* c1 = lista;

	while(c1)
	{
		if(c1->dec != d)
		{
			c1 = c1->sig;
		}
		else
		{
			break;
		}
	}
	return c1;
}

void ImprimeLL(HDC hdc)
{
	NP* c1 = lista;
	NR* c2;
	int x = 100, y = 100;
	char cad[3];
	int tam;

	while(c1)
	{
		itoa(c1->dec, cad, 10);
		tam= strlen(cad);
		TextOut(hdc, x, y, cad, tam);
		c2 = c1->abajo;
		while(c2)
		{
			itoa(c2->num, cad, 10);
			tam= strlen(cad);
			TextOut(hdc, x+=25, y, cad, tam);
			c2 = c2->sig;
		}
		y+= 20;
		x = 100;
		c1 = c1->sig;

	}
}