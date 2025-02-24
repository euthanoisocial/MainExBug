#include "stdafx.h"
#include "Resolution.h"
#include "Offset.h"
#include "Util.h"

#if ZOOM_MAX_CAM == 0
double Resolution_ClipX1 = 4190.0f;
double Resolution_ClipX2 = 4190.0f;
#else
double Resolution_ClipX1 = 2000.0f;
double Resolution_ClipX2 = 2000.0f;
#endif
void InitResolution() // OK
{
	SetCompleteHook(0xE9,0x004D13C2,&ResolutionSwitch);
	SetCompleteHook(0xE9,0x004D2782,&ResolutionSwitchFont);
	SetCompleteHook(0xE9,0x00830C3A,&ResolutionMoveList);
}

__declspec(naked) void ResolutionSwitch() // OK
{
	static DWORD ResolutionSwitchAddress1 = 0x004D1450;

	_asm
	{
		Mov Edx,Dword Ptr Ds:[MAIN_RESOLUTION]
		Mov Dword Ptr Ss:[Ebp-0x340],Edx
		Cmp Dword Ptr Ss:[Ebp-0x340],0x00
		Jnz NEXT1
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],640
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],360
		Jmp EXIT
		NEXT1:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x01
		Jnz NEXT2
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],800
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],450
		Jmp EXIT
		NEXT2:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x02
		Jnz NEXT3
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1024
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],576
		Jmp EXIT
		NEXT3:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x03
		Jnz NEXT4
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1280
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],720
		Jmp EXIT
		NEXT4:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x04
		Jnz NEXT5
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1360
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],765
		Jmp EXIT
		NEXT5:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x05
		Jnz NEXT6
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1440
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],810
		Jmp EXIT
		NEXT6:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x06
		Jnz NEXT7
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1600
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],900
		Jmp EXIT
		NEXT7:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x07
		Jnz NEXT8
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1700
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],956
		Jmp EXIT
		NEXT8:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x08
		Jnz EXIT
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X], 1800
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y], 1013
		NEXT9:
		Cmp Dword Ptr Ss:[Ebp-0x340],0x09
		Jnz EXIT
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X], 1920
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y], 1080
		EXIT:
		Jmp [ResolutionSwitchAddress1]
	}
}

__declspec(naked) void ResolutionSwitchFont() // OK
{
	static DWORD ResolutionSwitchFontAddress1 = 0x004D27FB;

	_asm
	{
		Mov Eax,Dword Ptr Ds:[MAIN_RESOLUTION_X]
		Mov Dword Ptr Ss:[Ebp-0xF20],Eax
		Cmp Dword Ptr Ss:[Ebp-0xF20],640
		Jnz NEXT1
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0C	//12
		Jmp EXIT
		NEXT1:
		Cmp Dword Ptr Ss:[Ebp-0xF20],800
		Jnz NEXT2

		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0D	//13
		Jmp EXIT

		NEXT2:
		Cmp Dword Ptr Ss:[Ebp-0xF20],1024
		Jnz NEXT3
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0F //15
		Jmp EXIT

		NEXT3:
		Cmp Dword Ptr Ss:[Ebp-0xF20],1280
		Jnz NEXT4
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0F //15
		Jmp EXIT

		NEXT4:
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0F //15
		Lea Ecx,Resolution_ClipX1
		Mov Edx,Dword Ptr Ds:[Ecx+0x00]
		Mov Eax,Dword Ptr Ds:[Ecx+0x04]
		Push Eax
		Push Edx
		Push 0x00D2C848
		Call [SetDouble]
		Add Esp,0x0C
		Lea Ecx,Resolution_ClipX2
		Mov Edx,Dword Ptr Ds:[Ecx+0x00]
		Mov Eax,Dword Ptr Ds:[Ecx+0x04]
		Push Eax
		Push Edx
		Push 0x00D2C898
		Call [SetDouble]
		Add Esp,0x0C
		EXIT:
		Jmp [ResolutionSwitchFontAddress1]
	}
}

__declspec(naked) void ResolutionMoveList() // OK
{
	static DWORD ResolutionMoveListAddress1 = 0x00830CE2;
	static DWORD ResolutionMoveListAddress2 = 0x00830C43;

	_asm
	{
		Mov Ecx,Dword Ptr Ds:[MAIN_RESOLUTION_X]
		Mov Dword Ptr Ss:[Ebp-0x08],Ecx
		Cmp Dword Ptr Ss:[Ebp-0x08],0x500
		Jbe EXIT
		Jmp [ResolutionMoveListAddress1]
		EXIT:
		Jmp [ResolutionMoveListAddress2]
	}
}
