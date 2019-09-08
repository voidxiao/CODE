#include"ELS.h"

extern int ctrl = 0;//控制回车  按了回车之后置1


LRESULT CALLBACK ELuoSi(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance, LPSTR lpCmdline, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hWnd;
	MSG msg;


	//创建窗口类
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(hinstance, MAKEINTRESOURCE(IDC_NODROP));
	wc.hIcon = LoadIcon(hinstance, MAKEINTRESOURCE(IDI_ICON2));
	wc.hIconSm = LoadIcon(hinstance, MAKEINTRESOURCE(IDI_ICON2));
	wc.hInstance = hinstance;
	wc.lpfnWndProc = ELuoSi;
	wc.lpszClassName = TEXT("els");
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	//注册窗口
	if (0 == RegisterClassEx(&wc))
	{
		return 0;
	}

	//创建窗口
	hWnd = CreateWindowEx(WS_EX_TOPMOST, TEXT("els"), TEXT("和平方块"), WS_SYSMENU | WS_MINIMIZEBOX, 515, 20, 520, 777, NULL, NULL, hinstance, NULL);
	if (NULL == hWnd)
	{
		return 0;
	}

	//显示窗口  正常显示返回1  隐藏显示返回0
	ShowWindow(hWnd, SW_SHOWNORMAL);

	//消息循环
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//翻译消息

		DispatchMessage(&msg); //分发消息
	}


	return 0;
}

//消息回调
LRESULT CALLBACK ELuoSi(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT lpPaint;
	HDC hDc;
	switch (Msg)
	{
	case WM_CREATE:
		connectServer(hWnd);
		OnCreate();
		break;

	//按键消息
	case WM_KEYDOWN:
		switch (wParam)
		{
			case VK_RETURN:
				if (0 == ctrl)
				{
					OnReturn(hWnd);
					ctrl = 1;
				}
				break;
			case VK_UP:
				if (ctrl == 1)
				{
					ChangeSquare(hWnd);
				}
				break;
			case VK_DOWN:
				if (ctrl == 1)
				{
					OnDown(hWnd);
				}
				break;
			case VK_LEFT:
				if (ctrl == 1)
				{
					OnLeft(hWnd);
				}
				/*if (1 == CanMoveLeft())
				{
					MoveLeft();
				}*/
				break;
			case VK_RIGHT:
				if (ctrl == 1)
				{
					OnRight(hWnd);
				}
				break;
		}
		break;

	case WM_TIMER:
		OnTimer(hWnd);
		break;

	case WM_PAINT:
		hDc = BeginPaint(hWnd, &lpPaint);

		OnPaint(hDc);


		EndPaint(hWnd, &lpPaint);
		break;

	case WM_DESTROY:
		KillTimer(hWnd, TIMER1);
		freeNetwork();
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}
