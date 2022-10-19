//// 44thWindowAPI.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
////
//
//#include "framework.h"
//#include "44thWindowAPI.h"
//
//#define MAX_LOADSTRING 100
//
//// ���� ����:
//HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
//WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
//WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
//
//// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ �����մϴ�:
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
//
//
////int main() {}
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//    _In_opt_ HINSTANCE hPrevInstance,
//    _In_ LPWSTR    lpCmdLine,
//    _In_ int       nCmdShow)
//{
//    UNREFERENCED_PARAMETER(hPrevInstance);
//    UNREFERENCED_PARAMETER(lpCmdLine);
//
//    // TODO: ���⿡ �ڵ带 �Է��մϴ�.
//
//    //���� ����
//
//    //1.wndcalss ���� ������ ���(�������� �Ӽ�)�� �Ǵ� Ŭ���� �������ش�.
//    // 
//    //2.�޸𸮻� ������ �Ҵ� CreateWindow
//
//    //3. showwindow �Լ��� ���ؼ� �����찡 ȭ�鿡 ��������.(update window)
//
//    //4. wndclass  �����Ҷ� �Լ������Ϳ� �־��� loop (wndproc)�� �����Ӹ��� �����Ѵ�
//
//    // ��������� ũ�� 3���� ���̺귯�� �̷�����ִµ�.
//    // �޸𸮸� �����ϰ� �����Ű�� KERNEL Ŀ��
//    // ���� �������̽��� �����ϴ� USER
//    // ȭ��ó���� �׷����� ����ϴ� GDI�� �̷�����ִ�.
//
//
//
//    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
//    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
//    LoadStringW(hInstance, IDC_MY44THWINDOWAPI, szWindowClass, MAX_LOADSTRING);
//    MyRegisterClass(hInstance);
//
//    // ���ø����̼� �ʱ�ȭ�� �����մϴ�:
//    if (!InitInstance(hInstance, nCmdShow))
//    {
//        return FALSE;
//    }
//
//    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY44THWINDOWAPI));
//
//    MSG msg;
//
//    // �⺻ �޽��� �����Դϴ�:
//    while (GetMessage(&msg, nullptr, 0, 0))
//    {
//        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//        {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//    }
//
//    return (int)msg.wParam;
//}
//
//
//
////
////  �Լ�: MyRegisterClass()
////
////  �뵵: â Ŭ������ ����մϴ�.
////
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//    WNDCLASSEXW wcex;
//
//    //������ �⺻ ����
//    wcex.cbSize = sizeof(WNDCLASSEX);
//
//    wcex.style = CS_HREDRAW | CS_VREDRAW;
//    wcex.lpfnWndProc = WndProc;
//    wcex.cbClsExtra = 0;
//    wcex.cbWndExtra = 0;
//    wcex.hInstance = hInstance;
//    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY44THWINDOWAPI));
//    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY44THWINDOWAPI);
//    wcex.lpszClassName = szWindowClass;
//    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//    return RegisterClassExW(&wcex);
//}
//
////
////   �Լ�: InitInstance(HINSTANCE, int)
////
////   �뵵: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
////
////   �ּ�:
////
////        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
////        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
////
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.
//
//    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//    if (!hWnd)
//    {
//        return FALSE;
//    }
//
//    SetWindowPos(hWnd, nullptr, 0, 0, 1920, 1080, 0);
//    ShowWindow(hWnd, nCmdShow);
//    UpdateWindow(hWnd);
//
//    return TRUE;
//}
//
////
//// //������ �κ��Դϴ�
//// 
//// 
////  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
////
////  �뵵: �� â�� �޽����� ó���մϴ�.
////
////  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
////  WM_PAINT    - �� â�� �׸��ϴ�.
////  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
////
////
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    switch (message)
//    {
//    case WM_CREATE:
//    {
//
//    }
//    case WM_COMMAND:
//    {
//        int wmId = LOWORD(wParam);
//        // �޴� ������ ���� �м��մϴ�:
//        switch (wmId)
//        {
//        case IDM_ABOUT:
//            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//            break;
//        case IDM_EXIT:
//            DestroyWindow(hWnd);
//            break;
//        default:
//            return DefWindowProc(hWnd, message, wParam, lParam);
//        }
//    }
//    break;
//    case WM_PAINT:
//    {
//        PAINTSTRUCT ps;
//        HDC hdc = BeginPaint(hWnd, &ps);
//
//
//
//        HBRUSH hClearBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
//        HBRUSH oldClearBrush = (HBRUSH)SelectObject(hdc, hClearBrush);
//
//        Rectangle(hdc, -1, -1, 1921, 1081);
//
//        HPEN hRedPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
//
//        HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 100, 0));
//
//        HPEN oldPen = (HPEN)SelectObject(hdc, hRedPen);
//        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hGreenBrush);
//
//        Rectangle(hdc, 100, 100, 200, 200);
//        Ellipse(hdc, 200, 200, 300, 300);
//
//        //���� ������Ʈ
//
//
//
//        SelectObject(hdc, oldPen);
//        SelectObject(hdc, oldBrush);
//
//        DeleteObject(hRedPen);
//        DeleteObject(hGreenBrush);
//
//
//
//
//        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
//        EndPaint(hWnd, &ps);
//
//        //����
//        //HFONT
//
//        //�׸�����
//        //HBITMAP
//
//        //DC ����
//
//        // 1.PEN BRUSH �ڵ��� �����Ѵ�.
//        // 2.GDI ������Ʈ�� �������ش�.
//        // 3.������ ������Ʈ�� hdc ��������� �Ѵ�, selectobject
//        //����ϰ� �����ϴ¹�
//
//        //������ ������Ʈ�� �ǵ����� (����)
//        //�ڵ��� �����Ѵ�.
//    }
//    break;
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}
//
//// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}
