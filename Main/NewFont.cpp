#include "stdafx.h"
#include "Util.h"
#include "NewFont.h"
#include "Interface.h"
#include "TMemory.h"
#include "Protect.h"
//--
Font gFont;
//--
char MyFontFaceName1[200];
char MyFontFaceName2[200];
char MyFontFaceName3[200];
char MyFontFaceName4[200];
char MyFontFaceName5[200];
char sValue[99];
//--
int Height600p=GetPrivateProfileIntA("Font","FontSize1",11, ".\\Settings.ini");
int Height768p=GetPrivateProfileIntA("Font","FontSize2",13, ".\\Settings.ini");
int Height1024p=GetPrivateProfileIntA("Font","FontSize3",15, ".\\Settings.ini");
int Height900p=GetPrivateProfileIntA("Font","FontSize4",16, ".\\Settings.ini");
int Height1080p=GetPrivateProfileIntA("Font","FontSize5",16, ".\\Settings.ini");
//--
int Bold1=GetPrivateProfileIntA("Font","Main_Font_Bold",0,".\\Settings.ini");
int Height=GetPrivateProfileIntA("Font","Main_Font_Height",13, ".\\Settings.ini");
int Italic=GetPrivateProfileIntA("Font","Main_Font_Italic",0,".\\Settings.ini");
int Unicode=GetPrivateProfileIntA("Font","Main_Font_Unicode",1,".\\Settings.ini");
//--
int Width=GetPrivateProfileIntA("Font","Main_Font_Width",0,".\\Settings.ini");
int UnderLine=GetPrivateProfileIntA("Font","Main_Font_Underline",0,".\\Settings.ini");
int Quality=GetPrivateProfileIntA("Font","Main_Font_Quality",3,".\\Settings.ini");
int StrikeOut=GetPrivateProfileIntA("Font","Main_Font_StrikeOut",0,".\\Settings.ini");
//--
void Font::Load()
{
	GetPrivateProfileStringA("Font","FontName1","Tahoma",MyFontFaceName1,200,".\\Settings.ini");
	GetPrivateProfileStringA("Font","FontName2","Tahoma",MyFontFaceName2,200,".\\Settings.ini");
	GetPrivateProfileStringA("Font","FontName3","Tahoma",MyFontFaceName3,200,".\\Settings.ini");
	GetPrivateProfileStringA("Font","FontName4","Tahoma",MyFontFaceName4,200,".\\Settings.ini");
	GetPrivateProfileStringA("Font","FontName5","Tahoma",MyFontFaceName5,200,".\\Settings.ini");
   //--
    SetCompleteHook(0xE8,Offset_CreateFontA1,&Font::LoadNewFont);
    SetCompleteHook(0xE8,Offset_CreateFontA2,&Font::LoadNewFont);
    SetCompleteHook(0xE8,Offset_CreateFontA3,&Font::LoadNewFont);
    SetCompleteHook(0xE8,Offset_CreateFontA4,&Font::LoadNewFont);
    SetCompleteHook(0xE8,Offset_CreateFontA5,&Font::LoadNewFont);
    //--
    SetByte((Offset_CreateFontA1+ 5),0x90);
    SetByte((Offset_CreateFontA2+ 5),0x90);
    SetByte((Offset_CreateFontA3+ 5),0x90);
    SetByte((Offset_CreateFontA4+ 5),0x90);
    SetByte((Offset_CreateFontA5+ 5),0x90);
	//--
	//Unicode Fix
	SetByte((0x00958D4C+3), 0xA8);	//1 Codepage utf China lang
	SetByte((0x00958D4C+4), 0x03);	//2	Codepage utf China lang
	//--
	SetByte(0x004215A7, 0xEB);	//[0-9A-Za-z] Name
	SetByte((0x00507AEA+1), 0x72); //can not use symbol
	SetByte(0x00507AFD, 0xEB);	//[0-9A-Za-z] Guild
	//--
}
//--
HFONT Font::LoadNewFont()
{
	HFONT MyFont;

	//640x480 Resolution
	/*if(pWinWidth==640)
	{
		SetByte(0x004D128F, 0x1D); //??
	}*/

	//640x480 & 800x600 Resolution
	if(pWinWidth==640 || pWinWidth==800)
	{
		if (Bold1==0)
		{
			if (Unicode==1)
			{
				MyFont=CreateFontA(Height600p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName1);
			}
			else
			{
				MyFont=CreateFontA(Height600p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName1);
			}
		}
		else
		{
			if (Unicode==1)
			{
				MyFont=CreateFontA(Height600p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName1);
			}
			else
			{
				MyFont=CreateFontA(Height600p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName1);
			}
		}
		return MyFont;
	}
	
	//1024x768 Resolution
	if(pWinWidth==1024)
{
	if (Bold1==0)
    {
        if (Unicode==1)
        {
            MyFont=CreateFontA(Height768p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName2);
        }
        else
        {
            MyFont=CreateFontA(Height768p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName2);
        }
    }
    else
    {
        if (Unicode==1)
        {
            MyFont=CreateFontA(Height768p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName2);
        }
        else
        {
            MyFont=CreateFontA(Height768p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName2);
        }
    }
    return MyFont;
}

//1280x1024 Resolution
if(pWinWidth==1280)
{
	//Fix Lugard
	SetDword(0x00892A21+1,(DWORD)0x167D);
	SetDword(0x00892A9A+1,(DWORD)0x167E);
	SetDword(0x00892B0F+1,(DWORD)0x167F);

    if (Bold1==0)
    {
        if (Unicode==1)
        {
            MyFont=CreateFontA(Height1024p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName3);
        }
        else
        {
            MyFont=CreateFontA(Height1024p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName3);
        }
    }
    else
    {
        if (Unicode==1)
        {
            MyFont=CreateFontA(Height1024p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName3);
        }
        else
        {
            MyFont=CreateFontA(Height1024p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName3);
        }
    }
    return MyFont;
}

//1366x768 Resolution
if(pWinWidth==1360)
{
	//Fix Lugard
	SetDword(0x00892A21+1,(DWORD)0x167D);
	SetDword(0x00892A9A+1,(DWORD)0x167E);
	SetDword(0x00892B0F+1,(DWORD)0x167F);

    if (Bold1==0)
    {
        if (Unicode==1)
        {
            MyFont=CreateFontA(Height768p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName2);
        }
        else
        {
            MyFont=CreateFontA(Height768p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName2);
        }
    }
    else
    {
        if (Unicode==1)
        {
            MyFont=CreateFontA(Height768p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName2);
        }
        else
        {
            MyFont=CreateFontA(Height768p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName2);
        }
    }
    return MyFont;
}

//1440x900 & 1600x900 Resolution
if(pWinWidth==1440 || pWinWidth==1600)
{
	//Fix Lugard
	SetDword(0x00892A21+1,(DWORD)0x167D);
	SetDword(0x00892A9A+1,(DWORD)0x167E);
	SetDword(0x00892B0F+1,(DWORD)0x167F);

    if (Bold1==0)
    {
        if (Unicode==1)
        {
            MyFont=CreateFontA(Height900p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName4);
        }
        else
        {
            MyFont=CreateFontA(Height900p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName4);
        }
    }
    else
    {
        if (Unicode==1)
        {
            MyFont=CreateFontA(Height900p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName4);
        }
        else
        {
            MyFont=CreateFontA(Height900p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName4);
        }
    }
    return MyFont;
}

//1680x1050 Resolution
if(pWinWidth==1680)
{
	//Fix Lugard
	SetDword(0x00892A21+1,(DWORD)0x167D);
	SetDword(0x00892A9A+1,(DWORD)0x167E);
	SetDword(0x00892B0F+1,(DWORD)0x167F);

    if (Bold1==0)
    {
        if (Unicode==1)
        {
            MyFont=CreateFontA(Height1080p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName5);
        }
        else
        {
            MyFont=CreateFontA(Height1080p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName5);
        }
    }
    else
    {
        if (Unicode==1)
        {
            MyFont=CreateFontA(Height1080p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName5);
        }
        else
        {
            MyFont=CreateFontA(Height1080p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName5);
        }
    }
    return MyFont;
}

//1920x1080 Resolution
if(pWinWidth==1920)
{
	//Fix Lugard
	SetDword(0x00892A21+1,(DWORD)0x167D);
	SetDword(0x00892A9A+1,(DWORD)0x167E);
	SetDword(0x00892B0F+1,(DWORD)0x167F);
	
	if (Bold1 == 0)
	{
		if (Unicode == 1)
		{
			MyFont=CreateFontA(Height1080p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName5);
		}
		else
		{
			MyFont=CreateFontA(Height1080p,Width,0,0,400,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName5);
		}
	}
	else
	{
		if (Unicode==1)
		{
			MyFont=CreateFontA(Height1080p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x01,0,0,Quality,0,MyFontFaceName5);
		}
		else
		{
			MyFont=CreateFontA(Height1080p,Width,0,0,700,Italic,UnderLine,StrikeOut,0x0,0,0,Quality,0,MyFontFaceName5);
		}
	}
	return MyFont;
}
}