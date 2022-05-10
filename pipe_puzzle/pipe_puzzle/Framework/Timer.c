#include "common.h"
#include "Timer.h"

clock_t s_prevTick;
float s_deltaTime;
float s_fixedTime;
void   Timer_Init(int32 fps)
{
	// ���� �ð��� ����Ѵ�.
	s_fixedTime = 1.0 / fps;
	// ������ �ϳ� ����ش�.
	s_prevTick = clock();
}

void   Timer_Update(void)
{
	// 1. ���� ������ ���Ѵ�.,
	clock_t currentTick = clock();

	// 2. ���� ������ ���� ������ ���̸� ���� �帥 �ð��� ���Ѵ�.
	float deltatime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC;
	
	// 3. ���� ���������κ��� �ð��� �� ������ �ʾҴٸ�
	if (deltatime < s_fixedTime)
	{
		return false;
	}


	// 4. ������ ������Ʈ�Ѵ�.		
	s_deltaTime = deltatime;
	s_prevTick = currentTick;
	return true;
}

float   Timer_GetDeltaTime(void)
{
	return s_deltaTime;
}