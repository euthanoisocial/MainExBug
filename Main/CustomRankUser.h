#ifndef _CUSTOM_RANK_USER_H
#define _CUSTOM_RANK_USER_H
#include "Protocol.h"
#include "Object.h"
// tue add---
#define pObjPreviewThis        ((DWORD)0x096A4C0)
#define CS_GET_STRUCT(x, y)	   (1124 * x + *(int*) y)
#define Color4f(r, b, g, o)	   ((o << 24) + (g << 16) + (b << 8) + r)
// ---
/*
struct PMSG_CUSTOM_RANKUSER
{
	PSBMSG_HEAD h;
	char szName[20];
	int iIndex;
	int iLevel;
	// tue fixx //////////
	int iReset;
	int iMReset;
	int iKills;
	int iDeads;
	int iFor;
	int iEne;
	int iAgi;
	int iVit;
	int iCom;
	int iClasse;
	int iRank;
	// ---
	int irDanhHieu;
	int irQuanHam;
	int irTuLuyen;
	int irThueVip;
	int irNguHanh;
	int iVipIcon;
	char iVip[20];
	// ---
	//--------------
	//////////////////////
	int m_RankTitle1;
#if SPK_QUANHAM
	int m_RankTitle2;
#endif
#if SPK_TUCHAN
	int m_RankTitle3;
#endif
#if SPK_NEWVIP
	int m_RankTitle4;
#endif
#if(SPK_HONHOAN)
	WORD m_RankTitle5;
#endif
#if(HT_THUE_FLAG)
	int m_RankTitle6;
#endif
#if RESETCHANGE
	int ReqResetChange[MAX_NUM_RSCHANGE];
	int ReqResetCoin[MAX_NUM_RSCHANGE];
	int ReqResetUpPoint[MAX_NUM_RSCHANGE];
#endif
};
*/
struct PMSG_CUSTOM_RANKUSER
{
	PSBMSG_HEAD h;
	char szName[20];
	int iIndex;
	int iLevel;
	int m_RankTitle1;
	int m_RankTitle2;
	int m_RankTitle3;
	int m_RankTitle4;
#if(SPK_HONHOAN)
	WORD m_RankTitle5;
#endif
#if(HT_THUE_FLAG)
	int m_RankTitle6;
#endif
#if RESETCHANGE
	int ReqResetChange[MAX_NUM_RSCHANGE];
	int ReqResetCoin[MAX_NUM_RSCHANGE];
	int ReqResetUpPoint[MAX_NUM_RSCHANGE];
#endif
	int iVipIcon;
	char iVip[20];
	//tue add
	int iReset;
	int iMReset;
	int iKills;
	int iDeads;
	int iFor;
	int iEne;
	int iAgi;
	int iVit;
	int iCom;
	int iClasse;
	int iRank;
	//end add

};
// ---
struct CUSTOM_RANKUSER_DATA
{
	WORD m_Index;
	WORD m_Level;
	WORD m_RankTitle1;
	
	//tue add
	WORD m_Rank;
	WORD m_Resets;
	WORD m_MResets;
	WORD m_Kills;
	WORD m_Deads;
	WORD m_For;
	WORD m_Vit;
	WORD m_Ene;
	WORD m_Agi;
	WORD m_Com;
	WORD m_Classe;
	//------
	int m_rDanhHieu;
	int m_rQuanHam;
	int m_rTuLuyen;
	int m_rThueVip;
	int m_rNguHanh;
	//-------
	// ---
	int irDanhHieu;
	int irQuanHam;
	int irTuLuyen;
	int irThueVip;
	int irNguHanh;
	int iVipIcon;
	// ---
	// --------------
	//-----
	#if SPK_QUANHAM
	WORD m_RankTitle2;
	#endif
	#if SPK_TUCHAN
	WORD m_RankTitle3;
	#endif
	#if SPK_NEWVIP
	WORD m_RankTitle4;
	#endif
	#if(SPK_HONHOAN)
	WORD m_RankTitle5;
	#endif
	#if(HT_THUE_FLAG)
	int m_RankTitle6;
	#endif

	WORD m_iVipIcon;
	char m_Vip[20];
	BOOL m_Enabled;
	BYTE	Attribute;
	
	//BYTE	Attribute;
	char szTitleRank[20];
	//----
	


};
// ---
class CCustomRankUser
{
	public:
	//tue add
	CCustomRankUser();
	// ---
	void DrawInfo();
	void	Test();
	int  DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	// end add---
	void RenderShowLogRank(DWORD ViewPortAddr, int index, int PosX, int PosY);
	void GCReqRankLevelUser(PMSG_CUSTOM_RANKUSER * aRecv);

	#if RESETCHANGE
	int ReqResetChange[MAX_NUM_RSCHANGE];
	int ReqResetCoin[MAX_NUM_RSCHANGE];
	int ReqResetUpPoint[MAX_NUM_RSCHANGE];
	#endif
	
	CUSTOM_RANKUSER_DATA m_Data[14000];
};
extern CCustomRankUser gCustomRankUser;
// tue add---
class CPreviewManager
{
public:
	bool ObjCheck(int index, int pThis);
	bool ObjSelect(int index, int pThis);
	// ---
	WORD  Index;
	BYTE  Live;
	BYTE  Type;
	BYTE  IsSafeZone;
	// ---
	VAngle Angle;
};
// ---

#endif