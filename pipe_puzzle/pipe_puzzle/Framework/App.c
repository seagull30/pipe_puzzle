#include "App.h"
#include "common.h"
#include "Renderer.h"
#include "timer.h"
#include "Input.h"
#include "Random.h"
#include "text.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}
	Random_Init();
	
	return true;
}

void processInput()
{
	Input_Update();
}


Text text[128];
void undate()
{
	//TextCopyWithWhite(text, L"�츮���� ������ �������̴�");
	TextCopy(text, L"�츮���� ������ �������̴�",TEXT_COLOR_BLACK);
	for (int32 i = 9; text[i].Char.UnicodeChar != L'\0'; ++i)
	{
		text[i].Attributes = BACK_COLOR_RED | TEXT_COLOR_WHITE | TEXT_COLOR_STRONG;

	}
	


}


void render()
{
	Renderer_DrawText(text, TextLen(text),10,10);
	
	Renderer_Flip();
}

void cleanup(void)
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);

	Timer_Init(60);

	const int32 FIXED_FPS = 60;
	const float FIXED_TIME = 1.0f / FIXED_FPS;
	
	// game loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
	while (true)
	{
		if (Timer_Update()) //deltatime : ������ ���� �ð�. ���� ���������κ��� ���� �������� ������ ������ �ɸ� �ð�
		{
		processInput(); // �Է� ó��
		undate(); // ���� ������Ʈ
		render(); //���� ���

		} 
	}
	return 0;
}