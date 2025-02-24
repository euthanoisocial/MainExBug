#include "StdAfx.h"
#include "Config.h"
#include "Util.h"
#include <stdlib.h>
#include "windows.h"
#include "atlstr.h"
#include "Protect.h"

cConfig gConfig;
void cConfig::Load()
{	
	for (int Menu = 0; Menu < MAX_RANGE_MENU; Menu++)
	{
		char section[50], key[50];
		sprintf_s(section, "MenuGame");
		sprintf_s(key, "MenuGame%0d", Menu);
		GetPrivateProfileStringA(section, key, "Null", MenuGame_TextVN[Menu], sizeof(MenuGame_TextVN[Menu]), MENU_GAME_FILE);
	}	
	for (int Key1 = 0; Key1 < MAX_RANGE_TOGGLE; Key1++)
	{
		char section[50], key[50];
		sprintf_s(section, "ToggleAuto");
		sprintf_s(key, "ToggleAuto%0d", Key1);
		GetPrivateProfileStringA(section, key, "Null", ToggleAuto_TextVN[Key1], sizeof(ToggleAuto_TextVN[Key1]), MENU_GAME_FILE);
	}
	#if(THANMA)	
	for (int ST = 0; ST < MAX_RANGE_TMC; ST++)
	{
		char section[250], key[250];
		sprintf_s(section, "TextVN_EventThanMa");
		sprintf_s(key, "Text%d", ST);
		GetPrivateProfileStringA(section, key, "Null", TextVN_ThanMaChien[ST], sizeof(TextVN_ThanMaChien[ST]), MENU_GAME_FILE);
	}
	#endif
	for (int Lang = 0; Lang < MAX_RANGE_TEXT; Lang++)
	{
		char section[MAX_RANGE_TEXT], key[MAX_RANGE_TEXT];
		sprintf_s(section, "SPK_TEXT");
		sprintf_s(key, "SPK_TEXT_%d", Lang);
		GetPrivateProfileStringA(section, key, "Null", TSPK_TEXT_ENGINE[Lang], sizeof(TSPK_TEXT_ENGINE[Lang]), MENU_GAME_FILE);
	}
	//tue add Notices
	//-> Server News Text Lines
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews0", "TextNews0", NewsText0, sizeof(NewsText0), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews1", "TextNews1", NewsText1, sizeof(NewsText1), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews2", "TextNews2", NewsText2, sizeof(NewsText2), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews3", "TextNews3", NewsText3, sizeof(NewsText3), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews4", "TextNews4", NewsText4, sizeof(NewsText4), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews5", "TextNews5", NewsText5, sizeof(NewsText5), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews6", "TextNews6", NewsText6, sizeof(NewsText6), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews7", "TextNews7", NewsText7, sizeof(NewsText7), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews8", "TextNews8", NewsText8, sizeof(NewsText8), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews9", "TextNews9", NewsText9, sizeof(NewsText9), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews10", "TextNews10", NewsText10, sizeof(NewsText10), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews11", "TextNews11", NewsText11, sizeof(NewsText11), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews12", "TextNews12", NewsText12, sizeof(NewsText12), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews13", "TextNews13", NewsText13, sizeof(NewsText13), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews14", "TextNews14", NewsText14, sizeof(NewsText14), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews15", "TextNews15", NewsText15, sizeof(NewsText15), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews16", "TextNews16", NewsText16, sizeof(NewsText16), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews17", "TextNews17", NewsText17, sizeof(NewsText17), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews18", "TextNews18", NewsText18, sizeof(NewsText18), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews19", "TextNews19", NewsText19, sizeof(NewsText19), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews20", "TextNews20", NewsText20, sizeof(NewsText20), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews21", "TextNews21", NewsText21, sizeof(NewsText21), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews22", "TextNews22", NewsText22, sizeof(NewsText22), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews23", "TextNews23", NewsText23, sizeof(NewsText23), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews24", "TextNews24", NewsText24, sizeof(NewsText24), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews25", "TextNews25", NewsText25, sizeof(NewsText25), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews26", "TextNews26", NewsText26, sizeof(NewsText26), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews27", "TextNews27", NewsText27, sizeof(NewsText27), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews28", "TextNews28", NewsText28, sizeof(NewsText28), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews29", "TextNews29", NewsText29, sizeof(NewsText29), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews30", "TextNews30", NewsText30, sizeof(NewsText30), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews31", "TextNews31", NewsText31, sizeof(NewsText31), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews32", "TextNews32", NewsText32, sizeof(NewsText32), CONFIG_FILE);
	GetPrivateProfileStringA("ServerNewsTextLine", "TextNews33", "TextNews33", NewsText33, sizeof(NewsText33), CONFIG_FILE);

	//-> Server News Text Colors
	ColorText0_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor0_R", 255, CONFIG_FILE);
	ColorText0_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor0_G", 255, CONFIG_FILE);
	ColorText0_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor0_B", 255, CONFIG_FILE);
	ColorText1_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor1_R", 255, CONFIG_FILE);
	ColorText1_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor1_G", 255, CONFIG_FILE);
	ColorText1_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor1_B", 255, CONFIG_FILE);
	ColorText2_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor2_R", 255, CONFIG_FILE);
	ColorText2_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor2_G", 255, CONFIG_FILE);
	ColorText2_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor2_B", 255, CONFIG_FILE);
	ColorText3_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor3_R", 255, CONFIG_FILE);
	ColorText3_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor3_G", 255, CONFIG_FILE);
	ColorText3_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor3_B", 255, CONFIG_FILE);
	ColorText4_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor4_R", 255, CONFIG_FILE);
	ColorText4_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor4_G", 255, CONFIG_FILE);
	ColorText4_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor4_B", 255, CONFIG_FILE);
	ColorText5_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor5_R", 255, CONFIG_FILE);
	ColorText5_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor5_G", 255, CONFIG_FILE);
	ColorText5_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor5_B", 255, CONFIG_FILE);
	ColorText6_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor6_R", 255, CONFIG_FILE);
	ColorText6_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor6_G", 255, CONFIG_FILE);
	ColorText6_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor6_B", 255, CONFIG_FILE);
	ColorText7_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor7_R", 255, CONFIG_FILE);
	ColorText7_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor7_G", 255, CONFIG_FILE);
	ColorText7_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor7_B", 255, CONFIG_FILE);
	ColorText8_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor8_R", 255, CONFIG_FILE);
	ColorText8_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor8_G", 255, CONFIG_FILE);
	ColorText8_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor8_B", 255, CONFIG_FILE);
	ColorText9_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor9_R", 255, CONFIG_FILE);
	ColorText9_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor9_G", 255, CONFIG_FILE);
	ColorText9_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor9_B", 255, CONFIG_FILE);
	ColorText10_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor10_R", 255, CONFIG_FILE);
	ColorText10_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor10_G", 255, CONFIG_FILE);
	ColorText10_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor10_B", 255, CONFIG_FILE);
	ColorText11_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor11_R", 255, CONFIG_FILE);
	ColorText11_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor11_G", 255, CONFIG_FILE);
	ColorText11_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor11_B", 255, CONFIG_FILE);
	ColorText12_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor12_R", 255, CONFIG_FILE);
	ColorText12_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor12_G", 255, CONFIG_FILE);
	ColorText12_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor12_B", 255, CONFIG_FILE);
	ColorText13_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor13_R", 255, CONFIG_FILE);
	ColorText13_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor13_G", 255, CONFIG_FILE);
	ColorText13_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor13_B", 255, CONFIG_FILE);
	ColorText14_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor14_R", 255, CONFIG_FILE);
	ColorText14_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor14_G", 255, CONFIG_FILE);
	ColorText14_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor14_B", 255, CONFIG_FILE);
	ColorText15_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor15_R", 255, CONFIG_FILE);
	ColorText15_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor15_G", 255, CONFIG_FILE);
	ColorText15_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor15_B", 255, CONFIG_FILE);
	ColorText16_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor16_R", 255, CONFIG_FILE);
	ColorText16_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor16_G", 255, CONFIG_FILE);
	ColorText16_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor16_B", 255, CONFIG_FILE);
	ColorText17_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor17_R", 255, CONFIG_FILE);
	ColorText17_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor17_G", 255, CONFIG_FILE);
	ColorText17_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor17_B", 255, CONFIG_FILE);
	ColorText18_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor18_R", 255, CONFIG_FILE);
	ColorText18_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor18_G", 255, CONFIG_FILE);
	ColorText18_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor18_B", 255, CONFIG_FILE);
	ColorText19_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor19_R", 255, CONFIG_FILE);
	ColorText19_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor19_G", 255, CONFIG_FILE);
	ColorText19_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor19_B", 255, CONFIG_FILE);
	ColorText20_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor20_R", 255, CONFIG_FILE);
	ColorText20_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor20_G", 255, CONFIG_FILE);
	ColorText20_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor20_B", 255, CONFIG_FILE);
	ColorText21_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor21_R", 255, CONFIG_FILE);
	ColorText21_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor21_G", 255, CONFIG_FILE);
	ColorText21_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor21_B", 255, CONFIG_FILE);
	ColorText22_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor22_R", 255, CONFIG_FILE);
	ColorText22_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor22_G", 255, CONFIG_FILE);
	ColorText22_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor22_B", 255, CONFIG_FILE);
	ColorText23_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor23_R", 255, CONFIG_FILE);
	ColorText23_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor23_G", 255, CONFIG_FILE);
	ColorText23_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor23_B", 255, CONFIG_FILE);
	ColorText24_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor24_R", 255, CONFIG_FILE);
	ColorText24_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor24_G", 255, CONFIG_FILE);
	ColorText24_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor24_B", 255, CONFIG_FILE);
	ColorText25_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor25_R", 255, CONFIG_FILE);
	ColorText25_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor25_G", 255, CONFIG_FILE);
	ColorText25_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor25_B", 255, CONFIG_FILE);
	ColorText26_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor26_R", 255, CONFIG_FILE);
	ColorText26_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor26_G", 255, CONFIG_FILE);
	ColorText26_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor26_B", 255, CONFIG_FILE);
	ColorText27_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor27_R", 255, CONFIG_FILE);
	ColorText27_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor27_G", 255, CONFIG_FILE);
	ColorText27_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor27_B", 255, CONFIG_FILE);
	ColorText28_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor28_R", 255, CONFIG_FILE);
	ColorText28_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor28_G", 255, CONFIG_FILE);
	ColorText28_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor28_B", 255, CONFIG_FILE);
	ColorText29_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor29_R", 255, CONFIG_FILE);
	ColorText29_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor29_G", 255, CONFIG_FILE);
	ColorText29_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor29_B", 255, CONFIG_FILE);
	ColorText30_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor30_R", 255, CONFIG_FILE);
	ColorText30_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor30_G", 255, CONFIG_FILE);
	ColorText30_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor30_B", 255, CONFIG_FILE);
	ColorText31_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor31_R", 255, CONFIG_FILE);
	ColorText31_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor31_G", 255, CONFIG_FILE);
	ColorText31_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor31_B", 255, CONFIG_FILE);
	ColorText32_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor32_R", 255, CONFIG_FILE);
	ColorText32_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor32_G", 255, CONFIG_FILE);
	ColorText32_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor32_B", 255, CONFIG_FILE);
	ColorText33_R = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor33_R", 255, CONFIG_FILE);
	ColorText33_G = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor33_G", 255, CONFIG_FILE);
	ColorText33_B = GetPrivateProfileIntA("ServerNewsTextColor", "TextColor33_B", 255, CONFIG_FILE);

	//-> Custom Item Position
	Item_01_Type = GetPrivateProfileIntA("ItemPosition", "Item_01_Type", 15, POSITION_FILE);
	Item_01_ID = GetPrivateProfileIntA("ItemPosition", "Item_01_ID", 255, POSITION_FILE);
	Item_01_SizeX = GetPrivateProfileIntA("ItemPosition", "Item_01_SizeX", 0.0, POSITION_FILE);
	Item_01_SizeY = GetPrivateProfileIntA("ItemPosition", "Item_01_SizeY", 0.0, POSITION_FILE);
	Item_01_SizeZ = GetPrivateProfileIntA("ItemPosition", "Item_01_SizeZ", 0.0, POSITION_FILE);
	Item_01_PosX = GetPrivateProfileIntA("ItemPosition", "Item_01_PosX", 0.0, POSITION_FILE);
	Item_01_PosY = GetPrivateProfileIntA("ItemPosition", "Item_01_PosY", 0.0, POSITION_FILE);
	//================================================
}