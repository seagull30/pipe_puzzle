#include "App.h"
#include "common.h"
#include "Renderer.h"

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

void undate()
{
	Renderer_DrawText("hello game", sizeof("hello game"));
}

void render()
{
	Renderer_Flip();
}

void cleanup()
{

}

int32 App_Run()
{
	atexit(cleanup);

	// game loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
	while (true)
	{
		processInput(); // �Է� ó��
		undate(); // ���� ������Ʈ
		render(); //���� ���
	}
	return 0;
}