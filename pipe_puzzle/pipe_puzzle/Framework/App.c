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
	sprintf_s(str, sizeof(str), "현재 입력 없음");

	if (Input_GetKey(VK_UP))
	{
		sprintf_s(str, sizeof(str), "위쪽 화살표 눌림");
	}

	if (Input_GetKey(VK_DOWN))
	{
		sprintf_s(str, sizeof(str), "아래쪽 화살표 눌림");
	}

	if (Input_GetKey(VK_LEFT) && Input_GetKey(VK_RIGHT))
	{
		sprintf_s(str, sizeof(str), "왼쪽, 오른쪽 화살표 동시 눌림");
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
	
	// game loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
	while (true)
	{
		if (Timer_Update()) //deltatime : 프레임 간의 시간. 이전 프레임으로부터 현재 프레임을 시작할 때까지 걸린 시간
		{
		processInput(); // 입력 처리
		undate(); // 게임 업데이트
		render(); //게임 출력

		} 
	}
	return 0;
}