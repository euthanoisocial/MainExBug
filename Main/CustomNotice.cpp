#include "stdafx.h"
#include "CustomNotice.h"
#include "Tmemory.h"
//#include "NewFont.h"
#include "Interface.h"
#include "Defines.h"
#include "Config.h"

extern DWORD	Test_Buff;
extern char	Test_LevelBuff[40];

Naked(Notices)
{
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_TEXTURE_2D);

	int PosX;
	PosX = 470;
		
	pDrawGUI(0x9969, (float)455 , (float)70 - 40, 173, 406);
	/*
	gInterface.DrawFormat(Color4f(Config.ColorText0_R, Config.ColorText0_G, Config.ColorText0_B, 255),510,47,250,1,Config.NewsText0);
	gInterface.DrawFormat(Color4f(Config.ColorText1_R, Config.ColorText1_G, Config.ColorText1_B, 255),480,77,250,1,Config.NewsText1);
	gInterface.DrawFormat(Color4f(Config.ColorText2_R, Config.ColorText2_G, Config.ColorText2_B, 255),480,87,250,1,Config.NewsText2);
	gInterface.DrawFormat(Color4f(Config.ColorText3_R, Config.ColorText3_G, Config.ColorText3_B, 255),480,97,250,1,Config.NewsText3);
	gInterface.DrawFormat(Color4f(Config.ColorText4_R, Config.ColorText4_G, Config.ColorText4_B, 255),480,107,250,1,Config.NewsText4);
	gInterface.DrawFormat(Color4f(Config.ColorText5_R, Config.ColorText5_G, Config.ColorText5_B, 255),480,117,250,1,Config.NewsText5);
	gInterface.DrawFormat(Color4f(Config.ColorText6_R, Config.ColorText6_G, Config.ColorText6_B, 255),480,127,250,1,Config.NewsText6);
	gInterface.DrawFormat(Color4f(Config.ColorText7_R, Config.ColorText7_G, Config.ColorText7_B, 255),480,137,250,1,Config.NewsText7);
	gInterface.DrawFormat(Color4f(Config.ColorText8_R, Config.ColorText8_G, Config.ColorText8_B, 255),480,147,250,1,Config.NewsText8);
	gInterface.DrawFormat(Color4f(Config.ColorText9_R, Config.ColorText9_G, Config.ColorText9_B, 255),480,157,250,1,Config.NewsText9);
	gInterface.DrawFormat(Color4f(Config.ColorText10_R, Config.ColorText10_G, Config.ColorText10_B, 255),480,167,250,1,Config.NewsText10);
	gInterface.DrawFormat(Color4f(Config.ColorText11_R, Config.ColorText11_G, Config.ColorText11_B, 255),480,177,250,1,Config.NewsText11);
	gInterface.DrawFormat(Color4f(Config.ColorText12_R, Config.ColorText12_G, Config.ColorText12_B, 255),480,187,250,1,Config.NewsText12);
	gInterface.DrawFormat(Color4f(Config.ColorText13_R, Config.ColorText13_G, Config.ColorText13_B, 255),480,197,250,1,Config.NewsText13);
	gInterface.DrawFormat(Color4f(Config.ColorText14_R, Config.ColorText14_G, Config.ColorText14_B, 255),480,207,250,1,Config.NewsText14);
	gInterface.DrawFormat(Color4f(Config.ColorText15_R, Config.ColorText15_G, Config.ColorText15_B, 255),480,217,250,1,Config.NewsText15);
	gInterface.DrawFormat(Color4f(Config.ColorText16_R, Config.ColorText16_G, Config.ColorText16_B, 255),480,227,250,1,Config.NewsText16);
	gInterface.DrawFormat(Color4f(Config.ColorText17_R, Config.ColorText17_G, Config.ColorText17_B, 255),480,237,250,1,Config.NewsText17);
	gInterface.DrawFormat(Color4f(Config.ColorText18_R, Config.ColorText18_G, Config.ColorText18_B, 255),480,247,250,1,Config.NewsText18);
	gInterface.DrawFormat(Color4f(Config.ColorText19_R, Config.ColorText19_G, Config.ColorText19_B, 255),480,257,250,1,Config.NewsText19);
	gInterface.DrawFormat(Color4f(Config.ColorText20_R, Config.ColorText20_G, Config.ColorText20_B, 255),480,267,250,1,Config.NewsText20);
	gInterface.DrawFormat(Color4f(Config.ColorText21_R, Config.ColorText21_G, Config.ColorText21_B, 255),480,277,250,1,Config.NewsText21);
	gInterface.DrawFormat(Color4f(Config.ColorText22_R, Config.ColorText22_G, Config.ColorText22_B, 255),480,287,250,1,Config.NewsText22);
	gInterface.DrawFormat(Color4f(Config.ColorText23_R, Config.ColorText23_G, Config.ColorText23_B, 255),480,297,250,1,Config.NewsText23);
	gInterface.DrawFormat(Color4f(Config.ColorText24_R, Config.ColorText24_G, Config.ColorText24_B, 255),480,307,250,1,Config.NewsText24);
	gInterface.DrawFormat(Color4f(Config.ColorText25_R, Config.ColorText25_G, Config.ColorText25_B, 255),480,317,250,1,Config.NewsText25);
	gInterface.DrawFormat(Color4f(Config.ColorText26_R, Config.ColorText26_G, Config.ColorText26_B, 255),480,327,250,1,Config.NewsText26);
	gInterface.DrawFormat(Color4f(Config.ColorText27_R, Config.ColorText27_G, Config.ColorText27_B, 255),480,337,250,1,Config.NewsText27);
	gInterface.DrawFormat(Color4f(Config.ColorText28_R, Config.ColorText28_G, Config.ColorText28_B, 255),480,347,250,1,Config.NewsText28);
	gInterface.DrawFormat(Color4f(Config.ColorText29_R, Config.ColorText29_G, Config.ColorText29_B, 255),480,357,250,1,Config.NewsText29);
	gInterface.DrawFormat(Color4f(Config.ColorText30_R, Config.ColorText30_G, Config.ColorText30_B, 255),480,367,250,1,Config.NewsText30);
	gInterface.DrawFormat(Color4f(Config.ColorText31_R, Config.ColorText31_G, Config.ColorText31_B, 255),480,377,250,1,Config.NewsText31);
	gInterface.DrawFormat(Color4f(Config.ColorText32_R, Config.ColorText32_G, Config.ColorText32_B, 255),480,387,250,1,Config.NewsText32);
	gInterface.DrawFormat(Color4f(Config.ColorText33_R, Config.ColorText33_G, Config.ColorText33_B, 255),480,397,250,1,Config.NewsText33);
	*/
	gInterface.DrawFormat(Color4f(gConfig.ColorText0_R, gConfig.ColorText0_G, gConfig.ColorText0_B, 255),510,47,250,1, gConfig.NewsText0);
	gInterface.DrawFormat(Color4f(gConfig.ColorText1_R, gConfig.ColorText1_G, gConfig.ColorText1_B, 255),480,77,250,1, gConfig.NewsText1);
	gInterface.DrawFormat(Color4f(gConfig.ColorText2_R, gConfig.ColorText2_G, gConfig.ColorText2_B, 255),480,87,250,1, gConfig.NewsText2);
	gInterface.DrawFormat(Color4f(gConfig.ColorText3_R, gConfig.ColorText3_G, gConfig.ColorText3_B, 255),480,97,250,1, gConfig.NewsText3);
	gInterface.DrawFormat(Color4f(gConfig.ColorText4_R, gConfig.ColorText4_G, gConfig.ColorText4_B, 255),480,107,250,1, gConfig.NewsText4);
	gInterface.DrawFormat(Color4f(gConfig.ColorText5_R, gConfig.ColorText5_G, gConfig.ColorText5_B, 255),480,117,250,1, gConfig.NewsText5);
	gInterface.DrawFormat(Color4f(gConfig.ColorText6_R, gConfig.ColorText6_G, gConfig.ColorText6_B, 255),480,127,250,1, gConfig.NewsText6);
	gInterface.DrawFormat(Color4f(gConfig.ColorText7_R, gConfig.ColorText7_G, gConfig.ColorText7_B, 255),480,137,250,1, gConfig.NewsText7);
	gInterface.DrawFormat(Color4f(gConfig.ColorText8_R, gConfig.ColorText8_G, gConfig.ColorText8_B, 255),480,147,250,1, gConfig.NewsText8);
	gInterface.DrawFormat(Color4f(gConfig.ColorText9_R, gConfig.ColorText9_G, gConfig.ColorText9_B, 255),480,157,250,1, gConfig.NewsText9);
	gInterface.DrawFormat(Color4f(gConfig.ColorText10_R, gConfig.ColorText10_G, gConfig.ColorText10_B, 255),480,167,250,1, gConfig.NewsText10);
	gInterface.DrawFormat(Color4f(gConfig.ColorText11_R, gConfig.ColorText11_G, gConfig.ColorText11_B, 255),480,177,250,1, gConfig.NewsText11);
	gInterface.DrawFormat(Color4f(gConfig.ColorText12_R, gConfig.ColorText12_G, gConfig.ColorText12_B, 255),480,187,250,1, gConfig.NewsText12);
	gInterface.DrawFormat(Color4f(gConfig.ColorText13_R, gConfig.ColorText13_G, gConfig.ColorText13_B, 255),480,197,250,1, gConfig.NewsText13);
	gInterface.DrawFormat(Color4f(gConfig.ColorText14_R, gConfig.ColorText14_G, gConfig.ColorText14_B, 255),480,207,250,1, gConfig.NewsText14);
	gInterface.DrawFormat(Color4f(gConfig.ColorText15_R, gConfig.ColorText15_G, gConfig.ColorText15_B, 255),480,217,250,1, gConfig.NewsText15);
	gInterface.DrawFormat(Color4f(gConfig.ColorText16_R, gConfig.ColorText16_G, gConfig.ColorText16_B, 255),480,227,250,1, gConfig.NewsText16);
	gInterface.DrawFormat(Color4f(gConfig.ColorText17_R, gConfig.ColorText17_G, gConfig.ColorText17_B, 255),480,237,250,1, gConfig.NewsText17);
	gInterface.DrawFormat(Color4f(gConfig.ColorText18_R, gConfig.ColorText18_G, gConfig.ColorText18_B, 255),480,247,250,1, gConfig.NewsText18);
	gInterface.DrawFormat(Color4f(gConfig.ColorText19_R, gConfig.ColorText19_G, gConfig.ColorText19_B, 255),480,257,250,1, gConfig.NewsText19);
	gInterface.DrawFormat(Color4f(gConfig.ColorText20_R, gConfig.ColorText20_G, gConfig.ColorText20_B, 255),480,267,250,1, gConfig.NewsText20);
	gInterface.DrawFormat(Color4f(gConfig.ColorText21_R, gConfig.ColorText21_G, gConfig.ColorText21_B, 255),480,277,250,1, gConfig.NewsText21);
	gInterface.DrawFormat(Color4f(gConfig.ColorText22_R, gConfig.ColorText22_G, gConfig.ColorText22_B, 255),480,287,250,1, gConfig.NewsText22);
	gInterface.DrawFormat(Color4f(gConfig.ColorText23_R, gConfig.ColorText23_G, gConfig.ColorText23_B, 255),480,297,250,1, gConfig.NewsText23);
	gInterface.DrawFormat(Color4f(gConfig.ColorText24_R, gConfig.ColorText24_G, gConfig.ColorText24_B, 255),480,307,250,1, gConfig.NewsText24);
	gInterface.DrawFormat(Color4f(gConfig.ColorText25_R, gConfig.ColorText25_G, gConfig.ColorText25_B, 255),480,317,250,1, gConfig.NewsText25);
	gInterface.DrawFormat(Color4f(gConfig.ColorText26_R, gConfig.ColorText26_G, gConfig.ColorText26_B, 255),480,327,250,1, gConfig.NewsText26);
	gInterface.DrawFormat(Color4f(gConfig.ColorText27_R, gConfig.ColorText27_G, gConfig.ColorText27_B, 255),480,337,250,1, gConfig.NewsText27);
	gInterface.DrawFormat(Color4f(gConfig.ColorText28_R, gConfig.ColorText28_G, gConfig.ColorText28_B, 255),480,347,250,1, gConfig.NewsText28);
	gInterface.DrawFormat(Color4f(gConfig.ColorText29_R, gConfig.ColorText29_G, gConfig.ColorText29_B, 255),480,357,250,1, gConfig.NewsText29);
	gInterface.DrawFormat(Color4f(gConfig.ColorText30_R, gConfig.ColorText30_G, gConfig.ColorText30_B, 255),480,367,250,1, gConfig.NewsText30);
	gInterface.DrawFormat(Color4f(gConfig.ColorText31_R, gConfig.ColorText31_G, gConfig.ColorText31_B, 255),480,377,250,1, gConfig.NewsText31);
	gInterface.DrawFormat(Color4f(gConfig.ColorText32_R, gConfig.ColorText32_G, gConfig.ColorText32_B, 255),480,387,250,1, gConfig.NewsText32);
	gInterface.DrawFormat(Color4f(gConfig.ColorText33_R, gConfig.ColorText33_G, gConfig.ColorText33_B, 255),480,397,250,1, gConfig.NewsText33);
		
	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 459, 150, 3, "Powered By Emershow");
	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 469, 150, 3, "2021 © Webzen all rights reserved");

	_asm
	{
		lea eax, Test_LevelBuff
			push eax
	}

	_asm
	{
		mov Test_Buff, 0x004D7D1D
			jmp Test_Buff
	}
}

void InitNotices()
{
	SetOp((LPVOID)0x004D7D13, (LPVOID)Notices, 0xE9);
}