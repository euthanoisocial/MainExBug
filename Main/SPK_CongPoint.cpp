#include "stdafx.h"
#if(ADD_POINT)
#include "Interface.h"
#include "SPK_CongPoint.h"
#include "User.h"
#include "Defines.h"
#include "PrintPlayer.h"
#include "SPK_ChangePass.h"
#include "Config.h"
#include "Central.h"
#include "SPK_ToolKit.h"
#include "UIControl.h"

SPKAddPoint gAddPoint;

void SPKAddPoint::BingObjectRenderAddPoint()
{
	gInterface.BindObject(eSTATSADD_MAIN,			0x7A5A, 222, 226, -1, -1);
	gInterface.BindObject(eSTATSADD_TITLE,			0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eSTATSADD_FRAME,			0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eSTATSADD_FOOTER,			0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eSTATSADD_CLOSE,			0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eSTATSADD_TEXTBOX01,		0x9307, 170, 21, -1, -1);
	gInterface.BindObject(eSTATSADD_STATBOX01,		0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eSTATSADD_STATBOX02,		0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eSTATSADD_STATBOX03,		0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eSTATSADD_STATBOX04,		0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eSTATSADD_STATBOX05,		0x7AA3, 170, 21, -1, -1);
	gInterface.BindObject(eSTATSADD_BTN_OK,			0x7A5B, 54, 30, -1, -1);
	gInterface.BindObject(eRESETSTATS_MAIN,			0x7A5A, 222, 140, -1, -1);
	gInterface.BindObject(eRESETSTATS_TITLE,		0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eRESETSTATS_FRAME,		0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eRESETSTATS_FOOTER,		0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eRESETSTATS_CLOSE,		0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(eRESETSTATS_POINT,		0x7B68, 10, 10, -1, -1);
	gInterface.BindObject(eRESETSTATS_BTN_OK,		0x7A5B, 54, 30, -1, -1);
	gInterface.BindObject(eCHARINFO_BTN_STAT,		0x7AA4, 16, 15, 475, 73);
	gInterface.BindObject(eCHARINFO_BTN_RESSTAT,	0x7AA4, 16, 15, 475, 94);
	gInterface.BindObject(eCHARINFO_BTN_FAKE,		0x7AA3, 170, 21, -1, -1);

}

void SPKAddPoint::GetFormat(char* str, char oldval, char newval)
{
	std::string Buff;
	Buff = str;
	std::replace(Buff.begin(), Buff.end(), oldval, newval);
	memcpy(str, Buff.c_str(), Buff.size());
}

void SPKAddPoint::DrawColoredAnimatedGUI(short ObjectID, float X, float Y, DWORD Color)
{
	gInterface.Data[ObjectID].X = X;
	gInterface.Data[ObjectID].Y = Y;
	gInterface.Data[ObjectID].MaxX = X + gInterface.Data[ObjectID].Width;
	gInterface.Data[ObjectID].MaxY = Y + gInterface.Data[ObjectID].Height;
	pDrawColorButton(gInterface.Data[ObjectID].ModelID, X, Y,
	gInterface.Data[ObjectID].Width, gInterface.Data[ObjectID].Height, 0, 0, Color);
}

void SPKAddPoint::DrawAnimatedButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	gInterface.Data[ObjectID].X = PosX;
	gInterface.Data[ObjectID].Y = PosY;
	gInterface.Data[ObjectID].MaxX = PosX + gInterface.Data[ObjectID].Width;
	gInterface.Data[ObjectID].MaxY = PosY + gInterface.Data[ObjectID].Height;
	pDrawButton(gInterface.Data[ObjectID].ModelID, PosX, PosY,
	gInterface.Data[ObjectID].Width, gInterface.Data[ObjectID].Height, ScaleX, ScaleY);
}

void SPKAddPoint::DrawStatsAddWindow()
{
	if (!gInterface.Data[eSTATSADD_MAIN].OnShow)
	{
		return;
	}
	if (gInterface.CheckWindow(ChatWindow))
	{
		this->CloseStatsAddWindow();
		return;
	}
	int ObjectCount = 4;
	if ((gObjUser.lpPlayer->Class & 7) == 4)
	{
		ObjectCount = 5;
	}
	char szCharNames[5][32];
	memcpy(szCharNames[0],gConfig.TSPK_TEXT_ENGINE[270],	sizeof(szCharNames[0]));
	memcpy(szCharNames[1],gConfig.TSPK_TEXT_ENGINE[271],	sizeof(szCharNames[1]));
	memcpy(szCharNames[2],gConfig.TSPK_TEXT_ENGINE[272],	sizeof(szCharNames[2]));
	memcpy(szCharNames[3],gConfig.TSPK_TEXT_ENGINE[273],	sizeof(szCharNames[3]));
	memcpy(szCharNames[4],gConfig.TSPK_TEXT_ENGINE[274],	sizeof(szCharNames[4]));
	int ObjectIDs[5] =
	{
		eSTATSADD_STATBOX01,
		eSTATSADD_STATBOX02,
		eSTATSADD_STATBOX03,
		eSTATSADD_STATBOX04,
		eSTATSADD_STATBOX05,
	};

	if (gInterface.Data[eSTATSADD_MAIN].ByClose == false)
	{
		if (gInterface.Data[eSTATSADD_MAIN].OpenedValue < 0)
		{
			gInterface.Data[eSTATSADD_MAIN].OpenedValue += gInterface.Data[eSTATSADD_MAIN].Speed;

			if (gInterface.Data[eSTATSADD_MAIN].OpenedValue >= -150)
			{
				gInterface.Data[eSTATSADD_MAIN].Speed = 15;
			}

			if (gInterface.Data[eSTATSADD_MAIN].OpenedValue > 0)
			{
				gInterface.Data[eSTATSADD_MAIN].OpenedValue = 0;
			}
		}
	}
	else
	{
		if (gInterface.Data[eSTATSADD_MAIN].OpenedValue > -226)
		{
			gInterface.Data[eSTATSADD_MAIN].OpenedValue -= gInterface.Data[eSTATSADD_MAIN].Speed;

			if (gInterface.Data[eSTATSADD_MAIN].OpenedValue <= -150)
			{
				gInterface.Data[eSTATSADD_MAIN].Speed = 20;
			}

			if (gInterface.Data[eSTATSADD_MAIN].OpenedValue <= -226)
			{
				gInterface.Data[eSTATSADD_MAIN].Close();
				for (int i = 0; i < ObjectCount; i++)
				{
					gInterface.Data[ObjectIDs[i]].Attribute = false;
				}
			}
		}
	}

	float MainWidth = 230.0;
	float StartY = 198;
	float StartX = gInterface.Data[eSTATSADD_MAIN].OpenedValue;
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	pSetCursorFocus = true;
	gInterface.DrawAnimatedGUI(eSTATSADD_MAIN, StartX, StartY + 2);
	gInterface.DrawAnimatedGUI(eSTATSADD_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(eSTATSADD_FRAME, StartX, StartY + 67.0, 8);
	gInterface.DrawAnimatedGUI(eSTATSADD_FOOTER, StartX, StartY);
	gInterface.DrawAnimatedGUI(eSTATSADD_CLOSE, StartX + MainWidth - gInterface.Data[eSTATSADD_CLOSE].Width, gInterface.Data[eSTATSADD_MAIN].Y - 2);
	if (gInterface.IsWorkZone(eSTATSADD_CLOSE))
	{
		DWORD Color = eGray100;
		if (gInterface.Data[eSTATSADD_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		gInterface.DrawColoredGUI(eSTATSADD_CLOSE, gInterface.Data[eSTATSADD_CLOSE].X, gInterface.Data[eSTATSADD_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[eSTATSADD_CLOSE].X + 5, gInterface.Data[eSTATSADD_CLOSE].Y + 25, gConfig.TSPK_TEXT_ENGINE[26]);
	}
	this->StatPoints = ViewPoint;

	for (int i = 0; i < ObjectCount; i++)
	{
		this->StatPoints -= atoi(gInterface.Data[ObjectIDs[i]].StatValue);
	}
	gInterface.DrawFormat(eGold, StartX + 10, gInterface.Data[eSTATSADD_MAIN].Y + 8, 210, 3, gConfig.TSPK_TEXT_ENGINE[275]);

	gCentral.gInfoBox(ButtonX - 45, gInterface.Data[eSTATSADD_MAIN].Y + 30, 180, 10, 0x00000096, 0, 0);
	gInterface.DrawFormat(eExcellent, StartX - 40, gInterface.Data[eSTATSADD_MAIN].Y + 34, 210, 3, gConfig.TSPK_TEXT_ENGINE[276]);

	gToolKit.CRenderNumberExNew(StartX + 200, gInterface.Data[eSTATSADD_MAIN].Y + 33, this->StatPoints, 4, 0.88);
	gInterface.DrawFormat(eWhite, StartX + 10, gInterface.Data[eSTATSADD_MAIN].Y + 65, 210, 3, gConfig.TSPK_TEXT_ENGINE[277]);

	if (gInterface.Data[eSTATSADD_MAIN].FirstLoad == true)
	{
		gInterface.Data[eSTATSADD_STATBOX01].Attribute = 1;
	}

	for (int i = 0; i < ObjectCount; i++)
	{
		if (gInterface.Data[eSTATSADD_MAIN].FirstLoad == true)
		{
			sprintf(gInterface.Data[ObjectIDs[i]].StatValue, "0");
		}
		double statValue = atof(gInterface.Data[ObjectIDs[i]].StatValue);

		gInterface.DrawAnimatedGUI(ObjectIDs[i], ButtonX - 35, gInterface.Data[eSTATSADD_MAIN].Y + 63 + ((i + 1) * 21));
		gInterface.DrawFormat(eWhite, StartX - 38, gInterface.Data[eSTATSADD_MAIN].Y + 69 + ((i + 1) * 21), 210, 3, szCharNames[i]);
		gToolKit.CRenderNumberExNew(StartX + 200, gInterface.Data[eSTATSADD_MAIN].Y + 69 + ((i + 1) * 21), statValue, 4, 0.88);
	}

	for (int i = 0; i < ObjectCount; i++)
	{
		if (gInterface.Data[ObjectIDs[i]].Attribute == 1)
		{
			DWORD Color = eGray100;
			this->DrawColoredAnimatedGUI(ObjectIDs[i], ButtonX - 35, gInterface.Data[eSTATSADD_MAIN].Y + 63 + ((i + 1) * 21), Color);
		}
	}

	this->DrawAnimatedButton(eSTATSADD_BTN_OK, StartX + 85, gInterface.Data[eSTATSADD_MAIN].Y + 194, 0, 0);

	if (gInterface.IsWorkZone(eSTATSADD_BTN_OK))
	{
		int ScaleY = 30;
		if (gInterface.Data[eSTATSADD_BTN_OK].OnClick)
		{
			ScaleY = 60;
		}
		this->DrawAnimatedButton(eSTATSADD_BTN_OK, StartX + 85, gInterface.Data[eSTATSADD_MAIN].Y + 194, 0, ScaleY);
	}

	if (gInterface.Data[eSTATSADD_MAIN].FirstLoad == true)
	{
		gInterface.Data[eSTATSADD_MAIN].FirstLoad = false;
	}
}
// ----------------------------------------------------------------------------------------------

void SPKAddPoint::EventStatsAddWindow(DWORD Event)
{
	this->EventStatsAddWindow_Close(Event);
}

void SPKAddPoint::EventStatsAddWindow_Close(DWORD Event)
{
	if (!gInterface.Data[eSTATSADD_MAIN].OnShow)
	{
		return;
	}

	DWORD CurrentTick = GetTickCount();

	int ObjectIDs[5] =
	{
		eSTATSADD_STATBOX01,
		eSTATSADD_STATBOX02,
		eSTATSADD_STATBOX03,
		eSTATSADD_STATBOX04,
		eSTATSADD_STATBOX05,
	};

	int ObjectCount = 4;
	if ((gObjUser.lpPlayer->Class & 7) == 4)
	{
		ObjectCount = 5;
	}

	for (int i = 0; i < ObjectCount; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			if (Delay < 500)
			{
				return;
			}
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 0; j < ObjectCount; j++)
			{
				gInterface.Data[ObjectIDs[j]].Attribute = 0;
			}

			gInterface.Data[ObjectIDs[i]].Attribute = 1;
		}
	}

	for (int i = 5; i < 5; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]))
		{
			DWORD Delay = (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);
			if (Event == WM_LBUTTONDOWN)
			{
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return;
			}
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			if (Delay < 500)
			{
				return;
			}
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();

			for (int j = 5; j < 8; j++)
			{
				gInterface.Data[ObjectIDs[j]].Attribute = 0;
			}

			gInterface.Data[ObjectIDs[i]].Attribute = 1;
		}
	}

	if (gInterface.IsWorkZone(eSTATSADD_BTN_OK))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eSTATSADD_BTN_OK].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSTATSADD_BTN_OK].OnClick = true;
			return;
		}
		gInterface.Data[eSTATSADD_BTN_OK].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eSTATSADD_BTN_OK].EventTick = GetTickCount();
		gInterface.Data[eSTATSADD_MAIN].CloseAnimated(15);
		PMSG_UPDATE_STATS_SEND pMsg;
		pMsg.Str = atoi(gInterface.Data[eSTATSADD_STATBOX01].StatValue);
		pMsg.Agi = atoi(gInterface.Data[eSTATSADD_STATBOX02].StatValue);
		pMsg.Vit = atoi(gInterface.Data[eSTATSADD_STATBOX03].StatValue);
		pMsg.Ene = atoi(gInterface.Data[eSTATSADD_STATBOX04].StatValue);
		pMsg.Com = 0;
		if (ObjectCount == 5)
		{
			pMsg.Com = atoi(gInterface.Data[eSTATSADD_STATBOX05].StatValue);
		}
		this->CGSendStatsAdd(pMsg);
	}

	if (gInterface.IsWorkZone(eSTATSADD_CLOSE))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eSTATSADD_CLOSE].EventTick);
		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eSTATSADD_CLOSE].OnClick = true;
			return;
		}
		gInterface.Data[eSTATSADD_CLOSE].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eSTATSADD_CLOSE].EventTick = GetTickCount();
		gInterface.Data[eSTATSADD_MAIN].CloseAnimated(15);
	}
	return;
}
void SekcPacketPointAdd(DWORD CurrentTick, DWORD Event, int eNum, int Packet)
{
	DWORD Delay = (CurrentTick - gInterface.Data[eNum].EventTick);

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNum].OnClick = true;
		return;
	}
	gInterface.Data[eNum].OnClick = false;
	if (Delay < 500)
	{
		return;
	}
	gInterface.Data[eNum].EventTick = GetTickCount();
	PMSG_TICKET_SEND pMsg;
	pMsg.header.set(0xFC, Packet, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}
void SPKAddPoint::EventCharacterWindow(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if (!gInterface.CheckWindow(Character))
	{
		return;
	}
	if (gInterface.IsWorkZone(eCHARINFO_BTN_STAT))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eCHARINFO_BTN_STAT].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			gInterface.Data[eCHARINFO_BTN_STAT].OnClick = true;
			return;
		}
		gInterface.Data[eCHARINFO_BTN_STAT].OnClick = false;
		if (Delay < 500)
		{
			return;
		}
		gInterface.Data[eCHARINFO_BTN_STAT].EventTick = GetTickCount();

		if (ViewPoint != 0)
		{
			this->SwitchStatsWindowState();
		}
		else
		{
			pDrawMessage("Bạn không đủ Point dư để cộng.", 1);
		}
	}

	if (gInterface.IsWorkZone(eCHARINFO_BTN_RESSTAT))
	{
		SekcPacketPointAdd(CurrentTick, Event, eCHARINFO_BTN_RESSTAT, 101);
	}
}


void SPKAddPoint::EventResetStatsWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eRESETSTATS_CLOSE].EventTick);
	if (!gInterface.Data[eRESETSTATS_MAIN].OnShow || !gInterface.IsWorkZone(eRESETSTATS_CLOSE))
	{
		return;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eRESETSTATS_CLOSE].OnClick = true;
		return;
	}
	gInterface.Data[eRESETSTATS_CLOSE].OnClick = false;
	if (Delay < 500)
	{
		return;
	}
	gInterface.Data[eRESETSTATS_CLOSE].EventTick = GetTickCount();
	this->SwitchResetStatsWindowState();
}

void SPKAddPoint::CGSendStatsAdd(PMSG_UPDATE_STATS_SEND pMsg)
{
	pMsg.header.set(0xFF, 0x0C, sizeof(pMsg));
	DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void SPKAddPoint::ExtraCpanelGetInfo(EXTRA_CPANEL_SENDINFO* lpMsg)
{
	this->m_QuickAdd	= lpMsg->QuickAdd;
	this->m_ResetStats	= lpMsg->ResetStat;

	this->d_Strength	= lpMsg->dStrength;
	this->d_Dexterity	= lpMsg->dDexterity;
	this->d_Vitality	= lpMsg->dVitality;
	this->d_Energy		= lpMsg->dEnergy;
	this->d_Leadership	= lpMsg->dLeadership;

	for (int i = 0; i < MAX_ACCOUNT_LEVEL; i++)
	{
		this->m_MaxStatPoint[i]	= lpMsg->MaxStatPoint[i];
	}
}
#include "CustomFont.h"
void SPKAddPoint::ChangeCharInfo(LPVOID This)
{
	if (!gInterface.CheckWindow(Character))
	{
		return;
	}

	gInterface.DrawFormat(eGold, 470, 56, 100, 1, gConfig.TSPK_TEXT_ENGINE[283], gObjUser.lpPlayer->Level, ViewReset);
	if (ViewPoint > 0)
	{
		if (gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			CustomFont.Draw((HFONT)pFontBold, gInterface.Data[eCHARINFO_BTN_STAT].X + 80, 56, 0x000000FF, 0x0080FFFF, 70, 0, 3, "Điểm: %s", gToolKit.QNumberFormat(ViewPoint));
		}
		else
		{
			gInterface.SPKText(eYelloCam, gInterface.Data[eCHARINFO_BTN_STAT].X + 90, 56, 50, 4, "Điểm: %d", ViewPoint);
		}
	}
	if (gAddPoint.m_QuickAdd == 1)
	{
		gInterface.DrawButton(eCHARINFO_BTN_STAT, 473, 73, 0, 0);
		gInterface.SPKText(eAncient,492, 76, 100, 1, "Cộng điểm nhanh");
		//gToolKit.MakeShadowText(492, 76, 100, 1, gConfig.TSPK_TEXT_ENGINE[284]);
		if (gInterface.IsWorkZone(eCHARINFO_BTN_STAT))
		{
			if (gInterface.Data[eCHARINFO_BTN_STAT].OnClick)
			{
				gInterface.DrawButton(eCHARINFO_BTN_STAT, 473, 73, 0, 14);
			}
		}
	}
	
	if (gAddPoint.m_ResetStats == 1)
	{
		gInterface.DrawButton(eCHARINFO_BTN_RESSTAT, 473, 94, 0, 0);
		gInterface.SPKText(eOrange,492, 97, 100, 1, "Tẩy Điểm Point");
		//gToolKit.MakeShadowText(492, 97, 100, 1, gConfig.TSPK_TEXT_ENGINE[285]);

		if (gInterface.IsWorkZone(eCHARINFO_BTN_RESSTAT))
		{
			if (gInterface.Data[eCHARINFO_BTN_RESSTAT].OnClick)
			{
				gInterface.DrawButton(eCHARINFO_BTN_RESSTAT, 473, 94, 0, 14);
			}
		}
	}
	else
	{
		((BOOL(__thiscall*)(LPVOID This))0x0077FAE0)(This);
	}	
}

int SPKAddPoint::GetMaxStatPoint(int AccountLevel)
{
	return this->m_MaxStatPoint[AccountLevel];
}
bool SPKAddPoint::ControlTextBox(DWORD Event)
{
	if (gInterface.Data[eSTATSADD_MAIN].OnShow)
	{
		char Value[20];
		int IsBackspace = false;
		int IsDelete = false;
		int IsTab = false;

		int ObjectCount = 4;

		if ((gObjUser.lpPlayer->Class & 7) == 4)
		{
			ObjectCount = 5;
		}

		int SelectedIndex = 0;

		if (Event == VK_BACK)
		{
			IsBackspace = true;
		}
		else if (Event == VK_DELETE)
		{
			IsDelete = true;
		}
		else if (Event == VK_TAB)
		{
			IsTab = true;
		}
		else if ((Event >= 0x30 && Event <= 0x39) || (Event >= 0x60 && Event <= 0x69))
		{
			int Symbol = GetSymbolFromVK(Event);
			if (Symbol == 0)
			{
				return true;
			}
			char buff[10];
			sprintf(buff, "%c", Symbol);
			strcpy_s(Value, buff);
		}
		else
		{
			return true;
		}
		int ObjectIDs[5] =
		{
			eSTATSADD_STATBOX01,
			eSTATSADD_STATBOX02,
			eSTATSADD_STATBOX03,
			eSTATSADD_STATBOX04,
			eSTATSADD_STATBOX05,
		};

		for (int i = 0; i < ObjectCount; i++)
		{
			if (gInterface.Data[ObjectIDs[i]].Attribute == 1)
			{
				SelectedIndex = i;
				if (IsBackspace == true)
				{
					gInterface.Data[ObjectIDs[i]].StatValue[strlen(gInterface.Data[ObjectIDs[i]].StatValue) - 1] = '\0';

					if (strlen(gInterface.Data[ObjectIDs[i]].StatValue) == 0)
					{
						strcpy_s(gInterface.Data[ObjectIDs[i]].StatValue, "0");
					}
					break;
				}
				else if (IsDelete == true)
				{
					strcpy_s(gInterface.Data[ObjectIDs[i]].StatValue, "0");
				}
				else if (IsTab == true)
				{
					gInterface.Data[ObjectIDs[i]].Attribute = 0;

					if (i == ObjectCount - 1)
					{
						gInterface.Data[ObjectIDs[0]].Attribute = 1;
					}
					else
					{
						gInterface.Data[ObjectIDs[i + 1]].Attribute = 1;
					}
					break;
				}
				else
				{
					if (strlen(gInterface.Data[ObjectIDs[i]].StatValue) < 8)
					{
						if (!strcmp(gInterface.Data[ObjectIDs[i]].StatValue, "0"))
						{
							strcpy_s(gInterface.Data[ObjectIDs[i]].StatValue, Value);
						}
						else
						{
							strcat_s(gInterface.Data[ObjectIDs[i]].StatValue, Value);
						}
					}
				}
			}
		}

		int StatPoints = 0;

		for (int i = 0; i < ObjectCount; i++)
		{
			if (i == SelectedIndex)
			{
				continue;
			}
			StatPoints += atoi(gInterface.Data[ObjectIDs[i]].StatValue);
		}

		if (StatPoints + atoi(gInterface.Data[ObjectIDs[SelectedIndex]].StatValue) > ViewPoint)
		{
			char buff[20];
			sprintf(buff, "%d", ViewPoint - StatPoints);
			strcpy_s(gInterface.Data[ObjectIDs[SelectedIndex]].StatValue, buff);
		}

		if (atoi(gInterface.Data[ObjectIDs[SelectedIndex]].StatValue) > this->GetMaxStatPoint(ViewAccountLevel))
		{
			char buff[20];
			sprintf(buff, "%d", this->GetMaxStatPoint(ViewAccountLevel) - 30);
			strcpy_s(gInterface.Data[ObjectIDs[SelectedIndex]].StatValue, buff);
		}
	}
	return false;
}
#endif