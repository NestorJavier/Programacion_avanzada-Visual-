/**************************************************************
*Nombre; Nestor Javier Mendez Gutierres
*Fecha:  Agosto 2017
*proyecto: Coordenadas mouse
*Funcionalidad: Obtiene las coordenadas del cursor y las imprime en el area cliente
*Metodos: InvalidateRect
*Handles:
*Mensages: 
*Tipo: 
*ESTRUCTURAS: 

**************************************************************/


#include <windows.h>
#include <string.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance;
char szProgName[] = "Mi Programa";
char szProgMenu[] = "Mimenu";
BOOL band = FALSE;
int xPos, yPos;


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
					"Programa Cascaron aplicacion Win32(SDK)", 
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
	char cad1[3], cad2[3];
	
	char cad3[] = "xPos = ";
	char cad4[] = "yPos = ";
	char cadf[20];
	int ilen;

	GetClientRect(hWnd, &rt);
	switch(messg)
	{
		case WM_PAINT:
			if(band)
			{
				hdc = BeginPaint(hWnd, &ps);
				strcpy( cadf, cad3);
				itoa(xPos, cad1, 10);
				strcat( cadf, cad1);
				strcat( cadf, " ");
				strcat( cadf, cad4);
				itoa(yPos, cad2, 10);
				strcat( cadf, cad2);
				ilen = strlen(cadf);
				TextOut(hdc, 100, 200, cadf, ilen);
				EndPaint(hWnd, &ps);
			}
		break;
		case WM_LBUTTONDOWN:
			xPos = LOWORD(lParam);  // horizontal position of cursor 
			yPos = HIWORD(lParam);  // vertical position of cursor 
			band = TRUE;
			InvalidateRect(hWnd, &rt, TRUE);
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
