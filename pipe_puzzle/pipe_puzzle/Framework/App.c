#include "App.h"
#include "common.h"
#include "Renderer.h"
#include "timer.h"

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

}

float count = 0;
void undate()
{
	// ��ʽ�
	// ������ : �ð�
	// 1 : deltaTime = fps : 1
	// 1 = deltaTime * fps 
	// fps = 1 /deltaTime
	count += DELTA_TIME;
	if (count > 0.5 && count < 1)
	{
		char str[128] = "";
		sprintf_s(str, sizeof(str), "���� FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
		Renderer_DrawText(str, strlen(str));
	}
	else if (count > 1)
		count = 0;

	
}


void render()
{
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