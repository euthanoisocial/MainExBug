#include "stdafx.h"
#include "Import.h"
#include "SPK_FixSolution.h"

SuaLoiKhungHinh gFixSolution;
//float BODY_01 = GetPrivateProfileIntA("TEST", "BODY_01", 0, "./Settings.ini");

void SuaLoiKhungHinh::StartLoadZoomPos()
{
	this->gZoomCurrent = (*(float*)(0x00D27BFC));
	if (this->gZoomCurrent <= 5)
	{
		this->DH_PosY = 800.0f;
		this->QH_PosY = 800.0f;
		this->VIP_PosY = 800.0f;
	}
	else if (this->gZoomCurrent <= 11)
	{
		this->DH_PosY = 23.0f;
		this->QH_PosY = 25.0f;
		this->VIP_PosY = 45.0f;
	}
	else if (this->gZoomCurrent <= 15)
	{
		this->DH_PosY = 47.0f;
		this->QH_PosY = 48.0f;
		this->VIP_PosY = 65.0f;
	}
	else if (this->gZoomCurrent <= 19)
	{
		this->DH_PosY = 57.0f;
		this->QH_PosY = 55.0f;
		this->VIP_PosY = 75.0f;
	}
	else if (this->gZoomCurrent <= 23)
	{
		this->DH_PosY = 66.0f;
		this->QH_PosY = 70.0f;
		this->VIP_PosY = 90.0f;
	}
	else if (this->gZoomCurrent <= 27)
	{
		this->DH_PosY = 76.0f;
		this->QH_PosY = 78.0f;
		this->VIP_PosY = 95.0f;
	}
	else if (this->gZoomCurrent <= 31)
	{
		this->DH_PosY = 84.0f;
		this->QH_PosY = 86.0f;
	}
	else if (this->gZoomCurrent <= 35)
	{
		this->DH_PosY = 85.0f;
		this->QH_PosY = 88.0f;
		this->VIP_PosY = 105.0f;
	}
	else if (this->gZoomCurrent <= 39)
	{
		this->DH_PosY = 89.0f;
		this->QH_PosY = 92.0f;
		this->VIP_PosY = 115.0f;
	}
	else if (this->gZoomCurrent <= 43)
	{
		this->DH_PosY = 91.0f;
	}
	else if (this->gZoomCurrent <= 47)
	{
		this->DH_PosY = 93.0f;
	}
	else if (this->gZoomCurrent <= 55)
	{
		this->DH_PosY = 95.0f;
		this->QH_PosY = 95.0f;
	}
	else if (this->gZoomCurrent <= 63)
	{
		this->DH_PosY = 96.0f;
	}
	else if (this->gZoomCurrent <= 99)
	{
		this->DH_PosY = 100.0f;
		this->QH_PosY = 100.0f;
	}
}
void SuaLoiKhungHinh::StartLoadPos()
{
	if (pWinWidth == 640)
	{
		this->SD_PosY = 4.0f;
		this->BP_PosY = 4.0f;
		this->DotStatus = 79.0f;
	}
	else if (pWinWidth == 800)
	{
		this->SD_PosY = 5.0f;
		this->BP_PosY = 5.0f;
		this->DotStatus = 79.0f;
	}
	else if (pWinWidth == 1024)
	{
		this->SD_PosY = 6.0f;
		this->BP_PosY = 6.0f;
		this->DotStatus = 77.5f;
	}
	else if (pWinWidth == 1280)
	{
		this->SD_PosY = 8.0f;
		this->BP_PosY = 8.0f;
		this->DotStatus = 76.5f;
	}
	else if (pWinWidth == 1366)
	{
		this->SD_PosY = 8.5f;
		this->BP_PosY = 8.5f;
		this->DotStatus = 76.5f;
	}
	else if (pWinWidth == 1440)
	{
		this->SD_PosY = 8.9f;
		this->BP_PosY = 8.9f;
		this->DotStatus = 76.5f;
	}
	else if (pWinWidth == 1600)
	{
		this->SD_PosY = 8.9f;
		this->BP_PosY = 8.9f;
		this->DotStatus = 76.5f;
	}
	else if (pWinWidth == 1680)
	{
		this->SD_PosY = 11.0f;
		this->BP_PosY = 11.0f;
		this->DotStatus = 75.0f;
	}
	else if (pWinWidth == 1700)
	{
		this->SD_PosY = 11.0f;
		this->BP_PosY = 11.0f;
		this->DotStatus = 75.0f;
	}
	else if (pWinWidth == 1800)
	{
		this->SD_PosY = 11.0f;
		this->BP_PosY = 11.0f;
		this->DotStatus = 75.0f;
	}
	else if (pWinWidth == 1920)
	{
		this->SD_PosY = 12.0f;
		this->BP_PosY = 12.0f;
		this->DotStatus = 75.0f;
	}
}