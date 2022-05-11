#include "App.h"
#include "common.h"
#include "Renderer.h"
#include "timer.h"
#include "Input.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}
	
	return true;
}

void processInput()
{
	Input_Update();
}

char str[128];
void undate()
{
	sprintf_s(str, sizeof(str), "���� �Է� ����");

	if (Input_GetKey(VK_UP))
	{
		sprintf_s(str, sizeof(str), "���� ȭ��ǥ ����");
	}

	if (Input_GetKey(VK_DOWN))
	{
		sprintf_s(str, sizeof(str), "�Ʒ��� ȭ��ǥ ����");
	}

	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT))
	{
		sprintf_s(str, sizeof(str), "����, ������ ȭ��ǥ ���� ����");
	}

}


void render()
{
	Renderer_DrawText(str, strlen(str));
	Renderer_Flip();
}

void cleanup()
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