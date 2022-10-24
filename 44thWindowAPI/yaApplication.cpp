#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaTime.h"
#include "yaInput.h"
namespace ya {
	//Application Application::mInstance;

	void Application::Initialize(WindowData data)
	{
		InitializeWindow(data);
		

		

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Application::Tick()
	{
		Time::Tick();
		Input::Tick();

		//clear
		Rectangle(mWindowData.backBuffer, -1, -1, 
			mWindowData.width + 1, mWindowData.height + 1);

		SceneManager::Tick();
		SceneManager::Render(mWindowData.backBuffer);

		Time::Render(mWindowData.backBuffer);
		Input::Render(mWindowData.backBuffer);

		//bitbit �Լ��� dc���� �̹����� �������ִ� �Լ�
		BitBlt(mWindowData.hdc, 0, 0, mWindowData.width, mWindowData.height, 
			mWindowData.backBuffer, 0, 0, SRCCOPY);
	}


	Application::Application()
	{
		mWindowData.clear();
	}



	Application::~Application()
	{
		SceneManager::Release();

		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
	}



	void Application::InitializeWindow(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);

		//��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�� ���
		RECT rect = { 0,0,mWindowData.width,mWindowData.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		//������ ũ�� ����
		SetWindowPos(mWindowData.hWnd,
			nullptr, 0, 0,
			rect.right - rect.left,
			rect.bottom - rect.top,
			0);

		//������ �׸��� �����ֱ�
		ShowWindow(mWindowData.hWnd, true);
		mWindowData.backTexture 
			= CreateCompatibleBitmap(mWindowData.hdc, mWindowData.width, mWindowData.height);

		mWindowData.backBuffer
			= CreateCompatibleDC(mWindowData.hdc);

		HBITMAP defaultBitmap 
			= (HBITMAP)SelectObject(mWindowData.backBuffer, mWindowData.backTexture);

		DeleteObject(defaultBitmap);
	}

	
}
