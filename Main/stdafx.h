#pragma once

typedef unsigned __int64 QWORD;

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

// System Include
#include <windows.h>
#include "../../Addon/KeySerial.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <winsock2.h>
#include <Mmsystem.h>
#include <time.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <Shellapi.h>
#include <vector>
#include <map>
#include <Windows.h>
#include <algorithm>
#include <winioctl.h>
#include <algorithm>
#include <tlhelp32.h>

#define va_start _crt_va_start
#define va_arg _crt_va_arg
#define va_end _crt_va_end
//tue add DMp file //--------
#include <dbghelp.h>
//tue add fixx ad DUMp file //-------------
#pragma comment(lib,"dbghelp.lib")
//------------------------------------------
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"Opengl32.lib")
#define MENU_GAME_FILE "./Data/SPK/Message/Messenger.ini"
#define MENU_NOTE_FILE  ".\\data\\Custom\\Notice.ini"
#define MENU_OPTN_FILE  "./Settings.ini"
#define pDrawMessage				((int(__cdecl*)(LPCSTR Text, int Mode)) 0x00597630)
#define MAXSIZEMOCNAP			15
#define MAXSIZERL				11
#define MAXSUBSIZE				6

#define MAX_WIN_WIDTH			640
#define MAX_WIN_HEIGHT			480

#define SPK_DANHHIEU_IMG		1677300
#define MAX_LEVEL_DANH_HIEU		25

#define SPK_QUANHAM_IMG			1677400
#define MAX_LEVEL_QUAN_HAM		20

#define SPK_TULUYEN_IMG			1677500
#define MAX_LEVEL_TU_LUYEN		40

#define SPK_NEWVIP_IMG			1677600
#define MAX_LEVEL_NEW_VIP		3

#define LevelHH					50
#define MAX_EFFECT_LIST			32
#define MAX_EFFECT_LINE			16 // tạo 2 dòng BUFF mỗi dòng 16
#define MAX_NUM_RSCHANGE		5

//UPDATE 03/06/2024 14:25
#define CUSTOM_HARMONY			1
#define TYPEZEN					0
#define SPK_VKR_HOOK			1
#define B_MOCNAP				1
#define OFF_SOCKET_HAMONY		1
#define NEWXSHOP				1
#define RELIFE					1
#define ZOOM_MAX_CAM			1
#define SPK_ITEMTRADE			1
#define ADD_POINT		        1
//#define SLOTPET2				0
#define SLOTPET2				1
#define SOIITEM					1
#define CMUI_RENDER_ZEN			1 // WC - Zen Phim V
#define HT_THUE_FLAG			1
#define SO_LUONG_BOSS			1
//#define RINGPEN_NEW				0
#define RINGPEN_NEW				1

#define CHAOS_RATE_FIX			1
#define	DAMAGE_RENDER_ENABLE	1
#define NOTICE_PKSYSTEM			1
#define BXHDAME					1
#define CB_EventArenaPvP		1
#define	SPK_HONHOAN				1
#define SPK_DANHHIEU			1
#define SPK_QUANHAM				1
#define SPK_TUCHAN				1
#define SPK_NEWVIP				1
#define SELECT_CHAR_INFO		1
#define CongHuongV2				1
#define LUC_CHIEN				0
#define BXH_LUCHIEN				1 
#define VONGQUAY_NEW				1

#define REGISTER_INGAME			1
#define CTCMINI					1
#define BUFF_PART_ICON			0
#define OFFNAMEGUILD			0
#define BUNDLE_ITEM				1
#define THANMA					1
#define	RESETCHANGE				1
#define TINHNANG_NEW			1

#define	SPK_STYLE				1
#define SAU_ANTIHACK			1
#define CUSTOM_GUILD_UPGRADE	1
#define MAIN_VERSION_S8			1
#define PREMIUN					1
#define MAX_CHAT_TYPE1			10
#define MOVE_HP_NUM				1
#define MAX_CUSTOM_GLOVES	50
#define MAX_CUSTOM_BOW		50
#define MAX_PET_ITEM		300
#define MAX_CUSTOMCLOAK		20

#define MAX_CUSTOM_WING			100
#define MAX_REMAKE_EFFECT		100
#define MAX_CUSTOM_ITEM_INFO	1000
#define MAX_POSITION_ITEM		1000
//--
#define MAX_CUSTOPETEFFECT			2000
#define MAX_DYNAMIC_WING_EFFECT		5000
#define MAX_CUSTOM_WING_EFFECT		5000

#define UPDATE 15



#define LODWORD(h)					((DWORD)(__int64(h) & __int64(0xffffffff)))

//===Custom

#define HORA_SERVER					1
#define NOTICE_MES					1
#define TEXT_IN_GAME				1
#define PARTYSEARCH					1

#define THONG_BAO_PLUGIN_ERROR		1
#ifndef TEXTVN_NEW
#define TEXTVN_NEW					1
#endif

#define HUY_HIEU_CUONG_HOA			1


#define ANTI_CRACK_MAIN				1
#define TAT_QUEST_T					1
#define FIX_MONTER_TRABE			1
#define FIX_LAG_QOAI				1
#define FIX_GIAM_LAG_MAIN			1

#define TYPE_VUKHI 0
#define TYPE_RIU 1
#define TYPE_CHUY 2
#define TYPE_GIAO 3
#define TYPE_CUNG 4
#define TYPE_GAY 5
#define TYPE_KHIENG 6
#define TYPE_WING 12
#define TYPE_RING 13

#define selectchars13 1
#define CheckSPK_WINDOWS gInterface.CheckWindow(ObjWindow::CashShop)				|| gInterface.CheckWindow(ObjWindow::FriendList)	|| gInterface.CheckWindow(ObjWindow::MoveList)		|| gInterface.CheckWindow(ObjWindow::Party)				|| gInterface.CheckWindow(ObjWindow::Quest)			|| gInterface.CheckWindow(ObjWindow::NPC_Devin)		|| gInterface.CheckWindow(ObjWindow::Guild)				|| gInterface.CheckWindow(ObjWindow::Trade)			|| gInterface.CheckWindow(ObjWindow::Warehouse)		|| gInterface.CheckWindow(ObjWindow::ChaosBox)			|| gInterface.CheckWindow(ObjWindow::CommandWindow) || gInterface.CheckWindow(ObjWindow::PetInfo)		|| gInterface.CheckWindow(ObjWindow::Shop)				|| gInterface.CheckWindow(ObjWindow::Inventory)		|| gInterface.CheckWindow(ObjWindow::Store)		|| gInterface.CheckWindow(ObjWindow::OtherStore)		|| gInterface.CheckWindow(ObjWindow::Character)		|| gInterface.CheckWindow(ObjWindow::DevilSquare)		|| gInterface.CheckWindow(ObjWindow::BloodCastle)		|| gInterface.CheckWindow(ObjWindow::CreateGuild)	|| gInterface.CheckWindow(ObjWindow::GuardNPC)		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)			|| gInterface.CheckWindow(ObjWindow::GuardNPC2)		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)	|| gInterface.CheckWindow(ObjWindow::IllusionTemple)		|| gInterface.CheckWindow(ObjWindow::HeroList)			|| gInterface.CheckWindow(ObjWindow::ChatWindow)	|| gInterface.CheckWindow(ObjWindow::FastMenu)		|| gInterface.CheckWindow(ObjWindow::Options)			|| gInterface.CheckWindow(ObjWindow::Help)			|| gInterface.CheckWindow(ObjWindow::FastDial)		|| gInterface.CheckWindow(ObjWindow::SkillTree)			|| gInterface.CheckWindow(ObjWindow::GoldenArcher1) || gInterface.CheckWindow(ObjWindow::GoldenArcher2)		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)	|| gInterface.CheckWindow(ObjWindow::NPC_Duel)		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)			|| gInterface.CheckWindow(ObjWindow::CashShop)		|| gInterface.CheckWindow(ObjWindow::Lugard)		|| gInterface.CheckWindow(ObjWindow::QuestList1)		|| gInterface.CheckWindow(ObjWindow::QuestList2)	|| gInterface.CheckWindow(ObjWindow::Jerint)		|| gInterface.CheckWindow(ObjWindow::FullMap)			|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)	|| gInterface.CheckWindow(ObjWindow::GensInfo)		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)			|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)	|| gInterface.CheckWindow(ObjWindow::ExpandInventory)		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)	|| gInterface.CheckWindow(ObjWindow::MuHelper)
#define CheckSPK_WINDOWS2 gInterface.CheckWindow(CashShop)|| gInterface.CheckWindow(SkillTree)|| gInterface.CheckWindow(FullMap)|| gInterface.CheckWindow(MoveList)|| gInterface.CheckWindow(Inventory)|| gInterface.CheckWindow(ExpandInventory)|| gInterface.CheckWindow(Store)|| gInterface.CheckWindow(Inventory)|| gInterface.CheckWindow(Party)	|| gInterface.CheckWindow(Trade)	|| gInterface.CheckWindow(Warehouse)|| gInterface.CheckWindow(ExpandWarehouse)
#define CheckSPK_WINDOWS3 gInterface.CheckWindow(ObjWindow::CashShop)|| gInterface.CheckWindow(ObjWindow::FriendList)|| gInterface.CheckWindow(ObjWindow::MoveList)|| gInterface.CheckWindow(ObjWindow::Party)|| gInterface.CheckWindow(ObjWindow::Quest)|| gInterface.CheckWindow(ObjWindow::NPC_Devin)|| gInterface.CheckWindow(ObjWindow::Guild)|| gInterface.CheckWindow(ObjWindow::Trade)|| gInterface.CheckWindow(ObjWindow::Warehouse)|| gInterface.CheckWindow(ObjWindow::ChaosBox)|| gInterface.CheckWindow(ObjWindow::CommandWindow)|| gInterface.CheckWindow(ObjWindow::PetInfo)|| gInterface.CheckWindow(ObjWindow::Shop)|| gInterface.CheckWindow(ObjWindow::Store)|| gInterface.CheckWindow(ObjWindow::OtherStore)|| gInterface.CheckWindow(ObjWindow::Character)|| gInterface.CheckWindow(ObjWindow::DevilSquare)|| gInterface.CheckWindow(ObjWindow::BloodCastle)|| gInterface.CheckWindow(ObjWindow::CreateGuild)|| gInterface.CheckWindow(ObjWindow::GuardNPC)|| gInterface.CheckWindow(ObjWindow::SeniorNPC)|| gInterface.CheckWindow(ObjWindow::GuardNPC2)|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)|| gInterface.CheckWindow(ObjWindow::CatapultNPC)|| gInterface.CheckWindow(ObjWindow::CrywolfGate)|| gInterface.CheckWindow(ObjWindow::IllusionTemple)|| gInterface.CheckWindow(ObjWindow::HeroList)|| gInterface.CheckWindow(ObjWindow::ChatWindow)|| gInterface.CheckWindow(ObjWindow::FastMenu)|| gInterface.CheckWindow(ObjWindow::Options)|| gInterface.CheckWindow(ObjWindow::Help)|| gInterface.CheckWindow(ObjWindow::FastDial)|| gInterface.CheckWindow(ObjWindow::SkillTree)|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)|| gInterface.CheckWindow(ObjWindow::NPC_Duel)|| gInterface.CheckWindow(ObjWindow::NPC_Titus)|| gInterface.CheckWindow(ObjWindow::CashShop)|| gInterface.CheckWindow(ObjWindow::Lugard)|| gInterface.CheckWindow(ObjWindow::QuestList1)|| gInterface.CheckWindow(ObjWindow::QuestList2)|| gInterface.CheckWindow(ObjWindow::Jerint)|| gInterface.CheckWindow(ObjWindow::FullMap)|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)|| gInterface.CheckWindow(ObjWindow::GensInfo)|| gInterface.CheckWindow(ObjWindow::NPC_Julia)|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)|| gInterface.CheckWindow(ObjWindow::ExpandInventory)|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)|| gInterface.CheckWindow(ObjWindow::MuHelper)

enum SPK_RenderFile
{
	BTN_NEX_NEW = 0x7E59,
	BTN_PREV_NEW = 0x7E5A,

	BTN_MENU_OFFSET = 0x17A3C,
	BG_IMG_OFFSET = 0x17A3D,
	MP_IMG_OFFSET = 0x17A40,
	MP_IMG_ENDSET = 0x1C92D,
	HP_IMG_ENDSET = 0x1C92E,
	HP_IMG_GRESET = 0x17A41,
	HP_IMG_REDSET = 0x17A42,
	BG_IMG_HDLSET = 0x17A43,
	BG_IMG_HDRSET = 0x17A44,	
	BG_IMG_CHARIC = 0x17A45,	

	BG_IMG_PERS = 0x17AEE,
	BG_IMG_NUM2 = 0x17AEF,

	BT_TOPRS = 0x17AF0,
	BT_TOPNAP = 0x17AF1,
	HP_IsSD = 0x17AF2,
	BG_IMG_MAP3 = 0x17AF3,
	BG_IMG_MAP4 = 0x17AF4,
	BG_IMG_MAP6 = 0x17AF6,
	BG_IMG_MAP7 = 0x17AF7,
	BG_IMG_MAP8 = 0x17AF8,
	BG_IMG_MAP10 = 0x17AFA,
	BG_IMG_MAP11 = 0x17AFB,
	BG_IMG_MAP12 = 0x17AFC,
	BG_IMG_MAP13 = 0x17AFD,
	BG_IMG_MAP14 = 0x17AFE,
	BG_IMG_MAP15 = 0x17AFF,
	BG_IMG_MAP16 = 0x17B00,
	BG_IMG_MAP17 = 0x17B01,
	BG_IMG_MAP18 = 0x17B02,
	BG_IMG_MAP19 = 0x17B03,
	BG_IMG_MAP20 = 0x17B04,
	BG_IMG_MAP21 = 0x17B05,
	BG_IMG_MAP22 = 0x17B06,
	BG_IMG_MAP23 = 0x17B07,
	BG_IMG_MAP30 = 0x17B0E,
	BG_IMG_MAP33 = 0x17B11,
	BG_IMG_MAP34 = 0x17B12,
	BG_IMG_MAP37 = 0x17B15,
	BG_IMG_MAP38 = 0x17B16,
	BG_IMG_MAP41 = 0x17B19,
	BG_IMG_MAP42 = 0x17B1A,
	BG_IMG_MAP51 = 0x17B23,
	BG_IMG_MAP52 = 0x17B24,
	BG_IMG_MAP53 = 0x17B25,
	BG_IMG_MAP56 = 0x17B28,
	BG_IMG_MAP57 = 0x17B29,
	BG_IMG_MAP63 = 0x17B2F,
	BG_IMG_MAP79 = 0x17B35,
	BG_IMG_MAP80 = 0x17B36,
	BG_IMG_MAP81 = 0x17B37,
	BG_IMG_MAP86 = 0x17B3C,
	BG_IMG_MAP89 = 0x17B3F,
	BG_IMG_MAP90 = 0x17B40,
};
