// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"


bool KeyHit(unsigned int keyCode)
{
	return (GetKeyState(keyCode) & 0x8000) != 0;
}


void Init()
{
	while (true)
	{
		if (KeyHit(49)) *(int*)0x7CF088 = 1;
		if (KeyHit(50)) *(int*)0x7CF088 = 0;
	}
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		if (*(int*)0x63BC93 != 0x24448B66)
			MessageBoxA(0, "Invalid executable!", 0, 0);
		else
		CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Init), nullptr, 0, nullptr);;
	}
}

