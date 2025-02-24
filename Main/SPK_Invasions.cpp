#include "stdafx.h"
#include "SPK_Invasions.h"
#include "Interface.h"
#include "Defines.h"
#include "Extras.h"
#include <fstream>
#include <string>
#include "Console.h"
#include "Central.h"
#include "SItemOption.h"
#include "CustomFont.h"
#include "SPK_DameBoss.h"
#include "UIControl.h"
#include "Config.h"

CActiveInvasions gActiveInvasions;

CActiveInvasions::CActiveInvasions()
{
	this->m_data.clear();
}

void CActiveInvasions::list_recv(PMSG_ACTIVE_INVASIONS_RECV* lpMsg)
{
	this->m_data.clear();
	for (int n = 0; n < lpMsg->count; n++)
	{
		auto info = reinterpret_cast<PMSG_ACTIVE_INVASIONS*>(reinterpret_cast<BYTE*>(lpMsg) + sizeof(PMSG_ACTIVE_INVASIONS_RECV) + (sizeof(PMSG_ACTIVE_INVASIONS) * n));

		if (info->count._count == 0 && info->count._max_count == 0)
		{
			continue;
		}
		ACTIVE_INVASIONS data;
		data.monster_id = info->monster_id;
		data.count = info->count;

		this->m_data.push_back(data);
	}
	gInterface.Data[eInvasionInfo].OnShow ^= 1;
}

void CActiveInvasions::update_monster_recv(PMSG_INVASION_MONSTER_UPDATE_RECV* lpMsg)
{
	for (auto it = this->m_data.begin(); it != this->m_data.end();)
	{
		if (it->monster_id == lpMsg->monster_id)
		{
			it->count._count = lpMsg->count;
			if (it->count._count == 0 && it->count._max_count == 0)
			{
				it = this->m_data.erase(it);
			}
			break;
		}
		++it;
	}
}
void CActiveInvasions::render()
{
	if (gInterface.CheckWindow(ChatWindow) || gInterface.CheckWindow(FullMap) || gInterface.CheckWindow(SkillTree) || gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(Inventory)
		|| gInterface.CheckWindow(Character) || gInterface.CheckWindow(Quest) || gInterface.CheckWindow(Party) || gInterface.CheckWindow(MuHelper) || gInterface.CheckWindow(Guild) || gInterface.CheckWindow(FriendList))
	{
		gInterface.Data[eInvasionInfo].OnShow = false;
	}
	if (!gInterface.Data[eInvasionInfo].OnShow)
	{
		return;
	}
	
	float MainWidth = 120.0;
	float MainHeight = 14 + (this->m_data.size() * 12);
	float StartY = 10;
	float StartX1 = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float StartX;

	char IsBossName[255], IsBossCount[255];
	ZeroMemory(IsBossName, sizeof(IsBossName));
	ZeroMemory(IsBossCount, sizeof(IsBossCount));
	if (gDmgBoss.CheckDrawBxhDame == 1)
	{
		StartX = MAX_WIN_WIDTH - 310;
	}
	else
	{
		StartX = MAX_WIN_WIDTH - 175;
	}
	
	if (this->m_data.size() == NULL)
	{
		gCentral.gInfoBox(StartX, StartY, MainWidth + 30, MainHeight, 0x00000096, 0, 0);
		CustomFont.Draw((HFONT)pFontNormal, StartX + 5, StartY + 7, 0xF0FA0AFF, 0x0, 150, 0, 3, gConfig.TSPK_TEXT_ENGINE[13]);
	}
	else
	{
		gCentral.gInfoBox(StartX, StartY, MainWidth + 30, MainHeight - 17, 0x00000096, 0, 0);
		for (int i = 0; i < this->m_data.size(); i++)
		{
			char* name = CCustomMonster::GetNameMonter(this->m_data[i].monster_id);
			wsprintf(IsBossName, "%d. %s :", i + 1, name);
			wsprintf(IsBossCount, "%d/%d", this->m_data[i].count);
			pSetBackgroundTextColor(pTextThis(), 255, 255, 255, 0);
			pSetTextColor(pTextThis(), 0xFAu, 0xC8u, 0x32u, 0xFFu);
			g_pRenderText.CRenderText(StartX + 10, StartY + 4 + (i * 12), IsBossName , 150, 0, 1, 0);
			g_pRenderText.CRenderText(StartX     , StartY + 4 + (i * 12), IsBossCount, 150, 0, 4, 0);
		}
	}
}


