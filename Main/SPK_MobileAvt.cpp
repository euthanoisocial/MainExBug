#include "stdafx.h"

#include "SPK_MobileAvt.h"
#include "Interface.h"
#include "Defines.h"
#include "CMacroUIEx.h"
#include "WindowsStruct.h"
#include "User.h"
#include "PrintPlayer.h"
#include "Common.h"
#include "MuHelper.h"
#include "Central.h"
#include "Util.h"
#include "SPK_ToolKit.h"
#include "Config.h"
#include "SPK_Relife.h"
void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
{
	DWORD v23;
	int v10 = *(DWORD*)(a1 + 40);
	int v11 = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	gInterface.DrawFormat(eGold, v11, v10 + 9, 186, 3, "Trang Bị");;

	if (gProtect.m_MainInfo.CustomInterfaceType != 2)
	{
		DWORD ColorKickSet, ColorKickSock;
		if ((signed int)(unsigned __int8)SetOption1((int)pUserStat()) <= 0 && (signed int)(unsigned __int8)SetOption2((int)pUserStat()) <= 0)
		{
			ColorKickSet = eGray100;
		}
		else
		{
			ColorKickSet = eGold;
		}
		gInterface.DrawFormat(ColorKickSet, v11 + 23, v10 + 34, 50, 1, "Set Thần");

		if (!sub_969000((void*)0x986C1B8))
		{
			ColorKickSock = eGray100;
		}
		else
		{
			ColorKickSock = eGold;
		}
		gInterface.DrawFormat(ColorKickSock, v11 + 117, v10 + 34, 50, 4, "Set Socket");

		#if TYPEZEN !=1
		char textzen[50], textGP[50], TextWC[50], textWP[50];
		ZeroMemory(textzen, sizeof(textzen));
		ZeroMemory(textGP, sizeof(textGP));
		ZeroMemory(TextWC, sizeof(TextWC));
		ZeroMemory(textWP, sizeof(textWP));

		pGetMoneyFormat(v23, textzen, 0);
		pGetMoneyFormat(Coin1, TextWC, 0);
		pGetMoneyFormat(Coin2, textWP, 0);
		pGetMoneyFormat(Coin3, textGP, 0);

		RenderBitmap(0x17915, v11 + 11, v10 + 363, 100.f, 16.f, 0, 0, 170.f / 256.f, 21.f / 32.f, 1, 1, 0.0);
		RenderBitmap(0x17915, v11 + 98, v10 + 363, 100.f, 16.f, 0, 0, 170.f / 256.f, 21.f / 32.f, 1, 1, 0.0);
		RenderBitmap(0x17915, v11 + 11, v10 + 377, 100.f, 16.f, 0, 0, 170.f / 256.f, 21.f / 32.f, 1, 1, 0.0);
		RenderBitmap(0x17915, v11 + 98, v10 + 377, 100.f, 16.f, 0, 0, 170.f / 256.f, 21.f / 32.f, 1, 1, 0.0);
		gInterface.DrawFormat(eWhite, v11 + 20, v10 + 366, 20, 1, gConfig.TSPK_TEXT_ENGINE[8]);
		gInterface.DrawFormat(eWhite, v11 + 110, v10 + 366, 20, 1, gConfig.TSPK_TEXT_ENGINE[9]);
		gInterface.DrawFormat(eWhite, v11 + 20, v10 + 380, 20, 1, gConfig.TSPK_TEXT_ENGINE[10]);
		gInterface.DrawFormat(eWhite, v11 + 110, v10 + 380, 20, 1, gConfig.TSPK_TEXT_ENGINE[11]);
		gInterface.DrawFormat(eGold, v11 + 37, v10 + 366, 54, 4, "%s", textzen);
		gInterface.DrawFormat(eGold, v11 + 126, v10 + 366, 54, 4, "%s", textGP);
		gInterface.DrawFormat(eGold, v11 + 37, v10 + 366 + 14, 54, 4, "%s", TextWC);
		gInterface.DrawFormat(eGold, v11 + 126, v10 + 380, 54, 4, "%s", textWP);
		#else
		RenderBitmap(0x17915, v11 + 11, v10 + 363, 100.f, 16.f, 0, 0, 170.f / 256.f, 21.f / 32.f, 1, 1, 0.0);
		RenderBitmap(0x17915, v11 + 98, v10 + 363, 100.f, 16.f, 0, 0, 170.f / 256.f, 21.f / 32.f, 1, 1, 0.0);
		RenderBitmap(0x17915, v11 + 11, v10 + 377, 100.f, 16.f, 0, 0, 170.f / 256.f, 21.f / 32.f, 1, 1, 0.0);
		RenderBitmap(0x17915, v11 + 98, v10 + 377, 100.f, 16.f, 0, 0, 170.f / 256.f, 21.f / 32.f, 1, 1, 0.0);
		gInterface.DrawFormat(eWhite, v11 + 20, v10 + 366, 20, 1, gConfig.TSPK_TEXT_ENGINE[8]);
		gToolKit.CRenderNumberExNew(v11 + 107, v10 + 366, v23, 4, 0.88);
		gInterface.DrawFormat(eWhite, v11 + 110, v10 + 366, 20, 1, gConfig.TSPK_TEXT_ENGINE[9]);
		gToolKit.CRenderNumberExNew(v11 + 194, v10 + 366, Coin3, 4, 0.88);
		gInterface.DrawFormat(eWhite, v11 + 20, v10 + 380, 20, 1, gConfig.TSPK_TEXT_ENGINE[10]);
		gToolKit.CRenderNumberExNew(v11 + 108, v10 + 380, Coin1, 4, 0.88);
		gInterface.DrawFormat(eWhite, v11 + 110, v10 + 380, 20, 1, gConfig.TSPK_TEXT_ENGINE[11]);
		gToolKit.CRenderNumberExNew(v11 + 194.5f, v10 + 380, Coin2, 4, 0.88);
		#endif
	}
	else
	{

		gInterface.DrawGUI(eMainMenuSet, v11 + 15, v10 + 21);

		char textzen[50];
		ZeroMemory(textzen, sizeof(textzen));
		pGetMoneyFormat(v23, textzen, 0);

		gInterface.DrawFormat(eWhite, v11 + 25, v10 + 372, 20, 1, gConfig.TSPK_TEXT_ENGINE[8]);
		gInterface.DrawGUI(eZen, v11 + 40, v10 + 366);
		DWORD ZenCorlor;
		if (v23 >= 0 && v23 <= 99999)
		{
			ZenCorlor = MilkZen;
		}
		else if (v23 >= 100000 && v23 <= 999999)
		{
			ZenCorlor = GreenZen;
		}
		else if (v23 >= 1000000 && v23 <= 6999999)
		{
			ZenCorlor = OrgZen;
		}
		else if (v23 >= 7000000)
		{
			ZenCorlor = RedZen;
		}
		gInterface.DrawFormat(ZenCorlor, v11 + 46, v10 + 371, 54, 1, "%s", textzen);
	}
	
}

__declspec(naked) void InfoTooltipSocketX()
{
	static DWORD Addr_JMP = 0x00835CBD;
	static DWORD This; // [sp+74h] [bp-4h]@1
	static DWORD RenderY; // [sp+74h] [bp-4h]@1
	static DWORD RenderX; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	RenderX = *(signed int*)(This + 36) + 54;
	RenderY = *(signed int*)(This + 40) + 10;

	_asm
	{
		PUSH RenderX
		PUSH RenderY
		JMP[Addr_JMP]
	}
}
__declspec(naked) void InfoTooltipAncestralX()
{
	static DWORD Addr_JMP = 0x00835C92;
	static DWORD This;
	static DWORD RenderY;

	This = GetInventory(GetInstance());

	RenderY = *(signed int*)(This + 40) + 10;

	_asm
	{
		PUSH RenderY
		JMP[Addr_JMP]
	}
}
__declspec(naked) void RemoveTextAncestralX()
{
	static DWORD Addr_JMP = 0x0083524C;

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RemoveTextSocketX()
{
	static DWORD Addr_JMP = 0x00835364;

	_asm
	{
		JMP[Addr_JMP]
	}
}
bool CheckMouseAncestralX(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	x = TransFor2X((double)*(signed int*)(This + 36));
	y = TransForY((double)*(signed int*)(This + 40));

	return pCheckMouseOver(Return2X(x + TransForX(28)), ReturnY(TransForY(33)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
}

bool CheckMouseSocketX(int x, int y, int w, int h)
{
	int This; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	x = TransFor2X((double)*(signed int*)(This + 36));
	y = TransForY((double)*(signed int*)(This + 40));

	return pCheckMouseOver(Return2X(x + TransForX(117)), ReturnY(y + TransForY(33)), Return2X(TransForX(133)), ReturnY(TransForY(17)));
}
void InitLoad()
{
	SetCompleteHook(0xE9, 0x00835CB1, &InfoTooltipSocketX); //-- Posicion Mostrar Tooltip de Equipamiento
	SetCompleteHook(0xE9, 0x00835C86, &InfoTooltipAncestralX); //-- Posicion Mostrar Tooltip de Equipamiento
	//--
	SetCompleteHook(0xE9, 0x0083516F, &RemoveTextAncestralX); //-- Text Ancient
	SetCompleteHook(0xE9, 0x008352B1, &RemoveTextSocketX); //-- Text Socket
	//--
	SetCompleteHook(0xE8, 0x0083538A, &CheckMouseSocketX); //-- InfoOption Socket Equip
	SetCompleteHook(0xE8, 0x00834C8D, &CheckMouseAncestralX); //-- InfoOption Ancient Equip
}
#if(SPK_STYLE == 1)
#include "SPK_ToolKit.h"
SuperKhung mSpk;

void SuperKhung::LoadImg()
{
	LoadBitmapA("SPK\\NhanVat\\DK1.tga", 531050, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\NhanVat\\DW1.tga", 531051, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\NhanVat\\FE1.tga", 531052, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\NhanVat\\MG1.tga", 531053, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\NhanVat\\DL1.tga", 531054, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\NhanVat\\SM1.tga", 531055, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\NhanVat\\RF1.tga", 531056, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\NhanVat\\BarFace.tga", 531049, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\InterSPK\\BarFaceBG.tga", 0x17AF1, GL_LINEAR, GL_CLAMP, 1, 0);
}


void SuperKhung::HienThiKhuonNhanVat()
{
	if (gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(SkillTree) || gInterface.CheckWindow(MoveList) || gInterface.CheckWindow(ObjWindow::MoveList))
	{
		return;
	}
	if (gInterface.IsWorkZone2(Setting_X - 10, Setting_Y - 20, 200, 100))
	{
		pSetCursorFocus = true;
	}

	this->ChieuDaiChar = 34;
	this->ChieuCaoChar = 45;
	this->ToaDoXChar = 6;
	this->ToaDoYChar = 2;

	this->ChieuDaiBg = 155;
	this->ChieuCaoBg = 100;
	this->ToaDoXBg = 0;
	this->ToaDoYBg = 0;

	this->mCharClass = pGetCharClass(*(BYTE*)(*(DWORD*)0x7BC4F04 + 19));
	
	switch (this->mCharClass)
	{
		case 0:		RenderBitmap(531051, this->ToaDoXChar, this->ToaDoYChar, this->ChieuDaiChar, this->ChieuCaoChar, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); break;
		case 1:		RenderBitmap(531050, this->ToaDoXChar, this->ToaDoYChar, this->ChieuDaiChar, this->ChieuCaoChar, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); break;
		case 2:		RenderBitmap(531052, this->ToaDoXChar, this->ToaDoYChar, this->ChieuDaiChar, this->ChieuCaoChar, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); break;
		case 3:		RenderBitmap(531053, this->ToaDoXChar, this->ToaDoYChar, this->ChieuDaiChar, this->ChieuCaoChar, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); break;
		case 4:		RenderBitmap(531054, this->ToaDoXChar, this->ToaDoYChar, this->ChieuDaiChar, this->ChieuCaoChar, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); break;
		case 5:		RenderBitmap(531055, this->ToaDoXChar, this->ToaDoYChar, this->ChieuDaiChar, this->ChieuCaoChar, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); break;
		case 6:		RenderBitmap(531056, this->ToaDoXChar, this->ToaDoYChar, this->ChieuDaiChar, this->ChieuCaoChar, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); break;
		default:	RenderBitmap(531051, this->ToaDoXChar, this->ToaDoYChar, this->ChieuDaiChar, this->ChieuCaoChar, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0); break;
	}
	

	RenderBitmap(531049, this->ToaDoXBg, this->ToaDoYBg - this->ChieuCaoBg / 4, this->ChieuDaiBg, this->ChieuCaoBg, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);

	gToolKit.CRenderNumberExNew(26.5, 45, gObjUser.lpPlayer->Level, 3, 0.74);

	char Cord[256];
	if (World >= 82 && World <= 100)
	{
		wsprintf(Cord, "%s  %d/%d", pGetTextLine(pTextLineThis, (3810 + World - 82)), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	else
	{
		wsprintf(Cord, "%s  %d/%d", pGetMapName(World), gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	}
	gInterface.DrawFormat(eWhite, 50, 7, 300, 1, "WWW.Mu-VĩnhCửu.com");

	gInterface.DrawFormat(eWhite, 50, 21, 300, 1, "Reset: %d - Relife: %d - Master: %d", ViewReset, G_SpkRelife.ResetLife, *(WORD*)0x87935D8);
	gInterface.DrawFormat(eWhite, 50, 31, 300, 1, Cord);
	gInterface.DrawFormat(eWhite, -2, 53, 50, 3, "%s", gObjUser.lpPlayer->Name);

	glColor3f(1.0f, 0.5167, 0.0f);
	
	glColor3f(1.0, 1.0, 1.0);
	EnableAlphaTest(1);


	gToolKit.DrawButtonIcon(ButtonSettings, 51546, Setting_X, Setting_Y, gConfig.TSPK_TEXT_ENGINE[27]);

	if (!*(BYTE*)(*(DWORD*)(MUHELPER_STRUC)+0x08))
	{
		gToolKit.DrawButtonIcon(ButtonStart, 51547, PlayHeperX, PlayHeperY, gConfig.TSPK_TEXT_ENGINE[28]);
	}
	else
	{
		if (offhelper == 1)
		{
			gMuHelper.RunningOffHelper();
		}
		gToolKit.DrawButtonIcon(ButtonStop, 51548, PlayHeperX, PlayHeperY, gConfig.TSPK_TEXT_ENGINE[29]);
	}
	gToolKit.DrawButtonIcon(eMenu, 51553, gMenuX, gMenuY, gConfig.TSPK_TEXT_ENGINE[30]);
}
#endif
