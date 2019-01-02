// serial.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "serial.h"
#include "../../VersionNum"

#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <WindowsX.h>

typedef unsigned char uint8_t;

#ifndef NOF_ELEMENTS
#define NOF_ELEMENTS(x) (sizeof(x)/sizeof(*(x)))
#endif

#define MAX_LOADSTRING 100

TCHAR portName[32];

static uint8_t key_map[] = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x1E, 0x26, 0xFF, 0xFF, 0xFF, 0x47, 0xFF, 0xFF,
  0x4C, 0x3B, 0x5E, 0x0F, 0x5D, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
  0x5F, 0x21, 0x36, 0x35, 0x20, 0x62, 0x59, 0x64,
  0x63, 0xFF, 0x0D, 0xFF, 0x0D, 0x1F, 0x34, 0xFF,
  0x1A, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
  0x18, 0x19, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  // 0x40
  0xFF, 0x3C, 0x52, 0x50, 0x3E, 0x29, 0x3F, 0x40,
  0x41, 0x2E, 0x42, 0x43, 0x44, 0x54, 0x53, 0x2F,
  0x30, 0x27, 0x2A, 0x3D, 0x2B, 0x2D, 0x51, 0x28,
  0x4F, 0x2C, 0x4E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x65, 0x5A, 0x5B, 0x5C, 0x48, 0x49, 0x4A, 0x37,
  0x38, 0x39, 0x24, 0x4B, 0xFF, 0x3A, 0x66, 0x23,
  0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
  0x09, 0x0A, 0x0B, 0x0C, 0xFF, 0xFF, 0xFF, 0xFF,
  // 0x80
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x22, 0x0E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x4C, 0x58, 0x3B, 0x61, 0x71, 0x71, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0x45, 0x1C, 0x55, 0x1B, 0x56, 0xFF
  // 0xC0
};

// Global Variables:
HINSTANCE hInst;								// current instance
HANDLE hPort;
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

static int log_printf(const char *fmt, ...)
{
   char buf[256];
   va_list ap;
   size_t len;
   FILE *out;
   va_start(ap, fmt);
   len = vsprintf(buf, fmt, ap);
   out = fopen("\\out.txt", "a");
   if (out)
   {
     fwrite(buf, 1, len, out);
     fclose(out);
   }
   va_end(ap);
   return len;
}

static const char *term_string(const char *msg, size_t len)
{
   static char buf[256];
   memcpy(buf, msg, len);
   buf[len] = '\0';
   return buf;
}

/*void Receive(void)
{
  BOOK ok;
  ok = ReadFile(hPort, buf, );
}*/

void Transmit(const char *msg, size_t len)
{
   DWORD written;
   BOOL ok;
   ok = WriteFile(hPort, msg, (DWORD)len, &written, NULL);
   if (!ok) {
      DWORD err = GetLastError();
      printf("err code %X\n", err);
   }
   assert(ok);
   log_printf("Requested %d, wrote %d '%s'\n", sizeof(msg)-1, written, term_string(msg, len));
}

void TransmitMsg(const char *msg)
{
   Transmit(msg, strlen(msg));
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

   _tcscpy(portName, lpCmdLine);
   if (portName[0]!=L'C') _tcscpy(portName, TEXT("COM4"));

MessageBox(NULL, portName, TEXT("Port name"), MB_OK);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SERIAL, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SERIAL));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

   CloseHandle(hPort);

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
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
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SERIAL));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SERIAL);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
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
   const char msg[] = "D60\nU60\nK41\nD79\n";
   TCHAR port[32];
   DCB dcb;
   BOOL ok;
   port[0] = L'\\'; port[1] = L'\\'; port[2] = L'.'; port[3] = L'\\';
   _tcscpy(port+4, portName);
   hPort = CreateFile(port,
      GENERIC_READ|GENERIC_WRITE,
      0,
      NULL,
      OPEN_EXISTING,
      FILE_ATTRIBUTE_NORMAL,
      NULL);
   assert(hPort != INVALID_HANDLE_VALUE);

   ok = GetCommState(hPort, &dcb);
   assert(ok);

//   printf("Reconfiguring from %d,%d,%d\n",
//      dcb.BaudRate, dcb.ByteSize, dcb.StopBits);

   dcb.BaudRate = 115200;
   dcb.ByteSize = 8;
   dcb.StopBits = 0;
   dcb.Parity = 0;
   dcb.fParity = FALSE;
   dcb.fOutxCtsFlow = FALSE;
   dcb.fOutxDsrFlow = FALSE;
   dcb.fDtrControl = FALSE;
   dcb.fDsrSensitivity = FALSE;
   dcb.fTXContinueOnXoff = TRUE;
   dcb.fOutX = FALSE;
   dcb.fInX = FALSE;
   dcb.fRtsControl = RTS_CONTROL_DISABLE;
   dcb.fAbortOnError = FALSE;

   ok = SetCommState(hPort, &dcb);
   assert(ok);

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
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
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
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
   case WM_KEYDOWN:
   case WM_KEYUP:
   log_printf("Key %s %d\n", (message == WM_KEYDOWN) ? "down" : "up", wParam);
      if (wParam < NOF_ELEMENTS(key_map)) {
         uint8_t kn = key_map[wParam];
         if (kn != 0xFF) {
            char buf[16];
            size_t len = sprintf(buf, "%c%d\n", (message == WM_KEYUP) ? 'U' : 'D', kn);
            Transmit(buf, len);
            return 1;
         }
      }
      break;
   case WM_MOUSEMOVE: {
         static clock_t last_time;
         static int first = 1;
         clock_t t = clock();
         if (first || (t - last_time) >= CLOCKS_PER_SEC/50) {
            int x = GET_X_LPARAM(lParam), y = GET_Y_LPARAM(lParam);
            char buf[16];
            x = x*2; y = 1078-y*2;
            if (x < 0) x = 0; else if (x >= 1920) x = 1920;
            if (y < 0) y = 0;  else if (y >= 1080) y = 1080;
            size_t len = sprintf(buf, "M%d,%d\n", x, y);
            Transmit(buf, len);
            last_time = t;
         }
         first = 0;
      }
      break;
   case WM_LBUTTONDOWN: TransmitMsg("D112\n"); break;
   case WM_MBUTTONDOWN: TransmitMsg("D113\n"); break;
   case WM_RBUTTONDOWN: TransmitMsg("D114\n"); break;
   case WM_LBUTTONUP:   TransmitMsg("U112\n"); break;
   case WM_MBUTTONUP:   TransmitMsg("U113\n"); break;
   case WM_RBUTTONUP:   TransmitMsg("U114\n"); break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		SetDlgItemText(hDlg, IDC_VERSIONNUM, _T(Module_ComponentName) _T(" ") _T(Module_FullVersion) _T(" (") _T(Module_ApplicationDate) _T(")"));
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
