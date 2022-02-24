// Bai1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Bai1.h"

#define MAX_LOADSTRING 100
#define ID_LB_LEFT 1
#define ID_LB_RIGHT 2
#define ID_BTN_L 3
#define ID_BTN_LL 4
#define ID_BTN_R 5
#define ID_BTN_RR 6
#define ID_EXIT 7



// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND txtLeftList, txtRightList, btnL, btnLL, btnR, btnRR, btnExit, staticText;
HMENU Reg, Main;
HWND Register;
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_BAI1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BAI1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BAI1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
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
   hInst = hInstance; // Store instance handle in our global variable
   Main = LoadMenu(hInstance, MAKEINTRESOURCE(IDC_BAI1));
   Reg = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU2));
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, Main, hInstance, nullptr);
   

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
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR Name[][30] = { TEXT("Van Phong"), TEXT("Access") ,TEXT("Pascal") ,TEXT("Foxoro"), TEXT("Mang"), TEXT("CTMT") }, item[50];
    static int index, count;
    static HINSTANCE hInstance;
    switch (message)
    {
    case WM_CREATE:
        hInstance = (HINSTANCE)::GetWindowLong(hWnd, GWL_HINSTANCE);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_MENU_REG:
                
                Register = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
                    CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, Reg, hInstance, nullptr);

                ShowWindow(Register, SW_SHOW);
                staticText = CreateWindow(TEXT("static"), TEXT("Chọn môn học"), WS_CHILD | WS_VISIBLE, 520, 10, 100, 20, Register, NULL, NULL, NULL);
                txtLeftList = CreateWindow(TEXT("listbox"), TEXT(""), WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_BORDER, 10, 50, 500, 400, Register, (HMENU)ID_LB_LEFT, NULL, NULL);
                txtRightList = CreateWindow(TEXT("listbox"), TEXT(""), WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_BORDER, 620, 50, 500, 400, Register, (HMENU)ID_LB_RIGHT, NULL, NULL);
                btnL = CreateWindow(TEXT("button"), TEXT(">"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 550, 50, 30, 30, Register, (HMENU)ID_BTN_L, NULL, NULL);
                btnLL = CreateWindow(TEXT("button"), TEXT(">>"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 550, 100, 30, 30, Register, (HMENU)ID_BTN_LL, NULL, NULL);
                btnRR = CreateWindow(TEXT("button"), TEXT("<"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 550, 150, 30, 30, Register, (HMENU)ID_BTN_R, NULL, NULL);
                btnRR = CreateWindow(TEXT("button"), TEXT("<<"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 550, 200, 30, 30, Register, (HMENU)ID_BTN_RR, NULL, NULL);
                btnExit = CreateWindow(TEXT("button"), TEXT("Kết Thúc"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 520, 450, 100, 30, Register, (HMENU)ID_EXIT, NULL, NULL);
                for (int i = 0; i < 6; i++)
                    SendMessage(txtLeftList, LB_INSERTSTRING, -1, (LPARAM)Name[i]);
                SendMessage(txtRightList, LB_INSERTSTRING, -1, (LPARAM)TEXT("Visual Basic"));
                break;
            case ID_BTN_L:
                index = SendMessage(txtLeftList, LB_GETCURSEL, 0, 0);
                if (index < 0) {
                    MessageBox(NULL, TEXT("Bạn chưa chọn phần tử!"), TEXT("Thông báo!"), MB_OK | MB_ICONERROR);
                }
                else {
                    SendMessage(txtLeftList, LB_GETTEXT, index, (LPARAM)item);
                    SendMessage(txtRightList, LB_INSERTSTRING, -1, (LPARAM)item);
                    SendMessage(txtLeftList, LB_DELETESTRING, index, 0);
                }
                break;
            case ID_BTN_LL:
                count = SendMessage(txtLeftList, LB_GETCOUNT, 0, 0);
                for (int i = 0; i < count; i++) {
                    SendMessage(txtLeftList, LB_GETTEXT, i, (LPARAM)item);
                    SendMessage(txtLeftList, LB_DELETESTRING, i, 0);
                    SendMessage(txtRightList, LB_INSERTSTRING, -1, (LPARAM)item); 
                    count--;
                    i--;
                }
                break;
            case ID_BTN_R:
                index = SendMessage(txtRightList, LB_GETCURSEL, 0, 0);
                if (index < 0) {
                    MessageBox(NULL, TEXT("Bạn chưa chọn phần tử!"), TEXT("Thông báo!"), MB_OK | MB_ICONERROR);
                }
                else {
                    SendMessage(txtRightList, LB_GETTEXT, index, (LPARAM)item);
                    SendMessage(txtLeftList, LB_INSERTSTRING, -1, (LPARAM)item);
                    SendMessage(txtRightList, LB_DELETESTRING, index, 0);
                }
                break;
            case ID_BTN_RR:
                count = SendMessage(txtRightList, LB_GETCOUNT, 0, 0);
                for (int i = 0; i < count; i++) {
                    SendMessage(txtRightList, LB_GETTEXT, i, (LPARAM)item);
                    SendMessage(txtLeftList, LB_INSERTSTRING, -1, (LPARAM)item);
                    SendMessage(txtRightList, LB_DELETESTRING, i, 0);
                    count--;
                    i--;
                }
                break;
            case ID_EXIT:
                CloseWindow(Register);
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
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
