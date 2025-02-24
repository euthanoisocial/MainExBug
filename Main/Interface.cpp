#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "SPK_ItemLocker.h"
#include "Common.h"
#include "CustomCommandInfo.h"
#include "SPK_DungLuyen.h"
#include "CustomEventTime.h"
#include "Interface.h"
#include "Import.h"
#include "SPK_DameRender.h"
#include "CSCharacterS13.h"
#include "TMemory.h"
#include "Defines.h"
#include "SPK_PKSystem.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "SPK_Harmony.h"
#include "Util.h"
#include "Offset.h"
#include "CustomCloak.h"
#include "ChatExpanded.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "Controller.h"
#include "postInterface.h"
#include "InterEx.h"
#include "Central.h"
#include "CustomFont.h"
#include "CustomEventTime.h"
#include "WindowsStruct.h"
#include "CMacroUIEx.h"
#include "PartySearchSettings.h"
#include "PartySearch.h"
#include "Config.h"
#include "time.h"
#include "CustomLuckySpin.h"
#include "CustomJewelBank.h"
#include "Ranking.h"
#include "SPK_ResetChange.h"
#include "Bytes.h"
#include "MuHelper.h"
#include "MessHacking.h"
#include "GuildUpgrade.h"
#include "CustomRankUser.h"
#include "Item.h"
#include "CB_ArenaPvP.h"
#if CHAOS_RATE_FIX
#include "ChaosMachine.h"
#endif
#include "SPK_CharacterList.h"
#include "SPK_DrawBoxAtm.h"
#include "SPK_Invasions.h"
#include "ThueFlag.h"
#include "SPK_ToolKit.h"
#include "SPK_MobileAvt.h"
#include "SPK_CongHuongV2.h"
#include "SPK_ThanMa.h"
#include "SPK_CtcMini.h"
#include "SPK_CongPoint.h"
#include "SPK_ItemTrader.h"
#include "SPK_Relife.h"
#include "SPK_MocNapNew.H"
#include "SPK_DrawFPS.h"
#include "SPK_HonHoan.h"
#include "SPK_DanhHieu.h"
#include "SPK_QuanHam.h"
#include "SPK_TuChan.h"
#include "SPK_NewVip.h"
#include "SPK_ChangePass.h"
#include "SPK_DameBoss.h"
#if NEWXSHOP
#include "SPK_xShop.h"
#include "InterfaceElemental.h"
#endif
#include "SPK_FixSolution.h"
#include "SPK_InterSS2.h"
#include "NewsBoard.h"
#include "EmojiSystem.h"
//add Notice Select Server , Tue
#include "Notice.h"
//----------------------------------

using namespace std;
Interface gInterface;

void Interface::DrawAnimatedGUI(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}
void Interface::RenderObjectSystem()
{	
	gRanking.BingImg();
	gFpsView.RenderObjectFps();
	#if RELIFE
	G_SpkRelife.BingRelife();
	#endif
	#if(HT_THUE_FLAG)
	ThueFlag.Bind();
#	endif	
	#if(NOTICE_PKSYSTEM)
	gPKSys.m_DataNoticePK.clear();
	#endif
	#if BXHDAME
	gDmgBoss.DAMECLEAR();
	#endif
	gTaiKhoan.BinObeject();
	gPartySearch.loadBind();
	InitEncDec();

	#if ADD_POINT
	gAddPoint.BingObjectRenderAddPoint();
	#endif
	this->BindObject(FormPassLock, 0x7AA3, 170, 21, -1, -1);
	this->BindObject(CTCMINI_MAIN,		0x7A5A, 222, 260, 205, -1);
	this->BindObject(CTCMINI_TITLE,		0x7A63, 230, 67, -1, -1);
	this->BindObject(CTCMINI_FRAME,		0x7A58, 230, 15, -1, -1);
	this->BindObject(CTCMINI_FOOTER,	0x7A59, 230, 50, -1, -1);
	this->BindObject(CTCMINI_DIV,		0x7A62, 223, 21, -1, -1);
	this->BindObject(CTCMINI_CLOSE,		0x7EC5, 36, 29, -1, -1);

	this->BindObject(TMC_MAIN,			0x7A5A, 222, 230, 205, -1);
	this->BindObject(TMC_TITLE,			0x7A63, 230, 67, -1, -1);
	this->BindObject(TMC_FRAME,			0x7A58, 230, 15, -1, -1);
	this->BindObject(TMC_FOOTER,		0x7A59, 230, 50, -1, -1);

	#if (RESETCHANGE)
	this->BindObject(eRESETCHANGE, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eBOTON1, 0x7E54, 52, 25, -1, -1);
	this->BindObject(eBOTON2, 0x7E54, 52, 25, -1, -1);
	this->BindObject(eBOTON3, 0x7E54, 52, 25, -1, -1);
	this->BindObject(eBOTON4, 0x7E54, 52, 25, -1, -1);
	this->BindObject(eBOTON5, 0x7E54, 52, 25, -1, -1);
	#endif
	//Jewel Bank
	this->BindObject(eJewelBank_MAIN	, 0x7A5A, 222, 300, -1, -1);
	this->BindObject(eJewelBank_TITLE	, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eJewelBank_FRAME	, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eJewelBank_FOOTER	, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eJewelBank_CLOSE	, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eJewelBank_NEXT	, BTN_PREV_NEW, 20, 22, -1, -1);
	this->BindObject(eJewelBank_PREV	, BTN_NEX_NEW, 20, 22, -1, -1);
	
	this->BindObject(RankingBtnNext, BTN_PREV_NEW, 20, 22, -1, -1);
	this->BindObject(RankingBtnPrev, BTN_NEX_NEW, 20, 22, -1, -1);

	this->BindObject(eWindowMocNapClose, 0x7EC5, 36, 29, -1, -1);

	for (int i = 0; i < 150; i++)
	{
		this->BindObject(eJewelBank_WITHDRAW + i, 31743, 16, 16, -1, -1);
	}
		
	this->BindObject(eJewelBank_Count, 0x17919, 32, 16, -1, -1);

	#if(VONGQUAY_NEW)
	this->BindObject(eLuckySpin, 31461, 640, 419, -1, -1);  // 31461
	this->BindObject(eLuckySpinRoll, 0x7E54, 52, 25, -1, -1);
	this->BindObject(eLuckySpinClose, 0x7EC5, 36, 29, -1, -1);
	#endif

	this->BindObject(eMenu_MAIN,    0x7A5A, 222, 377, 205, -1);
	this->BindObject(eMenu_TITLE,	0x7A63, 230, 67, -1, -1);
	this->BindObject(eMenu_FRAME,	0x7A58, 230, 15, -1, -1);
	this->BindObject(eMenu_FOOTER,	0x7A59, 230, 50, -1, -1);
	this->BindObject(eMenu_DIV,		0x7A62, 223, 21, -1, -1);
	this->BindObject(eMenu_CLOSE,   0x7EC5, 36,  29, -1, -1);
	this->BindObject(SPK_ITEM_BLOCK,  0xC942, 13, 13, -1, -1);
	this->BindObject(eCustomShop_CLOSE,   0x7EC5, 36,  29, -1, -1);
	//add News, Tue
	this->BindObject(eMenu_NEW_BOARD, 71545, 65, 26, -1, -1);
	this->BindObject(eNEWS_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eNEWS_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eNEWS_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eNEWS_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eNEWS_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eNEWS_INFOBG, 0x787D, 170, 21, -1, -1);
	this->BindObject(eNEWS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eNEWS_BACK, 0x7A5E, 128, 29, -1, -1);
	//================
	//add Notice Select Server, Tue
	//this->BindObject(eNotice_MAIN, 71545, 65, 26, -1, -1);
	this->BindObject(eNotice_MAIN, 0x7A5A, 222, 303, -1, -1);
	this->BindObject(eNotice_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eNotice_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eNotice_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eNotice_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eNotice_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(ePrevNotice, BTN_PREV_NEW, 20, 22, -1, -1);
	this->BindObject(eNextNotice, BTN_NEX_NEW, 20, 22, -1, -1);
	//================
	for (int i = 0; i < ButtonMenuSpk; ++i) 
	{
		this->BindObject(eMenu_OPT1 + i, 0x7A5E, 108, 29.5f, -1, -1);
	}

	this->BindObject(SPK_MAIN_ATM	, 0xC942, 15, 15, -1, -1);
	this->BindObject(SPK_MAIN_ARESET, 0xC942, 15, 15, -1, -1);
	this->BindObject(SPK_MAIN_RSCAM,  0xC942, 15, 15, -1, -1);
	this->BindObject(SPK_MAIN_ZMCAM,  0xC942, 15, 15, -1, -1);
	this->BindObject(SPK_MAIN_BOXSK,  0xC942, 15, 13, -1, -1);

	for (int i = 0; i < MAX_EVENTTIME; ++i) //Button Move EventTime
	{
		this->BindObject(SPK_MOVE_EVENT + i, 0x7906, 16, 12, -1, -1);
	}

	this->BindObject(eTIME, 30847, 106, 22, -10, 359);
	//--
	this->BindObject(eMAIN_RANKING, 0x7A5A, 445, 364, 205, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);

	this->BindObject(eCommand_MAIN, 0x7A5A, 222, 300, 205, -1);
	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, 205, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);
	//Custom Store
	this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
	this->BindObject(eSTORE_CLOSE, 0x7BFD, 108, 30, -1, -1);
	this->BindObject(ePLAYER_POINT, 31460, 3, 3, -1, -1);
	this->BindObject(eNULL_MAP, 31461, 128, 128, -1, -1);
	
	this->BindObject(eCamera3DInit, 31659, 17, 18, -1, -1);
	this->BindObject(eCamera3DSwitch, 31659, 17, 18, -1, -1);
	this->Data[eTIME].OnShow = true;
	if(gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		this->BindObject(ButtonSettings, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStart, 51522, 19, 19, -1, -1);
		this->BindObject(ButtonStop, 51522, 19, 19, -1, -1);
	}
	else
	{
		this->BindObject(ButtonSettings, 31461, 16, 13.3, -1, -1);
		this->BindObject(ButtonStart, 31461, 16, 13.3, -1, -1);
		this->BindObject(ButtonStop, 31461, 16, 13.3, -1, -1);
	}
	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);
	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
		case 0: 
		this->BindObject(eMenu, 31461, 19, 19, -1, -1);
		break;
		case 2:
		this->BindObject(eMenu, 0x7906, 14, 13, -1, -1);
		this->BindObject(MINIMAP_FRAME, 31608, 154, 162, -10, 359);
		this->BindObject(MINIMAP_TIME_FRAME, 31609, 134.0, 37.0, -10, 359);
		this->BindObject(MINIMAP_BUTTOM, 31617, 38.0f, 24.0f, -10, 569);
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 385);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 385);
		this->BindObject(eParty, iNewParty, 25, 25, 348, 449);
		this->BindObject(eCharacter, iNewCharacter, 25, 25, 379, 449);
		this->BindObject(eInventory, iNewInventory, 25, 25, 409, 449);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);
		this->BindObject(eFastMenu, iNewFastMenu, 53, 19, 5, 432);
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);

		this->BindObject(eZen, 0x17915, 113, 19, -1, -1);
		this->BindObject(eMainMenuSet, 0x17916, 160, 19, -1, -1);
		break;
		case 4:
		this->BindObject(eMenu, 31461, 19, 19, -1, -1);
		//Ex700
		this->BindObject(chatbackground, 51545, 300.0f, 128.0f, -10, 569);
		this->BindObject(eShop, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eCharacter, 51522, 19.5f, 19.5f, -1, -1);
		this->BindObject(eInventory, 51522, 19.5f, 19.5f, -1, -1);
		break;
		default:
		//this->BindObject(eMenu, BTN_MENU_OFFSET, 16, 13, -1, -1);
		break;
	}
	this->ClickTime = 0;

	SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	SetRange((LPVOID)0x008423C3, 5, ASM::NOP);
	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);
	#if CMUI_RENDER_ZEN
	SetRange((LPVOID)0x00835116, 5, ASM::NOP);
	SetOp((LPVOID)0x00835116, this->DrawZenAndRud, ASM::CALL);
	#endif
}
void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	pInitModelData2();
}

int Interface::LoadImg(char * Folder, DWORD ID)
{
	return pLoadImage(Folder, ID, GL_LINEAR, GL_CLAMP, 1, 0);
}


void LoadMapRender()
{
	//gCharList.ImgLoad(); // Tam OFF
	LoadBitmapA("SPK\\MainBoard.tga", 0x1791E, GL_LINEAR, 0x2901, 1, 0);
	LoadBitmapA("SPK\\MinRanking.tga", 0x1791F, GL_LINEAR, 0x2901, 1, 0);
	LoadBitmapA("SPK\\Text_RankingBoard.tga", 0x17920, GL_LINEAR, 0x2901, 1, 0);
	LoadBitmapA("SPK\\Text_EventBoard.tga", 0x17921, GL_LINEAR, 0x2901, 1, 0);
	LoadBitmapA("SPK\\Status.tga", 0x17922, GL_LINEAR, 0x2901, 1, 0);
	LoadBitmapA("SPK\\Text_DungLuyen.tga", 0x17923, GL_LINEAR, 0x2901, 1, 0);
	LoadBitmapA("SPK\\SPK_Porcento.tga", 531126, 0x2601, 0x2901, 1, 0);
	LoadBitmapA("SPK\\Page_Porcento.tga", 0x1791A, 0x2601, 0x2901, 1, 0);
	LoadBitmapA("SPK\\SPK_NumberWhite.tga", 31337, 9729, 10496, 1, 0);
	LoadBitmapA("SPK\\SPK_NumberYello.tga",	BG_IMG_NUM2, GL_LINEAR, GL_CLAMP, 1, 0);
	//tueadd
	pLoadImage("Local\\mutue-mini-season19.tga", 12359, 0x2601, 0x2901, 1, 0);
	//endadd
}


void Interface::LoadImages()
{
	LoadMapRender();
	gRanking.LoadImg();
	g_DamageRender.Load();
	#if(SPK_HONHOAN)
	gHonHoan.LoadImageHonHoan();
	#endif
	#if SPK_DANHHIEU
	gDanhHieu.LoadImageDanhHieu();
	#endif
	#if SPK_QUANHAM
	gQuanHam.LoadImageQuanHam();
	#endif
	#if SPK_TUCHAN
	gTuLuyen.LoadImageTuLuyen();
	#endif
	#if SPK_NEWVIP 
	gNewVip.LoadImageNewVip();
	#endif
	#if(SPK_STYLE == 1)
	mSpk.LoadImg();
	#endif
	LoadBitmapA("SPK\\CheckBox.tga", 0x17919, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("SPK\\character_ex.tga", 0x1791C, 0x2601, 0x2901, 1, 0);
	if(gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\Item_Money.jpg", 0x17915, GL_LINEAR, GL_CLAMP, 1, 0);			//Zen
	}
	else
	{
		pLoadImage("SPK\\iMoney.tga", 0x17915, GL_LINEAR, GL_REPEAT, 1, 0);
	}
    pLoadImage("SPK\\Other\\SPK-logo.tga", 0x17905, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("SPK\\Other\\ButtonA.tga", 0x17908, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("SPK\\Other\\ButtonB.tga", 0x17909, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("SPK\\Other\\CTC.tga", 0x17912, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("SPK\\Other\\ATM.tga", 0x17918, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("SPK\\Other\\MessSPK.tga", 0x1791B, GL_LINEAR, GL_REPEAT, 1, 0);
	LoadBitmapA("SPK\\Text_CuongHoa.tga", 0x1792D, GL_LINEAR, 0x2901, 1, 0);
	pLoadImage("SPK\\CTCMini\\CharPoint.tga"						, 32506  , GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("SPK\\CTCMini\\OtherCharPoint.tga"				, 32507  , GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("SPK\\CTCMini\\CTCMiniMap.tga"					, 32583  , GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("SPK\\CTCMini\\UiCtc.tga"							, 32584  , GL_LINEAR, GL_CLAMP, 1, 0);	
	pLoadImage("SPK\\CTCMini\\StartCTC.tga"						, 32585  , GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("SPK\\CTCMini\\WinCTC.tga"						, 32586  , GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("SPK\\CTCMini\\LoseCTC.tga"						, 32589  , GL_LINEAR, GL_CLAMP, 1, 0); 
	pLoadImage("SPK\\CTCMini\\DialogCTC.tga"						, 32588  , GL_LINEAR, GL_CLAMP, 1, 0);
//	LoadBitmapA("SPK\\MacroUI\\MacroUI_BBlock.tga",		151560, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("SPK\\Next.tga"	, 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	
	#if(PARTYSEARCH==1)
	gInterface.LoadImg("SPK\\PartySearch_Title.tga", 0x7E98);
	gInterface.LoadImg("SPK\\Info_Block.tga", 0x7E99);
	#endif
	pLoadImage("SPK\\mini_map_ui_party.tga", 61520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("SPK\\Nop\\none.tga", 31461, 0x2601, 0x2900, 1, 0);
	pLoadImage("SPK\\BtnMoveM.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);
	pLoadImage("SPK\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("SPK\\Maps\\edBtUcx_1.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("SPK\\Maps\\edBtUcx_2.tga", 31464, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("SPK\\Maps\\BackGrMaps.tga", 31465, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("SPK\\Maps\\mini_map_ui_blacksmith.tga", 31466, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("SPK\\Maps\\mini_map_ui_Potion.tga", 31467, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("SPK\\Maps\\mini_map_ui_baul.tga", 31468, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("SPK\\Maps\\mini_map_ui_Que.tga", 31469, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("SPK\\Maps\\mini_map_ui_monsterred.tga", 31471, 0x2601, 0x2900, 1, 0); //-- Dungeon Red
	pLoadImage("SPK\\Maps\\mini_map_ui_monsterblue.tga", 31472, 0x2601, 0x2900, 1, 0); //-- Dungeon Blue
	pLoadImage("SPK\\Maps\\Frame.tga" , 50000, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\Maps\\map_radar.tga", 61519, 0x2601, 0x2901, 1, 0);

	pLoadImage("SPK\\ToolTips\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\ToolTips\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\ToolTips\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\ToolTips\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\ToolTips\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\ToolTips\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\ToolTips\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\ToolTips\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0);

	pLoadImage("SPK\\PopUp\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\PopUp\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\PopUp\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\PopUp\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\PopUp\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\PopUp\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\PopUp\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\PopUp\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0);

	pLoadImage("SPK\\popup_line_m.tga", 71519, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\Render_buttom_1.tga", 71521, 0x2601, 0x2901, 1, 0); 
	pLoadImage("SPK\\Render_buttom_2.tga", 71522, 0x2601, 0x2901, 1, 0); 
	pLoadImage("SPK\\Render_buttom_3.tga", 71524, 0x2601, 0x2901, 1, 0); 
	pLoadImage("SPK\\RenderBits_Sound.tga", 71523, 0x2601, 0x2901, 1, 0); 
	pLoadImage("SPK\\newui_option_volume01.tga", 31596, 0x2601, 0x2901, 1, 0); 
	pLoadImage("SPK\\newui_option_volume02.tga", 31597, 0x2601, 0x2901, 1, 0); 

	pLoadImage("SPK\\Party\\newui_Party_Back.tga", 81520, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\Party\\newui_Party_flag.tga", 81521, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\Party\\newui_Party_HpBar.jpg", 81522, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\Party\\newui_Party_ManaBar.jpg", 81523, 0x2601, 0x2901, 1, 0);
	pLoadImage("SPK\\Party\\newui_Party_X.tga", 81524, 0x2601, 0x2901, 1, 0);

	LoadBitmapA("SPK\\newui_SW_Minimap_Frame.tga", 31608, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\newui_SW_Time_Frame.tga", 31609, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("SPK\\newui_SW_MiniMap_Bt_clearness.jpg", 31617, GL_LINEAR, GL_CLAMP, 1, 0);
	//
	//tue add Notices
	pLoadImage("Custom\\Interface\\Notice.jpg", 0x9969, 0x2601, 0x2900, 1, 0);
	//add News, Tue
	pLoadImage("Custom\\Interface\\ButtonCharacterInfo.tga", 71545, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\NewsBoard_Title.tga", 0x787D, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\Info.tga", 0x7915, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\Info2.tga", 0x7916, 0x2601, 0x2900, 1, 0);
	//=====================================
	//add Emoji Chat, Tue
	gEmojis.LoadImages(); //> Agregar esto
	//-----------------------------
	switch(gProtect.m_MainInfo.CustomInterfaceType) 
	{
		case 0:
		LoadBitmapA("SPK\\MacroUI\\MacroUI_BSetup.tga",		51546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_BStart.tga",		51547, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_Stop.tga",		51548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_Menu.tga",		51553, GL_LINEAR, GL_CLAMP, 1, 0);
		//LoadBitmapA("SPK\\MacroUI\\MacroUI_MenuNew.tga", BTN_MENU_OFFSET, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
		case 2:
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_weapon(L).tga", 0x7A82, GL_LINEAR, GL_CLAMP, 1, 0);	//VuKhi 1
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_weapon(R).tga", 0x7A83, GL_LINEAR, GL_CLAMP, 1, 0);	//VuKhi 2
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_cap.tga", 0x7A7F, GL_LINEAR, GL_CLAMP, 1, 0);			//Mu
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_upper.tga", 0x7A84, GL_LINEAR, GL_CLAMP, 1, 0);		//Au
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_lower.tga", 0x7A86, GL_LINEAR, GL_CLAMP, 1, 0);		//Quan
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_gloves.tga", 0x7A85, GL_LINEAR, GL_CLAMP, 1, 0);		//Gang
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_boots.tga", 0x7A7E, GL_LINEAR, GL_CLAMP, 1, 0);		//Giay
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_wing.tga", 0x7A81, GL_LINEAR, GL_CLAMP, 1, 0);			//Wing Slot 7
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_fairy.tga", 0x7A80, GL_LINEAR, GL_CLAMP, 1, 0);		//SlotPet
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_necklace.tga", 0x7A88, GL_LINEAR, GL_CLAMP, 1, 0);		//Pen
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\newui_item_ring.tga", 0x7A87, GL_LINEAR, GL_CLAMP, 1, 0);			//Ring
		LoadBitmapA("SPK\\InterfaceS2\\Inventory\\setitem.jpg", 0x17916, GL_LINEAR, GL_CLAMP, 1, 0);				//TopLine


		LoadBitmapA("SPK\\MacroUI\\MacroUI_MenuNew.tga", BTN_MENU_OFFSET, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Item_Back01.tga", 61522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Menu_left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("SPK\\InterfaceS2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Menu_right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("SPK\\InterfaceS2\\Menu_middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		LoadBitmapA("SPK\\InterfaceS2\\Menu_Red.jpg", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("SPK\\InterfaceS2\\Menu_Green.jpg", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("SPK\\InterfaceS2\\Menu_Blue.jpg", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		LoadBitmapA("SPK\\InterfaceS2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Boton\\Menu_fastmenu.jpg", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Boton\\Menu_Inventory.jpg", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Boton\\Menu_Character.jpg", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Boton\\Menu_Party.jpg", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Boton\\Menu_friend.jpg", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Boton\\Menu_guild.jpg", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\skillboxR.jpg", 0x700003, 0x2601, 0x2901, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\newui_skill2.jpg", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\newui_non_skill2.jpg", 31315, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Menu\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Menu\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Menu\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterfaceS2\\Chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
		case 4:
		LoadBitmapA("SPK\\InterSPK\\BACKGROUND.tga", BG_IMG_OFFSET, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\BLUE_MP_128.tga", MP_IMG_OFFSET, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\BLACK_MP_128.tga", MP_IMG_ENDSET, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\GREEN_HP_128.tga", HP_IMG_GRESET, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\RED_HP_128.tga", HP_IMG_REDSET, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\BLACK_HP_128.tga", HP_IMG_ENDSET, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\HEADER_DRA_L.tga", BG_IMG_HDLSET, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\HEADER_DRA_R.tga", BG_IMG_HDRSET, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\Main_I5.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\Main_I4.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\newui_skillbox2.tga", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\newui_skillbox1.tga", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\Main_Skillbox.tga", 51500, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("SPK\\InterSPK\\Buttom_empty_small.tga", 61525, GL_LINEAR, GL_CLAMP, 1, 0);
		//LoadBitmapA("SPK\\InterSPK\\newui_number1.tga", 6829, GL_LINEAR, GL_CLAMP, 1, 0); Number Slot Skill 1 2  34
		LoadBitmapA("SPK\\InterSPK\\chat_bg01.tga", 61550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\chat_bg02.tga", 61551, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\chat_bg03.tga", 61534, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\Chat_I5.tga", 61548, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("SPK\\InterSPK\\newui_chat_back.tga", 61549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\Main_IE_Buttons.tga", 0x901, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\winPet_I1.tga", 61545, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\InterSPK\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("SPK\\MacroUI\\MacroUI_Main.tga",		51550, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_BSetup.tga",		51546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_BStart.tga",		51547, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_Stop.tga",		51548, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_Bar.jpg",		51549, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_Menu.tga",		51553, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_BResetAuto.tga",	151554, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_BDanhHieu.tga",	151555, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_BReset.tga",		151556, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_BCamera.tga",		151557, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_BAtm.tga",		151558, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\MacroUI\\MacroUI_BInfo.tga",		151559, GL_LINEAR, GL_CLAMP, 1, 0);

		LoadBitmapA("SPK\\Nop\\none.tga", 31303, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\Nop\\none.tga", 31304, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\Nop\\none.tga", 31305, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\Nop\\none.tga", 31306, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\Nop\\none.tga", 31307, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\Nop\\none.tga", 51522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\Nop\\none.tga", 31294, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\Nop\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("SPK\\Nop\\none.tga", 31292, GL_LINEAR, GL_CLAMP, 1, 0);
		break;
	}
	if( gProtect.m_MainInfo.DisableEffectRemake == 0 )
	{
		pLoadImage("Effect\\flare01.jpg", 52002, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareRed.jpg", 52230, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\JointLaser01.jpg", 52224, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\hikorora.jpg", 52379, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flareBlue.jpg", 52229, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\bostar3_R.jpg", 32614, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\line_of_big_R.jpg", 32772, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Effect\\flare01.jpg", 42134, GL_LINEAR, GL_REPEAT, 1, 0);
	}
	//--
	if(gProtect.m_MainInfo.DisableCustomCloack == 0)
	{
		gCloak.LoadTexture();
	}
	
	//--
	#if(NOTICE_MES==1)
	pDrawMessage ( Notice_1, 0 );
	pDrawMessage ( Notice_2, 1 );
	#endif
	pLoadSomeForm();
}

void Interface::WindowsKG()
{	
	char interaltas[500];
	if (gInterface.validar == 0)
	{
		sprintf_s(interaltas, sizeof(interaltas), "%s - $%s", gProtect.m_MainInfo.WindowName, gToolKit.QNumberFormat(CoinAtm));
		SetWindowText(pGameWindow, interaltas);
	}
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawGUI3(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	RenderBitmap(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}
void Interface::ResetDrawIMG(short ObjectID)
{
	if( this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1 )
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}

void Interface::Work()
{
	//tueadd
	float x2 = 230.0f;
	float y2 = 340.0f;
	float w2 = 180.0;
	float h2 = 80.0;
	RenderBitmap(12359, x2, y2, w2, h2, 0, 0, 1, 1, 1, 1, 1.5);
	gInterface.DrawFormat(eGold, 5.0f , 320.0f, 25.0f, 0, "* Phát hiện hack, Zalo Admin nhận thưởng: (+84)813.583.027 ");
	gInterface.DrawFormat(eGold150, 5.0f , 315.0f, 25.0f, 0, "* Các Lệnh thường dùng: /tanthu, /reset, /taydiem ...");
	//---------

	nInterface.RenderWindow();
	gCustomHarmony.DrawHarmony();
	gMixDL.DrawWindows();
	gFixSolution.StartLoadZoomPos();
	#if(B_MOCNAP)
	gNewMocNap.DrawWindowMocNap();
	#endif	
	#if NEWXSHOP
	gNewCashShop.DrawShop();
	gElemental.DrawMessageBox();
	#endif
	#if RELIFE
	G_SpkRelife.CallWindows();
	#endif
	#if(SPK_ITEMTRADE)
	gItemTrade.DrawDoiItem();
	#endif
	#if ADD_POINT
	gAddPoint.DrawStatsAddWindow();
	#endif
	#if(HT_THUE_FLAG)
	ThueFlag.Draw();
	#endif
	#if CHAOS_RATE_FIX
	ChaosBoxMainProc();
	#endif
	#if(NOTICE_PKSYSTEM)
	gPKSys.DrawNoticePKSystem();
	#endif
	#if BXHDAME
	gDmgBoss.DAMEDRAW();
	#endif
	#if(CB_EventArenaPvP)
	gCBArenaPvP.Draw();
	#endif	
	gTaiKhoan.DrawVoidDoiPass();
	#if (CongHuongV2)
	gCongHuong2.DrawWindowCongHuong();	
	#endif
	gObjUser.Refresh();
	#if (RESETCHANGE==1)
	gResetChange.DrawResetChange();
	#endif
	gBoxAtm.DrawAtmWork();
	#if(THANMA)
	gThanMa.DrawTMAllWindows();
	#endif
	gToolKit.RunAntiHack();
	//add News, Tue
	//gInterface.DrawNewsWindow();
	gNewsBoard.DrawNewsWindow();
	//--------------------
	//add Notice Select Server , Tue
	gCustomNoticeInfo.DrawNoticeWindow();
	//-------------------------------

	if(gObjUser.lpViewPlayer->WeaponFirstSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponFirstSlot <= ITEM2(4,255)||gObjUser.lpViewPlayer->WeaponSecondSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponSecondSlot <= ITEM2(4,255))
	{
		gInterface.PetY = 38.0f;		
	}
	else
	{
		gInterface.PetY = 26.0f;
	}

	if(gObjUser.lpViewPlayer->PetSlot!= -1)
	{
		gInterface.PetX = 61.0f;
	}
	else
	{
		gInterface.PetX = 0;
	}
	if (gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		gInterface.DrawInterfaceDragonLS3();
		gInterface.DrawInterfaceDragonRS3();
	}
	#if(VONGQUAY_NEW)
	gLuckySpin.Draw();
	#endif
	#if(SPK_STYLE == 1)
	mSpk.HienThiKhuonNhanVat();
	#endif

#if(CTCMINI)
	gCtcMini.DrawCTCMiNiMap();	
	gCtcMini.DrawCTCMiniWindow();	
#endif
	gRanking.Draw();
	gCETime.DrawEventTimePanelWindow();
	gInterface.DrawMenu();
	gInterface.DrawMenuOpen();
	gCustomCommandInfo.DrawCommandWindow();
	gInterface.DrawConfirmOpen();
	gCustomJewelBank.DrawJewelBankWindow();

	#if(CUSTOM_GUILD_UPGRADE)
	GuildUpgrade.Draw();
	#endif

	#if(SPK_STYLE == 0)
	gInterface.WindowsKG();
	#endif

	#if SO_LUONG_BOSS
	gActiveInvasions.render();
	#endif

	#if(PARTYSEARCH==1)
	gPartySearch.DrawPartySearchWindow();
	gPartySearch.DrawPartySettingsWindow();
	#endif

	#if(SPK_HONHOAN)
	gHonHoan.DrawWindowNangCapHonHoan();
	#endif
	#if SPK_DANHHIEU
	gDanhHieu.DrawWindowNangCapDanhHieu();
	#endif
	#if SPK_QUANHAM
	gQuanHam.DrawWindowNangCapQuanHam();
	#endif
	#if SPK_TUCHAN
	gTuLuyen.DrawWindowNangCapTuLuyen();
	#endif
	#if SPK_NEWVIP
	gNewVip.DrawWindowNangCapNewVip();
	#endif
	if(gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		gInterface.DrawInterfaceCustom();
	}
	else
	{
		pDrawInterface();
	}

	if  (gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		gInterface.DrawInterfaceS2Menu();
	}
	if( GetForegroundWindow() == pGameWindow )
	{	
		if (GetKeyState('H') & 0x4000) 
		{
			if (gInterface.Data[eChangePass_Main].OnShow)
			{
				return;
			}
			else
			{
				gCETime.OpenWindow();
			}
		}
		if (GetKeyState('O') & 0x4000) 
		{
			if (gInterface.Data[eChangePass_Main].OnShow)
			{
				return;
			}
			else
			{
				gInterface.OpenConfig(0);
			}
		}

		if (GetKeyState('J') & 0x4000)
		{
			if (gInterface.Data[eChangePass_Main].OnShow)
			{
				return;
			}
			else
			{		
				gCustomJewelBank.OpenWindow();
			}
		}

		if (GetKeyState(VK_UP) & 0x4000) 
		{
			gInterface.OpenConfig(1);
		}
		else if (GetKeyState(VK_DOWN) & 0x4000) 
		{
			gInterface.OpenConfig(1);
		}
		
		if (GetKeyState(VK_F6) & 0x4000) 
		{
			gInterface.SwitchChatExpand();
		}

		if (GetKeyState(VK_F5) & 0x4000)
		{
			gInterface.SwitchHideDanhHieu();
		}
		if (GetKeyState(VK_F7) & 0x4000) 
		{
			gInterface.SwitchAntiLag2();
			gInterface.SwitchAntiLag1();
		}
		
		if (GetKeyState(VK_F8) & 0x4000) 
		{
			if((GetTickCount()-gInterface.Data[eMenu_MAIN].EventTick) > 300)
			{
				if (gInterface.CheckMenuWindow())
				{
					gInterface.Data[eMenu_MAIN].EventTick = GetTickCount();
					gInterface.CloseMenuWindow();
				}
				else
				{
					gInterface.Data[eMenu_MAIN].EventTick = GetTickCount();
					gInterface.CloseMenuWindow();
					gInterface.CloseEventTimeWindow(); //event time
					gInterface.Data[ePARTYSEARCH_MAIN].OnShow == false;//setting searchparty
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;//searchpeary
					gInterface.Data[eJewelBank_MAIN].OnShow == false;//searchpeary
					gInterface.Data[eMAIN_RANKING].OnShow == false;//searchpeary
					gInterface.OpenMenuWindow();
				
				}
			}
		}
		
		if (GetKeyState(VK_END) <0 ) 
		{
			{		
				gObjUser.ToggleAuto();
			}

		}

		if (GetKeyState(VK_INSERT) <0 ) 
		{
			{		
				gObjUser.ToggleAutoTron();
			}

		}
		if (GetKeyState(VK_F10) & 0x4000) 
		{
			gInterface.SwitchCamera();
		}
		if (GetKeyState(VK_F11) & 0x4000) 
		{
			gInterface.CameraInit();
		}

		if (GetKeyState(VK_F12) & 0x4000)
		{
			if (gTrayMode.TempWindowProc == NULL)
			{
				gTrayMode.TempWindowProc = SetWindowLong(pGameWindow, GWL_WNDPROC, (long)gController.Window);
			}
			// ----
			gTrayMode.SwitchState();
		}

		if (GetKeyState(VK_ESCAPE) < 0) 
		{
			if (gInterface.Data[eWindowHarmony].OnShow == true)
			{
				gInterface.Data[eWindowHarmony].OnShow = false;

				pCloseWindow(pWindowThis(), Inventory);
			}
			if (gInterface.Data[eWindowDungLuyenItem].OnShow == true)
			{
				gInterface.Data[eWindowDungLuyenItem].Close();
				pCloseWindow(pWindowThis(), Inventory);
			}
			if (gInterface.Data[ePARTYSEARCH_MAIN].OnShow == true)
			{
				gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}
			#if CongHuongV2
			if(gInterface.Data[eWindow_CongHuong].OnShow == true)
			{
				gInterface.Data[eWindow_CongHuong].Close();
				pCloseWindow(pWindowThis(), Inventory);
				
			}
			#endif
			if (gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == true)
			{
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}

			if (gInterface.CheckMenuWindow())
			{
				gInterface.CloseMenuWindow();
			}
			if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true)
			{
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				
				if(gProtect.m_MainInfo.CustomInterfaceType != 4)
				{
					pSetCursorFocus = false;
				}
			}
		}
	}
	char ClassName[11] = { 0 };
	memcpy(ClassName, gObjUser.lpPlayer->Name, sizeof(gObjUser.lpPlayer->Name));
	float PosMainX = 15;
	float PosMainY = 280;
	int gZoomCurrent = (*(float*)(0x00D27BFC));
	if (strcmp(ClassName, "SPK") == 0)
	{
					gCentral.gInfoBox(PosMainX - 5, PosMainY - 10 , 30, 46, 200, 0, 0);
		gInterface.DrawFormat(eWhite, PosMainX - 25, PosMainY + -8, 50, 4, "%d - Z", gZoomCurrent);;
		gInterface.DrawFormat(eWhite, PosMainX - 25, PosMainY + 2, 50, 4, "%d - X", pCursorX);;
		gInterface.DrawFormat(eWhite, PosMainX - 25, PosMainY + 12, 50, 4, "%d - Y", pCursorY);;
		gInterface.DrawFormat(eWhite, PosMainX - 25, PosMainY + 22, 50, 4, "%d - M", *(WORD*)0x00E61E18);
					 gFpsView.MainFps(PosMainX - 25, PosMainY + 32, 50, 4);
	}
}

void Interface::SwitchMiniMap()
{
	if((GetTickCount() - gInterface.Data[eNULL_MAP].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[eNULL_MAP].EventTick = GetTickCount();

	if (MiniMap != 0)
	{
		gInterface.DrawMessage(1, gConfig.TSPK_TEXT_ENGINE[0]);
		MiniMap = 0;
		WritePrivateProfileStringA("Graphics","MiniMap","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, gConfig.TSPK_TEXT_ENGINE[1]);
		MiniMap = 1;
		WritePrivateProfileStringA("Graphics","MiniMap","1","./Settings.ini");
	}
}

DWORD	SetInvisibleEffect_PointerYYYYY;
DWORD	SetInvisibleEffect_BuffYYYYY;
DWORD	SetInvisibleEffect_PointerYYYY;
DWORD	SetInvisibleEffect_BuffYYYY;

__declspec(naked) void ItemInvisible11(){
	static DWORD m_aaaaab = 0x0060B37A;
	_asm{
		mov SetInvisibleEffect_BuffYYYYY, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			mov SetInvisibleEffect_PointerYYYYY, esi
			mov esi, SetInvisibleEffect_BuffYYYYY
	}
	if (SetInvisibleEffect_PointerYYYYY != 0x1EA5
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 15)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 30)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 31)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 136)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 137)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 138)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 139)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 140)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 141)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 142)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(12, 143)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 13)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 14)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 16)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 31)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 42)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 13)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 41)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 43)
		|| SetInvisibleEffect_PointerYYYYY != ITEM2(14, 44))
	{
		_asm{
			jmp[m_aaaaab]
		}
	}
}
__declspec(naked) void ItemInvisible22(){
	static DWORD m_aaaaaa = 0x0060B41D;
	_asm{
		mov SetInvisibleEffect_BuffYYYY, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			jmp[m_aaaaaa]
	}
}
DWORD	SetInvisibleEffect_PointerXXX;
DWORD	SetInvisibleEffect_BuffXXX;

Naked(InvisibleEffectXX){
	_asm{
		mov SetInvisibleEffect_BuffXXX, esi
			mov ecx, dword ptr ss : [ebp + 8]
			mov esi, dword ptr ds : [ecx + 0x30]
			mov SetInvisibleEffect_PointerXXX, esi
			mov esi, SetInvisibleEffect_BuffXXX
	}
	if (SetInvisibleEffect_PointerXXX == 0x1EA5 || SetInvisibleEffect_PointerXXX == ITEM2(13, 18)){
		_asm{
			mov SetInvisibleEffect_BuffXXX, 0x0060B37A
				jmp SetInvisibleEffect_BuffXXX
		}
	}
	else{
		_asm{
			mov SetInvisibleEffect_BuffXXX, 0x0060B41D
				jmp SetInvisibleEffect_BuffXXX
		}
	}
}

void InvisibleItem11(){
	SetCompleteHook(0xE9, 0x0060B36A, &ItemInvisible11);
}
void InvisibleItem22(){
	SetCompleteHook(0xE9, 0x0060B36A, &ItemInvisible22);
}
void InvisibleItemXX(){
	SetRange((LPVOID)0x0060B36A, 10, ASM::NOP); //12
	SetCompleteHook(0xE9, 0x0060B36A, &InvisibleEffectXX);
}


void Interface::SwitchAntiLag1()
{
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		if (AntiLag1 != 0)
		{
			gInterface.DrawMessage(1, gConfig.TSPK_TEXT_ENGINE[2]);
			AntiLag1 = 0;
			SetByte(0x0074CD30, 0x55); //Enable Dynamic Effects
			SetByte(0x00771310, 0x55); //Enable Static Effects
			SetByte(0x00608200, 0x55); //Enable Glow Effects
			SetByte(0x00608FB0, 0x55); //Enable Skills Effects
			SetByte(0x005EDFE0, 0x55); //Enable Objects
			SetByte(0x0054A270, 0x55); //Shadows

		}
		else
		{
			gInterface.DrawMessage(1, gConfig.TSPK_TEXT_ENGINE[3]);
			AntiLag1 = 1;
			SetByte(0x0074CD30, 0xC3); //Disable Dynamic Effects
			SetByte(0x00771310, 0xC3); //Disable Static Effects
			SetByte(0x00608200, 0xC3); //Disable Glow Effects
			SetByte(0x00608FB0, 0xC3); //Disable Skills Effects
			SetByte(0x0054A270, 0xC3); //Disable Shadows
			
		}
	}
}
void Interface::SwitchAntiLag2()
{
	if (pPlayerState < GameProcess)
	{
		return;
	}
	if (gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::FriendList)
		|| gInterface.CheckWindow(ObjWindow::MoveList)
		|| gInterface.CheckWindow(ObjWindow::Party)
		|| gInterface.CheckWindow(ObjWindow::Quest)
		|| gInterface.CheckWindow(ObjWindow::NPC_Devin)
		|| gInterface.CheckWindow(ObjWindow::Guild)
		|| gInterface.CheckWindow(ObjWindow::Trade)
		|| gInterface.CheckWindow(ObjWindow::Warehouse)
		|| gInterface.CheckWindow(ObjWindow::ChaosBox)
		|| gInterface.CheckWindow(ObjWindow::CommandWindow)
		|| gInterface.CheckWindow(ObjWindow::PetInfo)
		|| gInterface.CheckWindow(ObjWindow::Shop)
		|| gInterface.CheckWindow(ObjWindow::Inventory)
		|| gInterface.CheckWindow(ObjWindow::Store)
		|| gInterface.CheckWindow(ObjWindow::OtherStore)
		|| gInterface.CheckWindow(ObjWindow::Character)
		|| gInterface.CheckWindow(ObjWindow::DevilSquare)
		|| gInterface.CheckWindow(ObjWindow::BloodCastle)
		|| gInterface.CheckWindow(ObjWindow::CreateGuild)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC)
		|| gInterface.CheckWindow(ObjWindow::SeniorNPC)
		|| gInterface.CheckWindow(ObjWindow::GuardNPC2)
		|| gInterface.CheckWindow(ObjWindow::CastleGateSwitch)
		|| gInterface.CheckWindow(ObjWindow::CatapultNPC)
		|| gInterface.CheckWindow(ObjWindow::CrywolfGate)
		|| gInterface.CheckWindow(ObjWindow::IllusionTemple)
		|| gInterface.CheckWindow(ObjWindow::HeroList)
		|| gInterface.CheckWindow(ObjWindow::ChatWindow)
		|| gInterface.CheckWindow(ObjWindow::FastMenu)
		|| gInterface.CheckWindow(ObjWindow::Options)
		|| gInterface.CheckWindow(ObjWindow::Help)
		|| gInterface.CheckWindow(ObjWindow::FastDial)
		|| gInterface.CheckWindow(ObjWindow::SkillTree)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher1)
		|| gInterface.CheckWindow(ObjWindow::GoldenArcher2)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin1)
		|| gInterface.CheckWindow(ObjWindow::LuckyCoin2)
		|| gInterface.CheckWindow(ObjWindow::NPC_Duel)
		|| gInterface.CheckWindow(ObjWindow::NPC_Titus)
		|| gInterface.CheckWindow(ObjWindow::CashShop)
		|| gInterface.CheckWindow(ObjWindow::Lugard)
		|| gInterface.CheckWindow(ObjWindow::QuestList1)
		|| gInterface.CheckWindow(ObjWindow::QuestList2)
		|| gInterface.CheckWindow(ObjWindow::Jerint)
		|| gInterface.CheckWindow(ObjWindow::FullMap)
		|| gInterface.CheckWindow(ObjWindow::NPC_Dialog)
		|| gInterface.CheckWindow(ObjWindow::GensInfo)
		|| gInterface.CheckWindow(ObjWindow::NPC_Julia)
		|| gInterface.CheckWindow(ObjWindow::NPC_ChaosMix)
		|| gInterface.CheckWindow(ObjWindow::ExpandInventory)
		|| gInterface.CheckWindow(ObjWindow::ExpandWarehouse)
		|| gInterface.CheckWindow(ObjWindow::MuHelper))
	{
		return;
	}
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
	{
		if (AntiLag2 != 0)
		{
			gInterface.DrawMessage(1, gConfig.TSPK_TEXT_ENGINE[4]);

			AntiLag2 = 0;
			InvisibleItem22();
			InvisibleItemXX();

			SetByte((0x0074CD80 + 2), (this->AntiLag2 == 0) ? 1 : 0); // DisableDynamicEffect
			SetByte((0x00771359 + 3), (this->AntiLag2 == 0) ? 1 : 0); // DisableStaticEffect
			DisableGlowEffect == this->AntiLag2 == 1;
			DisableShadow = this->AntiLag2 == 1;
			SetCompleteHook(0xE8, 0x00588661, 0x005655C0); // Dis Wings
			SetCompleteHook(0xE8, 0x00576DDB, 0x005655C0); //Enable Weapons
			SetCompleteHook(0xE8, 0x005883F4, 0x005655C0); //Enable Weapons
			SetByte(0x0051EE20, 0x55); //Enable Cloaks
		}
		else
		{
			gInterface.DrawMessage(1, gConfig.TSPK_TEXT_ENGINE[5]);
			InvisibleItem11();

			SetByte((0x0074CD80 + 2), (this->AntiLag2 == 1) ? 1 : 0); // DisableDynamicEffect
			SetByte((0x00771359 + 3), (this->AntiLag2 == 1) ? 1 : 0); // DisableStaticEffect

			DisableGlowEffect == this->AntiLag2 == 0;
			DisableShadow = this->AntiLag2 == 0;

			MemorySet(0x00588661, 0x90, 0x05); // On Wing
			MemorySet(0x00576DDB, 0x90, 0x05); //Disable Weapons
			MemorySet(0x005883F4, 0x90, 0x05); //Disable Weapons
			SetByte(0x0051EE20, 0xC3); //Disable Cloaks

			AntiLag2 = 1;
		}
	}
}
void Interface::SwitchHideDanhHieu()
{
	if ((GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 1000 || this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

	if (MinimizarOfRank == 0)
	{
		MinimizarOfRank = 1;
	}
	else
	{
		MinimizarOfRank = 0;
	}
}

void Interface::DrawTimeUI()
{
	if (TimerBar == 0 || (this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::FullMap) || this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(ObjWindow::SkillTree)|| this->CheckWindow(ObjWindow::MoveList) || pMapNumber == 34 || pMapNumber == 30))
	{
		return;
	}
}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;
}
int Interface::SPKText(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
    char Buff[2048];
    int BuffLen = sizeof(Buff) - 1;
    ZeroMemory(Buff, BuffLen);

    va_list args;
    va_start(args, Text);
    int Len = vsprintf_s(Buff, BuffLen, Text, args);
    va_end(args);

    int LineCount = 0;

    char* Line = strtok(Buff, "\n");

    while (Line != NULL)
    {
        std::string str = Line;
        std::stringstream ss(str);
        std::string token;
        std::vector<std::string> tokens;
        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }
        std::string num_str = tokens.back();
        int num = atoi(num_str.c_str());
        tokens.pop_back();
        std::string new_str = "";
        if (num < 1000) {
            new_str = num_str;
        }
        else {
            int num_digit = num_str.size();
            int num_commas = (num_digit - 1) / 3;
            int start = 0;
            for (int i = 0; i < num_commas; i++) {
                int end = num_digit - 3 * (i + 1);
                new_str = "," + num_str.substr(end, 3) + new_str;
                start = end;
            }
            new_str = num_str.substr(0, start) + new_str;
        }
        tokens.push_back(new_str);
        std::string new_line = "";
        for (int i = 0; i < tokens.size(); i++) {
            if (i != 0) new_line += " ";
            new_line += tokens[i];
        }
        pDrawColorText(new_line.c_str(), PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
        Line = strtok(NULL, "\n");
    }

    return PosY;
}
bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}
int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}
int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

bool Interface::IsWorkZone2(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}

bool Interface::IsWorkZone(short ObjectID)
{
	if( (pCursorX < this->Data[ObjectID].X || pCursorX > this->Data[ObjectID].MaxX) 
		|| (pCursorY < this->Data[ObjectID].Y || pCursorY > this->Data[ObjectID].MaxY) )
		return false;

	return true;
}

bool Interface::IsWorkZone(float X, float Y, float MaxX, float MaxY)
{
	if ((gObjUser.m_CursorX < X || gObjUser.m_CursorX > MaxX)
		|| (gObjUser.m_CursorY < Y || gObjUser.m_CursorY > MaxY))
	{
		return false;
	}
	// ----
	return true;
}
int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}
float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for (int i = 0; i < Count; i++)
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

float Interface::DrawRepeatGUIScale(short MonsterID, float X, float Y, float ScaleX, float ScaleY, int Count)
{
	float StartY = Y;
	// ----
	for (int i = 0; i < Count; i++)
	{
		this->DrawIMG(this->Data[MonsterID].ModelID, X, StartY, ScaleX, ScaleY);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (this->Data[eMenu].OnShow)
	{
		this->Data[eMenu].OnShow = false;
	}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Character))
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		CloseMenuWindow();
		return;
	}
	
	this->Data[eMenu].OnShow = true;
}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
		this->Data[eMenu].OnClick = true;
		return true;
	}
	this->Data[eMenu].OnClick = false;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eMenu].EventTick = GetTickCount();
	if (CheckMenuWindow())
	{
		CloseMenuWindow();
	}
	else
	{
		CloseCustomWindow();
		OpenMenuWindow();
	}
	return false;
}

void Interface::DrawMenuOpen()
{
	if (gInterface.CheckWindow(Character)
	|| gInterface.CheckWindow(Warehouse)
	|| gInterface.CheckWindow(ChaosBox)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore)
	|| gInterface.CheckWindow(ExpandInventory)
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Trade)
	|| gInterface.CheckWindow(LuckyCoin1)
	|| gInterface.CheckWindow(NPC_ChaosMix))
	{
		return;
	}
	//--
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1 || !this->Data[eMenu_MAIN].OnShow || pCheckWindow(pWindowThis(), 35))
	{
		return;
	}
	pSetCursorFocus = true;
	float MainWidth = 230.0;
	float StartY = 25;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (29.0 / 2);

	this->DrawAnimatedGUI(eMenu_MAIN, StartX, StartY + 2);
	this->DrawAnimatedGUI(eMenu_TITLE, StartX, StartY);
	StartY = this->DrawRepeatGUI(eMenu_FRAME, StartX, StartY + 67.0, 18);
	this->DrawAnimatedGUI(eMenu_FOOTER, StartX, StartY);
	this->DrawAnimatedGUI(eMenu_CLOSE, StartX + MainWidth - this->Data[eMenu_CLOSE].Width, this->Data[eMenu_MAIN].Y - 2);

	if (this->IsWorkZone(eMenu_CLOSE))
	{
		DWORD Color = eGray100;
		if (this->Data[eMenu_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		this->DrawColoredGUI(eMenu_CLOSE, this->Data[eMenu_CLOSE].X, this->Data[eMenu_CLOSE].Y, Color);
		this->DrawToolTip(this->Data[eMenu_CLOSE].X + 5, this->Data[eMenu_CLOSE].Y + 25, gConfig.TSPK_TEXT_ENGINE[26]);
	}

	this->DrawFormat(eGold, StartX + 10, this->Data[eMenu_MAIN].Y + 8, 210, 3, gConfig.TSPK_TEXT_ENGINE[39]);
	this->DrawFormat(eBlue, StartX + 10, this->Data[eMenu_MAIN].Y + 30, 210, 3, gConfig.TSPK_TEXT_ENGINE[106], gObjUser.lpPlayer->Name);
	this->DrawAnimatedGUI(eMenu_DIV, StartX, this->Data[eMenu_MAIN].Y + 33);
	float CurrentMove;
	int BtCount = -1;
	int BtStart = StartY + 48;

	int ObjectIDs[ButtonMenuSpk];
	for (int i = 0; i < ButtonMenuSpk; ++i) 
	{
		ObjectIDs[i] = eMenu_OPT1 + i;
	}
	for(int n = 0; n < ButtonMenuSpk; n++)
	{
		if(gProtect.m_MainInfo.MenuButtons[n] == 1)
		{
			BtCount++;
		}
		else
		{
			continue;
		}

		CurrentMove = 0.0;
		if (IsWorkZone(ObjectIDs[n]))
		{
			if (this->Data[ObjectIDs[n]].OnClick)
			{
				if( gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
				{	
					PlayBuffer(25, 0, 0);
					CurrentMove = 29;
				}
			}
		}
		
		int SoButton = ButtonMenuSpk;
		float CurY = 310.0f;
		COLORREF gColorString = RGB(255, 255, 255);
		HFONT MenuSample;
		if (BtCount %2 == 0)
		{
			this->DrawButton(ObjectIDs[n], StartX	+ 6,	BtStart + (27 * (BtCount/2))		- CurY, 0, CurrentMove);
			gToolKit.CreateFontNew(StartX + 6, BtStart + (27 * (BtCount / 2)) + 9 - CurY, 108, 3,13,700, gConfig.MenuGame_TextVN[((n == SoButton) ? 40 : 1 + n)], gColorString,MenuSample);
			//this->DrawFormat(eWhite								, StartX	+ 6,	BtStart + (30 * (BtCount/2)) + 9	- CurY, 108, 3,gConfig.MenuGame_TextVN[(( n == SoButton) ? 40 : 1 + n)]);	
		}
		else
		{
			this->DrawButton(ObjectIDs[n], StartX + (MainWidth) - (108 )	- 9,	BtStart + (27 * (BtCount/2))		- CurY, 0, CurrentMove);
			gToolKit.CreateFontNew(StartX + (MainWidth)-(108) - 9, BtStart + (27 * (BtCount / 2)) + 9 - CurY, 108, 3, 13, 700, gConfig.MenuGame_TextVN[((n == SoButton) ? 40 : 1 + n)], gColorString, MenuSample);
			//this->DrawFormat(eWhite, StartX + (MainWidth) - (108 )			- 9,	BtStart + (30 * (BtCount/2)) + 9	- CurY, 108, 3,gConfig.MenuGame_TextVN[(( n == SoButton) ? 40 : 1 + n)]);
		}
	}
}

bool Interface::SPKEventClick(DWORD Event)
{
	if (gInterface.Data[eMenu_MAIN].OnShow == false)
	{
		return false;
	}
	else
	{
		DWORD CurrentTick = GetTickCount();
		for (int i = 0; i < ButtonMenuSpk; i++)
		{
			DWORD Delay = (CurrentTick - this->Data[eMenu_OPT1 + i].EventTick);	
			if(gInterface.IsWorkZone(eMenu_OPT1 + i))
			{
				if(Event == WM_LBUTTONDOWN)
				{
					this->Data[eMenu_OPT1 + i].OnClick = true; return true;
				}
				this->Data[eMenu_OPT1 + i].OnClick = false;
				if(Delay < 500)
				{
					return false;
				}
				switch(eMenu_OPT1 + i)
				{
					case eMenu_OPT1: gCETime.OpenWindow();					break;
					case eMenu_OPT2: gNewVip.SendMenuButton();					break;
					case eMenu_OPT3: gRanking.SendMenuButton();						break;
					case eMenu_OPT4: gCustomCommandInfo.OpenCommandWindow()	;		break;
					case eMenu_OPT5: gCustomJewelBank.OpenWindow();					break;
					//case eMenu_OPT6: gTuLuyen.SendMenuButton();						break;
					case eMenu_OPT7: gPartySearch.SwitchPartySettingsWindowState();	break;
					case eMenu_OPT8: gPartySearch.SendMenuButton();					break;
					case eMenu_OPT9: gQuanHam.SendMenuButton();						break;
					case eMenu_OPT10: gDanhHieu.SendMenuButton();					break;
					case eMenu_OPT11: ThueFlag.OpenFlag();							break;
					case eMenu_OPT12: G_SpkRelife.SendMenuButton();					break;
					case eMenu_OPT13: gLuckySpin.SwitchLuckySpinWindowState();		break;
					case eMenu_OPT14: gNewMocNap.OpenWindowMocNap();				break;
					case eMenu_OPT15: gNewCashShop.OpenCustomShop();				break;
					case eMenu_OPT16: break;
					case eMenu_OPT17: gTaiKhoan.OpenWindowsChangePass();			break;
					case eMenu_OPT18: break;
					case eMenu_OPT19: gResetChange.OpenResetChange();				break; 	
					case eMenu_OPT20: gHonHoan.SendMenuButton();					break; 					
					default:
					break;
				}
				this->CloseMenuWindow();			
				gInterface.Data[eMenu_OPT1 + i].EventTick = GetTickCount();
			}
		}
		return false;
	}	
}

bool Interface::MiniMapCheck()
{
	bool visual = false;

	if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
    || gInterface.CheckWindow(8)
    || gInterface.CheckWindow(12)
    || gInterface.CheckWindow(9)
    || gInterface.CheckWindow(7)
    || gInterface.CheckWindow(14)
    || gInterface.CheckWindow(15)
    || gInterface.CheckWindow(60)
    || gInterface.CheckWindow(76) )
	{
		visual = true;
	}
	else
	{
		if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
		{
			visual = true;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
			{
				visual = true;
			}
			else
			{
				if ( gInterface.CheckWindow(27) )
				{
					visual = true;
				}
				else
				{
					if ( gInterface.CheckWindow(13)
					|| gInterface.CheckWindow(16)
					|| gInterface.CheckWindow(3)
					|| gInterface.CheckWindow(21)
					|| gInterface.CheckWindow(6)
					|| gInterface.CheckWindow(22)
					|| gInterface.CheckWindow(23)
					|| gInterface.CheckWindow(24)
					|| gInterface.CheckWindow(4)
					|| gInterface.CheckWindow(18)
					|| gInterface.CheckWindow(10)
					|| gInterface.CheckWindow(5)
					|| gInterface.CheckWindow(25)
					|| gInterface.CheckWindow(26)
					|| gInterface.CheckWindow(19)
					|| gInterface.CheckWindow(20)
					|| gInterface.CheckWindow(58)
					|| gInterface.CheckWindow(59)
					|| gInterface.CheckWindow(62)
					|| gInterface.CheckWindow(73)
					|| gInterface.CheckWindow(68)
					|| gInterface.CheckWindow(69)
					|| gInterface.CheckWindow(70)
					|| gInterface.CheckWindow(66)
					|| gInterface.CheckWindow(75)
					|| gInterface.CheckWindow(74) )
					{
						visual = true;
					}
					else
					{
						if ( gInterface.CheckWindow(79) )
						{
							if ( gInterface.CheckWindow(80) )
							{
								visual = true;
							}
							else
							{
								visual = true;
							}	
						}
					}
				}
			}
		}
	}
  
	if ( gInterface.CheckWindow(77) )
	{
		if ( gInterface.CheckWindow(Warehouse) ||
			gInterface.CheckWindow(ChaosBox) ||
			gInterface.CheckWindow(Store) ||
			gInterface.CheckWindow(OtherStore) ||
			gInterface.CheckWindow(Character))
		{
			visual = true;
		}
		else
		{
			visual = true;
		}
	}
	else if ( gInterface.CheckWindow(78) )
	{
			visual = true;
	}
	return visual;
}

bool Interface::CheckMap()
{
	switch(gObjUser.m_MapNumber)
	{
		case eMapNumber::Lorencia:	return false;	break;
		case eMapNumber::Dungeon:	return false;	break;
		case eMapNumber::Devias:	return false;	break;
		case eMapNumber::Noria:		return false;	break;
		case eMapNumber::LostTower:	return false;	break;
		case eMapNumber::Stadium:	return false;	break;
		case eMapNumber::Atlans:	return false;	break;
		case eMapNumber::Tarkan:	return false;	break;
		case eMapNumber::Elbeland:	return false;	break;
		case eMapNumber::Icarus:	return false;	break;
		case eMapNumber::Trials:	return false;	break;
		case eMapNumber::Aida:		return false;	break;
		case eMapNumber::Crywolf:	return false;	break;
		case eMapNumber::Kanturu1:	return false;	break;
		case eMapNumber::Kanturu3:	return false;	break;
		case eMapNumber::Barracks:	return false;	break;
		case eMapNumber::Calmness:	return false;	break;
		case eMapNumber::Raklion:	return false;	break;
		case eMapNumber::Vulcanus:	return false;	break;
		case eMapNumber::Karutan1:	return false;	break;
		case eMapNumber::Karutan2:	return false;	break;
		default:
		return true;
		break;
	}
}

void Interface::CloseCustomWindow()
{
	this->CloseMenuWindow();
	this->Data[eRankPANEL_MAIN].OnShow		= false;
	this->Data[eEventTimePANEL_MAIN].OnShow = false;
	this->Data[eCommand_MAIN].OnShow		= false;

	this->Data[eWindow_NangCapHonHoan].OnShow	= false;
	this->Data[eWindow_NangCapDanhHieu].OnShow	= false;
	this->Data[eWindow_NangCapQuanHam].OnShow	= false;
	this->Data[eWindow_NangCapTuChan].OnShow	= false;
	this->Data[eChangePass_Main].OnShow			= false;

	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}	
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0); 
	sub_635DE0_Addr();
	sub_635E40_Addr();

	glClear(0x100);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //vi tri bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //chức năng hiển thị BMD
	
	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1,1,1);
	pSetBlend(false);
}

void Interface::DrawConfirmOpen()
{
	if(!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
	{
		this->Data[eCONFIRM_MAIN].OnShow = false;
	}

	if( !this->Data[eCONFIRM_MAIN].OnShow )
	{
		return;
	}

	float StartX;
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		StartX = 205.0f;
	}
	else
	{
		StartX = 25.0f;
	}

	float MainWidth			= 230.0;
	float MainHeight		= 130.0;
	float StartBody			= 90.0;
	float StartY			= 90.0;
	
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

	this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

	this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_OK) )
	{
		int ScaleY = 30;
		if( this->Data[eCONFIRM_BTN_OK].OnClick )
		{
			ScaleY = 60;
		}
		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX+40, (int)StartBody + 70, 0, ScaleY);
	}

	this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, 0);

	if( this->IsWorkZone(eCONFIRM_BTN_CANCEL) )
	{
		int ScaleY = 30;
		if( this->Data[eCONFIRM_BTN_CANCEL].OnClick )
		{
			ScaleY = 60;
		}
		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX+140, (int)StartBody + 70, 0, ScaleY);
	}
}

bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();
	PMSG_ITEM_BUY_RECV pMsg;
	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));
	pMsg.slot = this->ConfirmSlot;
	DataSend((BYTE*)&pMsg,pMsg.header.size);
	this->Data[eCONFIRM_MAIN].OnShow = false;
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	if (Delay < 500)
	{
		return false;
	}
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();
	this->Data[eCONFIRM_MAIN].OnShow = false;
	if(gProtect.m_MainInfo.CustomInterfaceType != 3 || gProtect.m_MainInfo.CustomInterfaceType != 4)
	{
		pSetCursorFocus = false;
	}
	return false;
}

void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}
// ----------------------------------------------------------------------------------------------
bool Interface::CheckWindowEx(int WindowID)
{
	if (WindowID < 0 || WindowID > MAX_WINDOW_EX)
	{
		return 0;
	}
	return this->WindowEx[WindowID];
}


void Interface::SwitchChatExpand()
{

	if((GetTickCount() - gInterface.Data[chatbackground].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
	{
		return;
	}

	gInterface.Data[chatbackground].EventTick = GetTickCount();

	if (SeparateChat != 0)
	{
		gInterface.DrawMessage(1, gConfig.TSPK_TEXT_ENGINE[6]);
		SeparateChat = 0;
		WritePrivateProfileStringA("Setting","SeparateChat","0","./Settings.ini");
	}
	else 
	{
		gInterface.DrawMessage(1, gConfig.TSPK_TEXT_ENGINE[7]);
		SeparateChat = 1;
		WritePrivateProfileStringA("Setting","SeparateChat","1","./Settings.ini");
	}
		gChatExpanded.Switch();
}

void Interface::OpenConfig(int type)
{
	if(type == 0)
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 
			|| this->CheckWindow(ChatWindow) 
			|| this->CheckWindow(MuHelper) 
			|| this->CheckWindow(Inventory) 
			|| this->CheckWindow(Store) 
			|| this->CheckWindow(Character) 
			|| this->CheckWindow(CreateGuild) )
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (pCheckWindow(pWindowThis(), 35))
		{
			pCloseWindow(pWindowThis(), 35);
		}
		else 
		{
			pOpenWindow(pWindowThis(), 35);
		}
	}
	else if(type == 1 )
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 || OpenSwicthSkill == 0)
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (SkillPage == 1)
		{
			SkillPage = 2;
		}
		else
		{
			SkillPage = 1;
		}
	}

	PlayBuffer(25, 0, 0);
}
void Interface::SwitchCamera()
{

	if(gProtect.m_MainInfo.DisableHelper == 0)
	{
		if( (GetTickCount() - gInterface.Data[eCamera3DSwitch].EventTick) < 1000 )
		{
			return;
		}

		if( pMapNumber == 62 )
		{
			gInterface.DrawMessage(1, CameraNotAc);
			gCamera.Restore();
		}

		gInterface.Data[eCamera3DSwitch].EventTick = GetTickCount();

		gCamera.Toggle();

		if (gCamera.getEnabled())
		{
			gInterface.DrawMessage(1, CameraOn);
		}
		else
		{
			gInterface.DrawMessage(1, CameraOff);
		}
	}
}

void Interface::CameraInit(){

	if((GetTickCount() - gInterface.Data[eCamera3DInit].EventTick) < 1000 )
	{
		return;
	}

	gInterface.Data[eCamera3DInit].EventTick = GetTickCount();

	if (gCamera.getEnabled())
	{
		gInterface.DrawMessage(1, CameraDefault);
		gCamera.Restore();
	}
}

bool Interface::Button(DWORD Event, int WinID, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}

	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);

	if (Event == WM_LBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
	}

	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	if (Delay < 500)
	{
		return false;
	}
	this->Data[ButtonID].OnClick = false;
	this->Data[ButtonID].EventTick = GetTickCount();
	return false;
}

void Interface::EventNewInterface_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eFastMenu))
	{
		DWORD Delay = (CurrentTick - this->Data[eFastMenu].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFastMenu].OnClick = true;
			return;
		}
		this->Data[eFastMenu].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFastMenu].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu)) {
				this->CloseWindow(FastMenu);
		}
		else {
			this->OpenWindow(FastMenu);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}
void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(22, 461, gObjUser.lpViewPlayer->MapPosX, 1);
		pDrawInterfaceNumBer(46, 461, gObjUser.lpViewPlayer->MapPosY, 1);

	}
}

bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if (!this->IsWorkZone(ButtonID))
	{
		return false;
	}
	if (Type == true)
	{
		if (!this->Data[ButtonID].Attribute)
		{
			return false;
		}
	}
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[ButtonID].EventTick);
	if (Event == WM_LBUTTONDOWN && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
	}
	if (Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	if (Delay < 500)
	{
		return false;
	}
	this->Data[ButtonID].OnClick = false;
	this->Data[ButtonID].EventTick = GetTickCount();
	return false;
}

void testfunc()
{
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
}

void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();
	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();
	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);
	testfunc();
	glColor3f(1, 1, 1);
	pSetBlend(false);
}

void Interface::LoadImages2(char * Folder, int Code, int Arg3, int Arg4, int Arg5)
{
	pLoadImage(Folder, Code, Arg3, Arg4, Arg5,0);
}
void Interface::DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text)
{
	float StartY = Y;
	float StartX = X;

	gInterface.DrawGUI(ObjMain, StartX, StartY + 2);
	gInterface.DrawGUI(ObjTitle, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ObjFrame, StartX, StartY + 67.0, Repeat);
	gInterface.DrawGUI(ObjFooter, StartX, StartY);

	gInterface.DrawFormat(eGold, StartX + 10, Y + 10, 210, 3, Text);
}

bool Interface::IsWorkZone1(float x, float y, float x2, float y2)
{
	return pCursorX >= x && pCursorX <= x + x2 && pCursorY >= y && pCursorY <= y + y2;
}
void Interface::DrawInterfaceDragonLS3()
{
	if (this->CheckWindow(ObjWindow::CashShop)
		|| this->CheckWindow(ObjWindow::FullMap)
		|| this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList)
		)
	{
		return;
	}
	this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
}

void Interface::DrawInterfaceDragonRS3()
{
	if (this->MiniMapCheck() || (this->CheckWindow(SkillTree) || this->CheckWindow(CashShop) || this->CheckWindow(FullMap)
		|| this->CheckWindow(FastMenu) || this->CheckWindow(FriendList))
		|| pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 34 //Crywolf
		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}
	this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
	if (IsWorkZone(eFastMenu))
	{
		this->DrawToolTip(13, 420, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eFastMenu, 6, 433, 0.0, 0.0);
	}
}
//tue add Notice 
void Interface::DrawGU1(short ObjectID, float PosX, float PosY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY, this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}
//==========================================
//tue add News 
void Interface::DrawNewsWindow()
{
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		if (!this->Data[eNEWS_MAIN].OnShow)
		{
			return;
		}

		float MainWidth = 230.0;
		float MainHeight = 313.0;
		float StartY = 100.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (29.0 / 2);

		this->DrawGUI(eNEWS_TITLE, StartX, StartY);
		this->DrawGUI(eNEWS_FOOTER, StartX, StartY);
		gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
		this->DrawGUI(eNEWS_CLOSE, StartX + MainWidth - this->Data[eNEWS_CLOSE].Width, this->Data[eNEWS_TITLE].Height + this->Data[eNEWS_CLOSE].Height + 2);

		if (this->IsWorkZone1(eNEWS_CLOSE))
		{
			DWORD Color = eGray100;

			if (this->Data[eNEWS_CLOSE].OnClick)
			{
				Color = eGray150;
			}

			this->DrawColoredGUI(eNEWS_CLOSE, this->Data[eNEWS_CLOSE].X, this->Data[eNEWS_CLOSE].Y, Color);
			this->DrawToolTip(this->Data[eNEWS_CLOSE].X + 5, this->Data[eNEWS_CLOSE].Y + 25, "Close");
		}

		this->DrawFormat(eGold, StartX + 10, 110, 210, 3, "News Board");

		if (this->Data[eNEWS_MAIN].Attribute == 0)
		{
			for (int i = 0; i < gNewsBoard.m_LoadedCount; i++)
			{
				this->DrawGUI(eNEWS_INFOBG, StartX + 30, 140 + (i * 21));

				if (IsWorkZone1(StartX + 30, 140 + (i * 21), StartX + 200, 160 + (i * 21)))
				{
					this->DrawColoredGUI(eNEWS_INFOBG, StartX + 30, 140 + (i * 21), pMakeColor(255, 204, 20, 200));
				}

				this->DrawFormat(eGold, StartX + 18, 142 + (i * 21), 65, 3, gNewsBoard.m_Data[i].Title.Date);
				this->DrawFormat(eOrange, StartX + 18, 148 + (i * 21), 65, 3, gNewsBoard.m_Data[i].Title.Time);
				this->DrawFormat(eWhite, StartX + 80, 145 + (i * 21), 190, 1, gNewsBoard.m_Data[i].Title.Text);
			}

			this->DrawFormat(eBlue, StartX + 8, 130, 210, 3, "Last refresh: %d min. ago", gNewsBoard.m_LastRefreshMin);
		}
		else
		{
			BYTE ID = this->Data[eNEWS_MAIN].Attribute - 10;

			this->DrawGUI(eNEWS_INFOBG, StartX + 30, 140);
			this->DrawFormat(eGold, StartX + 18, 142, 65, 3, gNewsBoard.m_Data[ID].Title.Date);
			this->DrawFormat(eOrange, StartX + 18, 148, 65, 3, gNewsBoard.m_Data[ID].Title.Time);
			this->DrawFormat(eWhite, StartX + 80, 145, 190, 1, gNewsBoard.m_Data[ID].Title.Text);
			this->DrawFormat(eWhite, StartX + 15, 170, 200, 1, gNewsBoard.m_Data[ID].Text);

			this->DrawGUI(eNEWS_BACK, ButtonX, 341 + 10);
			this->DrawFormat(eWhite, StartX + 8, 341 + 20, 210, 3, "Back");
			this->DrawGUI(eNEWS_DIV, StartX, 341 - 10);


			if (IsWorkZone1(eNEWS_BACK))
			{
				DWORD Color = eGray100;

				if (this->Data[eNEWS_BACK].OnClick)
				{
					Color = eGray150;
				}

				this->DrawColoredGUI(eNEWS_BACK, this->Data[eNEWS_BACK].X, this->Data[eNEWS_BACK].Y, Color);
			}

			this->DrawFormat(eBlue, StartX + 8, 130, 210, 3, "Last page refresh: %d min. ago", gNewsBoard.m_Data[ID].LastRefreshMin);
		}
	}
	else
	{
		if (!this->Data[eNEWS_MAIN].OnShow)
		{
			return;
		}

		float MainWidth = 230.0;
		float MainHeight = 313.0;
		float StartY = 100.0;
		float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (29.0 / 2);

		this->DrawGUI(eNEWS_MAIN, StartX, StartY + 2);
		this->DrawGUI(eNEWS_TITLE, StartX, StartY);
		StartY = this->DrawRepeatGUI(eNEWS_FRAME, StartX, StartY + 67.0, 13);
		this->DrawGUI(eNEWS_FOOTER, StartX, StartY);
		this->DrawGUI(eNEWS_CLOSE, StartX + MainWidth - this->Data[eNEWS_CLOSE].Width, this->Data[eNEWS_TITLE].Height + this->Data[eNEWS_CLOSE].Height + 2);

		if (this->IsWorkZone1(eNEWS_CLOSE))
		{
			DWORD Color = eGray100;

			if (this->Data[eNEWS_CLOSE].OnClick)
			{
				Color = eGray150;
			}

			this->DrawColoredGUI(eNEWS_CLOSE, this->Data[eNEWS_CLOSE].X, this->Data[eNEWS_CLOSE].Y, Color);
			this->DrawToolTip(this->Data[eNEWS_CLOSE].X + 5, this->Data[eNEWS_CLOSE].Y + 25, "Close");
		}

		this->DrawFormat(eGold, StartX + 10, 110, 210, 3, "News Board");

		if (this->Data[eNEWS_MAIN].Attribute == 0)
		{
			for (int i = 0; i < gNewsBoard.m_LoadedCount; i++)
			{
				this->DrawGUI(eNEWS_INFOBG, StartX + 30, 140 + (i * 21));

				if (IsWorkZone1(StartX + 30, 140 + (i * 21), StartX + 200, 160 + (i * 21)))
				{
					this->DrawColoredGUI(eNEWS_INFOBG, StartX + 30, 140 + (i * 21), pMakeColor(255, 204, 20, 200));
				}

				this->DrawFormat(eGold, StartX + 18, 142 + (i * 21), 65, 3, gNewsBoard.m_Data[i].Title.Date);
				this->DrawFormat(eOrange, StartX + 18, 148 + (i * 21), 65, 3, gNewsBoard.m_Data[i].Title.Time);
				this->DrawFormat(eWhite, StartX + 80, 145 + (i * 21), 190, 1, gNewsBoard.m_Data[i].Title.Text);
			}

			this->DrawFormat(eBlue, StartX + 8, 130, 210, 3, "Last refresh: %d min. ago", gNewsBoard.m_LastRefreshMin);
		}
		else
		{
			BYTE ID = this->Data[eNEWS_MAIN].Attribute - 10;

			this->DrawGUI(eNEWS_INFOBG, StartX + 30, 140);
			this->DrawFormat(eGold, StartX + 18, 142, 65, 3, gNewsBoard.m_Data[ID].Title.Date);
			this->DrawFormat(eOrange, StartX + 18, 148, 65, 3, gNewsBoard.m_Data[ID].Title.Time);
			this->DrawFormat(eWhite, StartX + 80, 145, 190, 1, gNewsBoard.m_Data[ID].Title.Text);
			this->DrawFormat(eWhite, StartX + 15, 170, 200, 1, gNewsBoard.m_Data[ID].Text);

			this->DrawGUI(eNEWS_BACK, ButtonX, this->Data[eNEWS_FOOTER].Y + 10);
			this->DrawFormat(eWhite, StartX + 8, this->Data[eNEWS_FOOTER].Y + 20, 210, 3, "Back");
			this->DrawGUI(eNEWS_DIV, StartX, this->Data[eNEWS_FOOTER].Y - 10);

			if (IsWorkZone1(eNEWS_BACK))
			{
				DWORD Color = eGray100;

				if (this->Data[eNEWS_BACK].OnClick)
				{
					Color = eGray150;
				}

				this->DrawColoredGUI(eNEWS_BACK, this->Data[eNEWS_BACK].X, this->Data[eNEWS_BACK].Y, Color);
			}

			this->DrawFormat(eBlue, StartX + 8, 130, 210, 3, "Last page refresh: %d min. ago", gNewsBoard.m_Data[ID].LastRefreshMin);
		}
	}
}
bool Interface::EventNewsWindow_Main(DWORD Event)
{
	float MainWidth = 230.0;
	float MainHeight = 313.0;
	float StartY = 100.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	for (int i = 0; i < gNewsBoard.m_LoadedCount; i++)
	{
		if (this->IsWorkZone1(StartX + 30, 140 + (i * 21), StartX + 200, 161 + (i * 21)))
		{
			if (Event == WM_LBUTTONDOWN && this->Data[eNEWS_MAIN].Attribute == 0)
			{
				this->Data[eNEWS_MAIN].Attribute = i + 10;
				gNewsBoard.ReqOpenItem(i);
			}
		}
	}

	this->EventNewsWindow_Close(Event);
	this->EventNewsWindow_Back(Event);
	return true;
}
bool Interface::EventNewsWindow_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eNEWS_CLOSE].EventTick);

	if (!this->Data[eNEWS_MAIN].OnShow || !IsWorkZone(eNEWS_CLOSE))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eNEWS_CLOSE].OnClick = true;
		return true;
	}

	this->Data[eNEWS_CLOSE].OnClick = false;

	if (Delay < 500)
	{
		return false;
	}

	this->Data[eNEWS_CLOSE].EventTick = GetTickCount();
	this->Data[eNEWS_MAIN].Attribute = 0;
	this->CloseNewsWindow();

	return false;
}
bool Interface::EventNewsWindow_Back(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eNEWS_BACK].EventTick);

	if (!this->Data[eNEWS_MAIN].OnShow || !IsWorkZone(eNEWS_BACK))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eNEWS_BACK].OnClick = true;
		return true;
	}

	this->Data[eNEWS_BACK].OnClick = false;;

	if (Delay < 500)
	{
		return false;
	}

	this->Data[eNEWS_BACK].EventTick = GetTickCount();
	this->Data[eNEWS_MAIN].Attribute = 0;

	return false;
}
bool Interface::EventDrawMenu_NEW_BOARD(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_NEW_BOARD].EventTick);
	// ----
	//if (!this->Data[eADDPOINT5_MAIN].OnShow || !IsWorkZone(eMenu_NEW_BOARD))
	if (!this->Data[eSTATSADD_MAIN].OnShow || !IsWorkZone(eMenu_NEW_BOARD))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_NEW_BOARD].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_NEW_BOARD].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_NEW_BOARD].EventTick = GetTickCount();
	gInterface.CloseMenuWindow();
	gInterface.CloseEventTimeWindow(); //event time
	gInterface.Data[ePARTYSEARCH_MAIN].OnShow == false;//setting searchparty
	gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;//searchpeary
	gInterface.Data[eJewelBank_MAIN].OnShow == false;//searchpeary
	gInterface.Data[eMAIN_RANKING].OnShow == false;//searchpeary
	//gCustomMenu.CloseTestWindow();

	if (gInterface.CheckNewsWindow())
	{
		gInterface.CloseNewsWindow();
	}
	else
	{
		gNewsBoard.ReqOpenMain();
	}

	// ----
	return false;
}
bool Interface::IsWorkZone1(short ObjectID)
{
	float PosX = this->Data[ObjectID].X;
	float MaxX = PosX + this->Data[ObjectID].Width;

	if (ObjectID == eSAMPLEBUTTON
		//|| ObjectID == eMenuBG
		|| ObjectID == eMenu
		)
	{
		PosX = this->GetResizeX(ObjectID);
		MaxX = PosX + this->Data[ObjectID].Width;
	}

	if ((gObjUser.m_CursorX < PosX || gObjUser.m_CursorX > MaxX) || (gObjUser.m_CursorY < this->Data[ObjectID].Y || gObjUser.m_CursorY > this->Data[ObjectID].MaxY))
		return false;

	return true;
}
float Interface::GetResizeX(short ObjectID)
{
	if (pWinWidth == 800)
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if (pWinWidth != 1024)
	{
		return this->Data[ObjectID].X - 16.0;
	}

	return this->Data[ObjectID].X;
}

//===========================================