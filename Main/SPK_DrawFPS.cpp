#include "stdafx.h"
#include "SPK_DrawFPS.h"
#include "Interface.h"
#include "Defines.h"

SPKXemFps gFpsView;
bool SPKXemFps::CombinedChecks()
{
	if ((gInterface.CheckWindow(Inventory)
		&& gInterface.CheckWindow(ExpandInventory)
		&& gInterface.CheckWindow(Store)) ||
		(gInterface.CheckWindow(Inventory)
			&& gInterface.CheckWindow(Warehouse)
			&& gInterface.CheckWindow(ExpandWarehouse)) ||
		(gInterface.CheckWindow(Inventory)
			&& gInterface.CheckWindow(Character)
			&& gInterface.CheckWindow(Store)))
		return true;
	return false;
}

void SPKXemFps::RenderObjectFps()
{
	this->lastReport = GetTickCount();
	this->frameCount = 0;
}
void SPKXemFps::MainFps(float x, float y, float w, float h) 
{
	this->frameCount++;
	if (GetTickCount() - this->lastReport >= 1000)
	{
		this->frameRate = this->frameCount / ((GetTickCount() - this->lastReport) / 1000);
		sprintf(this->FPS_REAL, "FPS: %d", this->frameRate);
		this->lastReport = GetTickCount();
		this->frameCount = 0;
	}
	gInterface.DrawFormat(eGold, x, y, w, h, this->FPS_REAL);
}