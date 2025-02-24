#include "stdafx.h"
#if (CUSTOM_HARMONY)
#include "SPK_Harmony.h"
#include "MemScript.h"
#include "Util.h"
#include "Interface.h"
#include "Central.h"
#include "Defines.h"
#include "InterfaceElemental.h"
#include "User.h"
#include "CBUtil.h"
#include "SPK_ToolKit.h"
#include "PrintPlayer.h"
#include "CustomFont.h"
#include "SPK_ItemTrader.h"
CustomHarmony gCustomHarmony;

extern void* BCacheInfoItemDD;
extern DWORD CacheTimeShowInfoItem;
DWORD HarmonyEffect = 0;

CustomHarmony::CustomHarmony()
{
	this->Init();
}

void CustomHarmony::Init()
{
	this->m_HarmonyInfoList.clear();
	this->Harmony_ActiveMix = false;
	this->Harmony_EffectsMix = false;
	this->SetStateHarmony = false;
	this->Rate = 100;
	this->Price = 0;
	this->PriceType = -1;
	this->SoLuongDaTaoHoa = 0;
	this->IndexRandom = -1;
	memset(this->ItemChuaEp, 0, sizeof(this->ItemChuaEp));
}

char* CustomHarmony::GetNamePrice()
{
	switch (this->PriceType)
	{
		case 1:		return "WC";		break;
		case 2:		return "WP";		break;
		case 3:		return "GP";		break;
	}
	return "Zen";
}

void BackItemHarmony(int Type)
{
	if ((GetTickCount() - gInterface.Data[eWindowHarmony].EventTick) > 300)
	{
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD5, 0x2C, sizeof(pMsg));
		pMsg.ThaoTac = Type; //
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
		gInterface.Data[eWindowHarmony].EventTick = GetTickCount();
	}
}
void CustomHarmony::DrawHarmony()
{
	if (CheckSPK_WINDOWS3)
	{
		if (gInterface.Data[eWindowHarmony].OnShow == true)
		{
			gInterface.Data[eWindowHarmony].OnShow = false;
			pSetCursorFocus = false;
			return;
		}
	}

	if (!gInterface.Data[eWindowHarmony].OnShow)
	{
		if (gCustomHarmony.SetStateHarmony == 1)
		{
			XULY_CGPACKET pMsg;
			pMsg.header.set(0xD5, 0x2A, sizeof(pMsg));
			pMsg.ThaoTac = 111;
			DataSend((LPBYTE)&pMsg, pMsg.header.size);
			this->SetStateHarmony = false;
			this->Harmony_ActiveMix = false;
			this->Harmony_EffectsMix = false;
		}
		return;
	}
	if (pCheckWindow(pWindowThis(), Inventory) == false)
	{
		pOpenWindow(pWindowThis(), Inventory);
	}
	if (pCheckWindow(pWindowThis(), Character) == true)
	{
		pCloseWindow(pWindowThis(), Character);
	}
	
	float StartX = 10.f;
	float StartY = 60; // 0911105253
	float WindowW = 250;
	float WindowH = 350;

	RenderBitmap(0x1791E, StartX, StartY, WindowW, WindowH, 0, 0, 1, 1, 1, 1, 0.0);
	RenderBitmap(0x1792D, StartX, StartY, 250, 90, 0, 0, 1, 1, 1, 1, 0.0);
	if (pCheckMouseOver(StartX + 212, StartY + 10, 12, 12) == 1)
	{
		if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - this->ClickTime > 300)
		{
			if (GetKeyState(1) & 0x8000)
			{
				gCentral.LockMouse = GetTickCount() + 500;
				this->ClickTime = GetTickCount();
				gInterface.Data[eWindowHarmony].OnShow = false;
			}
		}
	}
	gCentral.gItemBoxInv(StartX + 15, StartY + 65, 4, 2, 0);
	gCentral.gItemBoxInv(StartX + 170, StartY + 65, 4, 2, 0);
	gInterface.DrawFormat(eWhite, StartX + 3, StartY + 50, 65, 3, "Item Gốc");
	gInterface.DrawFormat(eWhite, StartX + 158, StartY + 50, 65, 3, "Ngọc Tạo Hóa");
	gCBUtil.DrawItem3D(StartX + 165, StartY + 60, 50, 50, 7210, 0, 0, 0, 0, 0.80);
	gToolKit.CRenderNumberEx(StartX + 195, StartY + 107, this->SoLuongDaTaoHoa, 0.90, 0x7A69);
	gInterface.DrawFormat(eWhite, StartX + 60, StartY + 90, 65, 1, "Kết quả:");
	CustomFont.Draw((HFONT)pFontBold, StartX + 60, StartY + 100, 0x0, 0x00000069, 105, 30, 3, " ");
	gInterface.DrawFormat(eGold, StartX + 60, StartY + 65, 200, 1, "Giá cường hóa: %s %s / lần", gToolKit.QNumberFormat(this->Price), this->GetNamePrice());
	if (Coin1 >= this->Price)
	{
		gInterface.DrawFormat(eGold, StartX + 60, StartY + 77, 200, 1, "WcoinC hiện tại: %s WC", gToolKit.QNumberFormat(Coin1));
	}
	else
	{
		int CalcCoin = this->Price - Coin1;
		gInterface.DrawFormat(eRed, StartX + 60, StartY + 77, 200, 1, "WcoinC hiện tại: %s WC => [Thiếu %s WC]", gToolKit.QNumberFormat(Coin1), gToolKit.QNumberFormat(CalcCoin));
	}
	
	if (this->Harmony_EffectsMix && HarmonyEffect > GetTickCount() && HarmonyEffect != 0 && Coin1 >= this->Price)
	{
		gToolKit.RenderMixEffect(this->Harmony_EffectsMix, StartX + 20, StartY + 70, 2, 4);
		gInterface.DrawFormat(eWhite, StartX + 57, StartY + 104, 113, 3, "Đang ép đá, vui lòng chờ...");
	}
	else if (Coin1 < this->Price)
	{
		gInterface.DrawFormat(eRed, StartX + 57, StartY + 104, 113, 3, "KHÔNG ĐỦ COIN ĐỂ ÉP!");
	}
	else if (HarmonyEffect != 0)
	{
		HarmonyEffect = 0;
		if (this->Harmony_ActiveMix)
		{
			if ((GetTickCount() - gInterface.Data[eWindowHarmony].EventTick) > 300 && HarmonyEffect == 0)
			{
				XULY_CGPACKET pMsg;
				pMsg.header.set(0xD5, 0x2D, sizeof(pMsg));
				pMsg.ThaoTac = 113; //
				DataSend((LPBYTE)&pMsg, pMsg.header.size);
				gInterface.Data[eWindowHarmony].EventTick = GetTickCount();
			}
		}
	}

	if (this->IndexRandom != -1)
	{
		gInterface.DrawFormat(eExcellent, StartX + 57, StartY + 115, 113, 3, "%s", m_HarmonyInfoList[this->IndexRandom].Name);
	}
	gInterface.DrawFormat(eExcellent, StartX + 15, StartY + 155, 150, 1, "Bấm nút NHẬN để nhận lại vật phẩm đã nâng cấp.");
	gInterface.DrawFormat(eExcellent, StartX + 15, StartY + 167, 150, 1, "Click phải vào món đồ để trả lại item trước đó!");

	if (gElemental.gDrawButton(StartX + 60, StartY + 132, 70, 12, "Xoay", 40))
	{
		if (this->Harmony_ActiveMix)
		{
			this->Harmony_EffectsMix = 1;
		}
		else
		{
			gElemental.OpenMessageBox("Lỗi", "Kiểm tra lại vật phẩm!");
		}
		HarmonyEffect = GetTickCount() + 2000;
		this->IndexRandom = -1;
	}

	if (gElemental.gDrawButton(StartX + 125, StartY + 132, 70, 12, "Nhận", 40))
	{
		BackItemHarmony(4);
	}

	ObjectItem* CTItemChinh = &*(ObjectItem*)(BPConvertByteItem(*(DWORD*)(GetInstance() + 36), gCustomHarmony.ItemChuaEp));
	if (CTItemChinh->ItemID > 0)
	{
		gCBUtil.DrawItem3D(StartX + 10, StartY + 78, 50, 50, CTItemChinh->ItemID, CTItemChinh->Level, CTItemChinh->ExcellentOption, CTItemChinh->AncientOption, 0, 1.0);//BMD MOdel
		if (pCheckMouseOver(StartX + 10 + 7, StartY + 68, 40, 80) == 1)
		{
			BCacheInfoItemDD = CTItemChinh;
			CacheTimeShowInfoItem = GetTickCount() + 50;
			if (GetKeyState(VK_RBUTTON) & 0x8000)
			{
				BackItemHarmony(0);
			}
			JCCoord mousePosition;
			mousePosition.X = pCursorX + 50;
			mousePosition.Y = pCursorY;
			pSetBlend(true);
			glColor3f(1.0, 1.0, 1.0);
			sub_7E3E30(*(DWORD*)(GetInstance() + 308), mousePosition, (int)CTItemChinh, 0, 0, 0);
			pGLSwitch();
			pSetBlend(false);
		}
	}
}

void CustomHarmony::RecvHarmony(CHCSEV_COUNTLIST* lpMsg) // OK
{
	m_HarmonyInfoList.clear();

	for (int n = 0; n < lpMsg->Count; n++)
	{
		OPTITEM* lpInfo = (OPTITEM*)(((BYTE*)lpMsg) + sizeof(CHCSEV_COUNTLIST)+(sizeof(OPTITEM)* n));
		m_HarmonyInfoList.push_back(*lpInfo);

	}
}
#endif