#include "stdafx.h"
#include "resource.h"
#include "Controller.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Import.h"
#include "Interface.h"
#include "Protect.h"
#include "TMemory.h"
#include "CSCharacterS13.h"
#include "CMacroUIEx.h"
#include "Camera.h"
#include "TrayModeNew.h"
#include "MiniMap.h"
#include "MiniMapTron.h"
#include "WindowsStruct.h"
#include "Central.h"
#include "User.h"
#include "PartySearchSettings.h"
#include "PartySearch.h"
#include "CustomLuckySpin.h"
#include "CustomJewelBank.h"
#include "SPK_ResetChange.h"
#include "Ranking.h"
#include "SPK_ChangePass.h"
#include "SPK_CongHuongV2.h"
#include "SPK_CongPoint.h"
#include "SPK_Relife.h"
#include "SPK_MocNapNew.H"
#include "NewsBoard.h"

Controller	gController;

#if(NOTICE_MES==1)
char Notice_1[1024];
char Notice_2[1024];
char CameraNotAc[1024];
char CameraOn[1024];
char CameraOff[1024];
char CameraDefault[1024];
char GlowOn[1024];
char GlowOff[1024];
char AutoOn[1024];
char AutoOff[1024];
#endif

void __declspec(naked) iconHook()
{
	static DWORD dwIcon = (DWORD)LoadIcon(gController.Instance, MAKEINTRESOURCE(IDI_ICON1));
	static DWORD dwJmp = 0x004D0E3C;

	_asm
	{
		MOV EAX, dwIcon
		JMP dwJmp
	}
}

bool Controller::Load()
{
	if( !this->MouseHook )
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		#if(NOTICE_MES==1)
		GetPrivateProfileString("Notice", "Notice_1", "", Notice_1, 1024, MENU_NOTE_FILE);
		GetPrivateProfileString("Notice", "Notice_2", "", Notice_2, 1024, MENU_NOTE_FILE);
		GetPrivateProfileString("Notice", "CameraNotAc", "", CameraNotAc, 1024, MENU_NOTE_FILE);
		GetPrivateProfileString("Message", "CameraOn", "", CameraOn, 1024, MENU_NOTE_FILE);
		GetPrivateProfileString("Message", "CameraOff", "", CameraOff, 1024, MENU_NOTE_FILE);
		GetPrivateProfileString("Message", "CameraDefault", "", CameraDefault, 1024, MENU_NOTE_FILE);
		GetPrivateProfileString("Message", "GlowOn", "", GlowOn, 1024, MENU_NOTE_FILE);
		GetPrivateProfileString("Message", "GlowOff", "", GlowOff, 1024, MENU_NOTE_FILE);
		GetPrivateProfileString("Message", "AutoOn", "", AutoOn, 1024, MENU_NOTE_FILE);
		GetPrivateProfileString("Message", "AutoOff", "", AutoOff, 1024, MENU_NOTE_FILE);
		#endif
		if( !this->MouseHook )
		{
			return false;
		}
	}
	if( !this->KeyboardHook )
	{
		this->KeyboardHook = SetWindowsHookExA(WH_KEYBOARD, this->Keyboard, gController.Instance, GetCurrentThreadId());
	}
	SetOp((LPVOID)0x004D0E2F, iconHook, ASM::CALL);
	return true;
}


LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;
	gController.wMouse = wParam;
	switch(wParam)
	{
		case WM_LBUTTONUP:
		case WM_LBUTTONDOWN:
		{
			gRanking.ClickRanking(wParam);
			gTaiKhoan.EventClickChangePass(wParam);
			gCustomJewelBank.CommandNext(wParam);
			gCustomJewelBank.CommandPrev(wParam);
			gCustomJewelBank.EventJewelBankWindow_Close(wParam);
			gCustomJewelBank.EventJewelBankWithDraw(wParam);

			gInterface.EventDrawCTCMINI_Close(wParam);
			gInterface.SPKEventClick(wParam);
			
			gInterface.EventDrawMenu_Open(wParam);
			gInterface.EventDrawMenu_Close(wParam);
			gInterface.SPK_ResetAuto(wParam);
			gInterface.SPK_Camera3D(wParam);
			gInterface.SPK_RsCamera3D(wParam);
			gInterface.SPK_OpenBoxAtm(wParam);
			gInterface.SPK_OpenBoxBSK(wParam);
			gInterface.SPK_OpenBoxCfg(wParam);
			gInterface.SPK_ItemBlock(wParam);
			//add News, Tue
			//gInterface.EventDrawMenu_NEW_BOARD(wParam);
			//gInterface.EventNewsWindow_Main(wParam);
			//gInterface.EventNewsWindow_Back (wParam);
			//gInterface.EventNewsWindow_Close(wParam);
			//gNewsBoard.EventDrawMenu_NEW_BOARD(wParam);
			gNewsBoard.EventNewsWindow_Main(wParam);
			gNewsBoard.EventNewsWindow_Back(wParam);
			gNewsBoard.EventNewsWindow_Close(wParam);
			//--------------------------------
			//add Notice Select Server , Tue
			gCustomNoticeInfo.EventNoticeWindow_Close(wParam);
			gCustomNoticeInfo.NoticeNext(wParam);
			gCustomNoticeInfo.NoticePrev(wParam);
			//--------------------------------
			#if (RESETCHANGE==1)
			gResetChange.ButtonResetChange(wParam);
			#endif
			#if (CongHuongV2)
			gCongHuong2.EventScrollPos(Mouse, wParam);
			#endif
			gCETime.EventMove(wParam);

            #if(PARTYSEARCH==1)
			gPartySearch.EventPartySearchWindow_All(wParam);
			gPartySearch.EventPartySettingsWindow_Main(wParam);
            #endif
			#if(VONGQUAY_NEW)
			gLuckySpin.EventWindow_Main(wParam);
			#endif

			gInterface.EventConfirm_CANCEL(wParam);
			gInterface.EventConfirm_OK(wParam);
			EventMuOffhelper(wParam);
			if(gProtect.m_MainInfo.CustomInterfaceType == 2)
			{
				gInterface.EventNewInterface_All(wParam);
			}
			gOffTrade.EventOffTradeWindow_Main(wParam);
			gOffTrade.EventCloseTradeWindow_Main(wParam);

			#if ADD_POINT
			gAddPoint.EventCharacterWindow(wParam);
			gAddPoint.EventStatsAddWindow(wParam);
			#endif
			#if RELIFE
			G_SpkRelife.MainWindowsRelife(wParam);
			#endif
		}
		
		break;
		case WM_MOUSEMOVE:
		if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
		{
			gCamera.Move(Mouse);
		}
		break;
		case WM_MBUTTONDOWN:
		if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
		{
			gCamera.SetIsMove(1);
			gCamera.SetCursorX(Mouse->pt.x);
			gCamera.SetCursorY(Mouse->pt.y);
		}
		break;
		case WM_MBUTTONUP:
		if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
		{
			gCamera.SetIsMove(0);
		}
		break;
		case WM_MOUSEWHEEL:
		if(GetForegroundWindow() == *(HWND*)(0x00E8C578))
		{
			gCamera.Zoom(Mouse);
		}
		break;
	}
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}

LRESULT Controller::Keyboard(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	}

	if (Code < 0) return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	
	if( (Code == HC_ACTION) && (wParam == WM_KEYDOWN))
	{
		KBDLLHOOKSTRUCT Hook = *((KBDLLHOOKSTRUCT*)lParam);
		switch(Hook.vkCode)
		{
			case 0x48:
			{
				gCETime.OpenWindow();
			}
			break;
			case VK_ESCAPE:
			{
				if (gInterface.Data[ePARTYSEARCH_MAIN].OnShow == true)
				{
					gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;				
					if(gProtect.m_MainInfo.CustomInterfaceType != 4)
					{
						pSetCursorFocus = false;
					}
				}

				if (gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == true)
				{
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow == false;				
					if(gProtect.m_MainInfo.CustomInterfaceType != 4)
					{
						pSetCursorFocus = false;
					}
				}

				if (gInterface.Data[eCommand_MAIN].OnShow == true  && (gProtect.m_MainInfo.CustomInterfaceType != 4))
				{
					gInterface.Data[eCommand_MAIN].OnShow = false;
					pSetCursorFocus = false;
					return -1;
				}

				if (gInterface.Data[eEventTimePANEL_MAIN].OnShow == true && (gProtect.m_MainInfo.CustomInterfaceType != 4))
				{
					gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
					pSetCursorFocus = false;
					return -1;
				}
				if (gInterface.Data[eJewelBank_MAIN].OnShow)
				{
					gInterface.Data[eJewelBank_MAIN].Close();
					return -1;
				}
			
				if (gInterface.Data[eMAIN_RANKING].OnShow)
				{
					gInterface.Data[eMAIN_RANKING].Close();
					return -1;
				}
			}
			break;
			default:
			break;
		}
	}
	if( ((lParam >> 31) & 1) && (Code == HC_ACTION) )
	{
		if(GetForegroundWindow() != pGameWindow || pPlayerState != GameProcess)
		{
			return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
		}
		gController.wKeyBord = wParam;
	}
	if(GetForegroundWindow() == pGameWindow && pPlayerState == GameProcess) // 
	if(Code == HC_ACTION)
	{
		if(((DWORD)lParam & (1 << 30)) != 0 && ((DWORD)lParam & (1 << 31)) != 0)
		{
			if( GetForegroundWindow() == *(HWND*)(0x00E8C578) )
			{			
				gTaiKhoan.TextBoxChangePass(wParam);
				#if ADD_POINT
				gAddPoint.ControlTextBox(wParam);
				#endif
			}
		}
	}
	return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
}
LRESULT Controller::Window(HWND Window, DWORD Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{

		case TRAYMODE_ICON_MESSAGE:
		{
			switch(lParam)
			{
				case WM_LBUTTONDBLCLK:
				{
					gTrayMode.SwitchState();
				}
				break;
			}
		}
		break;
	}
	return CallWindowProc((WNDPROC)gTrayMode.TempWindowProc, Window, Message, wParam, lParam);
}


