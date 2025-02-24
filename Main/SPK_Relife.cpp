#include "stdafx.h"
#if RELIFE
#include "SPK_Relife.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "Interface.h"
#include "User.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "SItemOption.h"
#include "Import.h"
#include "Central.h"
#include "User.h"
#include "CustomJewelBank.h"
#include "Ranking.h"
#include "CustomFont.h"
#include "Console.h"

SpkRelife G_SpkRelife;

SpkRelife::SpkRelife()
{
	this->DrawMainRelife	= false;
	this->MainWidth			= 640;
	this->StartY			= 0;
	this->StartX			= 0;
	this->ClickTick			= 0;
}

void SpkRelife::BingRelife()
{
	gInterface.BindObject(SpkRelife_MainBox, 31461, 640, 419, -1, -1);  // 31461
	gInterface.BindObject(SpkRelife_CloseBox, 0x7EC5, 36, 29, -1, -1);

	for (int i = 0; i < MAXSIZERL; i++)
	{
		gInterface.BindObject(SpkRelifeButton + i, 0x7A5E, 108, 29, -1, -1);
	}
}
void SpkRelife::SendMenuButton()
{
	G_SpkRelife.OpenWindowsRelife();
	G_SpkRelife.RelifePacket(100);
}
void SpkRelife::CallWindows()
{
	this->CallWindowsRelife();
}
void SpkRelife::GetRelifeDataDraw(float x, float y, float Center, int SlotJw1, int SlotJw2, int SlotJw3, int SlotJw4, int SlotJw5, int gmCheckDieuKien, int gmCheckRelife) //OK SPK
{
	this->DrawLineTaiSinh(12, 15, 1, (x + 50), y + 150 - 24, "Ngọc Hỗn Nguyên");
	this->DrawLineTaiSinh(14, 13, 2, (x + 50), y + 170 - 24, "Ngọc Ước Nguyện");
	this->DrawLineTaiSinh(14, 14, 3, (x + 50), y + 190 - 24, "Ngọc Tâm Linh");
	this->DrawLineTaiSinh(14, 16, 4, (x + 50), y + 210 - 24, "Ngọc Sinh Mệnh");
	this->DrawLineTaiSinh(14, 22, 5, (x + 50), y + 230 - 24, "Ngọc Sáng Tạo");

	gInterface.DrawFormat(eGold, x + 102, y + 150 - 27, 200, 3, " %d / %d", SlotJw1, gCustomJewelBank.m_Data.ItemBank[7]);
	gInterface.DrawFormat(eGold, x + 102, y + 170 - 27, 200, 3, " %d / %d", SlotJw2, gCustomJewelBank.m_Data.ItemBank[0]);
	gInterface.DrawFormat(eGold, x + 102, y + 190 - 27, 200, 3, " %d / %d", SlotJw3, gCustomJewelBank.m_Data.ItemBank[1]);
	gInterface.DrawFormat(eGold, x + 102, y + 210 - 27, 200, 3, " %d / %d", SlotJw4, gCustomJewelBank.m_Data.ItemBank[2]);
	gInterface.DrawFormat(eGold, x + 102, y + 230 - 27, 200, 3, " %d / %d", SlotJw5, gCustomJewelBank.m_Data.ItemBank[3]);

	gCentral.gInfoBox(Center - 8, y + 235, 220, 73, 0x00000096, 0, 0);
	CustomFont.Draw((HFONT)pFontBold, Center - 7, y + 235, 0xFFFFFFFF, 0x00FBFF69, 225, 0, 3, "Cấp Độ %d/%d , Reset %d/%d", gObjUser.lpPlayer->Level, this->m_DieuKienLevel, ViewReset, gmCheckDieuKien);

	gInterface.DrawFormat(eExcellent,		x + 50, y + 255 - 4, 200, 1, "Tất cả các cột điểm sẽ về gốc!");
	gInterface.SPKText(eExcellent,	x + 50, y + 270 - 4, 200, 1, "Điểm dư sau khi Relife là: %d", gmCheckRelife);
	gInterface.DrawFormat(eExcellent,	x + 50, y + 285 - 4, 200, 1, "Ngọc sẽ trừ trực tiếp vào Bank!");

	if (this->ResetLife == 0)
	{
		gInterface.DrawFormat(MauVangCam, x + 50, y + 300 - 4, 200, 1, "Bạn chưa có Relife lần nào cả!");
	}
	else
	{
		gInterface.DrawFormat(MauVangCam, x + 50, y + 300 - 4, 200, 1, "Bạn đã Relife lần thứ: %d", this->ResetLife);
	}

	gInterface.DrawGUI(SpkRelifeButton + this->ResetLife, x + 90, y + 320);
	gInterface.DrawFormat(eGold, Center - 7, y + 330, 225, 3, "ĐỒNG Ý");
	if (gInterface.IsWorkZone(SpkRelifeButton + this->ResetLife))
	{
		DWORD Color = eGray150;
		gInterface.DrawColoredGUI(SpkRelifeButton + this->ResetLife, gInterface.Data[SpkRelifeButton + this->ResetLife].X, gInterface.Data[SpkRelifeButton + this->ResetLife].Y, Color);
	}
}
void SpkRelife::CallWindowsRelife()
{
	if (pPlayerState < GameProcess || gInterface.CheckWindow(ObjWindow::CashShop) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::MoveList) || gInterface.CheckWindow(ObjWindow::Party) || gInterface.CheckWindow(ObjWindow::Quest) || gInterface.CheckWindow(ObjWindow::NPC_Devin) || gInterface.CheckWindow(ObjWindow::Guild) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::ChaosBox) || gInterface.CheckWindow(ObjWindow::CommandWindow) || gInterface.CheckWindow(ObjWindow::PetInfo) || gInterface.CheckWindow(ObjWindow::Shop) || gInterface.CheckWindow(ObjWindow::Inventory) || gInterface.CheckWindow(ObjWindow::Store) || gInterface.CheckWindow(ObjWindow::OtherStore) || gInterface.CheckWindow(ObjWindow::Character) || gInterface.CheckWindow(ObjWindow::DevilSquare) || gInterface.CheckWindow(ObjWindow::BloodCastle) || gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::GuardNPC) || gInterface.CheckWindow(ObjWindow::SeniorNPC) || gInterface.CheckWindow(ObjWindow::GuardNPC2) || gInterface.CheckWindow(ObjWindow::CastleGateSwitch) || gInterface.CheckWindow(ObjWindow::CatapultNPC) || gInterface.CheckWindow(ObjWindow::CrywolfGate) || gInterface.CheckWindow(ObjWindow::IllusionTemple) || gInterface.CheckWindow(ObjWindow::HeroList) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FastMenu) || gInterface.CheckWindow(ObjWindow::Options) || gInterface.CheckWindow(ObjWindow::Help) || gInterface.CheckWindow(ObjWindow::FastDial) || gInterface.CheckWindow(ObjWindow::SkillTree) || gInterface.CheckWindow(ObjWindow::GoldenArcher1) || gInterface.CheckWindow(ObjWindow::GoldenArcher2) || gInterface.CheckWindow(ObjWindow::LuckyCoin1) || gInterface.CheckWindow(ObjWindow::LuckyCoin2) || gInterface.CheckWindow(ObjWindow::NPC_Duel) || gInterface.CheckWindow(ObjWindow::NPC_Titus) || gInterface.CheckWindow(ObjWindow::CashShop) || gInterface.CheckWindow(ObjWindow::Lugard) || gInterface.CheckWindow(ObjWindow::QuestList1) || gInterface.CheckWindow(ObjWindow::QuestList2) || gInterface.CheckWindow(ObjWindow::Jerint) || gInterface.CheckWindow(ObjWindow::FullMap) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::GensInfo) || gInterface.CheckWindow(ObjWindow::NPC_Julia) || gInterface.CheckWindow(ObjWindow::NPC_ChaosMix) || gInterface.CheckWindow(ObjWindow::ExpandInventory) || gInterface.CheckWindow(ObjWindow::ExpandWarehouse) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.Data[eMenu_MAIN].OnShow || gInterface.Data[eEventTimePANEL_MAIN].OnShow || gInterface.Data[eCommand_MAIN].OnShow || gInterface.Data[eChangePass_Main].OnShow || gInterface.Data[eRankPANEL_MAIN].OnShow || gInterface.Data[eCONFIRM_MAIN].OnShow || gInterface.Data[eJewelBank_MAIN].OnShow || gInterface.Data[ePARTYSETTINGS_MAIN].OnShow || gInterface.Data[ePARTYSEARCH_MAIN].OnShow || gInterface.Data[eLuckySpin].OnShow || !gInterface.Data[SpkRelife_MainBox].OnShow)
	{
		return;
	}
	float MainCenter = this->StartX + (this->MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);
	float StartDrawX = 170;

	gCentral.gDrawWindowCustom(MainCenter - 30, this->StartY + 60, 265, 300, SpkRelife_MainBox, "HỆ THỐNG RELIFE");
	gCentral.gInfoBox(MainCenter - 8, this->StartY + 105, 220, 113, 0x00000096, 0, 0);
	CustomFont.Draw((HFONT)pFontBold, MainCenter - 7, this->StartY + 105, 0xFFFFFFFF, 0x00FBFF69, 225, 0, 3, "Yêu Cầu Relife cho lần thứ %d", this->ResetLife + 1);

	for (int G = 0; G < 10; G++)
	{
		if (this->ResetLife == G)
		{
			this->GetRelifeDataDraw(StartDrawX, this->StartY, MainCenter,
				this->CheckDieuKienJw[G][0],
				this->CheckDieuKienJw[G][1],
				this->CheckDieuKienJw[G][2],
				this->CheckDieuKienJw[G][3],
				this->CheckDieuKienJw[G][4],
				 this->mCheckDieuKien[G],
			  this->mCheckDiemTaiSinh[G]);
		}
	}
}
void SpkRelife::RelifePacket(int Number)
{
	RelifeCheckReQuest pMsg;
	pMsg.h.set(0xFC, 0x08, sizeof(pMsg)); 
	pMsg.Number = Number;
	DataSend((BYTE*)&pMsg, pMsg.h.size);
}

bool SpkRelife::MainWindowsRelife(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	this->RejectWindowsRelife(Event);

	for (int resetIndex = 0; resetIndex < 10; resetIndex++)
	{
		if (this->ResetLife == resetIndex)
		{
			if (gInterface.Data[SpkRelife_MainBox].OnShow && gInterface.IsWorkZone(SpkRelifeButton + resetIndex))
			{
				DWORD CurrentTick = GetTickCount();
				DWORD Delay = (CurrentTick - gInterface.Data[SpkRelifeButton + resetIndex].EventTick);
				if (Event == WM_LBUTTONDOWN)
				{
					gInterface.Data[SpkRelifeButton + resetIndex].OnClick = true;
					pSetCursorFocus = true;
					return true;
				}
				gInterface.Data[SpkRelifeButton + resetIndex].OnClick = false;
				pSetCursorFocus = false;
				if (Delay < 500)
				{
					return false;
				}
				gInterface.Data[SpkRelifeButton + resetIndex].EventTick = GetTickCount();
				this->CloseWindowsRelife();
				this->RelifePacket(resetIndex + 1); 
			}
		}
	}

	return true;
}
bool SpkRelife::RejectWindowsRelife(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[SpkRelife_CloseBox].EventTick);
	if (!gInterface.Data[SpkRelife_MainBox].OnShow || !gInterface.IsWorkZone(SpkRelife_CloseBox))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[SpkRelife_CloseBox].OnClick = true;
		return true;
	}
	gInterface.Data[SpkRelife_CloseBox].OnClick = false;
	if (Delay < 500)
	{
		return false;
	}
	gInterface.Data[SpkRelife_CloseBox].EventTick = GetTickCount();
	G_SpkRelife.CloseWindowsRelife();
	return false;
}

void SpkRelife::TaiSinhCheckRecv(RelifeCheckUpdate* SPK)
{
	this->m_TaiSinh			= SPK->m_TaiSinh;
	this->m_DieuKienLevel	= SPK->m_DieuKienLevel;

	for (int x = 0; x < MAXSIZERL; x++)
	{
		this->mCheckDieuKien[x] = SPK->CheckDieuKien[x];
	}
	this->ResetLife = SPK->ResetLife;
}

void SpkRelife::TaiSinhDiemRecv(RelifePointUpdate* SPK)
{
	for ( int i = 0; i < MAXSIZERL; i++)
	{
		this->mCheckDiemTaiSinh[i] = SPK->CheckDiemTaiSinh[i];
	}
}

void SpkRelife::SaveFormGs(RelifeCheckReqInfoPart1* SPK)
{
	for (int i = 0; i < MAXSIZERL; i++)
	{
		this->CheckDieuKienJw[i][0] = SPK->CheckDieuKienNgocVal[i][0];
		this->CheckDieuKienJw[i][1] = SPK->CheckDieuKienNgocVal[i][1];
		this->CheckDieuKienJw[i][2] = SPK->CheckDieuKienNgocVal[i][2];
		this->CheckDieuKienJw[i][3] = SPK->CheckDieuKienNgocVal[i][3];
		this->CheckDieuKienJw[i][4] = SPK->CheckDieuKienNgocVal[i][4];
	}
}

void SpkRelife::DrawLineTaiSinh(int ItemType, int ItemIndex, int ItemLevel, float ItemDrawX, float ItemDrawY, char* ItemName)
{
	ItemBmdStruct* ItemInfo = pGetItemBmdStruct(ITEM(ItemType, ItemIndex));
	const int WidthValue = 30;
	const int HeightValue = 31;
	float barWidth = WidthValue * ItemInfo->ItemWidth;
	float barHeight = HeightValue * ItemInfo->ItemHeight;
	float flX = ItemDrawX + 10;
	float flY = ItemDrawY - 20;
	int iLevel = 0;
	gInterface.DrawItem2(flX - 7, flY + 15, 10, 15, GET_ITEM(ItemType, ItemIndex), SET_ITEMOPT_LEVEL(iLevel), 0, 0, 0);

	flX += 30;
	flY += 15;

	gInterface.DrawFormat(eYellow, flX, flY + 2, 120, 1, "%s", ItemName);
}
#endif
