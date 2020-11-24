/**************************************************************
*Nombre; Nestor Javier Mendez Gutierres
*Fecha: 31 Agosto de 2017
*proyecto: PreExamen Pizarron
*Funcionalidad: Imita la funcion de un pizarron en el area cliente
*Metodos: 
*Handles:
*Mensages:
*Tipo:
*ESTRUCTURAS:

**************************************************************/

#include "stdafx.h"
#include "resource.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
int figura = 0;
int brushStyle = HS_BDIAGONAL;
int penWidth = 1;
COLORREF colorPluma = RGB(0,0,0);




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
	LoadString(hInstance, IDC_PREEX_TIPICO_PIZARRON, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_PREEX_TIPICO_PIZARRON);

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

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_PREEX_TIPICO_PIZARRON);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= CreateSolidBrush( RGB(53,104, 45) );
	wcex.lpszMenuName	= (LPCSTR)IDC_PREEX_TIPICO_PIZARRON;
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
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
	RECT rt;
	static int xPos1, yPos1, xPos2, yPos2;
	static bool band = FALSE;
	static bool bandFinal = FALSE;
	HPEN penNew, penOld;
	int iPenw = 30;
			
	GetClientRect(hWnd, &rt);
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
				//Color Pluma
				case IDM_RED_P:
					if(penWidth != 32)
						colorPluma = RGB(205, 0, 0);
				break;
				case IDM_WHITE_P:
					if(penWidth != 32)
						colorPluma = RGB(255, 255, 255);
				break;
				//Borrador
				case IDM_ERASER:
					colorPluma = RGB(53, 104, 45);
					penWidth = 32;
				break;
				//pen
				case IDM_PEN:
					colorPluma = RGB(255, 255, 255);
					penWidth = 1;
				break;
				//ancho de pluma
				case IDM_P1:
					if(penWidth != 32)
						penWidth = 1;
				break;
				case IDM_P2:
					if(penWidth != 32)
						penWidth = 2;
				break;
				case IDM_P3:
					if(penWidth != 32)
						penWidth = 3;
				break;
				case IDM_P4:
					if(penWidth != 32)
						penWidth = 4;
				break;
				case IDM_P5:
					if(penWidth != 32)
						penWidth = 5;
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
				SetROP2(hdc, R2_COPYPEN);
				penNew = CreatePen(PS_SOLID, penWidth, colorPluma);//Pinta
				penOld = (HPEN)SelectObject(hdc, penNew);
				MoveToEx(hdc, xPos1, yPos1, NULL);
				LineTo(hdc, xPos2, yPos2);
				LineTo(hdc, xPos2, yPos2);
				xPos1 = xPos2;
				yPos1 = yPos2;
				SelectObject(hdc, penOld);
				Sleep(20);
				penOld = (HPEN)SelectObject(hdc, penNew);
				SelectObject(hdc, penOld);
				if(penWidth == 32)
				{
					Ellipse(hdc, xPos1-15, yPos1-15, xPos1+15, yPos1+15);
					Sleep(65);
					penNew = CreatePen(PS_SOLID, penWidth, colorPluma);//Pinta
					penOld = (HPEN)SelectObject(hdc, penNew);
					MoveToEx(hdc, xPos1, yPos1, NULL);
					LineTo(hdc, xPos2, yPos2);
					LineTo(hdc, xPos2, yPos2);
				}
			}
			else//Pinta por ultima vez
			{
				if(bandFinal)
				{
					penNew = CreatePen(PS_SOLID, penWidth, colorPluma);//Pinta
					penOld = (HPEN)SelectObject(hdc, penNew);
					SelectObject(hdc, penOld);
				}
			bandFinal = FALSE;
		}
		EndPaint(hWnd, &ps);
		break;
		case WM_LBUTTONDOWN:
			xPos1 = LOWORD(lParam);  // horizontal position of cursor 
			yPos1 = HIWORD(lParam);  // vertical position of cursor 
			//band = TRUE;
			//InvalidateRect(hWnd, &rt, FALSE);//Clear Device
		break;
		case WM_MOUSEMOVE:
			if(MK_LBUTTON && wParam)
			{
				xPos2 = LOWORD(lParam);  // horizontal position of cursor 
				yPos2 = HIWORD(lParam);  // vertical position of cursor 
				band = TRUE;
				InvalidateRect(hWnd, &rt, FALSE);//Clear Device
			}
		break;
		case WM_LBUTTONUP:
			xPos2 = LOWORD(lParam);  // horizontal position of cursor 
			yPos2 = HIWORD(lParam);  // vertical position of cursor 
			band = FALSE;
			bandFinal = TRUE;
			InvalidateRect(hWnd, &rt, FALSE);//Clear Device
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
