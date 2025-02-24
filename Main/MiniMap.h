#pragma once
//--/TAP FULLMAP
//----- (00790DF0) --------------------------------------------------------
//----- (00638130) --------------------------------------------------------
#define sub_82B7A0A ((char(__thiscall*)(int a1, signed int a4, signed int a5))0x0082B7A0)
#define pDrawMapFull ((void(__cdecl*)(int ModelID, float x, float y, float Width, float Heigth, float Rotacion))0x00638130)
#define sub_82B7A0 ((char(__thiscall*)(signed int a4, signed int a5))0x0082B7A0)
#define sub_8875E0 ((char(__cdecl*)(DWORD a1))0x008875E0)
#define sub_635CF0 ((void (__stdcall*)(signed int a4))0X00635CF0)
#define rFileOpen ((int(__cdecl*)(char* FileName, char* Mode)) 0x9D0040) //1.04E
#define rFileClose ((signed int(__cdecl*)(int a1))0x9CFC26) //1.04E 

//-- NEW
#define GetBindTexture ((bool(__cdecl*)(int a1)) 0x00635CF0)
#define sub_636420 ((double(__cdecl*)(float a1)) 0x00636420)
GLvoid GetDrawCircle(int ID, float X, float Y, float W, float CurrenX, float CurrenY, float SetScale, int ScaleSize, int ScalePosicion, float Alpha);

struct LoadTypeMap
{
	/*+0*/   DWORD ModelID;
	/*+4*/   DWORD XSW_Minimap_Frame;
	/*+8*/   DWORD YSW_Minimap_Frame;
	/*+12*/  DWORD XSW_Minimap;
	/*+16*/  DWORD YSW_Minimap;
	/*+20*/  DWORD XSW_Time_Frame;
	/*+24*/  DWORD YSW_Time_Frame;
	/*+92*/  DWORD This_92;
	/*+96*/  DWORD This_96;
	/*+100*/ DWORD DropMoveUserX;
	/*+104*/ DWORD DropMoveUserY;
	/*+108*/ DWORD This_108;
	/*+112*/ DWORD This_112;
	/*+116*/ float CurrentMoveX;
	/*+120*/ float CurrentMoveY;
	/*+124*/ DWORD Scale;
	/*+126*/ DWORD TimerEventVK;
	/*+128*/ float Alpha;
};

typedef struct
{
	BYTE gap1[4];
	DWORD UNONK4;
	DWORD UNONK8;
	DWORD x;
	DWORD y;
	DWORD UNONK20;
	DWORD UNONK24;
	DWORD UNONK28;
	DWORD UNONK32;
	BYTE gap2[63];
	DWORD UNONK96;
	DWORD UNONK100;
	DWORD UNONK104;
	DWORD UNONK108;
	DWORD UNONK112;
	float CurrentX;
	float CurrentY;
	DWORD Scale;
	float UNONK128;
	BYTE gap3[2];
	BYTE UNONK134;
	BYTE gap4[5];
	DWORD UNONK140;
	float UNONK144;
}JCMapStruct, * lpMapStruct;

#define MAX_MINI_MAP_DATA		100

typedef char MINI_MAP[116];
typedef struct
{
	char		byClass[12];	//-- +0
	char		m_TooltipText[28];	//-- +12
	DWORD		m_hToolTipFont;	//-- +40
	DWORD		m_TooltipTextColor;	//-- +44
	DWORD*      m_pNewUIMng;	//-- +48
	POINT		m_Pos;			//-- +52
	POINT		m_Width;		//-- +60
	POINT		m_MiniWidth;	//-- +68
	POINT		m_Lenth[6];		//-- +76
	int			m_MiniPos;		//-- +124
	char		m_BtnExit[172];	//-- +128
	MINI_MAP	m_Mini_Map_Data[MAX_MINI_MAP_DATA]; //-- +300
	float		m_Btn_Loc[MAX_MINI_MAP_DATA][4]; //-- 11900
	bool		m_bSuccess; //-- 13500
}UIMiniMap;

class CMinimap
{
public:
	CMinimap();
	void MiniMapload();
	static void LoadImages(char* a1, int a2, int a3, int a4, int a5, int a6);
	void CreateRadar();
	bool CMinimap::UpdateMouseEvent(UIMiniMap* thisa);
public:
	LoadTypeMap DataMap;
}; extern CMinimap gRenderMap;