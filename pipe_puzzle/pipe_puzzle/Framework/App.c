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
	//TextCopyWithWhite(text, L"우리반의 존잘은 안재현이다");
	TextCopy(text, L"우리반의 존잘은 안재현이다",TEXT_COLOR_BLACK);
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