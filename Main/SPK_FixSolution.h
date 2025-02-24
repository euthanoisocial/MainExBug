#pragma once
class SuaLoiKhungHinh
{
	public:
	float SD_PosY,BP_PosY;
	float DotStatus;

	int gZoomCurrent;
	float DH_PosY;
	float QH_PosY;
	float VIP_PosY;
	void SuaLoiKhungHinh::StartLoadPos();
	void SuaLoiKhungHinh::StartLoadZoomPos();
};
extern SuaLoiKhungHinh gFixSolution;