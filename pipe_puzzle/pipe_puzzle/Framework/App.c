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
	// game loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
	while (true)
	{
		processInput(); // �Է� ó��
		undate(); // ���� ������Ʈ
		render(); //���� ���
	}
	return 0;
}