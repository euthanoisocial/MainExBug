#include "stdafx.h"
#include "Protocol.h"
#include "Interface.h"
#include "SPK_HonHoan.h"
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

#if(SPK_HONHOAN)
cHonHoan gHonHoan;
std::string SPKCreateInmage(int index) 
{
    std::stringstream ss;
    ss << "SPK\\RankTitle\\HonHoan\\" << index << ".jpg";
    return ss.str();
}
char* cHonHoan::ItemHonHoan(int ItemType, int Level)
{
	char ItemNameGet[100];
	memset(ItemNameGet, 0, sizeof(ItemNameGet));
	pGetItemName(ItemType, (const char*)(GET_ITEMOPT_LEVEL(Level)), (char*)ItemNameGet);
	std::string a(ItemNameGet);
	return strdup(a.c_str());
}
void cHonHoan::LoadImageHonHoan()
{
	const int SoLuongLoad = LevelHH;
    const int baseIndex = eImgHonHoan;    
    std::string ThuMuc[SoLuongLoad];    
    for (int i = 0; i < SoLuongLoad; i++) 
	{
        ThuMuc[i] = SPKCreateInmage(i + 1);
    }    
    for (int i = 0; i < SoLuongLoad; i++) 
	{
        char SPKPatchChar[256];
        strcpy(SPKPatchChar, ThuMuc[i].c_str());
        LoadBitmapA(SPKPatchChar, baseIndex + i, GL_LINEAR, GL_CLAMP, 1, 0);
    }	
	this->m_DataConfigHonHoan.clear();
}

CONFIDATA_HONHOAN* GetConfigLvHonHoan(int LvHonHoan)
{
	std::map<int, CONFIDATA_HONHOAN>::iterator it = gHonHoan.m_DataConfigHonHoan.find(LvHonHoan);

	if (it == gHonHoan.m_DataConfigHonHoan.end())
	{
		return 0;
	}
	else
	{
		return &it->second;
	}
}
void cHonHoan::AddHonHoanCape(DWORD ObjectPointer)
{
	lpViewObj Object = &*(ObjectPreview*)(ObjectPointer);
	if (gCustomRankUser.m_Data[Object->aIndex].m_RankTitle5 > 0 && gCustomRankUser.m_Data[Object->aIndex].m_RankTitle5 < LevelHH + 1)
	{
		vec3_t Color;
		Vector(1.0, 1.0, 1.0, Color);
		int capDoHonHoan = gCustomRankUser.m_Data[Object->aIndex].m_RankTitle5;
		for (int i = 0; i <= LevelHH; i++)
		{
			if (capDoHonHoan == i && capDoHonHoan != 0)
			{
				gObjUser.CBRenderCharacter(ObjectPointer, eImgHonHoan + i - 1, 2.5f, 2.5f, Color, 0);
			}			
		}
	}
}
void cHonHoan::SendMenuButton()
{
	XULY_CGPACKET pMsg;
	pMsg.header.set(0xD5, 0x01, sizeof(pMsg));
	pMsg.ThaoTac = 1;
	DataSend((LPBYTE)&pMsg, pMsg.header.size);
}
void cHonHoan::SendPackHHButton()
{
	XULY_CGPACKET pMsg;
	pMsg.header.set(0xD5, 0x02, sizeof(pMsg));
	pMsg.ThaoTac = 1;
	DataSend((LPBYTE)&pMsg, pMsg.header.size);
}
void cHonHoan::SendHHProtocol(BYTE* lpMsg)
{
	gHonHoan.m_DataConfigHonHoan.clear();
	HHCSEV_COUNTLIST* mRecv = (HHCSEV_COUNTLIST*)lpMsg;
	for (int i = 0; i < mRecv->Count; i++)
	{
		CONFIDATA_HONHOAN lpInfo = *(CONFIDATA_HONHOAN*)(((BYTE*)lpMsg) + sizeof(HHCSEV_COUNTLIST) + (sizeof(CONFIDATA_HONHOAN) * i));
		gHonHoan.m_DataConfigHonHoan.insert(std::pair<int, CONFIDATA_HONHOAN>(lpInfo.LvHonHoan, lpInfo));
	}
	if ((GetTickCount() - gInterface.Data[eWindow_NangCapHonHoan].EventTick) > 300)
	{
		gInterface.Data[eWindow_NangCapHonHoan].OnShow ^= 1;
		gInterface.Data[eWindow_NangCapHonHoan].EventTick = GetTickCount();
	}
}
void cHonHoan::DrawWindowNangCapHonHoan()
{
	if (CheckSPK_WINDOWS)
	{
		gInterface.Data[eWindow_NangCapHonHoan].OnShow = false;
		return;
	}
	if (!gInterface.Data[eWindow_NangCapHonHoan].OnShow)
	{
		return;
	}

	float CuaSoW = 450.0;
	float CuaSoH = 270.0;

	float StartX = (MAX_WIN_WIDTH / 2) - (CuaSoW / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (CuaSoH / 2);
	gInterface.Data[eWindow_NangCapHonHoan].MaxX = StartX + CuaSoW;
	gInterface.Data[eWindow_NangCapHonHoan].MaxY = StartY + CuaSoH;
	int LvHonHoan = gCustomRankUser.m_Data[gObjUser.lpViewPlayer->aIndex].m_RankTitle5;
	CONFIDATA_HONHOAN* GetInfoLvHienTai = GetConfigLvHonHoan(LvHonHoan);
	CONFIDATA_HONHOAN* GetInfoLvTiepTheo = GetConfigLvHonHoan(LvHonHoan + 1);
	gCentral.gDrawWindowCustom(StartX, StartY, CuaSoW, CuaSoH, eWindow_NangCapHonHoan, gConfig.TSPK_TEXT_ENGINE[248]);
	gCentral.gInfoBox(StartX + 20, StartY + 40, (CuaSoW/4) + 10 , CuaSoH - 65, 0x00000096, 0, 0);
	gCentral.gInfoBox(StartX + (3 * CuaSoW / 4) - 40, StartY + 40, (CuaSoW/4) + 10, CuaSoH - 65, 0x00000096, 0, 0);
	int khoangcach = (3 * CuaSoW / 4);

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	for (int i = 0; i < LevelHH; i++)
	{
		if (LvHonHoan == i && i == 0)
		{
			RenderBitmap(eImgHonHoan + i, StartX + khoangcach - 25, StartY + 55, 100, 100, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		// cap tiep theo
		}
		else if (LvHonHoan == i && LvHonHoan < LevelHH)
		{
			RenderBitmap(eImgHonHoan + i - 1, StartX + 35, StartY + 55, 100, 100, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);	//cap hien tai	
			RenderBitmap(eImgHonHoan + i , StartX + khoangcach - 25, StartY + 55, 100, 100, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		// cap tiep theo
		}
		else if (LvHonHoan == LevelHH)
		{
			RenderBitmap(eImgHonHoan + i , StartX + 35, StartY + 55, 100, 100, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);	//cap hien tai	
			RenderBitmap(eImgHonHoan + i , StartX + khoangcach - 25, StartY + 55, 100, 100, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);		// cap tiep theo
		}
		
	}
	CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 45, 0xFFDE26FF, 0x0, 125, 0, 3, gConfig.TSPK_TEXT_ENGINE[249]); // hien thi so luong hon hoan max
	CustomFont.Draw(CustomFont.FontBold, StartX + khoangcach - 40, StartY + 45, 0xFFDE26FF, 0x0, 125, 0, 3, gConfig.TSPK_TEXT_ENGINE[250]); // hien thi so luong hon hoan max
	//===Info Bo Tro
	CustomFont.Draw(CustomFont.FontBold, StartX + 20, StartY + 55 + 110, 0xFFDE26FF, 0x0, 125, 0, 3, gConfig.TSPK_TEXT_ENGINE[251], LvHonHoan);
	if (LvHonHoan >= LevelHH)
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + khoangcach - 40, StartY + 55 + 110, 0xFFDE26FF, 0x0, 125, 0, 3, gConfig.TSPK_TEXT_ENGINE[252], LvHonHoan );
	}
	else
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + khoangcach - 40, StartY + 55 + 110, 0xFFDE26FF, 0x0, 125, 0, 3, gConfig.TSPK_TEXT_ENGINE[253], LvHonHoan + 1);
	}	

	float TextPlusY = StartY + 155 + 15;
	if (LvHonHoan < LevelHH) // so luong hon hoan
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + 10, 0x00FF90FF, 0x0, 125, 0, 1,			 gConfig.TSPK_TEXT_ENGINE[220], (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangMau);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + 20, 0x00FF90FF, 0x0, 125, 0, 1,			 gConfig.TSPK_TEXT_ENGINE[221], (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangSD);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 2) + 10, 0x00FF90FF, 0x0, 125, 0, 1, gConfig.TSPK_TEXT_ENGINE[222], (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangST);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 3) + 10, 0x00FF90FF, 0x0, 125, 0, 1, gConfig.TSPK_TEXT_ENGINE[223], (LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangPT);
		
		CustomFont.Draw(CustomFont.FontBold, StartX + khoangcach - 20, TextPlusY + 10, 0x00FF90FF, 0x0, 125, 0, 1,			 gConfig.TSPK_TEXT_ENGINE[220], GetInfoLvTiepTheo->TangMau);
		CustomFont.Draw(CustomFont.FontBold, StartX + khoangcach - 20, TextPlusY + 20, 0x00FF90FF, 0x0, 125, 0, 1,			 gConfig.TSPK_TEXT_ENGINE[221], GetInfoLvTiepTheo->TangSD);
		CustomFont.Draw(CustomFont.FontBold, StartX + khoangcach - 20, TextPlusY + (10 * 2) + 10, 0x00FF90FF, 0x0, 125, 0, 1,gConfig.TSPK_TEXT_ENGINE[222], GetInfoLvTiepTheo->TangST);
		CustomFont.Draw(CustomFont.FontBold, StartX + khoangcach - 20, TextPlusY + (10 * 3) + 10, 0x00FF90FF, 0x0, 125, 0, 1,gConfig.TSPK_TEXT_ENGINE[223], GetInfoLvTiepTheo->TangPT);
				
	}
	else
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + 10, 0x00FF90FF, 0x0, 125, 0, 1,			 gConfig.TSPK_TEXT_ENGINE[220],(LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangMau);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + 20, 0x00FF90FF, 0x0, 125, 0, 1,			 gConfig.TSPK_TEXT_ENGINE[221],(LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangSD);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 2) + 10, 0x00FF90FF, 0x0, 125, 0, 1, gConfig.TSPK_TEXT_ENGINE[222],(LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangST);
		CustomFont.Draw(CustomFont.FontBold, StartX + 30, TextPlusY + (10 * 3) + 10, 0x00FF90FF, 0x0, 125, 0, 1, gConfig.TSPK_TEXT_ENGINE[223],(LvHonHoan == 0 || GetInfoLvHienTai == 0) ? 0 : GetInfoLvHienTai->TangPT);
	}

	pGLSwitch();
	EnableAlphaTest(0);
	//==================
	int ct = 0;
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 45 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[254]);
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 45 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[229]);
	CustomFont.Draw(CustomFont.FontBold, StartX + 160, StartY + 45 + (12 * ct++), 0xC8FF00FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[230]);

	float YUpCapHonHoan = StartY + 35 + (12 * ct) + 15;
	if (LvHonHoan < LevelHH) // so luong hon hoan
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 10, YUpCapHonHoan, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[231], LvHonHoan + 1);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 40, YUpCapHonHoan + 13, 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, gConfig.TSPK_TEXT_ENGINE[232], GetInfoLvTiepTheo->YCItemSL, ItemHonHoan(GetInfoLvTiepTheo->YCItemID, GetInfoLvTiepTheo->YCItemLv));
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 40, YUpCapHonHoan + 13 + (12 * 1), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, gConfig.TSPK_TEXT_ENGINE[233], GetInfoLvTiepTheo->YCWC);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 40, YUpCapHonHoan + 13 + (12 * 2), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, gConfig.TSPK_TEXT_ENGINE[234], GetInfoLvTiepTheo->YCWP);
		CustomFont.Draw(CustomFont.FontBold, StartX + 160 + 40, YUpCapHonHoan + 13 + (12 * 3), 0x1FD2FFFF, 0x0, CuaSoW - 140, 0, 1, gConfig.TSPK_TEXT_ENGINE[235], GetInfoLvTiepTheo->YCGP);

		CustomFont.Draw(CustomFont.FontBold, StartX + 160, YUpCapHonHoan + 13 + (12 * 4) + 5, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[236]);

		if (gCentral.gDrawButton((StartX + CuaSoW)/2 - 10, StartY + (CuaSoH - 40), 110, 14, gConfig.TSPK_TEXT_ENGINE[237]) && (GetTickCount() - gInterface.Data[eWindow_NangCapHonHoan].EventTick) > 300)
		{
			this->SendPackHHButton();
		}
	}
	else
	{
		CustomFont.Draw(CustomFont.FontBold, StartX + 160, YUpCapHonHoan, 0xFFDE26FF, 0x0, CuaSoW - 170, 0, 1, gConfig.TSPK_TEXT_ENGINE[238]);
	}	
}
#endif
