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
	// 비례식
	// 프레임 : 시간
	// 1 : deltaTime = fps : 1
	// 1 = deltaTime * fps 
	// fps = 1 /deltaTime
	count += DELTA_TIME;
	if (count > 0.5 && count < 1)
	{
		char str[128] = "";
		sprintf_s(str, sizeof(str), "현재 FPS : %d", (int32)(1 / Timer_GetDeltaTime()));
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