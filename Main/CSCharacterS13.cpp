#include "stdafx.h"
#include "CSCharacterS13.h"
#include "Util.h"
#include "Interface.h"
#include "zzzMathLib.h"
#include "Offset.h"
#include "User.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "MultiSelect.h"
#include "CustomPet.h"
#include "Pet.h"
#include "UIControl.h"
#include "CustomRankUser.h"
#include "SPK_HonHoan.h"
#include "Central.h"

#define MAX_CHAR 8

CSCharacterS13 gCSCharacterS13;

char CGetCharacterClass(unsigned __int8 a1)
{
	char v2, v3, v4;

	v2 = 0;
	v3 = ((signed int)a1 >> 3) & 1;
	v4 = ((signed int)a1 >> 4) & 1;
	switch (a1 & 7)
	{
	case 0:
		if (v4) { v2 = 11; }
		else if (v3) { v2 = 7; }
		else { v2 = 0; }
		break;
	case 1:
		if (v4) { v2 = 12; }
		else if (v3) { v2 = 8; }
		else { v2 = 1; }
		break;
	case 2:
		if (v4) { v2 = 13; }
		else if (v3) { v2 = 9; }
		else { v2 = 2; }
		break;
	case 3:
		if (v4)
			v2 = 14;
		else
			v2 = 3;
		break;
	case 4:
		if (v4)
			v2 = 15;
		else
			v2 = 4;
		break;
	case 5:
		if (v4) { v2 = 16; }
		else if (v3) { v2 = 10; }
		else { v2 = 5; }
		break;
	case 6:
		if (v4)
			v2 = 17;
		else
			v2 = 6;
		break;
	case 7:
		if (v4) { v2 = 22; }
		else if (v3) { v2 = 21; }
		else { v2 = 20; }
		break;
	default:
		return v2;
	}
	return v2;
}
int JCGetClassname(unsigned __int8 a4)
{
	int result;
	char v5;
	v5 = CGetCharacterClass(a4);
	if (v5)
	{
		switch (v5)
		{
			case 1:			result = (int)pGetTextLine(pTextLineThis, 21);			break; //-- Dark Knight
			case 2: 		result = (int)pGetTextLine(pTextLineThis, 22);			break;//-- Elf
			case 3: 		result = (int)pGetTextLine(pTextLineThis, 23);			break;//-- Magic Gladiator
			case 4: 		result = (int)pGetTextLine(pTextLineThis, 24);			break;//-- Dark Lord
			case 5: 		result = (int)pGetTextLine(pTextLineThis, 1687);		break;//-- Summoner
			case 6: 		result = (int)pGetTextLine(pTextLineThis, 3150);		break;//-- Rage Fighter
			case 7: 		result = (int)pGetTextLine(pTextLineThis, 25);			break;//-- Soul Master
			case 8: 		result = (int)pGetTextLine(pTextLineThis, 26);			break;//-- Blade Knight
			case 9: 		result = (int)pGetTextLine(pTextLineThis, 27);			break;//-- Muse Elf
			case 10:		result = (int)pGetTextLine(pTextLineThis, 1688);		break;//-- Bloody Summoner
			case 11:		result = (int)pGetTextLine(pTextLineThis, 1669);		break;//-- Grand Master
			case 12:		result = (int)pGetTextLine(pTextLineThis, 1668);		break;//-- Blade Master
			case 13:		result = (int)pGetTextLine(pTextLineThis, 1670);		break;//-- High Elf
			case 14:		result = (int)pGetTextLine(pTextLineThis, 1671);		break;//-- Dual Master
			case 15:		result = (int)pGetTextLine(pTextLineThis, 1672);		break;//-- Lord Emperor
			case 16:		result = (int)pGetTextLine(pTextLineThis, 1689);		break;//-- Dimension Master
			case 17:		result = (int)pGetTextLine(pTextLineThis, 3151);		break;//-- Fist Master
			case 20:		result = (int)pGetTextLine(pTextLineThis, 3175);		break;//-- Grow Lancer
			case 21:		result = (int)pGetTextLine(pTextLineThis, 3176);		break;//-- Mirage Lancer
			case 22:		result = (int)pGetTextLine(pTextLineThis, 3176);		break;//-- Shining Lancer
			default:		result = (int)pGetTextLine(pTextLineThis, 2305);		break;//-- Error Code :
		}
	}
	else
	{
		result = (int)pGetTextLine(pTextLineThis, 20); //-- Dark Wizard
	}
	return result;
}
void GetColorCTCode(BYTE CTLCODE)
{
	int v9; // [sp+4h] [bp-8h]@1

	if (CTLCODE & 1)
	{
		v9 = -256;
	}
	else if (CTLCODE & 0x12)
	{
		v9 = -14165505;
	}
	else if (CTLCODE & 4)
	{
		v9 = -1;
	}
	else if (CTLCODE & 8)
	{
		v9 = -16776961;
	}
	else if (CTLCODE & 0x20)
	{
		v9 = -16776961;
	}
	else
	{
		v9 = -1;
	}

	SetTextColorByHDC(pTextThis(), v9);
}
int GetStatus(BYTE GuildStatus)
{
	if (GuildStatus <= 64)
	{
		if (GuildStatus == 64)
		{
			return 1301;
		}
		else if (GuildStatus)
		{
			if (GuildStatus != 32)
				goto LABEL_29;
			return 1302;
		}
		else
		{
			return 1330;
		}
	}
	if (GuildStatus == 128)
	{
	LABEL_29:
		return 1300;
	}
	else if (GuildStatus == 255)
	{
		return 488;
	}

	return 488;
}

int CSCharacterS13::JPlayerAddList(PMSG_CHARACTER_CREATE_RECV* lpMsg)
{
	signed int result; // eax@10
	DWORD v10; // [sp+20h] [bp-10h]@8
	float v11; // [sp+1Ch] [bp-14h]@2
	float v12; // [sp+24h] [bp-Ch]@0
	float v13; // [sp+28h] [bp-8h]@0

	PMSG_CHARACTER_LIST* lpInfo;

	std::map<int, PMSG_CHARACTER_LIST>::iterator it;
	
	if (lpMsg->result == 1)
	{
		if (lpMsg->slot >= 0 && lpMsg->slot < MAX_CHAR)
		{
			lpInfo = new PMSG_CHARACTER_LIST;
			lpInfo->slot = lpMsg->slot;
			memcpy(lpInfo->Name, lpMsg->name, sizeof(lpInfo->Name));
			lpInfo->Level = 400;
			lpInfo->GuildStatus = 255;
			lpInfo->CtlCode = 0;
			lpInfo->CharSet[0] = lpMsg->Class;
			lpInfo->Reset = 1;
			lpInfo->MasterReset = 0;

			lpInfo->pDanhHieu = 0;
			lpInfo->pQuanHam = 0;
			lpInfo->pTuLuyen = 0;
			lpInfo->pHonHoan = 0;
			
			for (int o = 1; o < 18; o++)
			{
				lpInfo->CharSet[o] = 0xFF;
			}

			it = gCSCharacterS13.lpInfoPlayer.find(lpMsg->slot);

			if (it != gCSCharacterS13.lpInfoPlayer.end())
			{
				gCSCharacterS13.lpInfoPlayer.erase(it);
			}
			gCSCharacterS13.lpInfoPlayer.insert(std::pair<int, PMSG_CHARACTER_LIST >(lpMsg->slot, *(PMSG_CHARACTER_LIST*)lpInfo));

		}
	}
	return 1;
}

int CSCharacterS13::JPlayerList(PMSG_CHARACTER_LIST_RECV* lpMsg)
{
	int v4; // ST1C_4@11
	DWORD result; // eax@12
	int v10; // [sp+18h] [bp-1Ch]@5
	float v11; // [sp+1Ch] [bp-18h]@5
	float v12; // [sp+20h] [bp-14h]@0
	float v13; // [sp+24h] [bp-10h]@0
	int PlayerSlot;
	int PlayerSelect;

	sub_63CB40();
	sub_4D5130(lpMsg->ClassCode);

	if (pPlayerState == 4)
		*(DWORD*)0xE61E18 = 93;

	gCSCharacterS13.lpInfoPlayer.clear();
	PlayerSlot = 0;
	PlayerSelect = 1;

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_CHARACTER_LIST* lpInfo = (PMSG_CHARACTER_LIST*)(((BYTE*)lpMsg) + sizeof(PMSG_CHARACTER_LIST_RECV) + (sizeof(PMSG_CHARACTER_LIST) * n));

		if (lpInfo->slot >= 0 && lpInfo->slot < MAX_CHAR)
		{
			gCSCharacterS13.lpInfoPlayer.insert(std::pair<int, PMSG_CHARACTER_LIST >(lpInfo->slot, *(PMSG_CHARACTER_LIST*)lpInfo));
		}

		v10 = (unsigned __int8)sub_587380(lpInfo->CharSet[0]);	//class
		v11 = 0.0;

		switch (lpInfo->slot)
		{
		case 0:
			v12 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.Rotate;// 115.0;
			PlayerSlot = 1;
			break;
		case 1:
			v12 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.Rotate;// 115.0;
			PlayerSlot = 1;
			break;
		case 2:
			v12 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.Rotate;// 115.0;
			PlayerSlot = 1;
			break;
		case 3:
			v12 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.Rotate;// 115.0;
			PlayerSlot = 1;
			break;
		case 4:
			v12 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.Rotate;// 115.0;
			PlayerSlot = 1;
			break;
		case 5:
			v12 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.Rotate;// 115.0;
			PlayerSlot = 1;
			break;
		case 6:
			v12 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.Rotate;// 115.0;
			PlayerSlot = 1;
			break;
		case 7:
			v12 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[lpInfo->slot].Coordenada1.Rotate;// 115.0;
			PlayerSlot = 1;
			break;
		default:
			break;
		}

		if (PlayerSlot == PlayerSelect)
		{
			PlayerSelect = 2;
			v12 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate;// 115.0;
			SetDword(0x004D6C73, lpInfo->slot);
		}

		v4 = JCSetModelCoord(lpInfo->slot, v10, 0, v12, v13, v11);//-- Agrega Personaje con Coordenada

		*(WORD*)(v4 + 130) = lpInfo->Level;

		*(BYTE*)(v4 + 21) = lpInfo->CtlCode;

		sub_9CF1C0((char*)(v4 + 56), lpInfo->Name, 0xAu);

		*(BYTE*)(v4 + 66) = 0;

		gCustomPet.PreviewCharSet(lpInfo->slot, &lpInfo->CharSet[1], 0, 0);//-- Mostrar Equipamiento

		*(BYTE*)(v4 + 24) = lpInfo->GuildStatus;

	}

	*(DWORD*)0x87935A4 = 51;

	pWarehouseExSet(pWarehouseExThis(pWindowThis()), lpMsg->ExtWarehouse);

	result = GetTickCount();
	*(DWORD*)0xE8CB30 = result;
	return result;
}

signed int JGCreateCharRecv(int JCCHARACTER)
{
	signed int result; // eax@10
	DWORD v10; // [sp+20h] [bp-10h]@8
	float v11; // [sp+1Ch] [bp-14h]@2
	float v12; // [sp+24h] [bp-Ch]@0
	float v13; // [sp+28h] [bp-8h]@0
	BYTE Slot;


	if (*(BYTE*)(JCCHARACTER + 4) == 1)
	{
		v11 = 0.0;
		Slot = *(BYTE*)(JCCHARACTER + 15);
		switch (Slot)
		{
		case 0:
			v12 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.Rotate;// 115.0;
			break;
		case 1:
			v12 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.Rotate;// 115.0;
			break;
		case 2:
			v12 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.Rotate;// 115.0;
			break;
		case 3:
			v12 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.Rotate;// 115.0;
			break;
		case 4:
			v12 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.Rotate;// 115.0;
			break;
		case 5:
			v12 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.Rotate;// 115.0;
			break;
		case 6:
			v12 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.Rotate;// 115.0;
			break;
		case 7:
			v12 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordX;// 8008.0;
			v13 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.CoordY;// 18885.0;
			v11 = gSelectCharRamdon.RenderSelect.PJ[Slot].Coordenada2.Rotate;// 115.0;
			break;
		default:
			break;
		}

		sub_57D760(*(BYTE*)(JCCHARACTER + 15));
		JCSetModelCoord(*(BYTE*)(JCCHARACTER + 15), (unsigned __int8)*(BYTE*)0x7BD0483, *(BYTE*)0x7BD0484, v12, v13, v11);

		v10 = pGetPreviewStruct(pPreviewThis(), *(BYTE*)(JCCHARACTER + 15));

		if (v10)
		{
			*(WORD*)(v10 + 130) = *(WORD*)(JCCHARACTER + 16);
			*(BYTE*)(v10 + 19) = sub_587380(*(BYTE*)(JCCHARACTER + 18));
			sub_9CF1C0((char*)(v10 + 56), (const void*)(JCCHARACTER + 5), 0xAu);
			*(BYTE*)(v10 + 66) = 0;
		}

		*(DWORD*)0x87935A4 = 53;

		sub_668520((char*)sub_482B70());
		sub_4057B0((char*)sub_482B70() + 32632);
		result = sub_402AD0((char*)sub_482B70() + 36744);
}
	else
	{
		result = *(BYTE*)(JCCHARACTER + 4);
		if (*(BYTE*)(JCCHARACTER + 4))
		{
			if (*(BYTE*)(JCCHARACTER + 4) == 2)
			{
				result = sub_484A10(sub_482B70(), 55, 0);
			}
		}
		else
		{
			result = sub_484A10(sub_482B70(), 54, 0);
		}
	}
	return result;
}


int PushBackPlayer(int a4)
{
	signed int v4; 
	int v5;
	int v6;
	int result;
	char v12;

	v12 = *(BYTE*)(a4 + 4);

	if (v12)
	{
		if (v12 == 1)
		{
			v6 = sub_96A4C0(sub_402BC0(), SelectedHero);
			sub_57D760(*(WORD*)(v6 + 126));

			std::map<int, PMSG_CHARACTER_LIST>::iterator it = gCSCharacterS13.lpInfoPlayer.find(SelectedHero);

			if (it != gCSCharacterS13.lpInfoPlayer.end())
			{
				gCSCharacterS13.lpInfoPlayer.erase(it);
			}

			result = sub_484A10(sub_482B70(), 96, 0);
		}
		else if (v12 == 3)
		{
			result = sub_484A10(sub_482B70(), 98, 0);
		}
		else
		{
			result = sub_484A10(sub_482B70(), 137, 0);
		}
}
	else
	{
		result = sub_484A10(sub_482B70(), 146, 0);
	}
	return result;
}
void CSCharacterS13::GetBarSelectCharacter(int a, int b, int c, int d, BYTE Slot)
{
	VAngle Angle;

	float ACoord_X = 25.0f + d;
	float ACoord_Y = 70.0f - c;
	#define BitMapRenderW 95
	#define BitMapRenderX 19

	std::map<int, PMSG_CHARACTER_LIST>::iterator it = this->lpInfoPlayer.find(Slot);
	if (it != this->lpInfoPlayer.end())
	{
		char ClassName[11] = { 0 };
		memcpy(ClassName, it->second.Name, sizeof(it->second.Name));

		DWORD ViewportAddress = pGetPreviewStruct(pPreviewThis(), Slot);
		Angle.X = *(float*)(ViewportAddress + 1028);
		Angle.Y = *(float*)(ViewportAddress + 1032);
		Angle.Z = *(float*)(ViewportAddress + 1036) + *(float*)(ViewportAddress + 0x3E8) + 350.0f;

		pGetPosFromAngle(&Angle, &a, &b);
		RenderBitmap(0x1791C, a - ACoord_X - 1, b + ACoord_Y, BitMapRenderW, 60, 0, 0, 1, 1, 1, 1, 0.0);
		pSetBackgroundTextColor(pTextThis(), 255, 255, 255, 0);
		GetColorCTCode(it->second.CtlCode);
		g_pRenderText.CRenderText(a - (ACoord_X + BitMapRenderX), b + (ACoord_Y + 3), ClassName, BitMapRenderW, 0, 3, 0);

		char ClassLevel[255];
		ZeroMemory(ClassLevel, sizeof(ClassLevel));
		wsprintf(ClassLevel, "%s - %d", (char*)JCGetClassname((unsigned __int8)sub_587380(it->second.CharSet[0])), it->second.Level);
		SetTextColorByHDC(pTextThis(), pMakeColor(0xD8u, 0xA6u, 0x9u, 0xFFu));
		g_pRenderText.CRenderText(a - (ACoord_X + BitMapRenderX), b + (ACoord_Y + 12), ClassLevel, BitMapRenderW, 0, 3, 0);

		char IsStatus[255];
		ZeroMemory(IsStatus, sizeof(IsStatus));
		wsprintf(IsStatus, "(%s)", pGetTextLine(pTextLineThis, GetStatus(it->second.GuildStatus)));
		SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
		g_pRenderText.CRenderText(a - (ACoord_X + BitMapRenderX), b + (ACoord_Y + 21), IsStatus, BitMapRenderW, 0, 3, 0);
	}

}
void CSCharacterS13::StatusInfo()
{
	VAngle Angle;
	//signed int v5;
	//signed int v6;
	int v48;
	int v49;
	//char nameClass[254];
	//float ForY = 21;

	#if SELECT_CHAR_INFO
	if (SelectedHero == 0)
	{
		GetBarSelectCharacter(v48, v49, 30, 0, 0);
	}
	else if (SelectedHero == 1)
	{
		GetBarSelectCharacter(v48, v49, 40, 0, 1);
	}
	else if (SelectedHero == 2)
	{
		GetBarSelectCharacter(v48, v49, 50, 5, 2);
	}
	else if (SelectedHero == 3)
	{
		GetBarSelectCharacter(v48, v49, 60, 4, 3);
	}
	else if (SelectedHero == 4)
	{
		GetBarSelectCharacter(v48, v49, 50, 5, 4);
	}
	else if (SelectedHero == 5)
	{
		GetBarSelectCharacter(v48, v49, 40, 12, 5);
	}
	else if (SelectedHero == 6)
	{
		GetBarSelectCharacter(v48, v49, 30, 15, 6);
	}
	#else
	for (int n = 0; n < 8; n++)
	{
		std::map<int, PMSG_CHARACTER_LIST>::iterator it = this->lpInfoPlayer.find(n);
		int fSize = 150;
		DWORD ViewportAddress = pGetPreviewStruct(pPreviewThis(), n);

		if (!ViewportAddress)
		{
			continue;
		}
		float BODY_X = GetPrivateProfileIntA("TEST", "BODY_X", 0, "./Settings.ini");
		float BODY_Y = GetPrivateProfileIntA("TEST", "BODY_Y", 0, "./Settings.ini");
		float BODY_W = GetPrivateProfileIntA("TEST", "BODY_W", 0, "./Settings.ini");
		float BODY_H = GetPrivateProfileIntA("TEST", "BODY_H", 0, "./Settings.ini");
		if (it != this->lpInfoPlayer.end())
		{
			Angle.X = *(float*)(ViewportAddress + 1028);
			Angle.Y = *(float*)(ViewportAddress + 1032);
			Angle.Z = *(float*)(ViewportAddress + 1036) + *(float*)(ViewportAddress + 0x3E8) + 350.0f;

			pGetPosFromAngle(&Angle, &v48, &v49);

			RenderBitmap(0x1791D, BODY_X, BODY_Y, BODY_W, BODY_H, 0, 0, 1, 1, 1, 1, 0.0);
			/*
			char ClassName[11] = { 0 };
			memcpy(ClassName, it->second.Name, sizeof(it->second.Name));
			
			
			char ClassCtl[255];
			ZeroMemory(ClassCtl, sizeof(ClassCtl));
			wsprintf(ClassCtl, "Chủng tộc: %s", (char*)JCGetClassname((unsigned __int8)sub_587380(it->second.CharSet[0])));
			SetTextColorByHDC(pTextThis(), pMakeColor(0xD8u, 0xA6u, 0x9u, 0xFFu));

			char ClassLevel[255];
			ZeroMemory(ClassLevel, sizeof(ClassLevel));
			wsprintf(ClassLevel, "Cấp độ: %d", it->second.Level);
			SetTextColorByHDC(pTextThis(), pMakeColor(0xD8u, 0xA6u, 0x9u, 0xFFu));

			char IsStatus[255];
			ZeroMemory(IsStatus, sizeof(IsStatus));
			wsprintf(IsStatus, "Trạng thái: %s", pGetTextLine(pTextLineThis, GetStatus(it->second.GuildStatus)));

			char IsReset[255];
			ZeroMemory(IsReset, sizeof(IsReset));
			wsprintf(IsReset, "Reset: %d lần", it->second.Reset);

			char IsRelife[255];
			ZeroMemory(IsRelife, sizeof(IsRelife));
			wsprintf(IsRelife, "Relife: %d lần", it->second.MasterReset);

			char mpDanhHieu[255];
			ZeroMemory(mpDanhHieu, sizeof(mpDanhHieu));
			wsprintf(mpDanhHieu, "Cấp độ danh hiệu: %d", it->second.pDanhHieu);

			char mpQuanHam[255];
			ZeroMemory(mpQuanHam, sizeof(mpQuanHam));
			wsprintf(mpQuanHam, "Cấp độ Quân Hàm: %d", it->second.pQuanHam);

			char mpTuChan[255];
			ZeroMemory(mpTuChan, sizeof(mpTuChan));
			wsprintf(mpTuChan, "Cấp độ Tu Chân: %d", it->second.pTuLuyen);

			char mpHonHoan[255];
			ZeroMemory(mpHonHoan, sizeof(mpHonHoan));
			wsprintf(mpHonHoan, "Cấp độ Hồn Hoàn: %d", it->second.pHonHoan);

			if (SelectedHero == n)
			{
				float BODY_W = 150.0f;
				float BODY_H = 120.0f;
				float BODY_X1 = 471.0f;
				float BODY_Y1 = 30.0f;
				gCentral.gInfoBox(BODY_X1 - 8, BODY_Y1 - 8, BODY_W, BODY_H, 200, 0, 0);
				pSetBackgroundTextColor(pTextThis(), 255, 255, 255, 0);
				GetColorCTCode(it->second.CtlCode);
				g_pRenderText.CRenderText(BODY_X1 + 0, BODY_Y1 + 4, ClassName, fSize - 15, 0, 4, 0);

				SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				g_pRenderText.CRenderText(BODY_X1 + 0, BODY_Y1 + 9, "__________________", fSize - 15, 0, 4, 0);
				//Class
				SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				g_pRenderText.CRenderText(BODY_X1 + 2, BODY_Y1 + 22, ClassCtl, fSize, 0, 1, 0);
				//cLevel
				SetTextColorByHDC(pTextThis(), pMakeColor(0xD8u, 0xA6u, 0x9u, 0xFFu));
				g_pRenderText.CRenderText(BODY_X1 + 2, BODY_Y1 + 32, ClassLevel, fSize, 0, 1, 0);
				//Status
				SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				g_pRenderText.CRenderText(BODY_X1 + 2, BODY_Y1 + 42, IsStatus, fSize, 0, 1, 0);
				//IsReset
				SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				g_pRenderText.CRenderText(BODY_X1 + 2, BODY_Y1 + 52, IsReset, fSize, 0, 1, 0);
				//IsRelife
				SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				g_pRenderText.CRenderText(BODY_X1 + 2, BODY_Y1 + 62, IsRelife, fSize, 0, 1, 0);
				//IsDanhHieu
				SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				g_pRenderText.CRenderText(BODY_X1 + 2, BODY_Y1 + 72, mpDanhHieu, fSize, 0, 1, 0);
				//IsQuanHam
				SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				g_pRenderText.CRenderText(BODY_X1 + 2, BODY_Y1 + 82, mpQuanHam, fSize, 0, 1, 0);
				//IsTuChan
				SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				g_pRenderText.CRenderText(BODY_X1 + 2, BODY_Y1 + 92, mpTuChan, fSize, 0, 1, 0);
				//IsDanhHieu
				SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
				g_pRenderText.CRenderText(BODY_X1 + 2, BODY_Y1 + 102, mpHonHoan, fSize, 0, 1, 0);
			}
			int SPK_DANHHIEU_LVL = it->second.pDanhHieu;
			int SPK_QUANHAM_LVL = it->second.pQuanHam;
			int SPK_TULUYEN_LVL = it->second.pTuLuyen;

			if (SPK_DANHHIEU_LVL >= 1 && SPK_DANHHIEU_LVL <= MAX_LEVEL_DANH_HIEU)
			{
				glColor3f(1.0, 1.0, 1.0);
				RenderBitmap(SPK_DANHHIEU_IMG + SPK_DANHHIEU_LVL, v48 - 35, v49, 100.0f, 100.0f, 0, 0, 1, 1, 1, 1, 0.0);
			}
			if (SPK_QUANHAM_LVL >= 1 && SPK_QUANHAM_LVL <= MAX_LEVEL_QUAN_HAM)
			{
				glColor3f(1.0, 1.0, 1.0);
				RenderBitmap(SPK_QUANHAM_IMG + SPK_QUANHAM_LVL, v48 - 22, v49 - 5, 70, 56, 0, 0, 1, 1, 1, 1, 0.0);
			}
			if (SPK_TULUYEN_LVL >= 1 && SPK_TULUYEN_LVL <= MAX_LEVEL_TU_LUYEN)
			{
				glColor3f(1.0, 1.0, 1.0);
				RenderBitmap(SPK_TULUYEN_IMG + SPK_TULUYEN_LVL, v48 - 15, v49 - 10, 60, 20, 0, 0, 1, 1, 1, 1, 0.0);
			}
			*/
		}
	}
	#endif
}
int sub_402A80(int a1)
{
	if (pPlayerState == 4) //Select Character
	{
		gCSCharacterS13.StatusInfo();
	}
	return 1;
}

void CSCharacterS13::initCharacter()
{
	#if(MAX_CHAR > 5)
	SetByte(0x004057E5, 0x5);
	SetByte(0x00405881, 0x5);
	SetByte(0x004D6F66, 0x5);
	SetByte(0x004D7075, 0x4);
	SetByte(0x004D70B0, 0x4);
	SetByte(0x004D71E0, 0x5);
	SetByte(0x004D72C7, 0x5);
	#endif
	
	SetByte(0x00402106, 0);
	SetDouble(0xD25508, 1);

	SetCompleteHook(0xE9, 0x00587620, &JCGetClassname);
	SetCompleteHook(0xE9, 0x0063D3D0, &JGCreateCharRecv);
	SetCompleteHook(0xE9, 0x0063D5E0, &PushBackPlayer);
	SetCompleteHook(0xE8, 0x004849C0, &sub_402A80);	
}