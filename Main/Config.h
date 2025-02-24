#ifndef _Config_H
#define _Config_H
#define MAX_RANGE_TEXT 322
#define MAX_RANGE_TOGGLE 10
#define MAX_RANGE_TMC 20
#define MAX_RANGE_MENU 41
class cConfig
{
	public:
		//tue add Notice 
		char NewsText0[32];
		char NewsText1[64];
		char NewsText2[64];
		char NewsText3[64];
		char NewsText4[64];
		char NewsText5[64];
		char NewsText6[64];
		char NewsText7[64];
		char NewsText8[64];
		char NewsText9[64];
		char NewsText10[64];
		char NewsText11[64];
		char NewsText12[64];
		char NewsText13[64];
		char NewsText14[64];
		char NewsText15[64];
		char NewsText16[64];
		char NewsText17[64];
		char NewsText18[64];
		char NewsText19[64];
		char NewsText20[64];
		char NewsText21[64];
		char NewsText22[64];
		char NewsText23[64];
		char NewsText24[64];
		char NewsText25[64];
		char NewsText26[64];
		char NewsText27[64];
		char NewsText28[64];
		char NewsText29[64];
		char NewsText30[64];
		char NewsText31[64];
		char NewsText32[64];
		char NewsText33[64];
		char NewsText34[64];
		char NewsText35[64];
		char NewsText36[64];
		//--
		WORD ColorText0_R;
		WORD ColorText0_G;
		WORD ColorText0_B;
		WORD ColorText1_R;
		WORD ColorText1_G;
		WORD ColorText1_B;
		WORD ColorText2_R;
		WORD ColorText2_G;
		WORD ColorText2_B;
		WORD ColorText3_R;
		WORD ColorText3_G;
		WORD ColorText3_B;
		WORD ColorText4_R;
		WORD ColorText4_G;
		WORD ColorText4_B;
		WORD ColorText5_R;
		WORD ColorText5_G;
		WORD ColorText5_B;
		WORD ColorText6_R;
		WORD ColorText6_G;
		WORD ColorText6_B;
		WORD ColorText7_R;
		WORD ColorText7_G;
		WORD ColorText7_B;
		WORD ColorText8_R;
		WORD ColorText8_G;
		WORD ColorText8_B;
		WORD ColorText9_R;
		WORD ColorText9_G;
		WORD ColorText9_B;
		WORD ColorText10_R;
		WORD ColorText10_G;
		WORD ColorText10_B;
		WORD ColorText11_R;
		WORD ColorText11_G;
		WORD ColorText11_B;
		WORD ColorText12_R;
		WORD ColorText12_G;
		WORD ColorText12_B;
		WORD ColorText13_R;
		WORD ColorText13_G;
		WORD ColorText13_B;
		WORD ColorText14_R;
		WORD ColorText14_G;
		WORD ColorText14_B;
		WORD ColorText15_R;
		WORD ColorText15_G;
		WORD ColorText15_B;
		WORD ColorText16_R;
		WORD ColorText16_G;
		WORD ColorText16_B;
		WORD ColorText17_R;
		WORD ColorText17_G;
		WORD ColorText17_B;
		WORD ColorText18_R;
		WORD ColorText18_G;
		WORD ColorText18_B;
		WORD ColorText19_R;
		WORD ColorText19_G;
		WORD ColorText19_B;
		WORD ColorText20_R;
		WORD ColorText20_G;
		WORD ColorText20_B;
		WORD ColorText21_R;
		WORD ColorText21_G;
		WORD ColorText21_B;
		WORD ColorText22_R;
		WORD ColorText22_G;
		WORD ColorText22_B;
		WORD ColorText23_R;
		WORD ColorText23_G;
		WORD ColorText23_B;
		WORD ColorText24_R;
		WORD ColorText24_G;
		WORD ColorText24_B;
		WORD ColorText25_R;
		WORD ColorText25_G;
		WORD ColorText25_B;
		WORD ColorText26_R;
		WORD ColorText26_G;
		WORD ColorText26_B;
		WORD ColorText27_R;
		WORD ColorText27_G;
		WORD ColorText27_B;
		WORD ColorText28_R;
		WORD ColorText28_G;
		WORD ColorText28_B;
		WORD ColorText29_R;
		WORD ColorText29_G;
		WORD ColorText29_B;
		WORD ColorText30_R;
		WORD ColorText30_G;
		WORD ColorText30_B;
		WORD ColorText31_R;
		WORD ColorText31_G;
		WORD ColorText31_B;
		WORD ColorText32_R;
		WORD ColorText32_G;
		WORD ColorText32_B;
		WORD ColorText33_R;
		WORD ColorText33_G;
		WORD ColorText33_B;
		WORD ColorText34_R;
		WORD ColorText34_G;
		WORD ColorText34_B;
		WORD ColorText35_R;
		WORD ColorText35_G;
		WORD ColorText35_B;
		WORD ColorText36_R;
		WORD ColorText36_G;
		WORD ColorText36_B;

		//-> Custom Item Position
		WORD Item_01_Type;
		WORD Item_01_ID;
		int Item_01_SizeX;
		int Item_01_SizeY;
		int Item_01_SizeZ;
		int Item_01_PosX;
		int Item_01_PosY;
		//=======================================================
	void Load();
	#if(TEXTVN_NEW)
	char MenuGame_TextVN[MAX_RANGE_MENU][120];
	char ToggleAuto_TextVN[MAX_RANGE_TOGGLE][120];
	char TextVN_ThanMaChien[MAX_RANGE_TMC][120];
	char TSPK_TEXT_ENGINE[MAX_RANGE_TEXT][120];
	#endif

};
#define CONFIG_FILE "./Data/Custom/Local/ServerNews.bmd"
#define POSITION_FILE "./Data/Custom/Local/ItemPosition.bmd"
extern cConfig gConfig;
#endif