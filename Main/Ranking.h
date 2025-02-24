#pragma once
#include "Protocol.h"

#define pIsKeyPress	((bool(*)(int))0x00791070)

#define iMaxCount 20
#define MaxBingH	20
#define MAXTOP		20
#define MAXPAGE		1
#define MOVE_UP		40
#define MAX_LINE	13

#define MaxCharInfo 25

struct CharTop
{
	char Name[11];
	BYTE Is_Class;
	int Is_cLevel;
	int Is_ResetCount;
	int Is_MasterResetCount;
	int Is_ResetTime;
	int Is_TotalPoint;
	char Is_SvSub[11];
};

struct DGCharTop
{
	PWMSG_HEAD h;
	CharTop	tp[MAXTOP];
};

struct CharTopNap
{
	char Name[11];
	BYTE Is_Class;
	int Is_TotalCoin;
	char Is_JoinDate[22];
	char Is_LastDate[22];
};

struct DGCharTopNap
{
	PWMSG_HEAD h;
	CharTopNap	tp[MAXTOP];
};


struct DATA_VIEWTOPRANKING
{
	PSWMSG_HEAD header;
	char NameChar[11];
	char GuildName[11];
	BYTE GuildMark[32];
	BYTE Item[12][16];
	int aIndex;
};
struct REQUESTINFO_CHARTOP
{
	PSBMSG_HEAD header; // C3:F3:03
	char NameChar[11];
	int aIndex;
};
//
 struct CharTopET
{
	char Name[11];
	int Is_BloodCS;
	int Is_ChaosCS;
	int Is_DevilCS;
};

struct DGCharTopET
{
	PWMSG_HEAD h;
	CharTopET	tp[MAXTOP];
};
//
struct CharTopTG
{
	char G_Name[11];
	char G_Master[11];
	int Is_GLevel;
	int Is_GScore;
	int Is_GMem;
	char Is_JoinDate[22];
};

struct DGCharTopTG
{
	PWMSG_HEAD h;
	CharTopTG	tp[MAXTOP];
};
//
struct CharTopPK
{
	char Name[11];
	int Is_Kills;
	int Is_Deads;
	int Is_OnlineHours;
	int Is_Win;
	int Is_Lose;
	int Is_Kboss;
	char Is_JoinDate[22];
};

struct DGCharTopPK
{
	PWMSG_HEAD h;
	CharTopPK	tp[MAXTOP];
};

//
struct CharTopDW
{
	char Name[11];
	BYTE Is_Class;
	int Is_cLevel;
	int Is_ResetCount;
	int Is_MasterResetCount;
	int Is_ResetTime;
	int Is_TotalPoint;
	char Is_SvSub[11];
};

struct DGCharTopDW
{
	PWMSG_HEAD h;
	CharTopDW	tp[MAXTOP];
};
//
struct CharTopDK
{
	char Name[11];
	BYTE Is_Class;
	int Is_cLevel;
	int Is_ResetCount;
	int Is_MasterResetCount;
	int Is_ResetTime;
	int Is_TotalPoint;
	char Is_SvSub[11];
};

struct DGCharTopDK
{
	PWMSG_HEAD h;
	CharTopDK	tp[MAXTOP];
};
//
struct CharTopEF
{
	char Name[11];
	BYTE Is_Class;
	int Is_cLevel;
	int Is_ResetCount;
	int Is_MasterResetCount;
	int Is_ResetTime;
	int Is_TotalPoint;
	char Is_SvSub[11];
};

struct DGCharTopEF
{
	PWMSG_HEAD h;
	CharTopEF	tp[MAXTOP];
};
//
struct CharTopMG
{
	char Name[11];
	BYTE Is_Class;
	int Is_cLevel;
	int Is_ResetCount;
	int Is_MasterResetCount;
	int Is_ResetTime;
	int Is_TotalPoint;
	char Is_SvSub[11];
};

struct DGCharTopMG
{
	PWMSG_HEAD h;
	CharTopMG	tp[MAXTOP];
};
//
struct CharTopDL
{
	char Name[11];
	BYTE Is_Class;
	int Is_cLevel;
	int Is_ResetCount;
	int Is_MasterResetCount;
	int Is_ResetTime;
	int Is_TotalPoint;
	char Is_SvSub[11];
};

struct DGCharTopDL
{
	PWMSG_HEAD h;
	CharTopDL	tp[MAXTOP];
};
//
struct CharTopSM
{
	char Name[11];
	BYTE Is_Class;
	int Is_cLevel;
	int Is_ResetCount;
	int Is_MasterResetCount;
	int Is_ResetTime;
	int Is_TotalPoint;
	char Is_SvSub[11];
};

struct DGCharTopSM
{
	PWMSG_HEAD h;
	CharTopSM	tp[MAXTOP];
};
//
struct CharTopRF
{
	char Name[11];
	BYTE Is_Class;
	int Is_cLevel;
	int Is_ResetCount;
	int Is_MasterResetCount;
	int Is_ResetTime;
	int Is_TotalPoint;
	char Is_SvSub[11];
};

struct DGCharTopRF
{
	PWMSG_HEAD h;
	CharTopRF	tp[MAXTOP];
};
class cRanking
{
	public:
	cRanking();
	void RecvInfo(DGCharTop* lpMsg); 
	CharTop RankingChar[MAXTOP];
	
	void RecvInfoNap(DGCharTopNap* lpMsg);
	CharTopNap RankingCharNap[MAXTOP];

	void RecvInfoET(DGCharTopET* lpMsg);
	CharTopET RankingCharET[MAXTOP];

	void RecvInfoTG(DGCharTopTG* lpMsg);
	CharTopTG RankingCharTG[MAXTOP];

	void RecvInfoPK(DGCharTopPK* lpMsg);
	CharTopPK RankingCharPK[MAXTOP];

	void RecvInfoDW(DGCharTopDW* lpMsg);
	CharTopDW RankingCharDW[MAXTOP];

	void RecvInfoDK(DGCharTopDK* lpMsg);
	CharTopDK RankingCharDK[MAXTOP];

	void RecvInfoEF(DGCharTopEF* lpMsg);
	CharTopEF RankingCharEF[MAXTOP];

	void RecvInfoMG(DGCharTopMG* lpMsg);
	CharTopMG RankingCharMG[MAXTOP];

	void RecvInfoDL(DGCharTopDL* lpMsg);
	CharTopDL RankingCharDL[MAXTOP];

	void RecvInfoSM(DGCharTopSM* lpMsg);
	CharTopSM RankingCharSM[MAXTOP];

	void RecvInfoRF(DGCharTopRF* lpMsg);
	CharTopRF RankingCharRF[MAXTOP];

	void cRanking::GetPacketSender(DWORD ClickMouse, DWORD Delay, BYTE Pages, int Packet);
	void cRanking::LoadImg();
	void cRanking::BingImg();
	void cRanking::ClickRanking(DWORD ClickMouse);
	void cRanking::SendMenuButton();
	void cRanking::GetBarInfo(int x, int y, int Value1, int Value2, DWORD BackColor, LPCSTR Char, ...);
	void Draw();
	bool Active;
	bool Show;
	int StartX;
	int StartY;
	int Page;
	DWORD ClickTick;
	int TrangRanking;
	DWORD ClickTime;

	DATA_VIEWTOPRANKING CacheDataUserTop;
	void GCReqInfoCharTop(DATA_VIEWTOPRANKING* lpMsg);
	bool CacheUserRank;
	bool SetItemCharTop;

};
extern cRanking gRanking;



