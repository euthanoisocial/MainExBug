#include "stdafx.h"
#include "Ranking.h"
#include "Import.h"
#include "Defines.h"
#include "Interface.h"
#include "Util.h"
#include "CustomMap.h"
#include "Controller.h"
#include "PartySearch.h"
#include "Central.h"
#include "User.h"
#include "WindowsStruct.h"
#include "CustomFont.h"
#include "UIControl.h"
#include "SPK_ToolKit.h"
#include "Import.h"
#include "Config.h"
#include "Console.h"
#include "ViewCharItem.h"
#include "SPK_FixSolution.h"
cRanking gRanking;

char* CharacterCode(int a)
{
	switch (a)
	{
		case 0:  return pGetTextLine(pTextLineThis, 20);
		case 1:  return pGetTextLine(pTextLineThis, 25);
		case 2:  return pGetTextLine(pTextLineThis, 1669);
		case 3:  return pGetTextLine(pTextLineThis, 1669);
		case 16: return pGetTextLine(pTextLineThis, 21);
		case 17: return pGetTextLine(pTextLineThis, 26);
		case 18: return pGetTextLine(pTextLineThis, 1668);
		case 19: return pGetTextLine(pTextLineThis, 1668);
		case 32: return pGetTextLine(pTextLineThis, 22);
		case 33: return pGetTextLine(pTextLineThis, 27);
		case 34: return pGetTextLine(pTextLineThis, 1670);
		case 35: return pGetTextLine(pTextLineThis, 1670);
		case 48: return pGetTextLine(pTextLineThis, 23);
		case 50: return pGetTextLine(pTextLineThis, 1671);
		case 66: return pGetTextLine(pTextLineThis, 24);
		case 67: return pGetTextLine(pTextLineThis, 24);
		case 64: return pGetTextLine(pTextLineThis, 24);
		case 65: return pGetTextLine(pTextLineThis, 24);
		case 68: return pGetTextLine(pTextLineThis, 1672);
		case 80: return pGetTextLine(pTextLineThis, 1687);
		case 81: return pGetTextLine(pTextLineThis, 1688);
		case 82: return pGetTextLine(pTextLineThis, 1689);
		case 83: return pGetTextLine(pTextLineThis, 1689);
		case 96: return pGetTextLine(pTextLineThis, 3150);
		case 97: return pGetTextLine(pTextLineThis, 3151);
		case 98: return pGetTextLine(pTextLineThis, 3151);
	}
	return "unknown";
}
cRanking::cRanking()
{
	this->Active = true;
	this->Show = false;
	this->StartX = 0;
	this->StartY = 0;
	this->Page = 1;
	this->ClickTick = 0;
	this->TrangRanking = 1;
}
void cRanking::SendMenuButton()
{
	UP_SEND_REQ pRequest;
	pRequest.h.set(0x7A, 0x01, sizeof(pRequest));
	DataSend((BYTE*)&pRequest, pRequest.h.size);

	this->Show = true;
}
void cRanking::BingImg()
{
	gInterface.BindObject(ChonTopRs,	0x7AE5, 15, 13, -1, -1);
	gInterface.BindObject(ChonTopNap,	0x7AE5, 15, 13, -1, -1);
	gInterface.BindObject(ChonTopGuild,	0x7AE5, 15, 13, -1, -1);
	gInterface.BindObject(ChonTopPK,	0x7AE5, 15, 13, -1, -1);
	gInterface.BindObject(ChonTopEvent,	0x7AE5, 15, 13, -1, -1);

	gInterface.BindObject(ChonTopDW, 0x7AE5, 15, 13, -1, -1);
	gInterface.BindObject(ChonTopDK, 0x7AE5, 15, 13, -1, -1);
	gInterface.BindObject(ChonTopEF, 0x7AE5, 15, 13, -1, -1);
	gInterface.BindObject(ChonTopMG, 0x7AE5, 15, 13, -1, -1);
	gInterface.BindObject(ChonTopDL, 0x7AE5, 15, 13, -1, -1);
	gInterface.BindObject(ChonTopSM, 0x7AE5, 15, 13, -1, -1);
	gInterface.BindObject(ChonTopRF, 0x7AE5, 15, 13, -1, -1);
}
void cRanking::GetPacketSender(DWORD ClickMouse, DWORD Delay, BYTE Pages, int Packet)
{
	if (ClickMouse == WM_LBUTTONDOWN)
	{
		pSetCursorFocus = true;
		return;
	}
	if (Delay < 300)
	{
		return;
	}
	if (TrangRanking = Pages)
	{
		ClickTick = GetTickCount();
		UP_SEND_REQ pRequest;
		pRequest.h.set(0x7A, Packet, sizeof(pRequest));
		DataSend((BYTE*)&pRequest, pRequest.h.size);
	}
}

void cRanking::ClickRanking(DWORD ClickMouse)
{
	if (!this->Active) return;
	if (!this->Show) return;
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - ClickTick);

	if (gInterface.IsWorkZone(ChonTopRs))
	{
		this->GetPacketSender(ClickMouse, Delay, 1, 0x01);
	}
	if (gInterface.IsWorkZone(ChonTopNap))
	{
		this->GetPacketSender(ClickMouse, Delay, 2, 0x02);
	}
	if (gInterface.IsWorkZone(ChonTopGuild))
	{
		this->GetPacketSender(ClickMouse, Delay, 3, 0x03);
	}
	if (gInterface.IsWorkZone(ChonTopPK))
	{
		this->GetPacketSender(ClickMouse, Delay, 4, 0x04);
	}
	if (gInterface.IsWorkZone(ChonTopEvent))
	{
		this->GetPacketSender(ClickMouse, Delay, 5, 0x05);
	}
	if (gInterface.IsWorkZone(ChonTopDW))
	{
		this->GetPacketSender(ClickMouse, Delay, 6, 0x06);
	}
	if (gInterface.IsWorkZone(ChonTopDK))
	{
		this->GetPacketSender(ClickMouse, Delay, 7, 0x07);
	}
	if (gInterface.IsWorkZone(ChonTopEF))
	{
		this->GetPacketSender(ClickMouse, Delay, 8, 0x08);
	}
	if (gInterface.IsWorkZone(ChonTopMG))
	{
		this->GetPacketSender(ClickMouse, Delay, 9, 0x09);
	}
	if (gInterface.IsWorkZone(ChonTopDL))
	{
		this->GetPacketSender(ClickMouse, Delay, 10, 0x0A);
	}
	if (gInterface.IsWorkZone(ChonTopSM))
	{
		this->GetPacketSender(ClickMouse, Delay, 11, 0x0B);
	}
	if (gInterface.IsWorkZone(ChonTopRF))
	{
		this->GetPacketSender(ClickMouse, Delay, 12, 0x0C);
	}
}
void cRanking::RecvInfo(DGCharTop * lpMsg)
{
	for (int i = 0; i<MAXTOP; i++)
	{
		strncpy(this->RankingChar[i].Name,		lpMsg->tp[i].Name, 11);

		this->RankingChar[i].Is_Class = lpMsg->tp[i].Is_Class;
		this->RankingChar[i].Is_cLevel = lpMsg->tp[i].Is_cLevel;
		this->RankingChar[i].Is_ResetCount = lpMsg->tp[i].Is_ResetCount;
		this->RankingChar[i].Is_MasterResetCount = lpMsg->tp[i].Is_MasterResetCount;
		this->RankingChar[i].Is_ResetTime = lpMsg->tp[i].Is_ResetTime;
		this->RankingChar[i].Is_TotalPoint = lpMsg->tp[i].Is_TotalPoint;
		strncpy(this->RankingChar[i].Is_SvSub, lpMsg->tp[i].Is_SvSub, 9);
	}
}
void cRanking::RecvInfoNap(DGCharTopNap* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharNap[i].Name, lpMsg->tp[i].Name, 11);
		this->RankingCharNap[i].Is_Class = lpMsg->tp[i].Is_Class;
		this->RankingCharNap[i].Is_TotalCoin = lpMsg->tp[i].Is_TotalCoin;
		strncpy(this->RankingCharNap[i].Is_JoinDate, lpMsg->tp[i].Is_JoinDate, 22);
		strncpy(this->RankingCharNap[i].Is_LastDate, lpMsg->tp[i].Is_LastDate, 22);
	}
}
void cRanking::RecvInfoET(DGCharTopET* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharET[i].Name, lpMsg->tp[i].Name, 11);
		this->RankingCharET[i].Is_BloodCS = lpMsg->tp[i].Is_BloodCS;
		this->RankingCharET[i].Is_ChaosCS = lpMsg->tp[i].Is_ChaosCS;
		this->RankingCharET[i].Is_DevilCS = lpMsg->tp[i].Is_DevilCS;
	}
}
void cRanking::RecvInfoTG(DGCharTopTG* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharTG[i].G_Name, lpMsg->tp[i].G_Name, 9);
		strncpy(this->RankingCharTG[i].G_Master, lpMsg->tp[i].G_Master, 11);
		this->RankingCharTG[i].Is_GLevel = lpMsg->tp[i].Is_GLevel;
		this->RankingCharTG[i].Is_GScore = lpMsg->tp[i].Is_GScore;
		this->RankingCharTG[i].Is_GMem = lpMsg->tp[i].Is_GMem;
		strncpy(this->RankingCharTG[i].Is_JoinDate, lpMsg->tp[i].Is_JoinDate, 22);
	}
}
void cRanking::RecvInfoPK(DGCharTopPK* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharPK[i].Name, lpMsg->tp[i].Name, 11);
		this->RankingCharPK[i].Is_Kills = lpMsg->tp[i].Is_Kills;
		this->RankingCharPK[i].Is_Deads = lpMsg->tp[i].Is_Deads;
		this->RankingCharPK[i].Is_OnlineHours = lpMsg->tp[i].Is_OnlineHours;
		this->RankingCharPK[i].Is_Win = lpMsg->tp[i].Is_Win;
		this->RankingCharPK[i].Is_Lose = lpMsg->tp[i].Is_Lose;
		this->RankingCharPK[i].Is_Kboss = lpMsg->tp[i].Is_Kboss;
		strncpy(this->RankingCharPK[i].Is_JoinDate, lpMsg->tp[i].Is_JoinDate, 22);
	}
}

void cRanking::RecvInfoDW(DGCharTopDW* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharDW[i].Name, lpMsg->tp[i].Name, 11);

		this->RankingCharDW[i].Is_Class = lpMsg->tp[i].Is_Class;
		this->RankingCharDW[i].Is_cLevel = lpMsg->tp[i].Is_cLevel;
		this->RankingCharDW[i].Is_ResetCount = lpMsg->tp[i].Is_ResetCount;
		this->RankingCharDW[i].Is_MasterResetCount = lpMsg->tp[i].Is_MasterResetCount;
		this->RankingCharDW[i].Is_ResetTime = lpMsg->tp[i].Is_ResetTime;
		this->RankingCharDW[i].Is_TotalPoint = lpMsg->tp[i].Is_TotalPoint;
		strncpy(this->RankingCharDW[i].Is_SvSub, lpMsg->tp[i].Is_SvSub, 9);
	}
}
//
void cRanking::RecvInfoDK(DGCharTopDK* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharDK[i].Name, lpMsg->tp[i].Name, 11);

		this->RankingCharDK[i].Is_Class = lpMsg->tp[i].Is_Class;
		this->RankingCharDK[i].Is_cLevel = lpMsg->tp[i].Is_cLevel;
		this->RankingCharDK[i].Is_ResetCount = lpMsg->tp[i].Is_ResetCount;
		this->RankingCharDK[i].Is_MasterResetCount = lpMsg->tp[i].Is_MasterResetCount;
		this->RankingCharDK[i].Is_ResetTime = lpMsg->tp[i].Is_ResetTime;
		this->RankingCharDK[i].Is_TotalPoint = lpMsg->tp[i].Is_TotalPoint;
		strncpy(this->RankingCharDK[i].Is_SvSub, lpMsg->tp[i].Is_SvSub, 9);
	}
}
//
void cRanking::RecvInfoEF(DGCharTopEF* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharEF[i].Name, lpMsg->tp[i].Name, 11);

		this->RankingCharEF[i].Is_Class = lpMsg->tp[i].Is_Class;
		this->RankingCharEF[i].Is_cLevel = lpMsg->tp[i].Is_cLevel;
		this->RankingCharEF[i].Is_ResetCount = lpMsg->tp[i].Is_ResetCount;
		this->RankingCharEF[i].Is_MasterResetCount = lpMsg->tp[i].Is_MasterResetCount;
		this->RankingCharEF[i].Is_ResetTime = lpMsg->tp[i].Is_ResetTime;
		this->RankingCharEF[i].Is_TotalPoint = lpMsg->tp[i].Is_TotalPoint;
		strncpy(this->RankingCharEF[i].Is_SvSub, lpMsg->tp[i].Is_SvSub, 9);
	}
}
//
void cRanking::RecvInfoMG(DGCharTopMG* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharMG[i].Name, lpMsg->tp[i].Name, 11);

		this->RankingCharMG[i].Is_Class = lpMsg->tp[i].Is_Class;
		this->RankingCharMG[i].Is_cLevel = lpMsg->tp[i].Is_cLevel;
		this->RankingCharMG[i].Is_ResetCount = lpMsg->tp[i].Is_ResetCount;
		this->RankingCharMG[i].Is_MasterResetCount = lpMsg->tp[i].Is_MasterResetCount;
		this->RankingCharMG[i].Is_ResetTime = lpMsg->tp[i].Is_ResetTime;
		this->RankingCharMG[i].Is_TotalPoint = lpMsg->tp[i].Is_TotalPoint;
		strncpy(this->RankingCharMG[i].Is_SvSub, lpMsg->tp[i].Is_SvSub, 9);
	}
}
//
void cRanking::RecvInfoDL(DGCharTopDL* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharDL[i].Name, lpMsg->tp[i].Name, 11);

		this->RankingCharDL[i].Is_Class = lpMsg->tp[i].Is_Class;
		this->RankingCharDL[i].Is_cLevel = lpMsg->tp[i].Is_cLevel;
		this->RankingCharDL[i].Is_ResetCount = lpMsg->tp[i].Is_ResetCount;
		this->RankingCharDL[i].Is_MasterResetCount = lpMsg->tp[i].Is_MasterResetCount;
		this->RankingCharDL[i].Is_ResetTime = lpMsg->tp[i].Is_ResetTime;
		this->RankingCharDL[i].Is_TotalPoint = lpMsg->tp[i].Is_TotalPoint;
		strncpy(this->RankingCharDL[i].Is_SvSub, lpMsg->tp[i].Is_SvSub, 9);
	}
}
//
void cRanking::RecvInfoSM(DGCharTopSM* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharSM[i].Name, lpMsg->tp[i].Name, 11);

		this->RankingCharSM[i].Is_Class = lpMsg->tp[i].Is_Class;
		this->RankingCharSM[i].Is_cLevel = lpMsg->tp[i].Is_cLevel;
		this->RankingCharSM[i].Is_ResetCount = lpMsg->tp[i].Is_ResetCount;
		this->RankingCharSM[i].Is_MasterResetCount = lpMsg->tp[i].Is_MasterResetCount;
		this->RankingCharSM[i].Is_ResetTime = lpMsg->tp[i].Is_ResetTime;
		this->RankingCharSM[i].Is_TotalPoint = lpMsg->tp[i].Is_TotalPoint;
		strncpy(this->RankingCharSM[i].Is_SvSub, lpMsg->tp[i].Is_SvSub, 9);
	}
}
//
void cRanking::RecvInfoRF(DGCharTopRF* lpMsg)
{
	for (int i = 0; i < MAXTOP; i++)
	{
		strncpy(this->RankingCharRF[i].Name, lpMsg->tp[i].Name, 11);

		this->RankingCharRF[i].Is_Class = lpMsg->tp[i].Is_Class;
		this->RankingCharRF[i].Is_cLevel = lpMsg->tp[i].Is_cLevel;
		this->RankingCharRF[i].Is_ResetCount = lpMsg->tp[i].Is_ResetCount;
		this->RankingCharRF[i].Is_MasterResetCount = lpMsg->tp[i].Is_MasterResetCount;
		this->RankingCharRF[i].Is_ResetTime = lpMsg->tp[i].Is_ResetTime;
		this->RankingCharRF[i].Is_TotalPoint = lpMsg->tp[i].Is_TotalPoint;
		strncpy(this->RankingCharRF[i].Is_SvSub, lpMsg->tp[i].Is_SvSub, 9);
	}
}

void cRanking::GCReqInfoCharTop(DATA_VIEWTOPRANKING* lpMsg)
{
	this->CacheUserRank = true;
	ZeroMemory(&this->CacheDataUserTop, sizeof(&this->CacheDataUserTop));
	memcpy(&this->CacheDataUserTop, lpMsg, sizeof(this->CacheDataUserTop));
	ViewCharItems.ClearSession();
	memcpy(&ViewCharItems.charItem.Guild[0], &this->CacheDataUserTop.GuildName[0], sizeof(ViewCharItems.charItem.Guild));
}
#define _DWORD		DWORD
#define B0042CFE0	((int (__thiscall*)(int This, unsigned int  a2)) 0x0042CFE0)
void __cdecl BCreateGuildMark(BYTE* mGuildMark, bool a2)
{
	int k; // [esp+4h] [ebp-24h]
	int j; // [esp+8h] [ebp-20h]
	int i; // [esp+Ch] [ebp-1Ch]
	_DWORD* v5; // [esp+10h] [ebp-18h]
	int* v6; // [esp+14h] [ebp-14h]
	BYTE* v7; // [esp+18h] [ebp-10h]
	int height; // [esp+1Ch] [ebp-Ch]
	int width; // [esp+20h] [ebp-8h]
	int v10; // [esp+24h] [ebp-4h]

	DWORD* dword_81C0450 = &*(DWORD*)0x81C0450;
	BYTE* byte_81CB59E = &*(BYTE*)0x81CB59E;
	v6 = (int*)B0042CFE0((int)0x9816AA0, 0x7BFCu);
	width = (int)*((float*)v6 + 65);
	height = (int)*((float*)v6 + 66);
	v5 = *(_DWORD**)((char*)v6 + 282);
	v10 = 128;
	if (a2)
	{
		v10 = 0;
	}

	for (int i = 0; i < 16; i++)
	{
		switch (i)
		{
			case 0:dword_81C0450[i] = (v10 << 24) + (0 << 16) + (0 << 8) + (0); break;
			case 1:dword_81C0450[i] = (255 << 24) + (0 << 16) + (0 << 8) + (0); break;
			case 2:dword_81C0450[i] = (255 << 24) + (128 << 16) + (128 << 8) + (128); break;
			case 3:dword_81C0450[i] = (255 << 24) + (255 << 16) + (255 << 8) + (255); break;
			case 4:dword_81C0450[i] = (255 << 24) + (0 << 16) + (0 << 8) + (255); break;
			case 5:dword_81C0450[i] = (255 << 24) + (0 << 16) + (128 << 8) + (255); break;
			case 6:dword_81C0450[i] = (255 << 24) + (0 << 16) + (255 << 8) + (255); break;
			case 7:dword_81C0450[i] = (255 << 24) + (0 << 16) + (255 << 8) + (128); break;
			case 8:dword_81C0450[i] = (255 << 24) + (0 << 16) + (255 << 8) + (0); break;
			case 9:dword_81C0450[i] = (255 << 24) + (128 << 16) + (255 << 8) + (0); break;
			case 10:dword_81C0450[i] = (255 << 24) + (255 << 16) + (255 << 8) + (0); break;
			case 11:dword_81C0450[i] = (255 << 24) + (255 << 16) + (128 << 8) + (0); break;
			case 12:dword_81C0450[i] = (255 << 24) + (255 << 16) + (0 << 8) + (0); break;
			case 13:dword_81C0450[i] = (255 << 24) + (255 << 16) + (0 << 8) + (128); break;
			case 14:dword_81C0450[i] = (255 << 24) + (255 << 16) + (0 << 8) + (255); break;
			case 15:dword_81C0450[i] = (255 << 24) + (128 << 16) + (0 << 8) + (255); break;
		}
	}
	BYTE GuildMark[64] = { 0 };
	for (int i = 0; i < 64; ++i)
	{
		if (i % 2 == 0)
			GuildMark[i] = (mGuildMark[i / 2] >> 4) & 0x0f;
		else
			GuildMark[i] = mGuildMark[i / 2] & 0x0f;
	}

	v7 = &*(BYTE*)GuildMark; //Mark
	for (j = 0; j < height; ++j)
	{
		for (k = 0; k < width; ++k)
			*v5++ = dword_81C0450[(unsigned __int8)*v7++];
	}
	glBindTexture(0xDE1u, *(_DWORD*)((char*)v6 + 277));
	glTexImage2D(0xDE1u, 0, *((char*)v6 + 276), width, height, 0, 0x1908u, 0x1401u, *(const GLvoid**)((char*)v6 + 282));
}
void cRanking::LoadImg()
{
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BTopRs.tga", 0x17AF0, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BTopNap.tga", 0x17BF1, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BGuild.tga", 0x17AF2, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BPkCount.tga", 0x17AF3, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BEvent.tga", 0x17AF4, GL_LINEAR, GL_CLAMP, 1, 0);

	LoadBitmapA("SPK\\MacroUI\\MacroUI_BDW.tga", 0x17AF5, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BDK.tga", 0x17AF6, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BEF.tga", 0x17AF7, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BMG.tga", 0x17AF8, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BDL.tga", 0x17AF9, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BSM.tga", 0x17AFA, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\MacroUI\\MacroUI_BRF.tga", 0x17AFB, GL_LINEAR, GL_CLAMP, 1, 0);
}
void GetInfoCharTop(char* Name)
{
	if (GetTickCount() < gInterface.Data[eRankPANEL_MAIN].EventTick + 300) return;
	gInterface.Data[eRankPANEL_MAIN].EventTick = GetTickCount();

	REQUESTINFO_CHARTOP pMsg;
	pMsg.header.set(0xD3, 0x40, sizeof(pMsg));
	pMsg.aIndex = 0;
	memcpy(pMsg.NameChar, Name, sizeof(pMsg.NameChar) - 1);
	DataSend((LPBYTE)&pMsg, pMsg.header.size);
}

void cRanking::Draw()
{
	if (gInterface.Data[eChangePass_Main].OnShow)
	{
		return;
	}
	if (!this->Active) return;
	if (!this->Show) return;
	float MainWidth = 445.0 + 160.0;
	float MainHeight = 364.0;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float StatusDotY = 75.70f;
	#if BXH_LUCHIEN
	int CloseX = StartX + MainWidth - 33.0f;
	int CloseY = StartY;
	#endif

	gInterface.Data[eMAIN_RANKING].MaxX = StartX + MainWidth;
	gInterface.Data[eMAIN_RANKING].MaxY = StartY + MainHeight;

	RenderBitmap(0x1791E, StartX + 130, StartY, 375, 600, 0, 0, 1, 1, 1, 1, 0.0);
	RenderBitmap(0x17920, StartX + 130, StartY, 375, 130, 0, 0, 1, 1, 1, 1, 0.0);

	if (pCheckMouseOver(CloseX - 135, CloseY + 8, 36, 36) == 1)
	{
		if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - this->ClickTime > 300)
		{
			if (GetKeyState(1) & 0x8000)
			{
				gCentral.LockMouse = GetTickCount() + 500;
				this->ClickTime = GetTickCount();
				gRanking.Show = false;
			}
		}
	}
	pSetCursorFocus = true;

	float PosY_Add = 55;

	gToolKit.DrawButtonIconRank(ChonTopRs,		0x17AF0,	StartX + 140, StartY + 30, "Top Reset");
	gToolKit.DrawButtonIconRank(ChonTopNap,		0x17BF1,	StartX + 155, StartY + 30, "Top Nap");
	gToolKit.DrawButtonIconRank(ChonTopGuild,	0x17AF3,	StartX + 170, StartY + 30, "Top PK");
	gToolKit.DrawButtonIconRank(ChonTopPK,		0x17AF2,	StartX + 185, StartY + 30, "Top Guild");
	gToolKit.DrawButtonIconRank(ChonTopEvent,	0x17AF4,	StartX + 200, StartY + 30, "Top Event");

	gToolKit.DrawButtonIconRank(ChonTopDW,		0x17AF5,	StartX + 215 + 135, StartY + 335, "Top DW");
	gToolKit.DrawButtonIconRank(ChonTopDK,		0x17AF6,	StartX + 230 + 135, StartY + 335, "Top DK");
	gToolKit.DrawButtonIconRank(ChonTopEF,		0x17AF7,	StartX + 245 + 135, StartY + 335, "Top EF");
	gToolKit.DrawButtonIconRank(ChonTopMG,		0x17AF8,	StartX + 260 + 135, StartY + 335, "Top MG");
	gToolKit.DrawButtonIconRank(ChonTopDL,		0x17AF9,	StartX + 275 + 135, StartY + 335, "Top DL");
	gToolKit.DrawButtonIconRank(ChonTopSM,		0x17AFA,	StartX + 290 + 135, StartY + 335, "Top SM");
	gToolKit.DrawButtonIconRank(ChonTopRF,		0x17AFB,	StartX + 305 + 135, StartY + 335, "Top RF");

	CustomFont.Draw((HFONT)pFontBold, StartX + 147,		StartY + 62, 0x0, 0x00FBFF69, 317, 0, 3, " ");

	
	switch (TrangRanking)
	{
		case 1:
		gInterface.DrawFormat(eWhite, StartX + 105, StartY + 62, 100, 3,"TOP");
		gInterface.DrawFormat(eWhite, StartX + 135, StartY + 62, 100, 3,"NAME");
		gInterface.DrawFormat(eWhite, StartX + 185, StartY + 62, 100, 3,"CLASS");
		gInterface.DrawFormat(eWhite, StartX + 230, StartY + 62, 100, 3,"LV/RS/RL");
		gInterface.DrawFormat(eWhite, StartX + 270, StartY + 62, 100, 3,"POINTS");
		gInterface.DrawFormat(eWhite, StartX + 325, StartY + 62, 100, 3,"ROOM");
		gInterface.DrawFormat(eWhite, StartX + 385, StartY + 62, 100, 3,"LAST RESET");
		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char NameID[11];
			char ROOM[9];
			int up = i + ((this->Page - 1) * iMaxCount);
			if (this->RankingChar[up].Name[0] == NULL) continue;
			memcpy(NameID, this->RankingChar[up].Name, sizeof(this->RankingChar[up].Name));
			memcpy(ROOM, this->RankingChar[up].Is_SvSub, sizeof(this->RankingChar[up].Is_SvSub));

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			time_t mTime; tm* lpTime = NULL;
			mTime = this->RankingChar[up].Is_ResetTime;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;	mMonth = 1 + lpTime->tm_mon; mDays = lpTime->tm_mday; hours = lpTime->tm_hour; minutes = lpTime->tm_min; seconds = lpTime->tm_sec;
			}

			if (i >= 0 && i <= 2)
			{
				Color = eGold;
			}
			else
			{
				Color = eWhite;
			}
			
			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 135, StartY + 75 + (i * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 185, StartY + 75 + (i * MAX_LINE), 100, 3, CharacterCode(this->RankingChar[up].Is_Class));
			gInterface.DrawFormat(Color, StartX + 230, StartY + 75 + (i * MAX_LINE), 100, 3, "%d/%d/%d",this->RankingChar[up].Is_cLevel, this->RankingChar[up].Is_ResetCount, this->RankingChar[up].Is_MasterResetCount);
			gInterface.DrawFormat(Color, StartX + 270, StartY + 75 + (i * MAX_LINE), 100, 3, "%s",gToolKit.QNumberFormat(this->RankingChar[up].Is_TotalPoint));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, ROOM);
			gInterface.DrawFormat(Color, StartX + 385, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d:%02d:%02d [%02d/%02d]", hours, minutes, seconds, mDays, mMonth);
			
			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 150, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 310, 0, 3, " ");
			}
		}
		break;
		case 2:		
		gInterface.DrawFormat(eWhite, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eWhite, StartX + 135, StartY + 62, 100, 3, "NAME");
		gInterface.DrawFormat(eWhite, StartX + 185, StartY + 62, 100, 3, "CLASS");
		gInterface.DrawFormat(eWhite, StartX + 230, StartY + 62, 100, 3, "ATM NẠP");
		gInterface.DrawFormat(eWhite, StartX + 300, StartY + 62, 100, 3, "NGÀY GIA NHẬP");
		gInterface.DrawFormat(eWhite, StartX + 375, StartY + 62, 100, 3, "LẦN NẠP CUỐI");
		for (int Coin = 0; Coin < iMaxCount; Coin++)
		{
			DWORD Color;
			char NameID[11];
			char OnMyDate[30];
			char LastDate[30];
			int up = Coin + ((this->Page - 1) * iMaxCount);
			if (this->RankingCharNap[up].Name[0] == NULL) continue;
			memcpy(NameID, this->RankingCharNap[up].Name, sizeof(this->RankingCharNap[up].Name));
			memcpy(OnMyDate, this->RankingCharNap[up].Is_JoinDate, sizeof(this->RankingCharNap[up].Is_JoinDate));
			memcpy(LastDate, this->RankingCharNap[up].Is_LastDate, sizeof(this->RankingCharNap[up].Is_LastDate));

			char NgayThamGia[24];
			sprintf(NgayThamGia, "%c%c:%c%c:%c%c %c%c/%c%c/%c%c%c%c",OnMyDate[11], OnMyDate[12],OnMyDate[14], OnMyDate[15],OnMyDate[17], OnMyDate[18],	OnMyDate[8], OnMyDate[9], OnMyDate[5], OnMyDate[6],	OnMyDate[0], OnMyDate[1], OnMyDate[2], OnMyDate[3]);

			char LanNapSauCung[24];	
			sprintf(LanNapSauCung, "%c%c:%c%c:%c%c %c%c/%c%c/%c%c%c%c", LastDate[11], LastDate[12], LastDate[14], LastDate[15],LastDate[17], LastDate[18],	LastDate[8], LastDate[9], LastDate[5], LastDate[6], LastDate[0], LastDate[1], LastDate[2], LastDate[3]);

			if (Coin >= 0 && Coin <= 2)	{Color = eGold;}else{Color = eWhite;}

			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (Coin * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 135, StartY + 75 + (Coin * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 185, StartY + 75 + (Coin * MAX_LINE), 100, 3, CharacterCode(this->RankingCharNap[up].Is_Class));
			gInterface.DrawFormat(Color, StartX + 230, StartY + 75 + (Coin * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharNap[up].Is_TotalCoin));
			gInterface.DrawFormat(Color, StartX + 300, StartY + 75 + (Coin * MAX_LINE), 100, 3, NgayThamGia);
			if (LanNapSauCung[0] == 0)
			{
				gInterface.DrawFormat(Color, StartX + 375, StartY + 75 + (Coin * MAX_LINE), 100, 3, "N/A");
			}
			else
			{
				gInterface.DrawFormat(Color, StartX + 375, StartY + 75 + (Coin * MAX_LINE), 100, 3, LanNapSauCung);
			}
			if (pCheckMouseOver(StartX + 151, StartY + 75 + (Coin * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 150, StartY + 75 + (Coin * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 310, 0, 3, " ");
			}
		}
		break;
		case 3:
		gInterface.DrawFormat(eYellow, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eYellow, StartX + 130, StartY + 62, 100, 3, "NAME");
		gInterface.DrawFormat(eYellow, StartX + 175, StartY + 62, 100, 3, "BLOOD CS");
		gInterface.DrawFormat(eYellow, StartX + 225, StartY + 62, 100, 3, "CHAOS CS");
		gInterface.DrawFormat(eYellow, StartX + 275, StartY + 62, 100, 3, "DEVIL CS");
		gInterface.DrawFormat(eYellow, StartX + 325, StartY + 62, 100, 3, "I-TEMPLE");
		gInterface.DrawFormat(eYellow, StartX + 375, StartY + 62, 100, 3, "KING PLAYER");

		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char NameID[11];
			int up = i + ((this->Page - 1) * iMaxCount);
			if (this->RankingCharET[up].Name[0] == NULL) continue;
			memcpy(NameID, this->RankingCharET[up].Name, sizeof(this->RankingCharET[up].Name));
			NameID[sizeof(NameID) - 1] = '\0';

			if (i >= 0 && i <= 2) { Color = eGold; }
			else { Color = eWhite; }

			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 130, StartY + 75 + (i * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 175, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharET[up].Is_BloodCS));
			gInterface.DrawFormat(Color, StartX + 225, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharET[up].Is_ChaosCS));
			gInterface.DrawFormat(Color, StartX + 275, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharET[up].Is_DevilCS));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, "0");
			gInterface.DrawFormat(Color, StartX + 375, StartY + 75 + (i * MAX_LINE), 100, 3, "0");

			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 147, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 317, 0, 3, " ");
			}
		}
		break;
		case 4:
		gInterface.DrawFormat(eYellow, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eYellow, StartX + 130, StartY + 62, 100, 3, "GUILD");
		gInterface.DrawFormat(eYellow, StartX + 175, StartY + 62, 100, 3, "CẤP ĐỘ");
		gInterface.DrawFormat(eYellow, StartX + 225, StartY + 62, 100, 3, "CHỦ GUILD");
		gInterface.DrawFormat(eYellow, StartX + 275, StartY + 62, 100, 3, "ĐIỂM GUILD");
		gInterface.DrawFormat(eYellow, StartX + 325, StartY + 62, 100, 3, "THÀNH VIÊN");
		gInterface.DrawFormat(eYellow, StartX + 375, StartY + 62, 100, 3, "NGÀY TẠO");

		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char G_Name[11];
			char G_Master[11];
			char OnMyDate[30];
			int up = i + ((this->Page - 1) * iMaxCount);

			if (this->RankingCharTG[up].G_Master[0] == NULL) continue;

			memcpy(G_Master, this->RankingCharTG[up].G_Master, sizeof(this->RankingCharTG[up].G_Master));
			memcpy(G_Name, this->RankingCharTG[up].G_Name, sizeof(this->RankingCharTG[up].G_Name));
			memcpy(OnMyDate, this->RankingCharTG[up].Is_JoinDate, sizeof(this->RankingCharTG[up].Is_JoinDate));

			if (i >= 0 && i <= 2) { Color = eGold; }
			else { Color = eWhite; }

			char ReversedDateTime[20];
			sprintf(ReversedDateTime, "%c%c:%c%c:%c%c %c%c-%c%c",
				OnMyDate[11], OnMyDate[12],
				OnMyDate[14], OnMyDate[15],
				OnMyDate[17], OnMyDate[18],
				OnMyDate[8], OnMyDate[9],
				OnMyDate[5], OnMyDate[6]);


			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 130, StartY + 75 + (i * MAX_LINE), 100, 3, G_Name);
			gInterface.DrawFormat(Color, StartX + 175, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharTG[up].Is_GLevel));
			gInterface.DrawFormat(Color, StartX + 225, StartY + 75 + (i * MAX_LINE), 100, 3, G_Master);
			gInterface.DrawFormat(Color, StartX + 275, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharTG[up].Is_GScore));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharTG[up].Is_GMem));
			gInterface.DrawFormat(Color, StartX + 375, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", ReversedDateTime);

			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 147, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 317, 0, 3, " ");
				GetInfoCharTop(this->RankingCharTG[up].G_Master);
				if (gRanking.CacheDataUserTop.GuildName[0] != 0xFFFFFFFF && strlen(gRanking.CacheDataUserTop.GuildName) > 1)
				{
					BCreateGuildMark(gRanking.CacheDataUserTop.GuildMark, 1);
					RenderBitmap(31740, pCursorX + 20, pCursorY, 26, 26, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
			}
			if (!gRanking.CacheUserRank)
			{
				GetInfoCharTop(G_Master);
			}
		}
		break;
		case 5:
		gInterface.DrawFormat(eYellow, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eYellow, StartX + 130, StartY + 62, 100, 3, "NAME");
		gInterface.DrawFormat(eYellow, StartX + 175, StartY + 62, 100, 3, "KILL BOSS");
		gInterface.DrawFormat(eYellow, StartX + 225, StartY + 62, 100, 3, "KILL/DEAD");
		gInterface.DrawFormat(eYellow, StartX + 275, StartY + 62, 100, 3, "DUEL W/L");
		gInterface.DrawFormat(eYellow, StartX + 325, StartY + 62, 100, 3, "ĐÃ CHƠI");
		gInterface.DrawFormat(eYellow, StartX + 375, StartY + 62, 100, 3, "NGÀY TẠO");

		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char NameID[11];
			char OnMyDate[30];
			int up = i + ((this->Page - 1) * iMaxCount);
			if (this->RankingCharPK[up].Name[0] == NULL) continue;

			memcpy(NameID, this->RankingCharPK[up].Name, sizeof(this->RankingCharPK[up].Name));
			memcpy(OnMyDate, this->RankingCharPK[up].Is_JoinDate, sizeof(this->RankingCharPK[up].Is_JoinDate));

			if (i >= 0 && i <= 2) { Color = eGold; }
			else { Color = eWhite; }

			char ReversedDateTime[20];
			sprintf(ReversedDateTime, "%c%c:%c%c:%c%c %c%c-%c%c",
				OnMyDate[11], OnMyDate[12],
				OnMyDate[14], OnMyDate[15],
				OnMyDate[17], OnMyDate[18],
				OnMyDate[8], OnMyDate[9],
				OnMyDate[5], OnMyDate[6]);


			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 130, StartY + 75 + (i * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 175, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharPK[up].Is_Kboss));
			gInterface.DrawFormat(Color, StartX + 225, StartY + 75 + (i * MAX_LINE), 100, 3, "%s / %s", gToolKit.QNumberFormat(this->RankingCharPK[up].Is_Kills), gToolKit.QNumberFormat(this->RankingCharPK[up].Is_Deads));
			gInterface.DrawFormat(Color, StartX + 275, StartY + 75 + (i * MAX_LINE), 100, 3, "%s / %s", gToolKit.QNumberFormat(this->RankingCharPK[up].Is_Win), gToolKit.QNumberFormat(this->RankingCharPK[up].Is_Lose));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, "%s tiếng", gToolKit.QNumberFormat(this->RankingCharPK[up].Is_OnlineHours));
			gInterface.DrawFormat(Color, StartX + 375, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", ReversedDateTime);

			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 147, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 317, 0, 3, " ");
			}
		}
		break;
		case 6:
		gInterface.DrawFormat(eWhite, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eWhite, StartX + 135, StartY + 62, 100, 3, "NAME");
		gInterface.DrawFormat(eWhite, StartX + 185, StartY + 62, 100, 3, "CLASS");
		gInterface.DrawFormat(eWhite, StartX + 230, StartY + 62, 100, 3, "LV/RS/RL");
		gInterface.DrawFormat(eWhite, StartX + 270, StartY + 62, 100, 3, "POINTS");
		gInterface.DrawFormat(eWhite, StartX + 325, StartY + 62, 100, 3, "ROOM");
		gInterface.DrawFormat(eWhite, StartX + 385, StartY + 62, 100, 3, "LAST RESET");
		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char NameID[11];
			char ROOM[9];
			int up = i + ((this->Page - 1) * iMaxCount);
			if (this->RankingCharDW[up].Name[0] == NULL) continue;
			memcpy(NameID, this->RankingCharDW[up].Name, sizeof(this->RankingCharDW[up].Name));
			memcpy(ROOM, this->RankingCharDW[up].Is_SvSub, sizeof(this->RankingCharDW[up].Is_SvSub));

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			time_t mTime; tm* lpTime = NULL;
			mTime = this->RankingCharDW[up].Is_ResetTime;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;	mMonth = 1 + lpTime->tm_mon; mDays = lpTime->tm_mday; hours = lpTime->tm_hour; minutes = lpTime->tm_min; seconds = lpTime->tm_sec;
			}

			if (i >= 0 && i <= 2)
			{
				Color = eGold;
			}
			else
			{
				Color = eWhite;
			}

			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 135, StartY + 75 + (i * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 185, StartY + 75 + (i * MAX_LINE), 100, 3, CharacterCode(this->RankingCharDW[up].Is_Class));
			gInterface.DrawFormat(Color, StartX + 230, StartY + 75 + (i * MAX_LINE), 100, 3, "%d/%d/%d", this->RankingCharDW[up].Is_cLevel, this->RankingCharDW[up].Is_ResetCount, this->RankingCharDW[up].Is_MasterResetCount);
			gInterface.DrawFormat(Color, StartX + 270, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharDW[up].Is_TotalPoint));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, ROOM);
			gInterface.DrawFormat(Color, StartX + 385, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d:%02d:%02d [%02d/%02d]", hours, minutes, seconds, mDays, mMonth);

			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 150, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 310, 0, 3, " ");
			}
		}
		break;
		case 7:
		gInterface.DrawFormat(eWhite, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eWhite, StartX + 135, StartY + 62, 100, 3, "NAME");
		gInterface.DrawFormat(eWhite, StartX + 185, StartY + 62, 100, 3, "CLASS");
		gInterface.DrawFormat(eWhite, StartX + 230, StartY + 62, 100, 3, "LV/RS/RL");
		gInterface.DrawFormat(eWhite, StartX + 270, StartY + 62, 100, 3, "POINTS");
		gInterface.DrawFormat(eWhite, StartX + 325, StartY + 62, 100, 3, "ROOM");
		gInterface.DrawFormat(eWhite, StartX + 385, StartY + 62, 100, 3, "LAST RESET");
		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char NameID[11];
			char ROOM[9];
			int up = i + ((this->Page - 1) * iMaxCount);
			if (this->RankingCharDK[up].Name[0] == NULL) continue;
			memcpy(NameID, this->RankingCharDK[up].Name, sizeof(this->RankingCharDK[up].Name));
			memcpy(ROOM, this->RankingCharDK[up].Is_SvSub, sizeof(this->RankingCharDK[up].Is_SvSub));

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			time_t mTime; tm* lpTime = NULL;
			mTime = this->RankingCharDK[up].Is_ResetTime;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;	mMonth = 1 + lpTime->tm_mon; mDays = lpTime->tm_mday; hours = lpTime->tm_hour; minutes = lpTime->tm_min; seconds = lpTime->tm_sec;
			}

			if (i >= 0 && i <= 2)
			{
				Color = eGold;
			}
			else
			{
				Color = eWhite;
			}

			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 135, StartY + 75 + (i * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 185, StartY + 75 + (i * MAX_LINE), 100, 3, CharacterCode(this->RankingCharDK[up].Is_Class));
			gInterface.DrawFormat(Color, StartX + 230, StartY + 75 + (i * MAX_LINE), 100, 3, "%d/%d/%d", this->RankingCharDK[up].Is_cLevel, this->RankingCharDK[up].Is_ResetCount, this->RankingCharDK[up].Is_MasterResetCount);
			gInterface.DrawFormat(Color, StartX + 270, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharDK[up].Is_TotalPoint));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, ROOM);
			gInterface.DrawFormat(Color, StartX + 385, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d:%02d:%02d [%02d/%02d]", hours, minutes, seconds, mDays, mMonth);

			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 150, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 310, 0, 3, " ");
			}
		}
		break;
		case 8:
		gInterface.DrawFormat(eWhite, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eWhite, StartX + 135, StartY + 62, 100, 3, "NAME");
		gInterface.DrawFormat(eWhite, StartX + 185, StartY + 62, 100, 3, "CLASS");
		gInterface.DrawFormat(eWhite, StartX + 230, StartY + 62, 100, 3, "LV/RS/RL");
		gInterface.DrawFormat(eWhite, StartX + 270, StartY + 62, 100, 3, "POINTS");
		gInterface.DrawFormat(eWhite, StartX + 325, StartY + 62, 100, 3, "ROOM");
		gInterface.DrawFormat(eWhite, StartX + 385, StartY + 62, 100, 3, "LAST RESET");
		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char NameID[11];
			char ROOM[9];
			int up = i + ((this->Page - 1) * iMaxCount);
			if (this->RankingCharEF[up].Name[0] == NULL) continue;
			memcpy(NameID, this->RankingCharEF[up].Name, sizeof(this->RankingCharEF[up].Name));
			memcpy(ROOM, this->RankingCharEF[up].Is_SvSub, sizeof(this->RankingCharEF[up].Is_SvSub));

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			time_t mTime; tm* lpTime = NULL;
			mTime = this->RankingCharEF[up].Is_ResetTime;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;	mMonth = 1 + lpTime->tm_mon; mDays = lpTime->tm_mday; hours = lpTime->tm_hour; minutes = lpTime->tm_min; seconds = lpTime->tm_sec;
			}

			if (i >= 0 && i <= 2)
			{
				Color = eGold;
			}
			else
			{
				Color = eWhite;
			}

			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 135, StartY + 75 + (i * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 185, StartY + 75 + (i * MAX_LINE), 100, 3, CharacterCode(this->RankingCharEF[up].Is_Class));
			gInterface.DrawFormat(Color, StartX + 230, StartY + 75 + (i * MAX_LINE), 100, 3, "%d/%d/%d", this->RankingCharEF[up].Is_cLevel, this->RankingCharEF[up].Is_ResetCount, this->RankingCharEF[up].Is_MasterResetCount);
			gInterface.DrawFormat(Color, StartX + 270, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharEF[up].Is_TotalPoint));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, ROOM);
			gInterface.DrawFormat(Color, StartX + 385, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d:%02d:%02d [%02d/%02d]", hours, minutes, seconds, mDays, mMonth);

			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 150, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 310, 0, 3, " ");
			}
		}
		break;
		case 9:
		gInterface.DrawFormat(eWhite, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eWhite, StartX + 135, StartY + 62, 100, 3, "NAME");
		gInterface.DrawFormat(eWhite, StartX + 185, StartY + 62, 100, 3, "CLASS");
		gInterface.DrawFormat(eWhite, StartX + 230, StartY + 62, 100, 3, "LV/RS/RL");
		gInterface.DrawFormat(eWhite, StartX + 270, StartY + 62, 100, 3, "POINTS");
		gInterface.DrawFormat(eWhite, StartX + 325, StartY + 62, 100, 3, "ROOM");
		gInterface.DrawFormat(eWhite, StartX + 385, StartY + 62, 100, 3, "LAST RESET");
		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char NameID[11];
			char ROOM[9];
			int up = i + ((this->Page - 1) * iMaxCount);
			if (this->RankingCharMG[up].Name[0] == NULL) continue;
			memcpy(NameID, this->RankingCharMG[up].Name, sizeof(this->RankingCharMG[up].Name));
			memcpy(ROOM, this->RankingCharMG[up].Is_SvSub, sizeof(this->RankingCharMG[up].Is_SvSub));

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			time_t mTime; tm* lpTime = NULL;
			mTime = this->RankingCharMG[up].Is_ResetTime;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;	mMonth = 1 + lpTime->tm_mon; mDays = lpTime->tm_mday; hours = lpTime->tm_hour; minutes = lpTime->tm_min; seconds = lpTime->tm_sec;
			}

			if (i >= 0 && i <= 2)
			{
				Color = eGold;
			}
			else
			{
				Color = eWhite;
			}

			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 135, StartY + 75 + (i * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 185, StartY + 75 + (i * MAX_LINE), 100, 3, CharacterCode(this->RankingCharMG[up].Is_Class));
			gInterface.DrawFormat(Color, StartX + 230, StartY + 75 + (i * MAX_LINE), 100, 3, "%d/%d/%d", this->RankingCharMG[up].Is_cLevel, this->RankingCharMG[up].Is_ResetCount, this->RankingCharMG[up].Is_MasterResetCount);
			gInterface.DrawFormat(Color, StartX + 270, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharMG[up].Is_TotalPoint));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, ROOM);
			gInterface.DrawFormat(Color, StartX + 385, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d:%02d:%02d [%02d/%02d]", hours, minutes, seconds, mDays, mMonth);

			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 150, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 310, 0, 3, " ");
			}
		}
		break;
		case 10:
		gInterface.DrawFormat(eWhite, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eWhite, StartX + 135, StartY + 62, 100, 3, "NAME");
		gInterface.DrawFormat(eWhite, StartX + 185, StartY + 62, 100, 3, "CLASS");
		gInterface.DrawFormat(eWhite, StartX + 230, StartY + 62, 100, 3, "LV/RS/RL");
		gInterface.DrawFormat(eWhite, StartX + 270, StartY + 62, 100, 3, "POINTS");
		gInterface.DrawFormat(eWhite, StartX + 325, StartY + 62, 100, 3, "ROOM");
		gInterface.DrawFormat(eWhite, StartX + 385, StartY + 62, 100, 3, "LAST RESET");
		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char NameID[11];
			char ROOM[9];
			int up = i + ((this->Page - 1) * iMaxCount);
			if (this->RankingCharDL[up].Name[0] == NULL) continue;
			memcpy(NameID, this->RankingCharDL[up].Name, sizeof(this->RankingCharDL[up].Name));
			memcpy(ROOM, this->RankingCharDL[up].Is_SvSub, sizeof(this->RankingCharDL[up].Is_SvSub));

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			time_t mTime; tm* lpTime = NULL;
			mTime = this->RankingCharDL[up].Is_ResetTime;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;	mMonth = 1 + lpTime->tm_mon; mDays = lpTime->tm_mday; hours = lpTime->tm_hour; minutes = lpTime->tm_min; seconds = lpTime->tm_sec;
			}

			if (i >= 0 && i <= 2)
			{
				Color = eGold;
			}
			else
			{
				Color = eWhite;
			}

			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 135, StartY + 75 + (i * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 185, StartY + 75 + (i * MAX_LINE), 100, 3, CharacterCode(this->RankingCharDL[up].Is_Class));
			gInterface.DrawFormat(Color, StartX + 230, StartY + 75 + (i * MAX_LINE), 100, 3, "%d/%d/%d", this->RankingCharDL[up].Is_cLevel, this->RankingCharDL[up].Is_ResetCount, this->RankingCharDL[up].Is_MasterResetCount);
			gInterface.DrawFormat(Color, StartX + 270, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharDL[up].Is_TotalPoint));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, ROOM);
			gInterface.DrawFormat(Color, StartX + 385, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d:%02d:%02d [%02d/%02d]", hours, minutes, seconds, mDays, mMonth);

			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 150, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 310, 0, 3, " ");
			}
		}
		break;
		case 11:
		gInterface.DrawFormat(eWhite, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eWhite, StartX + 135, StartY + 62, 100, 3, "NAME");
		gInterface.DrawFormat(eWhite, StartX + 185, StartY + 62, 100, 3, "CLASS");
		gInterface.DrawFormat(eWhite, StartX + 230, StartY + 62, 100, 3, "LV/RS/RL");
		gInterface.DrawFormat(eWhite, StartX + 270, StartY + 62, 100, 3, "POINTS");
		gInterface.DrawFormat(eWhite, StartX + 325, StartY + 62, 100, 3, "ROOM");
		gInterface.DrawFormat(eWhite, StartX + 385, StartY + 62, 100, 3, "LAST RESET");
		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char NameID[11];
			char ROOM[9];
			int up = i + ((this->Page - 1) * iMaxCount);
			if (this->RankingCharSM[up].Name[0] == NULL) continue;
			memcpy(NameID, this->RankingCharSM[up].Name, sizeof(this->RankingCharSM[up].Name));
			memcpy(ROOM, this->RankingCharSM[up].Is_SvSub, sizeof(this->RankingCharSM[up].Is_SvSub));

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			time_t mTime; tm* lpTime = NULL;
			mTime = this->RankingCharSM[up].Is_ResetTime;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;	mMonth = 1 + lpTime->tm_mon; mDays = lpTime->tm_mday; hours = lpTime->tm_hour; minutes = lpTime->tm_min; seconds = lpTime->tm_sec;
			}

			if (i >= 0 && i <= 2)
			{
				Color = eGold;
			}
			else
			{
				Color = eWhite;
			}

			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 135, StartY + 75 + (i * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 185, StartY + 75 + (i * MAX_LINE), 100, 3, CharacterCode(this->RankingCharSM[up].Is_Class));
			gInterface.DrawFormat(Color, StartX + 230, StartY + 75 + (i * MAX_LINE), 100, 3, "%d/%d/%d", this->RankingCharSM[up].Is_cLevel, this->RankingCharSM[up].Is_ResetCount, this->RankingCharSM[up].Is_MasterResetCount);
			gInterface.DrawFormat(Color, StartX + 270, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharSM[up].Is_TotalPoint));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, ROOM);
			gInterface.DrawFormat(Color, StartX + 385, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d:%02d:%02d [%02d/%02d]", hours, minutes, seconds, mDays, mMonth);

			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 150, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 310, 0, 3, " ");
			}
		}
		break;
		case 12:
		gInterface.DrawFormat(eWhite, StartX + 105, StartY + 62, 100, 3, "TOP");
		gInterface.DrawFormat(eWhite, StartX + 135, StartY + 62, 100, 3, "NAME");
		gInterface.DrawFormat(eWhite, StartX + 185, StartY + 62, 100, 3, "CLASS");
		gInterface.DrawFormat(eWhite, StartX + 230, StartY + 62, 100, 3, "LV/RS/RL");
		gInterface.DrawFormat(eWhite, StartX + 270, StartY + 62, 100, 3, "POINTS");
		gInterface.DrawFormat(eWhite, StartX + 325, StartY + 62, 100, 3, "ROOM");
		gInterface.DrawFormat(eWhite, StartX + 385, StartY + 62, 100, 3, "LAST RESET");
		for (int i = 0; i < iMaxCount; i++)
		{
			DWORD Color;
			char NameID[11];
			char ROOM[9];
			int up = i + ((this->Page - 1) * iMaxCount);
			if (this->RankingCharRF[up].Name[0] == NULL) continue;
			memcpy(NameID, this->RankingCharRF[up].Name, sizeof(this->RankingCharRF[up].Name));
			memcpy(ROOM, this->RankingCharRF[up].Is_SvSub, sizeof(this->RankingCharRF[up].Is_SvSub));

			int mYear = 0;
			int mMonth = 0;
			int mDays = 0;
			int hours = 0;
			int minutes = 0;
			int seconds = 0;
			time_t mTime; tm* lpTime = NULL;
			mTime = this->RankingCharRF[up].Is_ResetTime;
			lpTime = localtime(&mTime);
			if (lpTime)
			{
				mYear = 1952 + lpTime->tm_year;	mMonth = 1 + lpTime->tm_mon; mDays = lpTime->tm_mday; hours = lpTime->tm_hour; minutes = lpTime->tm_min; seconds = lpTime->tm_sec;
			}

			if (i >= 0 && i <= 2)
			{
				Color = eGold;
			}
			else
			{
				Color = eWhite;
			}

			gInterface.DrawFormat(Color, StartX + 105, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d", up + 1);
			gInterface.DrawFormat(Color, StartX + 135, StartY + 75 + (i * MAX_LINE), 100, 3, NameID);
			gInterface.DrawFormat(Color, StartX + 185, StartY + 75 + (i * MAX_LINE), 100, 3, CharacterCode(this->RankingCharRF[up].Is_Class));
			gInterface.DrawFormat(Color, StartX + 230, StartY + 75 + (i * MAX_LINE), 100, 3, "%d/%d/%d", this->RankingCharRF[up].Is_cLevel, this->RankingCharRF[up].Is_ResetCount, this->RankingCharRF[up].Is_MasterResetCount);
			gInterface.DrawFormat(Color, StartX + 270, StartY + 75 + (i * MAX_LINE), 100, 3, "%s", gToolKit.QNumberFormat(this->RankingCharRF[up].Is_TotalPoint));
			gInterface.DrawFormat(Color, StartX + 325, StartY + 75 + (i * MAX_LINE), 100, 3, ROOM);
			gInterface.DrawFormat(Color, StartX + 385, StartY + 75 + (i * MAX_LINE), 100, 3, "%02d:%02d:%02d [%02d/%02d]", hours, minutes, seconds, mDays, mMonth);

			if (pCheckMouseOver(StartX + 151, StartY + 75 + (i * MAX_LINE), (310), 13) == 1)
			{
				CustomFont.Draw((HFONT)pFontBold, StartX + 150, StartY + 75 + (i * MAX_LINE), 0xFFFFFFFF, 0x00FBFF69, 310, 0, 3, " ");
			}
		}
		break;
		default:
		break;
	}
	DWORD Delay = (GetTickCount() - this->ClickTime);
	
	int ButX = 30;
	int ButY = 55;
}
void cRanking::GetBarInfo(int x, int y, int Value1, int Value2, DWORD BackColor, LPCSTR Char,...)
{
	int CurentLife = Value1;
	float TyleLife = (70 * CurentLife) / Value2;

	if (TyleLife > 70)
	{
		TyleLife = 70;
	}
	CustomFont.Draw(CustomFont.FontBold, x, y, 0xFFFFFFFF, BackColor, TyleLife, 13, 3, " ");
	gInterface.DrawFormat(eWhite, x - 29, y + 2, 100, 1, Char);
	gInterface.DrawFormat(eWhite, x - 14, y + 1, 100, 3, "%s / %s", gToolKit.QNumberFormat(Value1), gToolKit.QNumberFormat(Value2));
}

