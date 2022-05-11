#include "Input.h"
#include "Type.h"
#include "common.h"
//���� ¥����
/*
short s_PrevInputKey[2];
short s_CurrentInputKey[2];

// �Էºθ� �ʱ�ȭ�Ѵ�.
bool Input_Init(void)
{
	for (int i = 0; i < 2; i++)
	{
		s_PrevInputKey[i] = 0;
		s_CurrentInputKey[i] = 0;
	}

	return true;
}

// �Էºθ� ������Ʈ�Ѵ�.
// ���� �������� Ű ���� ���� �� ���� �������� Ű ���¸� �����;� ��.
void Input_Update(void)
{
	
	if (s_CurrentInputKey[0] != NULL || s_CurrentInputKey[1] != NULL)
	{
		for (int i = 0; i < 2; i++)
		{
			s_PrevInputKey[i] = s_CurrentInputKey[i];
			s_CurrentInputKey[i] = NULL;

		}
	}
	
	int count = 0;

	for (int i = 0x20; i < 0xff; i++)
	{
		if (0x8000 & GetAsyncKeyState(i))
		{
			s_CurrentInputKey[count] = i;
			count++;
		}
		if (count > 1)
			break;
	}

}

// ���� �����ӿ� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
bool Input_GetKeyDown(uint8 vkey)
{
	for (int i = 0; i < 2; i++)
	{
		if (vkey == s_CurrentInputKey[i] && vkey != s_PrevInputKey[i])
			return true;
	}
	return false;
}

// ���� �����ӿ� Ű�� �����ٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
bool Input_GetKeyUp(uint8 vkey)
{
	for (int i = 0; i < 2; i++)
	{
		if (vkey != s_CurrentInputKey[i] && vkey == s_PrevInputKey[i])
			return true;
	}
	return false;
}

// ���� �����Ӱ� ���� �����ӿ� ��� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
bool Input_GetKey(uint8 vkey)
{
	for (int i = 0; i < 2; i++)
	{
		if (vkey == s_CurrentInputKey[i] && vkey == s_PrevInputKey[i])
			return true;
	}
	return false;
}
*/

#define IS_KEY_DOWN(vkey) (0x8000 & GetAsyncKeyState(vkey))

bool s_prevKeyStates[256];

bool s_currentKeyStates[256];

void Input_Update(void)
{
	memcpy(s_prevKeyStates, s_currentKeyStates, sizeof(s_currentKeyStates));
	for (int32 vkey = 0; vkey < 256; ++vkey)
	{
		if (IS_KEY_DOWN(vkey))
			s_currentKeyStates[vkey] = true;
		else
			s_currentKeyStates[vkey] = false;
	}

}

bool Input_GetKeyDown(uint8 vkey)
{
	if (false == s_prevKeyStates[vkey] && true == s_currentKeyStates[vkey])
		return true;
	else
		return false;
}

bool Input_GetKeyUp(uint8 vkey)
{
	if (true == s_prevKeyStates[vkey] && false == s_currentKeyStates[vkey])
		return true;
	else
		return false;
}

bool Input_GetKey(uint8 vkey)
{
	if (true == s_prevKeyStates[vkey] && true == s_currentKeyStates[vkey])
		return true;
	else
		return false;
}