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

	// game loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
	while (true)
	{
		processInput(); // 입력 처리
		undate(); // 게임 업데이트
		render(); //게임 출력
	}
	return 0;
}