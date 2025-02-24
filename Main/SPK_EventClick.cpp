#include "stdafx.h"
#include "Interface.h"
#include "Ranking.h"
#include "Defines.h"
#include "SPK_DrawBoxAtm.h"
#include "SPK_MocNapNew.H"
#include "SPK_ItemLocker.h"
void HadleClickClose()
{
	gRanking.Show = false;
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
	gInterface.Data[eJewelBank_MAIN].OnShow = false;
	gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;
	gInterface.Data[ePARTYSEARCH_MAIN].OnShow == false;
	gInterface.Data[eCommand_MAIN].OnShow = false;
	gInterface.Data[eWindow_NangCapHonHoan].OnShow = false;
	gInterface.Data[eWindow_NangCapQuanHam].OnShow = false;
	gInterface.Data[eWindow_NangCapTuChan].OnShow = false;
	gInterface.Data[eWindow_NangCapDanhHieu].OnShow = false;
	gInterface.Data[eWindow_NangCapNewVip].OnShow = false;
	gInterface.Data[eChangePass_Main].OnShow = false;
	gInterface.Data[TMC_MAIN].OnShow = false;
	gInterface.Data[eCTCMiniWindow].OnShow = false;

	gInterface.Data[eMenu_MAIN].OnShow = false;
	gInterface.Data[eTopDame].OnShow = false;
	gInterface.Data[eSTATSADD_MAIN].OnShow = false;
	gInterface.Data[eRESETSTATS_MAIN].OnShow = false;
	gInterface.Data[SpkRelife_MainBox].OnShow = false;
	gInterface.Data[eCustomShop].OnShow = false;
	gInterface.Data[eWindowMocNap].OnShow = false;
	gInterface.Data[eWindowHarmony].OnShow = false;
	gInterface.Data[eWindowDungLuyenItem].OnShow = false;
}
bool Interface::SPK_ItemBlock(DWORD Event)
{
	#define OKMENU SPK_ITEM_BLOCK
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		HadleClickClose();
		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	nInterface.OpenWindowLock();
	return false;
}
bool Interface::SPK_OpenBoxCfg(DWORD Event)
{
	#define OKMENU SPK_CONFIG_BOX
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		gRanking.Show = false;
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		gInterface.Data[eJewelBank_MAIN].OnShow = false;
		gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;
		gInterface.Data[eCommand_MAIN].OnShow = false;

		this->Data[eWindow_NangCapHonHoan].OnShow = false;
		this->Data[eWindow_NangCapQuanHam].OnShow = false;
		this->Data[eWindow_NangCapTuChan].OnShow = false;

		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	gInterface.OpenConfig(0);
	return false;
}
bool Interface::SPK_OpenBoxBSK(DWORD Event)
{
#define OKMENU SPK_MAIN_BOXSK
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		gRanking.Show = false;
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		gInterface.Data[eJewelBank_MAIN].OnShow = false;
		gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;
		gInterface.Data[eCommand_MAIN].OnShow = false;

		this->Data[eWindow_NangCapHonHoan].OnShow = false;
		this->Data[eWindow_NangCapQuanHam].OnShow = false;
		this->Data[eWindow_NangCapTuChan].OnShow = false;

		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	//PMSG_RESET_SEND pMsg;
	//pMsg.header.set(0xF7, 0x02, sizeof(pMsg));
	//DataSend((LPBYTE)&pMsg, pMsg.header.size);
	return false;
}
bool Interface::SPK_OpenBoxAtm(DWORD Event)
{
#define OKMENU SPK_MAIN_ATM
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		gRanking.Show = false;
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		gInterface.Data[eJewelBank_MAIN].OnShow = false;
		gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;
		gInterface.Data[eCommand_MAIN].OnShow = false;

		this->Data[eWindow_NangCapHonHoan].OnShow = false;
		this->Data[eWindow_NangCapQuanHam].OnShow = false;
		this->Data[eWindow_NangCapTuChan].OnShow = false;

		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	//tm.OpenDrawBoxAtm();
	return false;
}
bool Interface::SPK_RsCamera3D(DWORD Event)
{
#define OKMENU SPK_MAIN_ZMCAM
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		gRanking.Show = false;
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		gInterface.Data[eJewelBank_MAIN].OnShow = false;
		gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;
		gInterface.Data[eCommand_MAIN].OnShow = false;

		this->Data[eWindow_NangCapHonHoan].OnShow = false;
		this->Data[eWindow_NangCapQuanHam].OnShow = false;
		this->Data[eWindow_NangCapTuChan].OnShow = false;

		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	//gInterface.SwitchCamera();
	return false;
}
bool Interface::SPK_Camera3D(DWORD Event)
{
#define OKMENU SPK_MAIN_RSCAM
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		gRanking.Show = false;
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		gInterface.Data[eJewelBank_MAIN].OnShow = false;
		gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;
		gInterface.Data[eCommand_MAIN].OnShow = false;

		this->Data[eWindow_NangCapHonHoan].OnShow = false;
		this->Data[eWindow_NangCapQuanHam].OnShow = false;
		this->Data[eWindow_NangCapTuChan].OnShow = false;

		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	//gInterface.CameraInit();
	return false;
}
bool Interface::SPK_ResetAuto(DWORD Event)
{
	#define OKMENU SPK_MAIN_ARESET
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[OKMENU].EventTick);
	if (KiemTraCacEvent_1 || !IsWorkZone(OKMENU))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[OKMENU].OnClick = true;
		gRanking.Show = false;
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		gInterface.Data[eJewelBank_MAIN].OnShow = false;
		gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;
		gInterface.Data[eCommand_MAIN].OnShow = false;

		this->Data[eWindow_NangCapHonHoan].OnShow = false;
		this->Data[eWindow_NangCapQuanHam].OnShow = false;
		this->Data[eWindow_NangCapTuChan].OnShow = false;

		return true;
	}
	this->Data[OKMENU].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[OKMENU].EventTick = GetTickCount();
	this->CloseMenuWindow();
	//PMSG_TICKET_SEND pMsg;
	//pMsg.header.set(0xFC, 100, sizeof(pMsg)); // AutoReset Send
	//DataSend((BYTE*)&pMsg, pMsg.header.size);
	return false;
}

bool Interface::EventDrawMenu_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	#define EVENTICK eMenu_CLOSE
	DWORD Delay = (CurrentTick - this->Data[EVENTICK].EventTick);
	if (!this->Data[eMenu_MAIN].OnShow || !IsWorkZone(EVENTICK))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EVENTICK].OnClick = true;
		return true;
	}
	this->Data[EVENTICK].OnClick = false;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EVENTICK].EventTick = GetTickCount();
	this->CloseMenuWindow();
	return false;
}
bool Interface::EventDrawCTCMINI_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	#define EVENTICK CTCMINI_CLOSE
	DWORD Delay = (CurrentTick - this->Data[EVENTICK].EventTick);
	if (!this->Data[CTCMINI_MAIN].OnShow || !IsWorkZone(EVENTICK))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[EVENTICK].OnClick = true;
		return true;
	}
	this->Data[EVENTICK].OnClick = false;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[EVENTICK].EventTick = GetTickCount();
	this->CloseMenuWindow();
	return false;
}