#include "stdafx.h"
#if (RESETCHANGE==1)
#include "SPK_ResetChange.h"
#include "Interface.h"
#include "Protect.h"
#include "Defines.h"
#include "Protocol.h"
#include "User.h"
#include "CustomRankUser.h"
#include "Central.h"
#include "Config.h"
CResetChange gResetChange;

#define MoveDown 10

void GetButtonCreate(float StartX, float ButtonX, int eNumButton, int AddY, BYTE ID)
{
	gInterface.DrawFormat(eWhite, StartX - 27, gInterface.Data[eRESETCHANGE].Y		+ AddY + MoveDown,			200, 3, gConfig.TSPK_TEXT_ENGINE[309], gCustomRankUser.ReqResetChange[ID], gCustomRankUser.ReqResetUpPoint[ID], gCustomRankUser.ReqResetCoin[ID]);
	gInterface.DrawFormat(eYellow, ButtonX + 85.5, gInterface.Data[eRESETCHANGE].Y	+ (AddY + 2) + MoveDown,	100, 3, gConfig.TSPK_TEXT_ENGINE[310]);
	if (gInterface.IsWorkZone(eNumButton))
	{
		DWORD Color = eGray100;
		if (gInterface.Data[eNumButton].OnClick)
		{
			Color = eGray150;
		}
		gInterface.DrawColoredGUI(eNumButton, gInterface.Data[eNumButton].X, gInterface.Data[eNumButton].Y, Color);
	}
}
void CResetChange::DrawResetChange()
{
	if (!gInterface.Data[eRESETCHANGE].OnShow)
	{
		return;
	}
	if (gInterface.CheckWindow(CashShop)
		|| gInterface.CheckWindow(SkillTree)
		|| gInterface.CheckWindow(FullMap)
		|| gInterface.CheckWindow(MoveList)
		|| gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(Party)
		|| gInterface.CheckWindow(Trade)
		|| gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(ExpandWarehouse))
	{
		return;
	}
	DWORD ItemNameColor = eWhite;
	float MainWidth = 230.0;
	float MainHeight = 233.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	gCentral.gDrawWindowCustom(StartX - 20, StartY - 30, MainWidth + 40, MainHeight, eRESETCHANGE, gConfig.TSPK_TEXT_ENGINE[311]);

	gCentral.gInfoBox(StartX - 5,	StartY + 10,	160.0f, 133.0f,	200, 0, 0);
	gCentral.gInfoBox(StartX + 170, StartY + 10,	50.0f,	133.0f,	200, 0, 0);
	gCentral.gInfoBox(StartX - 5,	StartY + 160,	230,	20.0f,	200, 0, 0);
	
	gInterface.DrawFormat(eYellow, StartX, gInterface.Data[eRESETCHANGE].Y + 265, 300, 1, gConfig.TSPK_TEXT_ENGINE[312]);
	gInterface.DrawFormat(eYellow, StartX, gInterface.Data[eRESETCHANGE].Y + 277, 300, 1, gConfig.TSPK_TEXT_ENGINE[313]);

	gInterface.DrawGUI(eBOTON1, ButtonX + 111.5, gInterface.Data[eRESETCHANGE].Y + 104 + MoveDown);
	GetButtonCreate(StartX, ButtonX, eBOTON1, 110,0);

	gInterface.DrawGUI(eBOTON2, ButtonX + 111.5, gInterface.Data[eRESETCHANGE].Y + 131 + MoveDown);
	GetButtonCreate(StartX, ButtonX, eBOTON2, 137,1);

	gInterface.DrawGUI(eBOTON3, ButtonX + 111.5, gInterface.Data[eRESETCHANGE].Y + 158 + MoveDown);
	GetButtonCreate(StartX, ButtonX, eBOTON3, 164,2);

	gInterface.DrawGUI(eBOTON4, ButtonX + 111.5, gInterface.Data[eRESETCHANGE].Y + 185 + MoveDown);
	GetButtonCreate(StartX, ButtonX, eBOTON4, 191,3);

	gInterface.DrawGUI(eBOTON5, ButtonX + 111.5, gInterface.Data[eRESETCHANGE].Y + 212 + MoveDown);
	GetButtonCreate(StartX, ButtonX, eBOTON5, 218,4);
}

void CResetChange::ButtonResetChange(DWORD Event)
{
	DWORD Delay = (GetTickCount() - gInterface.ClickTime);
	if (gInterface.Data[eRESETCHANGE].OnShow)
	{
		if (gInterface.ButtonEx(Event, eBOTON1, false))
		{
			this->ResetChange(1);
			return;
		}

		if (gInterface.ButtonEx(Event, eBOTON2, false))
		{
			this->ResetChange(2);
			return;
		}

		if (gInterface.ButtonEx(Event, eBOTON3, false))
		{
			this->ResetChange(3);
			return;
		}

		if (gInterface.ButtonEx(Event, eBOTON4, false))
		{
			this->ResetChange(4);
			return;
		}

		if (gInterface.ButtonEx(Event, eBOTON5, false))
		{
			this->ResetChange(5);
			return;
		}
	}
}

void CResetChange::OpenResetChange()
{

	if (gInterface.Data[eRESETCHANGE].OnShow == true)
	{
		gInterface.Data[eRESETCHANGE].OnShow = false;
		pSetCursorFocus = false;
		return;
	}

	DWORD CurrentTick = GetTickCount();

	gInterface.Data[eRESETCHANGE].EventTick = GetTickCount();
	gInterface.Data[eRESETCHANGE].OnShow = true;
	pSetCursorFocus = true;

}

void CResetChange::ResetChange(int numchange)
{
	RESETCHANGE_REQ pRequest;
	pRequest.h.set(0xF3, 0xD9, sizeof(pRequest));
	pRequest.numchange = numchange;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}

#endif