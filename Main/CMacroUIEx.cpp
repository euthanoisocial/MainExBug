#include "stdafx.h"
#include "CMacroUIEx.h"
#include "Util.h"
#include "Offset.h"
#include "Import.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "MuHelper.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "Common.h"
#include "MiniMap.h"
#include "MiniMapTron.h"
#include "InfoLog.h"
#include "UIControl.h"
#include "WindowsStruct.h"
#include "SPK_ToolKit.h"
#include "Config.h"
CMacroUIEx gCMacroUIEx;
#define SizeBtnClickW 15
#define SizeBtnClickH 18
void CMacroUIEx::RenderFrame(int *This)
{
	#if(SPK_STYLE == 1)
	float X = 0;
	float Y = 0;
//	gToolKit.DrawButtonIcon(SPK_ITEM_BLOCK, 151560, X + 133.0f - 4, Y + 1,"Khóa Giao Dịch");
	gInterface.DrawFormat(eShinyGreen, 5, 390, 200, 1, "-> Noria - Cường Hoá - Dung Luyện - Đổi Cánh");
	gInterface.DrawFormat(eWhite, 5, 400, 200, 1, "-> reset - auto - vip - Xoado - taymaster ");
	gInterface.DrawFormat(eGold, 5, 410, 200, 1, "-> Liên Hệ Admin -> 0911105253");
	#else
	float CY;
	char Cord[256];
	float X = (double)*((DWORD *)This + 5);
	float Y = (double)*((signed int *)This + 6);

	float renderMenu = 5.0f;

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	renderMenu = 10.0f;
	RenderBitmap(51550, X + 84.0 + renderMenu, Y, 124.0, 24.0, 0.0, 0.285, 0.715, 0.26, 1, 1, 0.0);
	RenderBitmap(51550, X, Y, 124.0, 24.0, 0.0, 0.0, 0.715, 0.28, 1, 1, 0.0);
	pSetFont(pTextThis(), (int)pFontNormal);	
	
	if (World >= 82 && World <= 100)
	{
		wsprintf(Cord, "%s  %d/%d", pGetTextLine(pTextLineThis, (3810 + World - 82)), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	else
	{
		wsprintf(Cord, "%s  %d/%d", pGetMapName(World), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	gToolKit.MakeShadowText(X - 40, Y + 4, 200, 3, Cord);
	renderMenu = 15.0f;

	gToolKit.DrawButtonIcon(ButtonSettings, 51546, X + 119 + renderMenu, Y + 7.0, gConfig.TSPK_TEXT_ENGINE[27]);

	if (!*(BYTE*)(*(DWORD*)(MUHELPER_STRUC)+0x08))
	{
		gToolKit.DrawButtonIcon(ButtonStart, 51547, 138 + renderMenu, Y + 7.0, gConfig.TSPK_TEXT_ENGINE[28]);
	}
	else
	{
		if (offhelper == 1)
		{
			gMuHelper.RunningOffHelper();
		}
		gToolKit.DrawButtonIcon(ButtonStop, 51548, 138 + renderMenu, Y + 7.0, gConfig.TSPK_TEXT_ENGINE[29]);
	}
	gToolKit.DrawButtonIcon(eMenu, 51553, X + 100.0f + renderMenu, Y + 7.0, gConfig.TSPK_TEXT_ENGINE[30]);

	gToolKit.DrawButtonIcon(SPK_MAIN_ZMCAM,		151556,  X + 5.0f + renderMenu, Y + gMoveYButton, gConfig.TSPK_TEXT_ENGINE[31]);
	gToolKit.DrawButtonIcon(SPK_MAIN_RSCAM,		151557, X + 24.0f + renderMenu, Y + gMoveYButton, gConfig.TSPK_TEXT_ENGINE[32]);
	gToolKit.DrawButtonIcon(SPK_MAIN_ARESET,	151554, X + 43.0f + renderMenu, Y + gMoveYButton, gConfig.TSPK_TEXT_ENGINE[33]);
	gToolKit.DrawButtonIcon(SPK_MAIN_ATM,		151558, X + 81.0f + renderMenu, Y + gMoveYButton, gConfig.TSPK_TEXT_ENGINE[34]);
	

	float gMoveYButtonY = 1;
	float gMoveYButtonX = 1;
	gInterface.DrawButtonRender(SPK_MAIN_BOXSK, X + 157.0f + renderMenu - gMoveYButtonX, Y + gMoveYButtonY, -50, -50);
	if (gInterface.IsWorkZone(SPK_MAIN_BOXSK)) {
		gInterface.DrawToolTip(X + 157.0f + renderMenu - gMoveYButtonX, 50, gConfig.TSPK_TEXT_ENGINE[35]);
		if (gInterface.Data[SPK_MAIN_BOXSK].OnClick) {
			RenderBitmap(151559, X + 157.0f + renderMenu - gMoveYButtonX, Y + gMoveYButtonY, 12, 12, 0.0, 0.451f, 0.878, 0.225, 1, 1, 0.0);}else{
			RenderBitmap(151559, X + 157.0f + renderMenu - gMoveYButtonX, Y + gMoveYButtonY, 12, 12, 0.0, 0.2255f, 0.878, 0.225, 1, 1, 0.0);}}else{
			RenderBitmap(151559, X + 157.0f + renderMenu - gMoveYButtonX, Y + gMoveYButtonY, 12, 12, 0.0, 0.0, 0.878, 0.225, 1, 1, 0.0);
	}
	//gInterface.DrawFormat(eOrange, 5 , 370, 200, 1, " F8 Menu Game - Phím H Bảng Sự Kiện- J Ngân Hàng Ngọc");
	//gInterface.DrawFormat(eGold, 5 , 380, 200, 1, " Lưu Ý -> Tất Cả Mọi Giao Dịch Mua Bán Phải  Trung Gian Qua Admin");
	gInterface.DrawFormat(eShinyGreen, 5 , 390, 200, 1, "-> F8 Menu - Noria - Cường Hoá - Dung Luyện - Đổi Cánh");
	gInterface.DrawFormat(eWhite, 5 , 400, 200, 1, "-> reset - auto - vip - Xoado - taymaster ");
	gInterface.DrawFormat(eGold, 5 , 410, 200, 1, "-> Liên Hệ Admin -> 0911105253");
	pGLSwitch();
	EnableAlphaTest(0);
#endif
}
char BarTime(int This)
{
	float v1; // ST10_4@2
	float v2; // ST0C_4@2
	float v3; // ST30_4@3
	float v4; // ST08_4@3
	float v5; // ST04_4@3
	int v13; // [sp+30h] [bp-4h]@1

	 v13 = This;

	if ( *(BYTE *)(v13 + 72) == 1 )
	{
		v1 = (double)*(signed int *)(This + 20);
		v2 = (double)*(signed int *)(This + 16);
		RenderImage2(51522, v5, v4);
		if ( *(DWORD *)(v13 + 88) == 1 )
		{
			v3 = *(float *)(v13 + 92) * 50.0;
			v4 = (double)(*(DWORD *)(v13 + 20) + 2);
			v5 = (double)(*(DWORD *)(v13 + 16) + 2);
			RenderImage(51549, v5 + 108.0, v4 - 16.0, v3, 3.0);
		}
		else if ( *(DWORD *)(v13 + 88) > 1 )
		{
			RenderImage2(51522, v5, v4);
			v3 = *(float *)(v13 + 92) * 50.0;
			v4 = (double)(*(DWORD *)(v13 + 20) + 2);
			v5 = (double)(*(DWORD *)(v13 + 16) + 2);
			RenderImage(51549, v5 + 108.0, v4 - 16.0, v3, 3.0);
		}
	}
  return 1;
}

__declspec(naked) void MuHelperRemake_01() 
{
	static DWORD Remake_Buffer = 0x007D26DA;
	#if(SPK_STYLE == 1)
	static DWORD W = Setting_S;
	static DWORD H = Setting_S;
	static DWORD X = Setting_X;
	static DWORD Y = Setting_Y;
	#else
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 119 + 15.0f;
	static DWORD Y = 7;
	#endif
	_asm
	{
		PUSH H                                  ; |Arg6 = 0000000D
		PUSH W                                  ; |Arg5 = 00000012
		MOV EDX,DWORD PTR SS:[EBP-0xB8]         ; |
		MOV EAX,DWORD PTR DS:[EDX+0x18]            ; |
		PUSH Y                                 ; |Arg4
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0x14]            ; |
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0xC]             ; |
		LEA EDX,DWORD PTR DS:[EDX+ECX+0x29]        ; |
		PUSH X                                 ; |Arg3
		JMP [Remake_Buffer]
	}
}
__declspec(naked) void MuHelperRemake_02()
{
	static DWORD Remake_Buffer = 0x007D2776;
	#if(SPK_STYLE == 1)
	static DWORD W = Setting_S;
	static DWORD H = Setting_S;
	static DWORD X = PlayHeperX;
	static DWORD Y = PlayHeperY;
	#else
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 138 + 15.0f;
	static DWORD Y = 7;
	#endif
 	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_03()  //<- PauseHelper
{
	static DWORD Remake_Buffer = 0x007D2821;
	#if(SPK_STYLE == 1)
	static DWORD W = Setting_S;
	static DWORD H = Setting_S;
	static DWORD X = PlayHeperX;
	static DWORD Y = PlayHeperY;
	#else
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 138 + 15.0f;
	static DWORD Y = 7;
	#endif
 
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Remake_Buffer]
	}
}


void CMacroUIEx::RenderHelperFrame(int *This)
{
//	float X = 0;
//	float Y = 0;
//	gToolKit.DrawButtonIcon(SPK_ITEM_BLOCK, 151560, X + 133.0f + 15, Y + 33,"Khóa Giao Dịch"); // 0911105253

	//gInterface.DrawFormat(eBlue250, 5 , 390, 200, 1, "-> Reset In Game - Reset - Reset Auto - Reset AutoVip");
	//gInterface.DrawFormat(eShinyGreen, 5 , 400, 200, 1, "-> Lệnh Thường Dùng - Change - XoaDo - TayDiem");
	//gInterface.DrawFormat(eBlowPink, 5 , 410, 200, 1, "-> Liên Hệ Admin -> 0911105253");
}

__declspec(naked) void MuHelperRemake2_01()  //<- ConfigHelper
{
	static DWORD PosX = 0;
	if (pWinWidth >= 1024)
	{
		PosX = 93;
	}
	else
	{
		PosX = 93 + 26;
	}

	static DWORD Addr_JMP = 0x007D26DA;
	//static DWORD W = 18;
	//static DWORD H = 13.3;
	//static DWORD X = PosX;
	//static DWORD Y = 1;
 
	#if(SPK_STYLE == 1)
	static DWORD W = Setting_S;
	static DWORD H = Setting_S;
	static DWORD X = Setting_X;
	static DWORD Y = Setting_Y;
	#else
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 138 + 15.0f;
	static DWORD Y = 7;
	#endif
	_asm
	{
		PUSH H                                  ; |Arg6 = 0000000D
		PUSH W                                  ; |Arg5 = 00000012
		MOV EDX,DWORD PTR SS:[EBP-0xB8]         ; |
		MOV EAX,DWORD PTR DS:[EDX+0x18]            ; |
		PUSH Y                                 ; |Arg4
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0x14]            ; |
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0xC]             ; |
		LEA EDX,DWORD PTR DS:[EDX+ECX+0x29]        ; |
		PUSH X                                 ; |Arg3
		JMP [Addr_JMP]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake2_02()  //<- PlayHelper
{
	static DWORD PosX = 0;
	if (pWinWidth >= 1024)
	{
		PosX = 93;
	}
	else
	{
		PosX = 93 + 26;
	}
	static DWORD Addr_JMP = 0x007D2776;
	//static DWORD W = 18;
	//static DWORD H = 13.3;
	//static DWORD X = PosX + 18.0f;
	//static DWORD Y = 1;
 #if(SPK_STYLE == 1)
	static DWORD W = Setting_S;
	static DWORD H = Setting_S;
	static DWORD X = PlayHeperX;
	static DWORD Y = PlayHeperY;
	#else
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 138 + 15.0f;
	static DWORD Y = 7;
	#endif
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Addr_JMP]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake2_03()  //<- PauseHelper
{
	static DWORD PosX = 0;
	if (pWinWidth >= 1024)
	{
		PosX = 93;
	}
	else
	{
		PosX = 93 + 26;
	}
	static DWORD Addr_JMP = 0x007D2821;
	//static DWORD W = 18;
	//static DWORD H = 13.3;
	//static DWORD X = PosX + 18.0f;
	//static DWORD Y = 1;
 #if(SPK_STYLE == 1)
	static DWORD W = Setting_S;
	static DWORD H = Setting_S;
	static DWORD X = PlayHeperX;
	static DWORD Y = PlayHeperY;
	#else
	static DWORD W = 19;
	static DWORD H = 19;
	static DWORD X = 138 + 15.0f;
	static DWORD Y = 7;
	#endif
	_asm
	{
		PUSH H                                     ; |Arg6 = 0000000D
		PUSH W                                     ; |Arg5 = 00000012
		MOV EAX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x18]            ; |
		PUSH Y                                     ; |Arg4
		MOV EDX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x14]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0xB8]            ; |
		MOV EDX,DWORD PTR DS:[ECX+0xC]             ; |
		LEA EAX,DWORD PTR DS:[EAX+EDX+0x3B]        ; |
		PUSH X                                     ; |Arg3
		JMP [Addr_JMP]
	}
}

void OffHelper(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(id, x, y, w, h);
	if( gInterface.IsWorkZone(ButtonStartAttack) )
	{
		if( gInterface.Data[ButtonStartAttack].OnClick )
		{
			if(offhelper == 0)
			{
				offhelper = 1;
			}
			else
			{
				offhelper = 0;
			}
			gInterface.Data[ButtonStartAttack].OnClick = false;
		}
	}
	if(offhelper == 1)
	{
		gInterface.DrawButtonRender(ButtonStartAttack, x + 50, y + 8, 0, 0);
	}
	else
	{
		gInterface.DrawButtonRender(ButtonStartAttack, x + 50, y + 8, 0, 15);
	}
	gInterface.DrawFormat(eGold, x + 50 + 16, y + 12, 60, 1, gConfig.TSPK_TEXT_ENGINE[40]);
}

#define pHelperMouseClick		((char(__thiscall*)(int a1)) 0x007D2920)

char FixHelperMouseClick(int a1)
{
	if(gInterface.CheckWindow(ChaosBox) || gInterface.CheckWindow(Warehouse))
		return 0;

	return pHelperMouseClick(a1);
}
bool CheckCursor(int x, int y, int w, int h)
{
	bool Check = false; // al@2
	return Check = pCheckMouseOver(1, 1, 200, 40);
}
__declspec(naked) void MoveTextArrow()
{
	static DWORD Addr_main = 0x007DF898;
	static DWORD MOVEY = -99;

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x4]
			ADD ECX, MOVEY; |
			PUSH ECX; / Arg2
			MOV EDX, DWORD PTR SS : [EBP - 0x8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x10]; |
			PUSH EAX; | Arg1
			MOV ECX, DWORD PTR SS : [EBP - 0x8]; |
			JMP[Addr_main]
	}
}
void CMacroUIEx::Load()
{
	SetCompleteHook(0xE8,0x007D2B0C,&FixHelperMouseClick);
	SetCompleteHook(0xE8, 0x007F76CD, &OffHelper);
	SetCompleteHook(0xE8, 0x007D2B3D, &CheckCursor);
	if(gProtect.m_MainInfo.CustomInterfaceType == 4 )
	{
		SetCompleteHook(0xE9, 0x007D2BC0, this->RenderFrame);
		SetCompleteHook(0xE9, 0x0080B8E0, &BarTime);
		SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake_01);
		SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake_02);
		SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake_03);
		SetCompleteHook(0xE9, 0x007DF88A, &MoveTextArrow);		
	}
	else
	{
		SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake2_01);
		SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake2_02);
		SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake2_03);
		SetCompleteHook(0xE9, 0x007D2BC0, this->RenderHelperFrame);
	}
}
