/**************************************************************
*Nombre; Nestor Javier Mendez Gutierres
*Fecha: 17 Agosto 2017
*proyecto: Cascaron
*Funcionalidad: Minima, ventana de la aplicacion.
*Metodos: LoadCursor, GetStockObject, RegisterClass, CreateWindow, ShowWindow, UpdateWindow, GetMessage, TranslateMessage, DispatchMessage, 
GetClientRect, BeginPaint, SetTextColor, TextOut, EndPaint, PostQuitMessage
*Handles: HWND HINSTANCE
*Mensages: WM_PAINT WM_DESTROY
*Tipo: LRESULT, CALLBACK, UNIT, WPARAM, WINAPI, LPSTR, HDC
*Estructuras: MSG, WNDCLASS, PAINTSTRUCT, RECT, RGB.

**************************************************************/


#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance;
char szProgName[] = "Mi Programa";
char szProgMenu[] = "Mimenu";



int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS wcApp;
	
	hInstance = hInst;

	wcApp.lpszClassName = szProgName;
	wcApp.hInstance = hInst;
	wcApp.lpfnWndProc = WndProc;
	wcApp.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcApp.hIcon = 0;
	wcApp.lpszMenuName = szProgMenu;
	wcApp.hbrBackground = GetStockObject(WHITE_BRUSH);
	wcApp.style = CS_HREDRAW|CS_VREDRAW;
	wcApp.cbClsExtra = 0;
	wcApp.cbWndExtra = 0;

	/*Registro de a ventana*/
	if(!RegisterClass(&wcApp))
		return 0;
	/*Creacion de a ventana*/
	hWnd = CreateWindow(szProgName, 
					"Hola Mundo", 
					WS_OVERLAPPEDWINDOW, 
					CW_USEDEFAULT, 
					CW_USEDEFAULT, 
					CW_USEDEFAULT, 
					CW_USEDEFAULT, (HWND)NULL, (HMENU)NULL, (HANDLE)hInst, (LPSTR)NULL);
	
	/*Actualizacion de a ventana*/
	ShowWindow(hWnd, nCmdShow); //SW_MINIMIZE, SW_MAXIMIZE
	UpdateWindow(hWnd);

	/*Ciclo de mensages*/
	while(GetMessage(&lpMsg,0,0,0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return(lpMsg.wParam);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rt;

	GetClientRect(hWnd, &rt);
	switch(messg)
	{
		case WM_PAINT:
				hdc = BeginPaint(hWnd, &ps);
				SetTextColor(hdc, RGB(127,127,127));
				TextOut(hdc, (rt.right/2)-(01/2)*8, rt.bottom/2,"Hola mundo", 10);
				EndPaint(hWnd, &ps);
		break;
		case WM_DESTROY:
				PostQuitMessage(0);
		break;
		default:
			return(DefWindowProc(hWnd, messg, wParam, lParam));
		break;
	}
	return 0;
}
