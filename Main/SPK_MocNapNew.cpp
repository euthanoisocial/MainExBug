#include "StdAfx.h"
#if(B_MOCNAP)

#include "SPK_MocNapNew.h"
#include "Interface.h"
#include "CBNewUiEx.h"
#include "CBUtil.h"
#include "postInterface.h"
#include "Defines.h"
#include "Central.h"
#include "SPK_ToolKit.h"
#include "CustomFont.h"
#include "Console.h"
NewMocNap gNewMocNap;
HFONT IsText, IsDrawValue;

void NewMocNap::OpenWindowMocNap()
{
	if (GetTickCount() < gInterface.Data[eWindowMocNap].EventTick + 300)
	{
		return;
	}
	gInterface.Data[eWindowMocNap].EventTick = GetTickCount();
	if (!gInterface.Data[eWindowMocNap].OnShow)
	{
		XULY_CGPACKET pMsg;
		pMsg.header.set(0xD3, 0x9C, sizeof(pMsg));
		pMsg.ThaoTac = 1;
		DataSend((LPBYTE)&pMsg, pMsg.header.size);
	}
	gInterface.Data[eWindowMocNap].OnShow ^= 1;
}
CNewUIScrollBar* ListMocNap = nullptr;
CNewUIScrollBar* ListItemNhan = nullptr;
int MaxListMocNapInPage = 10;
int MaxListItemInPage = 8;
int SelectTypeMocNap = -1;

void ClickSendPacketViewItem(int n)
{
	SelectTypeMocNap = mDataMocNapClient.DanhSachMocNap[n].IndexMocNap;
	gInterface.Data[eWindowMocNapList].OnShow = true;
	gInterface.Data[eWindowMocNapList].EventTick = GetTickCount();
	XULY_CGPACKET pMsg;
	pMsg.header.set(0xD3, 0x9B, sizeof(pMsg));
	pMsg.ThaoTac = SelectTypeMocNap; //
	DataSend((LPBYTE)&pMsg, pMsg.header.size);
}
void ClickSendPacketRecItem(int n)
{
	XULY_CGPACKET pMsg;
	pMsg.header.set(0xD3, 0x9A, sizeof(pMsg));
	pMsg.ThaoTac = mDataMocNapClient.DanhSachMocNap[n].IndexMocNap;
	DataSend((LPBYTE)&pMsg, pMsg.header.size);
}
void NewMocNap::DrawWindowMocNap()
{
	if (gInterface.CheckWindow(ObjWindow::MoveList) || gInterface.CheckWindow(ObjWindow::CashShop) || gInterface.CheckWindow(ObjWindow::SkillTree) || gInterface.CheckWindow(ObjWindow::FullMap)
		|| (gInterface.CheckWindow(Inventory)
			&& gInterface.CheckWindow(ExpandInventory)
			&& gInterface.CheckWindow(Store))
		|| (gInterface.CheckWindow(Inventory)
			&& gInterface.CheckWindow(Warehouse)
			&& gInterface.CheckWindow(ExpandWarehouse)))
	{
		gInterface.Data[eWindowMocNap].OnShow = 0;

		return;
	}
	if (!gInterface.Data[eWindowMocNap].OnShow)
	{
		if (ListMocNap) ListMocNap = nullptr;
		if (SelectTypeMocNap != -1) SelectTypeMocNap = -1;
		return;
	}

	float WindowW = 220;
	float WindowH = 270;
	gInterface.Data[eWindowMocNap].Width = WindowW;
	float StartXA = (MAX_WIN_WIDTH / 2) - (WindowW / 2);
	float StartX = StartXA - 48;
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (WindowH / 2);

	float InfoMocNapX = (StartX + 10) + 3;
	float InfoMocNapY = (StartY + 35);
	float WInfo = (WindowW - 20) / 10;
	float WProcess = (WInfo * (7.5 - 2.7));
	float WButton = 38;
	float HInfo = WindowH - 100;
	COLORREF WhiteColor = RGB(255, 255, 255);
	COLORREF RedColor = RGB(80, 220, 60);
	gCentral.gDrawWindowCustom(StartX , StartY, WindowW + 100, WindowH, eWindowMocNap, "MỐC NẠP");
	{
		pSetBlend(true);
		glColor3f(1.0, 1.0, 1.0);
		//------------------------------------------------
		int TongSoDaNap = mDataMocNapClient.TongNap;
		int MocDaNhan = mDataMocNapClient.NhanMocNap;
		
		char IsValue[255],DrawValue[255];
		ZeroMemory(IsValue, sizeof(IsValue));
		wsprintf(IsValue, "Điểm tích lũy: %s", gToolKit.QNumberFormat(TongSoDaNap));
		gCentral.gInfoBox(StartX + 13, StartY + 40, WindowW + 64, 7.0f, 0x00FBFF69, 0, 0);
		gToolKit.CreateFontNew(StartX + 13, StartY + 42.5f, WindowW + 64, 3, 16, 700, IsValue, WhiteColor, IsText);
	
		float KhoangCachYMocNap = 17;
		gCentral.gInfoBox(StartX + 13, StartY + 58, WindowW - 46, 175.0f, 0x00000096, 0, 0);

		int DataListMocNap = mDataMocNapClient.DanhSachMocNap.size();
		if (!ListMocNap)
		{
			ListMocNap = new CNewUIScrollBar();
			ListMocNap->Create((StartX + WindowW) - 38, InfoMocNapY + 30, HInfo);
			if (ListMocNap)
			{
				ListMocNap->SetMaxPos((DataListMocNap <= MaxListMocNapInPage) ? 0 : (DataListMocNap / MaxListMocNapInPage) - 1);
				ListMocNap->SetPos((StartX + WindowW) - 38, InfoMocNapY + 30);
			}
		}
		if (ListMocNap)
		{
			if (gInterface.Data[eWindowMocNap].OnClick)
			{
				ListMocNap->SetPos((StartX + WindowW) - 38, InfoMocNapY + 30);
				ListMocNap->SetCurPos(0);
			}
			ListMocNap->MouseWheelWindow = pCheckMouseOver(InfoMocNapX, InfoMocNapY, WInfo * 7.5, HInfo + 10);
			ListMocNap->Render();
			ListMocNap->UpdateMouseEvent();
			ListMocNap->Update();
		}
		int MixItemListPage = ListMocNap->GetCurPos();
		int MaxList = 0;

		for (int n = (MixItemListPage * MaxListMocNapInPage); n < DataListMocNap; n++)
		{
			float TyleNap = (96.0 * TongSoDaNap ) / mDataMocNapClient.DanhSachMocNap[n].GiaTriNap ;

			if (TyleNap > 96.0)
			{
				TyleNap = 96.0;
			}
			double Tyle = (static_cast<double>(TongSoDaNap) / mDataMocNapClient.DanhSachMocNap[n].GiaTriNap) * 100;

			ZeroMemory(DrawValue, sizeof(DrawValue));
			wsprintf(DrawValue, "Mốc %02d: %s", mDataMocNapClient.DanhSachMocNap[n].IndexMocNap, gToolKit.QNumberFormat(mDataMocNapClient.DanhSachMocNap[n].GiaTriNap));

			CustomFont.Draw(CustomFont.FontBold, InfoMocNapX + 5, InfoMocNapY + 31, 0xFFFFFFFF, 0xca0e0e69, TyleNap, 15, 3, " ");

			if (pCheckMouseOver(InfoMocNapX + 5, InfoMocNapY + 31 + (0), DataListMocNap + 97, 15) == 1)
			{
				if (pIsKeyPress(VK_LBUTTON) && GetTickCount() > gInterface.Data[eWindowMocNapList].EventTick + 300)
				{
					ClickSendPacketViewItem(n);
					CustomFont.Draw(CustomFont.FontBold, InfoMocNapX + 5, InfoMocNapY + 31, 0xFFFFFFFF, 0x78701469, 97, 15, 3, " ");
				}
				CustomFont.Draw(CustomFont.FontBold, InfoMocNapX + 5, InfoMocNapY + 31, 0xFFFFFFFF, 0x00FBFF69, 97, 15, 3, " ");
			}
			gCentral.gInfoBox(InfoMocNapX + 5, InfoMocNapY + 31, 90, 7.0f, 0, 0, 0);
			gToolKit.CreateFontNew(InfoMocNapX + 5, InfoMocNapY + 34, 90, 3, 16, 700, DrawValue, WhiteColor, IsDrawValue);

			if (MocDaNhan < mDataMocNapClient.DanhSachMocNap[n].IndexMocNap) 
			{
				if (pCheckMouseOver(InfoMocNapX + 107, InfoMocNapY + 31, DataListMocNap + 50, 15) == 1)
				{
					CustomFont.Draw(CustomFont.FontBold, InfoMocNapX + 107, InfoMocNapY + 31, 0xFFFFFFFF, 0x00FBFF69, 50, 15, 3, " ");
					if (pIsKeyPress(VK_LBUTTON) && GetTickCount() > gInterface.Data[eWindowMocNapList].EventTick + 300)
					{
						ClickSendPacketRecItem(n);
					}
				}
				gCentral.gInfoBox(InfoMocNapX + 107, InfoMocNapY + 31, 44, 7.0f, 0xCA0E0E69, 0, 0);

				if (Tyle < 100)
				{
					CustomFont.Draw(CustomFont.FontBold, InfoMocNapX + 107, InfoMocNapY + 34, 0xFFFFFFFF, 0x0, 50, 0, 3, "%0.1f%%", Tyle);
				}
				else
				{
					gToolKit.CreateFontNew(InfoMocNapX + 107, InfoMocNapY + 34, 50, 3, 16, 700, "NHẬN", WhiteColor, IsDrawValue);
				}
			}
			else
			{
				gCentral.gInfoBox(InfoMocNapX + 107, InfoMocNapY + 31, 44, 7.0f, 0xCA0E0E69, 0, 0);
				gToolKit.CreateFontNew(InfoMocNapX + 107, InfoMocNapY + 34, 50, 3, 16, 700, "ĐÃ NHẬN", WhiteColor, IsDrawValue);
			}
			
			InfoMocNapY = InfoMocNapY + (KhoangCachYMocNap);
			MaxList++;
			if (MaxList >= MaxListMocNapInPage) break;
		}
		gCentral.gInfoBox(StartX + 200, StartY + 58, WindowW - 120, 175.0f, 0x00000096, 0, 0);

		int DataListItem = mDataListItemMocNapClient.ListItemMocNap.size();
		if (!ListItemNhan)
		{
			ListItemNhan = new CNewUIScrollBar();
			ListItemNhan->Create((StartX + WindowW) + 75, StartY + 35 + 30, HInfo);
			if (ListItemNhan)
			{
				ListItemNhan->SetMaxPos((DataListItem <= MaxListItemInPage) ? 0 : (DataListItem / MaxListItemInPage) - 1);
				ListItemNhan->SetPos((StartX + WindowW) + 75, StartY + 35 + 30);
			}
		}
		if (ListItemNhan)
		{
			if (gInterface.Data[eWindowMocNapList].OnClick)
			{
				ListItemNhan->SetPos((StartX + WindowW) + 75, StartY + 35 + 30);
				ListItemNhan->SetCurPos(0);
			}
			ListItemNhan->MouseWheelWindow = pCheckMouseOver(StartX + WindowW, StartY + 35 + 30, WindowW, HInfo + 10);
			ListItemNhan->Render();
			ListItemNhan->UpdateMouseEvent();
			ListItemNhan->Update();
		}

		float PosXBoxItemGoc = StartX + 205;
		float PosXBoxItem = StartX + 205;
		float PosYBoxItem = StartY + 60;
		float WBox = 30;
		float KhoangCach = 40;
		int CountNgang = 0;
		int CountDoc = 0;
		int ItemListPage = ListItemNhan->GetCurPos();
		int BBShowInfoItem = -1;
		float KiemTraViTriY = 0;
		for (int n = (ItemListPage * MaxListItemInPage); n < DataListItem; n++)
		{
			ItemBmdStruct* is = pGetItemBmdStruct(mDataListItemMocNapClient.ListItemMocNap[n].Index);
			int size = max(is->ItemWidth, is->ItemHeight);

			float itemScale = 1.0;
			float addY = 0;
			switch (size)
			{
				case 4:				addY = -5;				break;
				case 3:				addY = -3;				break;
				case 2:				addY = -1;				break;
			}
			gCentral.gItemBoxInv(PosXBoxItem + 3, PosYBoxItem + 5, 2, 2, 0);
			if (SPK_ITEM_KHIENG)
			{
				KiemTraViTriY = 8;
			}
			else if (SPK_ITEM_MU || SPK_ITEM_AO)
			{
				KiemTraViTriY = 12;
			}
			else if(SPK_ITEM_GANG || SPK_ITEM_GIAY || SPK_ITEM_QUAN)
			{
				KiemTraViTriY = 11;
			}
			gCBUtil.DrawItem3D(PosXBoxItem + 8, PosYBoxItem + 5 + addY + KiemTraViTriY, WBox, WBox, mDataListItemMocNapClient.ListItemMocNap[n].Index, mDataListItemMocNapClient.ListItemMocNap[n].Item.Level, mDataListItemMocNapClient.ListItemMocNap[n].Item.ExcellentOption, mDataListItemMocNapClient.ListItemMocNap[n].Item.AncientOption, 0, 1.0 / mDataListItemMocNapClient.ListItemMocNap[n].SizeBMD);//Show Item
			
			if (mDataListItemMocNapClient.ListItemMocNap[n].Count > 1)
			{
				gToolKit.CRenderNumberEx(PosXBoxItem + 35, PosYBoxItem + 30, mDataListItemMocNapClient.ListItemMocNap[n].Count, 0.96, 31337);
			}
			if (pCheckMouseOver(PosXBoxItem, PosYBoxItem, WBox, WBox))
			{
				BBShowInfoItem = n;
			}
			PosXBoxItem += KhoangCach;
			CountDoc++;
			CountNgang++;
			if (CountNgang >= 2)
			{
				PosXBoxItem = PosXBoxItemGoc;
				PosYBoxItem += KhoangCach;
				CountNgang = 0;
			}
			if (CountDoc >= MaxListItemInPage) break;
		}
		if (BBShowInfoItem != -1)
		{
			gPostInterface.DrawItemToolTipText((void*)&mDataListItemMocNapClient.ListItemMocNap[BBShowInfoItem].Item, *(int*)0x879340C, *(int*)0x8793410 + 25);
			glColor3f(1, 1, 1);
			pSetBlend(false);
		}

		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}
}
#endif