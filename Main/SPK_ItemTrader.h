#pragma once
#define sub_7E3E30 ((signed int (__thiscall*)(int a1, JCCoord a5, int a6, int a7, int a8, int a9)) 0x007E3E30)
#define BPConvertByteItem ((int (__thiscall*)(int a1, void *lp)) 0x7E1B10)
#if(SPK_ITEMTRADE)
struct JCCoord
{
	int X;
	int Y;
};

class SPK_NPC_TRADER
{
	public:
	bool ActiveMix;
	bool EffectsMix;
	bool SetStateDoiItem;
	BYTE ItemChinh[16];
	BYTE ItemPhu[3][16];
	BYTE ItemKetQua[6][16];
	int WCoinC;
	int WCoinP;
	int WCoinG;
	int CoinAtm;

	void DrawInfoItemSet();
	void BackDoiItem(int Type);
	void DrawDoiItem();
	void SendToProtocol6A(BYTE* lpMsg);
	void SendToProtocol6B(BYTE* lpMsg);
	void DrawItemSlotSelect(float X, float Y, float W, float H,BYTE ItemSlot);
	void DrawItemSlotToolTip(float X, float Y, float W, float H,BYTE ItemSlot);
	private:
	float guiX;
	float guiY;
	short curX;
	short curY;
	bool  dragging;
	DWORD ActionTime;
	bool is_move;
};
extern SPK_NPC_TRADER gItemTrade;
#endif