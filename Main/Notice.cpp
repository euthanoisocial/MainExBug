#include "StdAfx.h"
#include "Notice.h"
#include "Tmemory.h"
#include "Defines.h"
#include "Interface.h"
#include "CustomFont.h"
#include "CustomMessage.h"
#include "User.h"
#include "Protect.h"

// -------------------------------------------------------------------------------


CCustomNoticeInfo gCustomNoticeInfo;
// -------------------------------------------------------------------------------

CCustomNoticeInfo::CCustomNoticeInfo()
{
	this->Init();
}
// -------------------------------------------------------------------------------

CCustomNoticeInfo::~CCustomNoticeInfo()
{
	// ----
}
// -------------------------------------------------------------------------------


extern DWORD      Test_Buff;
extern char      Test_LevelBuff[40];

//Naked(NoticesTue)
__declspec(naked) void NoticesTue()
{
	//debug 
	//char IsValue[255];
	//ZeroMemory(IsValue, sizeof(IsValue));
	//wsprintf(IsValue, "gProtect.m_MainInfo.CustomNewsEnable ==  %d", gProtect.m_MainInfo.CustomNewsEnable);
	//pDrawMessage(IsValue, 1);
	//-----------
	gCustomNoticeInfo.OpenNoticeWindow();
	if (gProtect.m_MainInfo.CustomNewsEnable == 1)
	{
		int PosX;
		PosX = 470;

		pDrawGUI(0x9969, (float)455, (float)70 - 47, 173, 407);

		CustomFont.Draw(CustomFont.FontSize20, 480, 50, 0xDAA520FF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameE);
		CustomFont.Draw(CustomFont.FontSize19, PosX, 80, 0x8B0000FF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameF);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 100, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameG);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 115, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameH);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 130, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameI);
		CustomFont.Draw(CustomFont.FontSize19, PosX, 150, 0x8B0000FF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameJ);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 165, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameK);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 180, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameL);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 195, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameM);
		CustomFont.Draw(CustomFont.FontSize19, PosX, 215, 0x8B0000FF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameN);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 230, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameO);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 245, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameP);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 260, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameQ);

		CustomFont.Draw(CustomFont.FontSize19, PosX, 280, 0x8B0000FF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameR);

		CustomFont.Draw(CustomFont.FontSize18, PosX, 295, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameS);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 310, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameT);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 325, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameU);

		CustomFont.Draw(CustomFont.FontSize19, PosX, 345, 0x8B0000FF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameV);

		CustomFont.Draw(CustomFont.FontSize18, PosX, 360, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameW);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 375, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameX);
		CustomFont.Draw(CustomFont.FontSize18, PosX, 390, 0xFFFFFFFF, 0x0, 0, 0, 0, gProtect.m_MainInfo.ServerNameY);



		_asm
		{
			lea eax, Test_LevelBuff
			push eax
			//   // ----
		}
		_asm
		{
			mov Test_Buff, 0x004D7D1D
			jmp Test_Buff
		}
	}
}




//void InitNotices()
void InitNoticesTue()
{

	SetRange((PVOID)0x004D7DAD, 0x0f, ASM::NOP);

	//SetOp((LPVOID)0x004D7D13, (LPVOID)Notices, ASM::JMP);
	SetOp((LPVOID)0x004D7D13, (LPVOID)NoticesTue, ASM::JMP);
}

void CCustomNoticeInfo::Init() // OK
{
	for (int n = 0; n < MAX_CUSTOM_Notice; n++)
	{
		this->m_CustomNoticeInfo[n].Index = -1;
	}
	this->Count = 0;
	this->Page = 0;
}

void CCustomNoticeInfo::Load(CUSTOM_Notice_INFO* info) // OK
{
	for (int n = 0; n < MAX_CUSTOM_Notice; n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomNoticeInfo::SetInfo(CUSTOM_Notice_INFO info) // OK
{
	if (info.Index < 0 || info.Index >= MAX_CUSTOM_Notice)
	{
		return;
	}
	this->Count = info.Index + 1;
	this->m_CustomNoticeInfo[info.Index] = info;
}

CUSTOM_Notice_INFO* CCustomNoticeInfo::GetInfo(int index) // OK
{
	if (index < 0 || index >= MAX_CUSTOM_Notice)
	{
		return 0;
	}

	if (this->m_CustomNoticeInfo[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomNoticeInfo[index];
}


void CCustomNoticeInfo::DrawNoticeWindow()
{
	if (!gInterface.Data[eNotice_MAIN].OnShow)
	{
		return;
	}

	// ----
	float MainWidth = 230.0;
	float MainHeight = 180.0;
	float StartBody = 10.0;
	float StartY = 10.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);
	// ----
	gInterface.DrawGU1(eNotice_MAIN, StartX, StartY + (float)2.0);
	gInterface.DrawGU1(eNotice_TITLE, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(eNotice_FRAME, StartX, StartY + (float)15.0, 16);
	gInterface.DrawGU1(eNotice_FOOTER, StartX, StartY);
	gInterface.DrawGU1(eNotice_CLOSE, StartX + MainWidth - gInterface.Data[eNotice_CLOSE].Width, StartBody);
	// ----
	DWORD Color = eGray100;

	if (gInterface.IsWorkZone(eNotice_CLOSE))
	{

		// ----
		if (gInterface.Data[eNotice_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(eNotice_CLOSE, gInterface.Data[eNotice_CLOSE].X, StartBody, Color);
		gInterface.DrawToolTip((int)gInterface.Data[eNotice_CLOSE].X + 5, StartBody + 25, "Close");
	}
	// ----
	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Notices");

	if ((this->Page == 0 && this->Count > 25) || (this->Page == 1 && this->Count > 50) || (this->Page == 2 && this->Count > 75))
	{
		gInterface.DrawGU1(eNextNotice, StartX + MainWidth - 8, 150);
	}
	else
	{
		gInterface.ResetDrawIMG(eNextNotice);
	}

	if (this->Page == 1 || this->Page == 2 || this->Page == 3)
	{
		gInterface.DrawGU1(ePrevNotice, StartX - 20, 150);
	}
	else
	{
		gInterface.ResetDrawIMG(ePrevNotice);
	}

	for (int i = (25 * Page) + 0; i < (25 * Page) + 25; i++)
	{
		if (this->m_CustomNoticeInfo[i].Index == -1)
		{
			continue;
		}

		if (this->m_CustomNoticeInfo[i].Color == 1)
		{
			Color = eGold;
		}
		else if (this->m_CustomNoticeInfo[i].Color == 2)
		{
			Color = eWhite;
		}
		else if (this->m_CustomNoticeInfo[i].Color == 3)
		{
			Color = eOrange;
		}
		else if (this->m_CustomNoticeInfo[i].Color == 4)
		{
			Color = eRed2;
		}
		else if (this->m_CustomNoticeInfo[i].Color == 5)
		{
			Color = eExcellent;
		}
		else if (this->m_CustomNoticeInfo[i].Color == 6)
		{
			Color = eYellow;
		}
		else if (this->m_CustomNoticeInfo[i].Color == 7)
		{
			Color = eSocket;
		}
		else
		{
			Color = eGold;
		}

		int x = i;

		if (this->Page > 0)
		{
			x = x - (25 * Page);
		}

		gInterface.DrawFormat(Color, (int)StartX + 18, (int)StartBody + 35 + (x * 10), 100, 1, this->m_CustomNoticeInfo[i].Notice);

		//gInterface.DrawFormat(Color, (int)StartX + 112, (int)StartBody + 35 + (i*10), 100, 1, this->m_CustomNoticeInfo[i].Description);
		pDrawColorText(this->m_CustomNoticeInfo[i].Description, (int)StartX + 112, (int)StartBody + 35 + (x * 10), 100, 0, Color, 0, 1);

	}

}

void CCustomNoticeInfo::OpenNoticeWindow()
{

	if (gInterface.Data[eNotice_MAIN].OnShow == true)
	{
		gInterface.Data[eNotice_MAIN].OnShow = false;
		pSetCursorFocus = false;
		return;
	}

	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eRankPANEL_MAIN].EventTick);

	if (Delay < 1500)
	{
		gInterface.Data[eNotice_MAIN].OnShow = false;
		return;
	}

	gInterface.CloseCustomWindow();
	gInterface.Data[eNotice_MAIN].EventTick = GetTickCount();
	gInterface.Data[eNotice_MAIN].OnShow = true;
	pSetCursorFocus = true;

}

bool CCustomNoticeInfo::EventNoticeWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNotice_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eNotice_MAIN].OnShow || !gInterface.IsWorkZone(eNotice_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNotice_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eNotice_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eNotice_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eNotice_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

bool CCustomNoticeInfo::NoticeNext(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eNextNotice].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[ePrevNotice].EventTick);

	if (!gInterface.Data[eNotice_MAIN].OnShow)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(eNextNotice))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eNextNotice].OnClick = true;
		return true;
	}

	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[eNextNotice].OnClick = false;

	this->Page++;

	gInterface.Data[eNextNotice].EventTick = GetTickCount();


	return true;
}

bool CCustomNoticeInfo::NoticePrev(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[ePrevNotice].EventTick);
	DWORD Delay2 = (CurrentTick - gInterface.Data[eNextNotice].EventTick);

	if (!gInterface.Data[eNotice_MAIN].OnShow)
	{
		return false;
	}

	if (!gInterface.IsWorkZone(ePrevNotice))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[ePrevNotice].OnClick = true;
		return true;
	}

	if (Delay < 100 || Delay2 < 100)
	{
		return false;
	}

	gInterface.Data[ePrevNotice].OnClick = false;

	gInterface.Data[ePrevNotice].EventTick = GetTickCount();

	this->Page--;

	return true;
}


