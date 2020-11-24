/**************************************************************
*Nombre: Nestor Javier Mendez Gutierres
*Fecha: 25 Septiembre 2017
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
#include "Combo_Decenas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text
NP *grafo;
BOOL band = FALSE;
HDC hdc;


// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void Ini();
NP* CreaNodoNP(char n);
NR* CreaNodoNR(int n);
void Crea_Lista(NP* f);

void InsertaColaNP(NP *c2, NP* np);
void InsertaColaNR(NR *c3, NR* nr);
void Imprime_Grafo(HDC hdc);

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
	LoadString(hInstance, IDC_COMBO_DECENAS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_COMBO_DECENAS);

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
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_COMBO_DECENAS);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_COMBO_DECENAS;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
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

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
	RECT rt;
	//int numeros, i;
	static char name = 'A';
	int x = 100, y = 100;
	NP* c1, *c2, *np;//*_np;
	NR *nr, *c3;


	GetClientRect(hWnd, &rt);
	switch (message) 
	{
		case WM_CREATE:
		break;
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				break;
				case IDM_LL:
					Ini();
					//Crea A y sus Relaciones
					np = CreaNodoNP(name);
					c1 = c2 = np;//Tambien c2
					nr = CreaNodoNR(5);
					np->abajo = nr;//La primer Relacion de A
					nr->arriba = np;
					InsertaColaNP(c2, np);
					//Crear B y ligarlo a A
					name++;
					c3 = nr;
					np = CreaNodoNP(name);
					nr = CreaNodoNR(10);
					nr->arriba = np;
					InsertaColaNR(c3, nr);
					c2->sig = np;
					c2 = np;
					//Crear c y ligarlo a b
					name++;
					c3 = nr;
					np = CreaNodoNP(name);
					nr = CreaNodoNR(20);
					nr->arriba = np;
					InsertaColaNR(c3, nr);
					c2->sig = np;
					c2 = np;
					//Crea relaciones de B: Regresa c2(A) y avanza c1 C(B)
					c2 = grafo;
					c1 = c1->sig;
					nr = CreaNodoNR(30);
					c2 = c2->sig;//Avanza c2 hacia B y
					c2 = c2->sig;// despues a c por que es la unica relacion de B
					nr->arriba = c2; // nodo c
					c1->abajo = nr;//La primer Relacion de B
					//Crea relaciones de C: avanza c1(C) y regreza c2(A)
					c2 = grafo;
					c1 = c1->sig;
					nr = CreaNodoNR(40);
					c2 = c2->sig;//(B)
					nr->arriba = c2;
					c1->abajo = nr;//La primer Relacion de B
					band = TRUE;
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
			if(band)
			{
				Imprime_Grafo(hdc);
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
	grafo = NULL;
}

NP* CreaNodoNP(char n)
{
	NP* nodo = new NP;

	nodo->nombre = n;
	nodo->abajo = NULL;
	nodo->sig = NULL;

	return nodo;
}

NR* CreaNodoNR(int n)
{
	NR* nodo = new NR;

	nodo->num = n;
	nodo->sig = NULL;
	nodo->arriba = NULL;

	return nodo;

}

void InsertaColaNP(NP *c2, NP* np)
{
	if(!grafo)
	{
		grafo = np;
	}
	else
	{
		c2->sig = np;
		
	}
}

void InsertaColaNR(NR *c3, NR* nr)
{
	c3->sig = nr;
}

void Imprime_Grafo(HDC hdc)
{
	NP *c2;
	NR *c3;
	int x = 100, y = 100, n = 100;
	//char cad1[3] = {'\0'};
	int tam1, tam2;

	c2 = grafo;
	while(c2)
	{
		char cad[5] = {'\0'}, cad1[3] = {'\0'};
		cad[0] = (char)c2->nombre;
		strcat(cad, ": ");
		tam1 = strlen(cad);
		x = x+tam1*10;
		TextOut(hdc, x, y, cad, tam1);
		c3 = c2->abajo;
		while(c3)
		{
			itoa (c3->num, cad, 10);
			strcat(cad, "_");
			cad1[0] =+ (char)c3->arriba->nombre;
			strcat(cad, cad1);

			strcat(cad, "->");
			tam2 = strlen(cad);
			x = x+tam1*15;
			TextOut(hdc, x, y, cad, tam2);

			c3 = c3->sig;
		}
		x = x+tam1*15;
		TextOut(hdc, x, y, "NULL", tam2);
		y+=20;
		x=100;
		c2 = c2->sig;
	}
	TextOut(hdc, x, y, "NULL", tam2);
}
