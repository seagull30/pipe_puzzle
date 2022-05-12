#pragma once
#include "Random.h"
#include "common.h"
#include "Type.h"
// 내가 짜본것
/*
void Random_Init()
{
	srand((unsigned)time(NULL));
	return true;
}

int32 Random_GetNumberFromRange(int32 minInclusive, int32 maxExclusive)
{
	int64 randsum = 1;

	do
	{
		randsum *= rand();
	} while (randsum < maxExclusive);
	return randsum % (uint32)(maxExclusive - minInclusive) + minInclusive;

}

float Random_GetFNumberFromRange(float minInclusive, float maxInclusive)
{
	int64 randsum = 1;
	
	int32 maxNum = maxInclusive * 1000000;
	int32 minNum = minInclusive * 1000000;
	do
	{
		randsum *= rand();
	} while (randsum < maxNum);

	return (float)(randsum % (uint32)(maxNum - minNum) + minNum) / 1000000;

}
*/


void Random_Init(void)
{
	srand(time(NULL));
}

int32 Random_GetNumberFromRange(int32 minInclusive, int32 maxExclusive)
{
	int32 range = maxExclusive - minInclusive;
	int32 count = 1 + range / RAND_MAX;

	int32 result = 0;
	for (int32 i = 0; i < count; ++i)
	{
		result += rand() % range;
	}
	result += minInclusive;

	return result;
}

float Random_GetFNumberFromRange(float minInclusive, float maxInclusive)
{
	float normalizedRandom = rand() / (float)RAND_MAX;
	float range = maxInclusive - minInclusive;
	float result = minInclusive + normalizedRandom * range;

	return result;
}
