#include "stdafx.h"
#include "CustomEventTime.h"
#include "CustomMessage.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "Util.h"
#include "Object.h"
#include "Import.h"
#include "Central.h"
#include "Protocol.h"
#include "CustomFont.h"
#include "User.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Config.h"

CCustomEventTime gCETime;

void CCustomEventTime::Load(CUSTOM_EVENT_INFO* info) // OK
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomEventTime::SetInfo(CUSTOM_EVENT_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_EVENTTIME)
	{
		return;
	}

	this->m_CustomEventInfo[info.Index] = info;
}

void CCustomEventTime::ClearCustomEventTime() // OK
{
	for (int n = 0; n < MAX_EVENTTIME; n++)
	{
		gCustomEventTime[n].time = -1;
	}
	this->count = 0;
	this->EventTimeEnable = 0;
}

void CCustomEventTime::GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg) // OK
{
	this->count = lpMsg->count;

	for (int n = 0; n < lpMsg->count; n++)
	{
		CUSTOM_EVENTTIME_DATA* lpInfo = (CUSTOM_EVENTTIME_DATA*)(((BYTE*)lpMsg) + sizeof(PMSG_CUSTOM_EVENTTIME_RECV) + (sizeof(CUSTOM_EVENTTIME_DATA)*n));

		this->gCustomEventTime[n].index = lpInfo->index;
		this->gCustomEventTime[n].time = lpInfo->time;

		if (this->gCustomEventTime[n].index >= 28 && this->gCustomEventTime[n].time != -1) this->Arena = 1;
	}

	this->EventTimeEnable = 1;
}

int NextEvent = 0;
int PreventEvent = 0;

void CCustomEventTime::DrawEventTimePanelWindow()
{
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow)
	{
		return;
	}
	if (gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix)
		|| gInterface.CheckWindow(MoveList)
		) //-- 76
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
		return;
	}
	float MainWidth = 400.0;
	float MainHeight = 320.0;
	float StartBody = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY = ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX1 = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float StartX = StartX1 - 5;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	pSetCursorFocus = true;
	#define MoveUp 30

	int CloseX = StartX + MainWidth - 33.0f;
	int CloseY = StartY;
	RenderBitmap(0x1791E, StartX - 10, (StartY - 20) + (MoveUp), 470, 550, 0, 0, 1, 1, 1, 1, 0.0);
	RenderBitmap(0x17921, StartX - 10, (StartY - 25) + (MoveUp), 470, 140, 0, 0, 1, 1, 1, 1, 0.0);
	
	if (pCheckMouseOver(CloseX + 22, (CloseY - 4) + (MoveUp), 23, 23) == 1)
	{
		if (pIsKeyPress(VK_LBUTTON) && GetTickCount() - this->ClickTime > 300)
		{
			if (GetKeyState(1) & 0x8000)
			{
				gCentral.LockMouse = GetTickCount() + 500;
				this->ClickTime = GetTickCount();
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
			}
		}
	}

	DWORD Color = eGray100;
	if (this->EventTimeEnable == 1)
	{
		gInterface.DrawFormat(eGold, StartX + 13,  StartBody + 43 + (MoveUp), 52, 1, gCustomMessage.GetMessage(149));
		gInterface.DrawFormat(eGold, StartX + 100, StartBody + 43 + (MoveUp), 52, 1, gCustomMessage.GetMessage(150));
		gInterface.DrawFormat(eGold, StartX + 180, StartBody + 43 + (MoveUp), 52, 1, gCustomMessage.GetMessage(151));
		gInterface.DrawFormat(eGold, StartX + 300, StartBody + 43 + (MoveUp), 52, 1, gCustomMessage.GetMessage(152));
		gInterface.DrawFormat(eGold, StartX + 350, StartBody + 43 + (MoveUp), 52, 1, gCustomMessage.GetMessage(153));

		if ((GetTickCount() - this->EventTimeTickCount) > 1000)
		{
			for (int i = 0; i < this->count; i++)
			{
				if (this->gCustomEventTime[i].time > 0)
				{
					this->gCustomEventTime[i].time = this->gCustomEventTime[i].time - 1;
				}
			}
			this->EventTimeTickCount = GetTickCount();
		}

		char text1[20];
		char text2[30];
		int totalseconds;
		int hours;
		int minutes;
		int seconds;
		int days;
		int line = 0;

		for (int i = 0; i < 30; i++)
		{
			if (this->gCustomEventTime[i].time <= -1)
			{
				continue;
			}
			else if (this->gCustomEventTime[i].time == 0)
			{
				wsprintf(text2, gConfig.TSPK_TEXT_ENGINE[46]);
			}
			else
			{
				totalseconds = this->gCustomEventTime[i].time;
				hours = totalseconds / 3600;
				minutes = (totalseconds / 60) % 60;
				seconds = totalseconds % 60;
				wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);

				if (hours > 23)
				{
					days = hours / 24;
					wsprintf(text2, "%d day(s)+", days);
				}
				else
				{
					wsprintf(text2, "%02d:%02d:%02d", hours, minutes, seconds);
				}
			}

			if (this->gCustomEventTime[i].time <= -1)
			{
				Color = eRed2;
			}
			else if (this->gCustomEventTime[i].time == 0)
			{
				Color = eExcellent;
			}
			else if (this->gCustomEventTime[i].time < 300)
			{
				Color = eExcellent;
			}
			else
			{
				Color = eYellow;
			}

			gInterface.DrawFormat(eWhite, StartX + 10			, StartBody + MoveUp + 65 + (line), 80, 1, this->m_CustomEventInfo[i].Name);
			gInterface.DrawFormat(eWhite, StartX + 100			, StartBody + MoveUp + 65 + (line), 60, 1, this->m_CustomEventInfo[i].Note);
			gInterface.DrawFormat(eExcellentS15, StartX + 170	, StartBody + MoveUp + 65 + (line), 140, 1, this->m_CustomEventInfo[i].Gift);
			gInterface.DrawFormat(Color, StartX + 300			, StartBody + MoveUp + 65 + (line), 52, 1, text2);

			for (int x = 0; x < MAX_EVENTTIME; x++)
			{
				if (i == x)
				{
					if (this->gCustomEventTime[i].time < 300)
					{ 
						gInterface.DrawGUI(SPK_MOVE_EVENT + x, StartX + 360, StartBody + MoveUp + 64 + (line) );
					} 
				}
			}
			line += 14;
		}
	}
}

void CCustomEventTime::OpenInterFace()
{

	if (gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.CheckWindow(ObjWindow::Store) || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::CashShop))
	{
		return;
	}

	if ((GetTickCount() - gInterface.Data[eEventTimePANEL_MAIN].EventTick) < 500)
	{
		return;
	}

	gInterface.Data[eEventTimePANEL_MAIN].EventTick = GetTickCount();


	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

		if (gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		return;
	}

	gInterface.CloseCustomWindow();
	this->ClearCustomEventTime();
	PMSG_CUSTOM_EVENTTIME_SEND pMsg;
	pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = true;

	if (gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void CCustomEventTime::OpenWindow()
{

	if (gInterface.CheckWindow(ObjWindow::CreateGuild) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::FriendList) || gInterface.CheckWindow(ObjWindow::NPC_Dialog) || gInterface.CheckWindow(ObjWindow::MuHelper) || gInterface.CheckWindow(ObjWindow::Store) || gInterface.CheckWindow(ObjWindow::Warehouse) || gInterface.CheckWindow(ObjWindow::Trade) || gInterface.CheckWindow(ObjWindow::CashShop))
	{
		return;
	}

	if ((GetTickCount() - gInterface.Data[eEventTimePANEL_MAIN].EventTick) < 500)
	{
		return;
	}

	gInterface.Data[eEventTimePANEL_MAIN].EventTick = GetTickCount();


	if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
	{
		gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

		if (gProtect.m_MainInfo.CustomInterfaceType != 4)
		{
			pSetCursorFocus = false;
		}
		return;
	}

	gInterface.CloseCustomWindow();
	this->ClearCustomEventTime();
	PMSG_CUSTOM_EVENTTIME_SEND pMsg;
	pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
	gInterface.Data[eEventTimePANEL_MAIN].OnShow = true;

	if (gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
}

void CCustomEventTime::MOVE_EVENT(int MOVE_EVENT)
{
	MOVE_EVENT_REQ pRequest;
	pRequest.h.set(0xF3, 0x27, sizeof(pRequest));
	pRequest.MOVE_EVENT = MOVE_EVENT;
	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}
bool CCustomEventTime::EventMove(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if (!gInterface.Data[eEventTimePANEL_MAIN].OnShow)
	{
		return false;
	}
	for (int i =  0; i < MAX_EVENTTIME; i++)
	{
		DWORD Delay = (CurrentTick - gInterface.Data[SPK_MOVE_EVENT + i].EventTick);
				
		if (gInterface.IsWorkZone(SPK_MOVE_EVENT + i))
		{
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[SPK_MOVE_EVENT + i].OnClick = true;
				return true;
			}

			gInterface.Data[SPK_MOVE_EVENT + i].OnClick = false;

			if (Delay < 500)
			{
				return false;
			}

			gInterface.CloseMenuWindow();
			gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;

			this->MOVE_EVENT(i + 1);
			gInterface.Data[SPK_MOVE_EVENT + i].EventTick = GetTickCount();
		}				
	}
	return false;
}
