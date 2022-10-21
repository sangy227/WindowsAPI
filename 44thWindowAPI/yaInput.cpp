#include "yaInput.h"
namespace ya {
	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
	};				  
	std::vector<Input::key> Input::mKeys;

	void Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			key key;
			key.keyCode = (eKeyCode)i;
			key.state = eKeyState::NONE;
			key.bPressed = false;

			mKeys.push_back(key);
		}
	}
	void Input::Tick()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::End; i++)
		{
			//�ش�Ű�� ���� ������ �ִ°��
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				//���� �����ӿ� ������ �־���.
				if (mKeys[i].bPressed)
				{
					mKeys[i].state = eKeyState::PRESSED;
				}
				else
				{
					mKeys[i].state = eKeyState::DOWN;
				}
				mKeys[i].bPressed = true;
			}
			//������ ���� ���� ���
			else
			{
				if (mKeys[i].bPressed)
				{
					mKeys[i].state = eKeyState::UP;
				}
				else
				{
					mKeys[i].state = eKeyState::NONE;
				}
				mKeys[i].bPressed = false;

			}
		}
	}
	void Input::Render(HDC hdc)
	{
	}

	eKeyState Input::GetkeyState(eKeyCode keycode) {
		return mKeys[(UINT)keycode].state;
	}
}
