#include "stdafx.h"
#if(SPK_QUANHAM)
#include "Protocol.h"
#include "Interface.h"
#include "SPK_QuanHam.h"
#include "CustomRankUser.h"
#include "User.h"
#include "Central.h"
#include "CustomFont.h"
#include "Controller.h"
#include "Item.h"
#include "Defines.h"
#include "Object.h"
#include <sstream>
#include "CustomJewelBank.h"
#include "Config.h"
#include "SPK_FixSolution.h"
cQuanHam gQuanHam;

char* cQuanHam::ItemQuanHam(int ItemType, int Level)
{
	char ItemNameGet[100];
	memset(ItemNameGet, 0, sizeof(ItemNameGet));
	pGetItemName(ItemType, (const char*)(GET_ITEMOPT_LEVEL(Level)), (char*)ItemNameGet);
	std::string a(ItemNameGet);
	return strdup(a.c_str());
}
void cQuanHam::LoadImageQuanHam()
{
	for (int i = 0; i <= MAX_LEVEL_QUAN_HAM ; i ++) 
	{
		char fileName[100];
		sprintf(fileName, "SPK\\RankTitle\\QuanHam\\QuanHam_%d.tga", i);
		pLoadImage(fileName, SPK_QUANHAM_IMG + i , 0x2601, 0x2900, 1, 0);
	}
	this->m_DataConfigQuanHam.clear();
}

CONFIDATA_QUANHAM* GetConfigLvQuanHam(int LvQuanHam)
{
	std::map<int, CONFIDATA_QUANHAM>::iterator it = gQuanHam.m_DataConfigQuanHam.find(LvQuanHam);
	if (it == gQuanHam.m_DataConfigQuanHam.end())
	{
		return 0;
	}
	else
	{
		return &it->second;
	}
}

void cQuanHam::ShowQuanHamSPK(int index,int PosX, int PosY)
{
	this->SPK_QUANHAM_LVL = gCustomRankUser.m_Data[index].m_RankTitle2;
	if(this->SPK_QUANHAM_LVL >= 1 && this->SPK_QUANHAM_LVL <= MAX_LEVEL_QUAN_HAM )
	{
		glColor3f(1.0, 1.0, 1.0);
		RenderBitmap(SPK_QUANHAM_IMG + this->SPK_QUANHAM_LVL , (float)PosX + 16, (float)PosY - gFixSolution.QH_PosY, 70, 56, 0, 0, 1, 1, 1, 1, 0.0);
	}	
}
void cQuanHam::SendMenuButton()
{
	XULY_QUANHAM pMsg;
	pMsg.header.set(0xD5, 0x07, sizeof(pMsg));
	pMsg.ThaoTac = 1;
	DataSend((LPBYTE)&pMsg, pMsg.header.size);
}
void cQuanHam::SendPackQHButton()
{
	XULY_QUANHAM pMsg;
	pMsg.header.set(0xD5, 0x08, sizeof(pMsg));
	pMsg.ThaoTac = 1;
	DataSend((LPBYTE)&pMsg, pMsg.header.size);
}
void cQuanHam::SendQHProtocol(BYTE* lpMsg)
{
	gQuanHam.m_DataConfigQuanHam.clear();
	QHCSEV_COUNTLIST* mRecv = (QHCSEV_COUNTLIST*)lpMsg;
	for (int i = 0; i < mRecv->Count; i++)
	{
		CONFIDATA_QUANHAM lpInfo = *(CONFIDATA_QUANHAM*)(((BYTE*)lpMsg) + sizeof(QHCSEV_COUNTLIST) + (sizeof(CONFIDATA_QUANHAM) * i));
		gQuanHam.m_DataConfigQuanHam.insert(std::pair<int, CONFIDATA_QUANHAM>(lpInfo.LvQuanHam, lpInfo));
	}
	if ((GetTickCount() - gInterface.Data[eWindow_NangCapQuanHam].EventTick) > 300)
	{
		gInterface.Data[eWindow_NangCapQuanHam].OnShow ^= 1;
		gInterface.Data[eWindow_NangCapQuanHam].EventTick = GetTickCount();
	}
}
void cQuanHam::DrawWindowNangCapQuanHam()
{
	if (CheckSPK_WINDOWS)
	{
		gInterface.Data[eWindow_NangCapQuanHam].OnShow = false;
		return;
	}
	if (!gInterface.Data[eWindow_NangCapQuanHam].OnShow)
	{
		return;
	}
	float CuaSoW = 450.0;
	float CuaSoH = 270.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (CuaSoH / 2);
	gInterface.Data[eWindow_NangCapQuanHam].MaxX = StartX + CuaSoW;
	gInterface.Data[eWindow_NangCapQuanHam].MaxY = StartY + CuaSoH;
	int LvQuanHam = gCustomRankUser.m_Data[gObjUser.lpViewPlayer->aIndex].m_RankTitle2;
	CONFIDATA_QUANHAM* GetInfoLvHienTai = GetConfigLvQuanHam(LvQuanHam);
	CONFIDATA_QUANHAM* GetInfoLvTiepTheo = GetConfigLvQuanHam(LvQuanHam + 1);
	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindow_NangCapQuanHam, gConfig.TSPK_TEXT_ENGINE[255]);
	gCentral.gInfoBox(StartX + 20, StartY + 40, (CuaSoW/4) + 10 , CuaSoH - 65, 0x00000096, 0, 0);
	gCentral.gInfoBox(StartX + (3 * CuaSoW / 4) - 40, StartY + 40, (CuaSoW/4) + 10, CuaSoH - 65, 0x00000096, 0, 0);
	this->KhoanCach_Distance = (3 * CuaSoW / 4);

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);
	float TextPlusY = StartY + 155 + 15;
	float IMG_H = 40.0f;
	float IMG_W = 126.0f;	

	if (LvQuanHam < MAX_LEVEL_QUAN_HAM + 1)
	{
		RenderBitmap(SPK_QUANHAM_IMG + LvQuanHam , StartX + 23, StartY + 25, 160, 156, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		gInterface.SPKText(eExcellent,StartX + 30, TextPlusY + 10, 125,				1, gConfig.TSPK_TEXT_ENGINE[220], (LvQuanHam == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangMau);
		gInterface.SPKText(eExcellent,StartX + 30, TextPlusY + 20, 125,				1, gConfig.TSPK_TEXT_ENGINE[221], (LvQuanHam == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangSD);
		gInterface.SPKText(eExcellent,StartX + 30, TextPlusY + (10 * 2) + 10, 125,  1, gConfig.TSPK_TEXT_ENGINE[222], (LvQuanHam == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangST);
		gInterface.SPKText(eExcellent,StartX + 30, TextPlusY + (10 * 3) + 10, 125,  1, gConfig.TSPK_TEXT_ENGINE[223], (LvQuanHam == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangPT);

		if( LvQuanHam + 1 > MAX_LEVEL_QUAN_HAM )
		{
			RenderBitmap(SPK_QUANHAM_IMG, StartX + this->KhoanCach_Distance - 38, StartY + 25, 160, 156, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		}
		else
		{
			RenderBitmap(SPK_QUANHAM_IMG + LvQuanHam + 1, StartX + this->KhoanCach_Distance - 38, StartY + 25, 160, 156, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		}

		gInterface.SPKText(eWhite,StartX + this->KhoanCach_Distance - 30, TextPlusY + 10, 125,				1, gConfig.TSPK_TEXT_ENGINE[220], GetInfoLvTiepTheo->TangMau);
		gInterface.SPKText(eWhite,StartX + this->KhoanCach_Distance - 30, TextPlusY + 20, 125,				1, gConfig.TSPK_TEXT_ENGINE[221], GetInfoLvTiepTheo->TangSD);
		gInterface.SPKText(eWhite,StartX + this->KhoanCach_Distance - 30, TextPlusY + (10 * 2) + 10, 125,	1, gConfig.TSPK_TEXT_ENGINE[222], GetInfoLvTiepTheo->TangST);
		gInterface.SPKText(eWhite,StartX + this->KhoanCach_Distance - 30, TextPlusY + (10 * 3) + 10, 125,	1, gConfig.TSPK_TEXT_ENGINE[223], GetInfoLvTiepTheo->TangPT);
		CustomFont.Draw(CustomFont.FontBold,			StartX + this->KhoanCach_Distance - 40, StartY + 55 + 110, 0xFFDE26FF, 0x0, 125, 0, 3, gConfig.TSPK_TEXT_ENGINE[224], LvQuanHam + 1);
	}
	else
	{
		RenderBitmap(SPK_QUANHAM_IMG + LvQuanHam , StartX + 23, StartY + 25, 160, 156, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 40, TextPlusY + 10 , 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, gConfig.TSPK_TEXT_ENGINE[225]);
		CustomFont.Draw(CustomFont.FontBold, StartX + this->KhoanCach_Distance - 40, StartY + 55 + 110, 0xFFDE26FF, 0x0, 125, 0, 3, gConfig.TSPK_TEXT_ENGINE[226]);

		RenderBitmap(SPK_QUANHAM_IMG, StartX + this->KhoanCach_Distance - 38, StartY + 25, 160, 156, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	}
	CustomFont.Draw(CustomFont.FontBold, StartX + 23, StartY + 55 + 110, 0xFFDE26FF, 0x0, 125, 0, 3, gConfig.TSPK_TEXT_ENGINE[227], LvQuanHam);
	
	pGLSwitch();
	EnableAlphaTest(0);
	int ct = 0;
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 45 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[228]);
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 45 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[229]);
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 45 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[230]);

	float YUpCapQuanHam = StartY + 35 + (12 * ct) + 15;
	if (LvQuanHam < MAX_LEVEL_QUAN_HAM)
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 10, YUpCapQuanHam, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[231], LvQuanHam + 1);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 30, YUpCapQuanHam + 13, 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, gConfig.TSPK_TEXT_ENGINE[232], GetInfoLvTiepTheo->YCItemSL, this->ItemQuanHam(GetInfoLvTiepTheo->YCItemID, GetInfoLvTiepTheo->YCItemLv));
		
		gInterface.SPKText(eExcellent, StartX + 160 + 30, YUpCapQuanHam + 13 + (12 * 1), 125,1,gConfig.TSPK_TEXT_ENGINE[233], GetInfoLvTiepTheo->YCWC);
		gInterface.SPKText(eExcellent, StartX + 160 + 30, YUpCapQuanHam + 13 + (12 * 2), 125,1,gConfig.TSPK_TEXT_ENGINE[234], GetInfoLvTiepTheo->YCWP);
		gInterface.SPKText(eExcellent, StartX + 160 + 30, YUpCapQuanHam + 13 + (12 * 3), 125,1,gConfig.TSPK_TEXT_ENGINE[235], GetInfoLvTiepTheo->YCGP);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160, YUpCapQuanHam + 13 + (12 * 4) + 5, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[236]);

		if (gCentral.gDrawButton((StartX + CuaSoW)/2 - 10, StartY + (CuaSoH - 40), 110, 14, gConfig.TSPK_TEXT_ENGINE[237]) && (GetTickCount() - gInterface.Data[eWindow_NangCapQuanHam].EventTick) > 300)
		{
			this->SendPackQHButton();
		}
	}
	else
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 160, YUpCapQuanHam, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[238]);
	}	
}
#endif
