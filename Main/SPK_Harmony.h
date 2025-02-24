#pragma once
#if (CUSTOM_HARMONY)

#include "Protocol.h"
#define BPConvertByteItem ((int (__thiscall*)(int a1, void *lp)) 0x7E1B10)
struct CHCSEV_COUNTLIST
{
	PSWMSG_HEAD header;
	int Count;
};

struct OPTITEM
{
	int OptIndex;
	char Name[60];
	int Level;
	int Rate;
};

struct HARMONY_SENDCLIENT
{
	PSWMSG_HEAD header;
	BYTE ActiveMix;
	BYTE ItemChuaEp[16];
	int Rate;
	int Price;
	int PriceType;
	int SoLuongDaTaoHoa;
	int IndexRandom;
};
struct JCCoordX
{
	int X;
	int Y;
};
class CustomHarmony
{
	public:
	CustomHarmony();
	void Init();
	void DrawHarmony();
	void RecvHarmony(CHCSEV_COUNTLIST* lpMsg);
	std::vector<OPTITEM> m_HarmonyInfoList;
	char* GetNamePrice();
	bool Harmony_ActiveMix;
	bool Harmony_EffectsMix;
	bool SetStateHarmony;
	BYTE ItemChuaEp[16];
	int Rate;
	int Price;
	int PriceType;
	int SoLuongDaTaoHoa;
	int IndexRandom;
	DWORD ClickTime;
};

extern CustomHarmony gCustomHarmony;
#endif