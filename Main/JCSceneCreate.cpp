#include "StdAfx.h"
#include "Import.h"
#include "JCSceneCreate.h"
#include "Offset.h"
#include "Defines.h"
#include "Util.h"
#include "Object.h"
#include "Pet.h"

#include "Protect.h"
#include "UIControl.h"
#include "InfoLog.h"

GCCreateChar GCCharacter;

void sub_403FA0( int _this )
{
	signed int v8;
	int X = 223;
	int Y = 70;

	X = pWinWidth / pWinHeightReal / 2 - 186;
	LPCTSTR GetCharacterInfo[35] =
	{
//-- DW
		(LPCTSTR)&*(LPVOID*)0xD22AE0, 
		(LPCTSTR)&*(LPVOID*)0xD22AE4, 
		(LPCTSTR)&*(LPVOID*)0xD22AE8,
		(LPCTSTR)&*(LPVOID*)0xD22AEC,"0",
//-- DK
		(LPCTSTR)&*(LPVOID*)0xD22AF0, 
		(LPCTSTR)&*(LPVOID*)0xD22AF4, 
		(LPCTSTR)&*(LPVOID*)0xD22AF8,
		(LPCTSTR)&*(LPVOID*)0xD22AFC, "0",
//-- ELF
		(LPCTSTR)&*(LPVOID*)0xD22B00, 
		(LPCTSTR)&*(LPVOID*)0xD22B04, 
		(LPCTSTR)&*(LPVOID*)0xD22B08,
		(LPCTSTR)&*(LPVOID*)0xD22B0C, "0",
//-- MG
		(LPCTSTR)&*(LPVOID*)0xD22B10, 
		(LPCTSTR)&*(LPVOID*)0xD22B14, 
		(LPCTSTR)&*(LPVOID*)0xD22B18,
		(LPCTSTR)&*(LPVOID*)0xD22B1C, "0",
//-- DL
		(LPCTSTR)&*(LPVOID*)0xD22B20, 
		(LPCTSTR)&*(LPVOID*)0xD22B24, 
		(LPCTSTR)&*(LPVOID*)0xD22B28,
		(LPCTSTR)&*(LPVOID*)0xD22B2C, 
		(LPCTSTR)&*(LPVOID*)0xD22B50,
//-- SUM
		(LPCTSTR)&*(LPVOID*)0xD22B30, 
		(LPCTSTR)&*(LPVOID*)0xD22B34, 
		(LPCTSTR)&*(LPVOID*)0xD22B38,
		(LPCTSTR)&*(LPVOID*)0xD22B3C, "0",
//-- RF
		(LPCTSTR)&*(LPVOID*)0xD22B40, 
		(LPCTSTR)&*(LPVOID*)0xD22B44, 
		(LPCTSTR)&*(LPVOID*)0xD22B48,
		(LPCTSTR)&*(LPVOID*)0xD22B4C, "0",
	};

	pSetFont(pTextThis( ), *(DWORD*)0xE8C58C);

	int BODY_X1		= 180;
	int BODY_X1A	= 17;
	int BODY_Y1		= 76;

	if ( *(BYTE *)(_this + 2800) != 1 )
	{
		SetTextColorByHDC(pTextThis( ), -16730881);
		pDrawText(pTextThis( ), X + BODY_X1 - BODY_X1A, Y + BODY_Y1, GetCharacterInfo[*(BYTE*)0x7BD0483 * 5 + 0], 0, 0, (LPINT) 1, 0);
		pDrawText(pTextThis( ), X + BODY_X1 - BODY_X1A, Y + BODY_Y1 + 10, GetCharacterInfo[*(BYTE*)0x7BD0483 * 5 + 1], 0, 0, (LPINT) 1, 0);
		pDrawText(pTextThis( ), X + BODY_X1 - BODY_X1A, Y + BODY_Y1 + 20, GetCharacterInfo[*(BYTE*)0x7BD0483 * 5 + 2], 0, 0, (LPINT) 1, 0);
		pDrawText(pTextThis( ), X + BODY_X1 - BODY_X1A, Y + BODY_Y1 + 30, GetCharacterInfo[*(BYTE*)0x7BD0483 * 5 + 3], 0, 0, (LPINT) 1, 0);
		//-- informacion
		SetTextColorByHDC(pTextThis( ), eGray100);
		pDrawText(pTextThis( ), X + (BODY_X1-50), Y + BODY_Y1, pGetTextLine(pTextLineThis, 1701 + 0), 0, 0, (LPINT) 1, 0);
		pDrawText(pTextThis( ), X + (BODY_X1-50), Y + BODY_Y1 + 10, pGetTextLine(pTextLineThis, 1701 + 1), 0, 0, (LPINT) 1, 0);
		pDrawText(pTextThis( ), X + (BODY_X1-50), Y + BODY_Y1 + 20, pGetTextLine(pTextLineThis, 1701 + 2), 0, 0, (LPINT) 1, 0);
		pDrawText(pTextThis( ), X + (BODY_X1-50), Y + BODY_Y1 + 30, pGetTextLine(pTextLineThis, 1701 + 3), 0, 0, (LPINT) 1, 0);
	}

	if ( *(DWORD *)(_this + 2640) == 4 && !*(BYTE *)(_this + 2800) )
	{
		SetTextColorByHDC(pTextThis( ), eGray100);
		pDrawText(pTextThis( ), X + (BODY_X1 -50), Y + (BODY_Y1 + 40), pGetTextLine(pTextLineThis, 1738), 0, 0, (LPINT) 1, 0);
		SetTextColorByHDC(pTextThis( ), -16730881);
		pDrawText(pTextThis( ), X + (BODY_X1 - BODY_X1A), Y + (BODY_Y1 + 40), GetCharacterInfo[*(BYTE*)0x7BD0483 * 5 + 4], 0, 0, (LPINT) 1, 0);
	}
	SetTextColorByHDC(pTextThis( ), -1);
	pSetFont(pTextThis( ), *(DWORD*)0xE8C588);
}

__declspec(naked) void JCSetBoundsInformation( )
{
	static DWORD Addr_JMP= 0x004042FD;
	static DWORD Addr_Call= 0x00401C20;
	static DWORD _this;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x80]
		MOV _this, ECX
		ADD ECX,0x120
		CALL Addr_Call
		ADD EAX,0x16
		MOV DWORD PTR SS:[EBP-0x7C],EAX
	}

	sub_403FA0( _this );

	_asm
	{
		JMP[Addr_JMP]
	}
}

void GCCreateChar::Load( )
{
	SetCompleteHook(0xE9, 0x004040FF, &JCSetBoundsInformation);
}