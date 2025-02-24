#include "stdafx.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "Interface.h"
//#include "zzzMathLib.h"
#include "Protect.h"
//#include "NewFont.h"
#include "CustomFont.h"
#include "CustomMessage.h"
#include "NoticeSelectServer.h"

extern DWORD		Test_Buff;
extern char		Test_LevelBuff[40];

//__declspec(naked) void Notices()
__declspec(naked) void NoticesSlSrv()
{
	int PosX;
	int PosX2;
	PosX = 480; //Demas textos
	PosX2 = 510; //Texto Principal

 #if HORA_SERVER
	//-- Hora+Fecha
	char fecha[25];
	time_t current_time;
	current_time = time(NULL);
	ctime(&current_time);
	strcpy(fecha, ctime(&current_time));

	//-- Hora+Fecha
	gInterface.DrawFormat(eWhite, 510, 5, 250, 1, "%s", fecha); //500 mover lados//40 mover arriba,abajo//250 etc
#endif

	pSetBlend(false);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8); // Transparencia
	pDrawBarForm(475.0, 40.0, 160.0, 395.0, 0.0f, 0); // Primer Valor= EjeX <> / Segundo Valor= Arriba y Abajo / Tercer Valor= Ancho Del Cuadro / Cuarto Valor Tamaño de Arriba y Abajo del Cuadro
	pGLSwitchBlend();
	glColor3f(1.0, 1.0, 1.0);

	CustomFont.Draw(CustomFont.FontSize25, PosX2, 50, 0xDAA520FF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(75));
													 
	CustomFont.Draw(CustomFont.FontSize21, PosX, 80, 0x8B0000FF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(76));

	CustomFont.Draw(CustomFont.FontSize16, PosX, 100, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(77));
	CustomFont.Draw(CustomFont.FontSize16, PosX, 115, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(78));
	CustomFont.Draw(CustomFont.FontSize16, PosX, 130, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(79));

	CustomFont.Draw(CustomFont.FontSize21, PosX, 150, 0x8B0000FF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(80));

	CustomFont.Draw(CustomFont.FontSize16, PosX, 170, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(81));
	CustomFont.Draw(CustomFont.FontSize16, PosX, 185, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(82));	
	CustomFont.Draw(CustomFont.FontSize16, PosX, 200, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(83));	

	CustomFont.Draw(CustomFont.FontSize21, PosX, 220, 0x8B0000FF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(84));

	CustomFont.Draw(CustomFont.FontSize16, PosX, 240, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(85));
	CustomFont.Draw(CustomFont.FontSize16, PosX, 255, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(86));	
	CustomFont.Draw(CustomFont.FontSize16, PosX, 270, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(87));	

	CustomFont.Draw(CustomFont.FontSize21, PosX, 290, 0x8B0000FF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(88));

	CustomFont.Draw(CustomFont.FontSize16, PosX, 310, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(89));
	CustomFont.Draw(CustomFont.FontSize16, PosX, 325, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(90));	
	CustomFont.Draw(CustomFont.FontSize16, PosX, 340, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(91));	

	CustomFont.Draw(CustomFont.FontSize21, PosX, 360, 0x8B0000FF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(92));

	CustomFont.Draw(CustomFont.FontSize16, PosX, 380, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(93));
	CustomFont.Draw(CustomFont.FontSize16, PosX, 395, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(94));	
	CustomFont.Draw(CustomFont.FontSize16, PosX, 410, 0xFFFFFFFF, 0x0, 0, 0, 0, gCustomMessage.GetMessage(95));

	gInterface.DrawFormat(eYellow, (MAX_WIN_WIDTH / 2) - 115, 470, 220, 3, "(c) Copyright 2001 Webzen - UmbrellaGaming.");

	//gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 70, 470, 200, 0, "%s (C) Copyright 2004 - 2021. All Rights Reserved." , gProtect.m_MainInfo.WindowName); //Trabaja con MainInfo-Tools

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

void InitCNewUINotice()
{
	SetRange((PVOID)0x004D7DAD, 0x0f, ASM::NOP);
    //SetOp((LPVOID)0x004D7D13, (LPVOID)Notices, ASM::JMP);
    SetOp((LPVOID)0x004D7D13, (LPVOID)NoticesSlSrv, ASM::JMP);
}