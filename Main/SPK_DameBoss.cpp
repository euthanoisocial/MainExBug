#include "Stdafx.h"
#if BXHDAME
#include "SPK_DameBoss.h"
#include "Interface.h"
#include "Central.h"
#include "CustomFont.h"
#include "Util.h"
#include "HealthBar.h"

#include "Console.h"
#include "User.h"
#include "Config.h"
#include "SPK_ToolKit.h"

SPK_DAMEBOSS_CLASS gDmgBoss;
 
void SPK_DAMEBOSS_CLASS::DAMECLEAR()
{
	for (int n = 0; n < 10; n++)
	{
		memset(gDmgBoss[n].szName, 0, sizeof(gDmgBoss[n].szName));
		gDmgBoss[n].Kill = 0;
	}
	this->CalcString;
}
void SPK_DAMEBOSS_CLASS::Initz()
{
	this->guiX = MAX_WIN_WIDTH - 150;
	this->guiY = 10;
	this->curX = pCursorX;
	this->curY = pCursorY;
	this->dragging = false;
}
void SPK_DAMEBOSS_CLASS::DAMEGETINFO(PMSG_NEW_HEALTH_BAR_RECV* lpMsg)
{
	CalcString = 0;
	this->SPK_DAMEBOSS_ID = 0;
	this->MaxLife = 0;
	this->MinLife = 0;
	this->Level = 0;
	for (int n = 0; n < 10; n++)
	{
		memset(gDmgBoss[n].szName, 0, sizeof(gDmgBoss[n].szName));
		gDmgBoss[n].Kill = 0;
	}

	for (int n = 0; n < lpMsg->count; n++)
	{
		SPK_DAMEBOSS_STR* lpInfo = (SPK_DAMEBOSS_STR*)(((BYTE*)lpMsg) + sizeof(PMSG_NEW_HEALTH_BAR_RECV) + (sizeof(SPK_DAMEBOSS_STR) * n));
		memcpy(gDmgBoss[n].szName, lpInfo->szName, sizeof(gDmgBoss[n].szName));
		gDmgBoss[n].Kill = lpInfo->Kill;
		CalcString++;
		SPK_DAMEBOSS_ID = lpInfo->monsterid;
		MaxLife			= lpInfo ->MaxLife;
		Level			= lpInfo->Level;
		MinLife			= lpInfo->MinLife;
		if (CalcString > 10)
		{
			break;
		}
	}
}

void SPK_DAMEBOSS_CLASS::DAMEDRAW()
{
	if (!gInterface.Data[eTopDame].OnShow)
	{
		return;
	}
	unsigned long ADD_ANTOAN = *(unsigned long*)(0x07BC4F04);
	if (ADD_ANTOAN)
	{
		this->ADD_OFF_ANTOAN = *(DWORD*)(ADD_ANTOAN + 0x0E);
		if (ADD_OFF_ANTOAN == 0)
		{
			this->CheckDrawBxhDame = 1;
			if ((gInterface.CheckWindow(ObjWindow::CashShop) || gInterface.CheckWindow(ObjWindow::FullMap) || gInterface.CheckWindow(ObjWindow::ChatWindow) || gInterface.CheckWindow(ObjWindow::Inventory) || gInterface.CheckWindow(ObjWindow::SkillTree)
				|| gInterface.CheckWindow(ObjWindow::MoveList)))
			{
				return;
			}

			float ScaleWidth = 150;
			float ScaleHeight = 80 + (CalcString * 10);

			if (GetKeyState(VK_RBUTTON) & 0x8000 && GetTickCount() > this->ActionTime + 1000)
			{
				if (gInterface.IsWorkZone1(this->guiX, this->guiY, ScaleWidth, ScaleHeight))
				{
					if (!this->dragging)
					{
						this->dragging = true;
						this->curX = pCursorX;
						this->curY = pCursorY;
					}
				}
				if (this->dragging)
				{
					this->guiX += pCursorX - this->curX;
					this->guiY += pCursorY - this->curY;
					this->curX = pCursorX;
					this->curY = pCursorY;
				}
			}
			else
			{
				if (this->dragging)
				{
					this->dragging = false;
				}
			}

			if (this->guiX < 0)
				this->guiX = 0;
			if (this->guiY < 20)
				this->guiY = 20;

			if (this->guiX > 640 - ScaleWidth)
				this->guiX = 640 - ScaleWidth;
			if (this->guiY > 480 - ScaleHeight - 51)
				this->guiY = 480 - ScaleHeight - 51;

			float X = this->guiX;
			float Y = this->guiY;

			gCentral.gInfoBox(X, Y, ScaleWidth - 25, ScaleHeight - 35, 0x00000096, 0, 0);
			CustomFont.Draw(CustomFont.FontBold, X - 10, Y + 7, 0xE6FCF7FF, 0x0, ScaleWidth, 0, 3, gConfig.TSPK_TEXT_ENGINE[217], pGetMonsterName(this->SPK_DAMEBOSS_ID), this->Level);
			gInterface.SPKText(eRed2, X - 10, Y + 22, ScaleWidth , 3, "HP: %s", FormatNumber(this->MaxLife).c_str());
			Y += 30;
			CustomFont.Draw(CustomFont.FontBold, X + 5, Y + 5, 0xFABB00FF, 0x0, ScaleWidth / 2, 0, 1, "Name");
			CustomFont.Draw(CustomFont.FontBold, X + ScaleWidth / 2 - 25, Y + 5, 0xFABB00FF, 0x0, ScaleWidth / 2, 0, 4, gConfig.TSPK_TEXT_ENGINE[218]);
			DWORD ColorTextRank = 0xE0DFDCFF;
			for (int i = 0; i < CalcString; i++)
			{
				if (i % 2)
				{
					ColorTextRank = 0xA3A3A3FF;
				}
				else 
				{
					ColorTextRank = 0xE0DFDCFF;
				}
				if (i < 3) { ColorTextRank = 0xFFE240FF; }
				CustomFont.Draw(CustomFont.FontBold, X + 5, Y + (15) + (i * 10), ColorTextRank, (i < 3) ? 0x0 : 0x0, ScaleWidth / 2, 0, 1, "%d - %s", i + 1, gDmgBoss[i].szName);
				CustomFont.Draw(CustomFont.FontBold, X + ScaleWidth / 2 - 25, Y + (15) + (i * 10), ColorTextRank, (i < 3) ? 0x0 : 0x0, ScaleWidth / 2, 0, 4, "%s", gToolKit.QNumberFormat(gDmgBoss[i].Kill));
			}
		}
		else
		{
			gInterface.Data[eTopDame].OnShow = false;
			this->CheckDrawBxhDame = 0;
		}
	}	
}

#endif