#include "App.h"
#include "common.h"

bool App_Init()
{
	return true;
}

void processInput()
{

}

void undate()
{

}

void render()
{
	system("cls");
	puts("hello Game");
}

int32 App_Run()
{
	// game loop : 게임을 동작시키는 루프. 프레임(Frame)이라고 한다.
	while (true)
	{
		processInput(); // 입력 처리
		undate(); // 게임 업데이트
		render(); //게임 출력
	}
	return 0;
}