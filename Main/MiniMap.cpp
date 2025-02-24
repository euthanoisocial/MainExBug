#include "stdafx.h"
#include "MiniMap.h"
#include "Import.h"
#include "Util.h"
#include "Offset.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "Common.h"
#include "MiniMapInfo.h"
#include "Central.h"
#include "WindowsStruct.h"
#include "InfoLog.h"
#include "PrintPlayer.h"
#include "CMacroUIEx.h"
#include "Extras.h"

CMinimap gRenderMap;

CMinimap::CMinimap()
{
	this->DataMap.ModelID = -1;
	this->DataMap.XSW_Minimap_Frame = 486;  //-- Minimap_FrameX
	this->DataMap.YSW_Minimap_Frame = 234;  //-- Minimap_FrameY
	this->DataMap.XSW_Minimap = 510; //-- MiniMapX
	this->DataMap.YSW_Minimap = 265; //265; //-- MiniMapY
	this->DataMap.XSW_Time_Frame = 506; //-- Time_FrameX
	this->DataMap.YSW_Time_Frame = 392; //-- Time_FrameY
	this->DataMap.This_92 = 0;
	this->DataMap.This_96 = 0;
	this->DataMap.DropMoveUserX = 0; //-- DropMoveUserX
	this->DataMap.DropMoveUserY = 0; //-- DropMoveUserY
	this->DataMap.This_108;
	this->DataMap.This_112;
	this->DataMap.CurrentMoveX = 0.0; //-- CurrentMoveX
	this->DataMap.CurrentMoveY = 0.0; //-- CurrentMoveY
	this->DataMap.Scale = 1; //-- Scale
	this->DataMap.TimerEventVK = 0; //-- Scale
	this->DataMap.Alpha = 1.0f; //-- Alpha
}

double sub_636450(float a1)
{
	return (float)((double)(unsigned int)pWinHeight * a1 / 480.0);
}

GLvoid GetDrawCircle(int ID, float X, float Y, float W, float CurrenX, float CurrenY, float SetScale, int ScaleSize, int ScalePosicion, float Alpha)
{
	float v14; // ST1C_4@1
	float v15; // ST18_4@1
	GLuint vertexcount; // ST1C_4@5
	float v33; // ST1C_4@5
	GLfloat angle; // ST1C_4@5
	GLfloat texturecoord[2]; // [sp+2Ch] [bp-40h]@5
	GLfloat VertexCoord[4]; // [sp+4Ch] [bp-20h]@5

	SetScale = SetScale / 2;
	//--
	W = W / 2;
	X = X + W;
	Y = Y + W;

	if ( ScalePosicion )
	{
		X = sub_636420( X );
		Y = sub_636450( Y );
	}

	if ( ScaleSize )
	{
		W = sub_636420( W );
	}

	v33 = (double)pWinHeight - Y;

	vertexcount = 20;

	GetBindTexture( ID );

	glBegin( GL_TRIANGLE_FAN );

	angle = 2.0 * 3.1415926 / vertexcount;
	//--
	if ( Alpha > 0.0 )
		glColor4f(1.0, 1.0, 1.0, Alpha);
	texturecoord[0] = CurrenX;
	texturecoord[1] = CurrenY;
	glTexCoord2fv(texturecoord);
	//--
	VertexCoord[0] = X;
	VertexCoord[1] = v33;
	VertexCoord[2] = 0.0;
	VertexCoord[3] = 1.0;
	glVertex4fv(VertexCoord);

	for(int i = 0; i < vertexcount ; i++) 
	{
		texturecoord[0] = (std::cos(angle * i) * SetScale) + CurrenX;
		texturecoord[1] = (std::sin(angle * i) * SetScale) + CurrenY;
		glTexCoord2fv(texturecoord);
		VertexCoord[0] = (std::cos(angle * i) * W) + X;
		VertexCoord[1] = (std::sin(angle * i) * -W) + v33;
		VertexCoord[2] = 0.0;
		VertexCoord[3] = 1.0;
		glVertex4fv(VertexCoord);
	}
	//--
	texturecoord[0] = ( 1.0 * SetScale ) + CurrenX;
	texturecoord[1] = ( 0.0 * SetScale ) + CurrenY;
	glTexCoord2fv(texturecoord);
	//--
	VertexCoord[0] = (1.0 * W) + X;
	VertexCoord[1] = (0.0 * -W) + v33;
	VertexCoord[2] = 0.0;
	VertexCoord[3] = 1.0;
	glVertex4fv(VertexCoord);
	//--
	if ( Alpha > 0.0 )
		glColor4f(1.0, 1.0, 1.0, 1.0);
	//--
	glEnd();
}

bool FileMapCheck(int map) // OK
{
	if (map - 1 == 30) { return 1; }

	char Path[64];

	wsprintf(Path, "Data\\SPK\\Maps\\TabMini\\World%d.ozt", map);

	FILE* file;

	if (fopen_s(&file, Path, "r") != 0)
	{
		return 0;
	}
	else
	{
		fclose(file);
		return 1;
	}
}

void MiniMapLoad() // OK
{
	if (pMapNumber < 100 && pMapNumber != 30)
	{
		char buff1[32];

		wsprintf(buff1, "SPK\\Maps\\TabMini\\World%d.tga", (pMapNumber + 1));
		MiniMap = 0;

		if (FileMapCheck((pMapNumber + 1)) != 0)
		{
			MiniMap = 1;
			LoadBitmapA(buff1, 550000, 0x2601, 0x2900, 1, 0);
		}
	}
}

void LoadObjectMapCore() // OK
{
	((void(*)())0x00629180)();

	MiniMapLoad();
}

void CMinimap::LoadImages(char* a1, int a2, int a3, int a4, int a5, int a6)
{
	LoadBitmapA(a1, a2, a3, a4, a5, a6);
}

DWORD CRadara1;
DWORD CRadara2;
DWORD CRadara3;

__declspec(naked) void CMinimap::CreateRadar()
{
	static DWORD CReturn01 = 0x005FC88D;
	static DWORD CReturn02 = 0x005FC881;

	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP + 0x8]
		MOV CRadara1, EDX
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0xC]
		MOV CRadara2, EAX
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x10]
		MOV CRadara3, EAX
	}
	// ----
	if (CRadara3 == ITEM2(6, 65) || CRadara3 == ITEM2(6, 66) || CRadara3 == ITEM2(6, 67))
	{
		// ----
		glColor3fv((GLfloat*)(CRadara1 + 72));
		// ----
		RenderMesh(CRadara1,
			1,
			2,
			*(float*)(CRadara2 + 152),
			*(DWORD*)(CRadara2 + 68),
			*(float*)(CRadara2 + 100),
			*(float*)(CRadara2 + 104),
			*(float*)(CRadara2 + 108),
			-1);

		float FormulaX = (float)(pGetUserCoorX - 22.0f) / 512;
		float FormulaY = -(float)(pGetUserCoorY - 234.5f) / 512;

		RenderMesh(CRadara1,
			0,
			2,
			*(float*)(CRadara2 + 152),
			0,
			*(float*)(CRadara2 + 100),
			FormulaX,
			FormulaY,
			550000);
		_asm
		{
			Jmp CReturn02
		}
	}
	// ----
	_asm
	{
		CMP DWORD PTR SS : [EBP + 0x10] , 0x10A6 //Flameberge
		Jmp CReturn01
	}
}

//----- (0088E360) --------------------------------------------------------
char sub_88E360(int a4, int a5, int a6, int a7, float a8, float a9, float a10, float a11, int a12, int a13, int a14, float a15)
{
	int v15; // eax@1
	float v16; // ST10_4@1
	float v17; // ST0C_4@1
	float v18; // ST08_4@1
	float v19; // ST04_4@1

	glColor4f(1.0, 1.0, 1.0, a15);
	v15 = pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu);
	v16 = (double)a7;
	v17 = (double)a6;
	v18 = (double)a5;
	v19 = (double)a4;
	RenderBitMapColored(a12 + 31486, v19, v18, v17, v16, a8, a9, a10, a11, v15);
	return 1;
}
#define Convert ((double(__cdecl*)(float a1)) 0x004DB0C0)

void sub_88C680()
{
	int red; // ST20_4@14
	int v7; // ST20_4@16
	int v8; // ST00_4@16
	int* v10; // ST48_4@17
	int v11; // ST20_4@19
	int v12; // ST00_4@19
	char v155; // [sp+4Ch] [bp-26Ch]@17
	float v176; // [sp+9Ch] [bp-21Ch]@7
	int v177; // [sp+A0h] [bp-218h]@7
	int v233; // [sp+2B4h] [bp-4h]@17

	v176 = 0.0;
	float v35; // [sp+338h] [bp-4h]@1

	v177 = *(float*)0x5EF5A1C * 0.001000000047497451;
	v35 = Convert(v177) + 1.0;

	v176 = (signed int)((2.0 - v35) * 127.0) / 255;

	if (*(DWORD*)0xE66DF8 > 0)
		* (DWORD*)0xE66DF8 -= 15;
	else
		*(DWORD*)0xE66DF8 = 0;
	if (15 * *(DWORD*)0xE66DD8 <= 479)
	{
		if (*(BYTE*)0xE66DD1)
		{
			v11 = *(DWORD*)0xE66DDC;
			v12 = 15 * *(DWORD*)0xE66DD8 - 329;
			*(DWORD*)(GetInstance() + 216);
			sub_88E360(v12, 50, 329, 94, 0.0, 0.0, 0.640625, 0.7265625, v11, 0, 0, v176);
		}
		else
		{
			v7 = *(DWORD*)0xE66DDC;
			v8 = 15 * *(DWORD*)0xE66DD8 + 150;
			*(DWORD*)(GetInstance() + 216);
			sub_88E360(v8, 50, 329, 94, 0.0, 0.0, 0.640625, 0.7265625, v7, 0, 0, v176);
			if (15 * ++ * (DWORD*)0xE66DD8 > 479)
			{
				*(DWORD*)0xE66DD8 = 0;
				*(BYTE*)0xE66DD1 = -1;
				*(DWORD*)0xE66DF8 = 390;
				*(BYTE*)0x9867469 = 1;
				v233 = 0;
				v233 = -1;
			}
		}
	}
	else
	{
		red = *(DWORD*)0xE66DDC;
		*(DWORD*)(GetInstance() + 216);
		sub_88E360(150, 50, 329, 94, 0.0, 0.0, 0.640625, 0.7265625, red, 0, 0, v176);
	}
}

void DataViewPortMapUser(float x, float y, float charx, float chary)
{
	int v4; // eax@4
	float v5; // ST34_4@16
	float v6; // ST38_4@16
	int v7; // [sp+24h] [bp-18h]@1
	int v8; // [sp+2Ch] [bp-10h]@4
	signed int i; // [sp+30h] [bp-Ch]@1

	for (i = 0; i < 400; ++i)
	{
		v8 = pGetPreviewStruct(pPreviewThis(), i);
		if (v8 && *(BYTE*)(v8 + 780) && v8 != dword_7BC4F04
			&& (*(BYTE*)(v8 + 800) == 1 || *(BYTE*)(v8 + 800) == 2 || *(BYTE*)(v8 + 800) == 4))
		{
			if (*(BYTE*)(v8 + 800) != 4 && (*(BYTE*)(v8 + 800) != 2 || *(DWORD*)(v8 + 824) != 730))
				glColor4f(0.80000001, 0.0, 0.0, 1.0);
			else
				glColor4f(1.0, 0.0, 1.0, 1.0);

			v5 = (double)(x + *(DWORD*)(v8 + 172) / 0.5 - charx) - 2.0;
			v6 = (double)(y + (256 - *(DWORD*)(v8 + 176)) / 0.5 - chary) - 4.0;
			pDrawBarForm(v5, v6, 4.0, 4.0, 0.0, 0);
			pGLSwitch();

			if (pCheckMouseOver((int)v5, (int)v6, (int) 4.0, (int) 4.0))
			{
				pDrawToolTip((int)v5, (int)v6 - 10, (char*)(v8 + 56));
			}
		}
	}
}

//----- (0082ABA0)
char GetFullMap(UIMiniMap* thisa)
{
	float Rot = 45.f;
	if (MiniMap)
	{
		float x, y;
		float XNPC = 0;
		float YNPC = 0;
		thisa->m_Width.x = 500;
		thisa->m_Width.y = 300;
		thisa->m_Pos.x = MAX_WIN_WIDTH / 2.f - (thisa->m_Width.x/2);
		thisa->m_Pos.y = (MAX_WIN_HEIGHT - 55) / 2.f - (thisa->m_Width.y/2);

		x = thisa->m_Pos.x;
		y = thisa->m_Pos.y;

		float DIRPointer;

		EnableAlphaTest(1);
		pDrawBarForm(x - 5, y - 5, thisa->m_Width.x + 10, thisa->m_Width.y + 10, 0.45000002, 1);
		pGLSupremo();
		EnableAlphaTest(1);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		CRenderBitmaps(550000, x, y, thisa->m_Width.x, thisa->m_Width.y, 0.0, 0.0, 1.f, 1.f, 1, 1, 0);
		pDrawGUI(50000, x - 5, y - 5, 510.0f, 310.0f);

		POINTFLOAT m_CurHero = { (float)(*(int*)(Hero + 172)) / 256.0, (float)(256.0 - *(int*)(Hero + 176)) / 256.0 };
		EnableAlphaTest(1);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		for (int n = 0; n < 400; n++)
		{
			lpViewObj lpObj = &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), n);

			if (!lpObj)
			{
				continue;
			}

			if (lpObj->m_Model.Unknown4 == 0)
			{
				continue;
			}

			XNPC = (float)(x + (lpObj->MapPosX * 1.980000000000000));
			YNPC = (float)(y + ((255 - lpObj->MapPosY) * 1.190000000000000));

			DIRPointer = (lpObj->m_Model.Angle.Z) + 180.0;

			if (lpObj->m_Model.ObjectType == emPlayer)
			{
				sub_637E80(61519, XNPC+3 , YNPC-3, 10.0, 10.0, DIRPointer, 0.0, 0.0, 0.1030000001, 0.05200000107);
			}
			else if (lpObj->m_Model.ObjectType == emMonster) 
			{
				sub_637E80(61519, XNPC, YNPC, 8.0, 8.0, 0, 0.1349999905, 0.0, 0.1030000001, 0.05200000107);
			}
			else if (lpObj->m_Model.ObjectType == emNPC)
			{
				if (lpObj->ID == 251)
				{
					sub_637E80(61519, XNPC, YNPC - 0.5, 8.0, 8.0, 0, 0.009999999776, 0.1319999844, 0.1030000001, 0.05200000107);
				}
				else if (lpObj->ID == 255 || lpObj->ID == 253) //Potion
				{
					sub_637E80(61519, XNPC + 5, YNPC - 8, 8.0, 8.0, 0, 0.1349999905, 0.1319999844, 0.1030000001, 0.05200000107);
				}
				else if (lpObj->ID == 240) //-- Baul
				{
					sub_637E80(61519, XNPC, YNPC, 8.0, 8.0, 0, 0.009999999776, 0.1920999587, 0.1030000001, 0.05200000107);
				}
				else if (lpObj->ID == 229 || lpObj->ID == 235 || lpObj->ID == 233 || lpObj->ID == 237) //-- Quest
				{
					sub_637E80(61519, XNPC, YNPC, 8.0, 8.0, 0, 0.0, 0.06599999219, 0.1030000001, 0.05200000107);
				}
				else
				{
					sub_637E80(61519, XNPC, YNPC - 5, 8.0, 8.0, 0, 0.1349999905, 0.06599999219, 0.1030000001, 0.05200000107);
				}
			}
			if (pCheckMouseOver((int)XNPC - 5, (int)YNPC - 7, (int)8, (int)8))
			{
				pDrawToolTip((int)XNPC, (int)YNPC - 10, (char*)(lpObj->Name));
			}
		}
	}
	return MiniMap;
}

bool pDisabledMouseMAP(int x, int y, int w, int h)
{
	return 0;
}

void CMinimap::MiniMapload()
{
	SetCompleteHook(0xFF, 0x0062EB26, &LoadObjectMapCore); //ok
	SetCompleteHook(0xE8, 0x007C206F, this->LoadImages);
	SetCompleteHook(0xE9, 0x0082ABA0, &GetFullMap);
	SetCompleteHook(0xE8, 0x0082B772, &pDisabledMouseMAP); //ok
}