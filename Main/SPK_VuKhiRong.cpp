#include "StdAfx.h"
#include "SPK_VuKhiRong.h"
#include "Console.h"

ITEM00 GITEM00;
ITEM06 GITEM06;
ITEM07 GITEM07;
ITEM08 GITEM08;
ITEM09 GITEM09;
ITEM10 GITEM10;
ITEM11 GITEM11;
ITEM12 GITEM12;
ITEM13 GITEM13;

void ITEM00::SendData(GS_ITEM00* lpMsg)
{
	this->MainItemRong = lpMsg->MainItemRong;
}
void ITEM06::SendData(GS_ITEM06* lpMsg)
{
	this->MainItemRong = lpMsg->MainItemRong;
}

void ITEM07::SendData(GS_ITEM07* lpMsg)
{
	this->MainItemRong = lpMsg->MainItemRong;
}

void ITEM08::SendData(GS_ITEM08* lpMsg)
{
	this->MainItemRong = lpMsg->MainItemRong;
}

void ITEM09::SendData(GS_ITEM09* lpMsg)
{
	this->MainItemRong = lpMsg->MainItemRong;
}

void ITEM10::SendData(GS_ITEM10* lpMsg)
{
	this->MainItemRong = lpMsg->MainItemRong;
}

void ITEM11::SendData(GS_ITEM11* lpMsg)
{
	this->MainItemRong = lpMsg->MainItemRong;
}

void ITEM12::SendData(GS_ITEM12* lpMsg)
{
	this->MainItemRong = lpMsg->MainItemRong;
}

void ITEM13::SendData(GS_ITEM13* lpMsg)
{
	this->MainItemRong = lpMsg->MainItemRong;
}

