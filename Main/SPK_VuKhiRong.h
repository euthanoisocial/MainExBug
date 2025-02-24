#pragma once
#include "Protocol.h"
#include "Interface.h"

struct GS_ITEM00
{
	PSBMSG_HEAD	header;
	BYTE MainItemRong;
};
struct GS_ITEM06
{
	PSBMSG_HEAD	header;
	BYTE MainItemRong;
};
struct GS_ITEM07
{
	PSBMSG_HEAD	header;
	BYTE MainItemRong;
};
struct GS_ITEM08
{
	PSBMSG_HEAD	header;
	BYTE MainItemRong;
};
struct GS_ITEM09
{
	PSBMSG_HEAD	header;
	BYTE MainItemRong;
};
struct GS_ITEM10
{
	PSBMSG_HEAD	header;
	BYTE MainItemRong;
};
struct GS_ITEM11
{
	PSBMSG_HEAD	header;
	BYTE MainItemRong;
};
struct GS_ITEM12
{
	PSBMSG_HEAD	header;
	BYTE MainItemRong;
};
struct GS_ITEM13
{
	PSBMSG_HEAD	header;
	BYTE MainItemRong;
};
//---------------------------
class ITEM00
{
	public:
	void SendData(GS_ITEM00* lpMsg);
	BYTE MainItemRong;
};
class ITEM06
{
	public:
	void SendData(GS_ITEM06* lpMsg);
	BYTE MainItemRong;
};
class ITEM07
{
	public:
	void SendData(GS_ITEM07* lpMsg);
	BYTE MainItemRong;
};
class ITEM08
{
	public:
	void SendData(GS_ITEM08* lpMsg);
	BYTE MainItemRong;
};
class ITEM09
{
	public:
	void SendData(GS_ITEM09* lpMsg);
	BYTE MainItemRong;
};
class ITEM10
{
	public:
	void SendData(GS_ITEM10* lpMsg);
	BYTE MainItemRong;
};
class ITEM11
{
	public:
	void SendData(GS_ITEM11* lpMsg);
	BYTE MainItemRong;
};
class ITEM12
{
	public:
	void SendData(GS_ITEM12* lpMsg);
	BYTE MainItemRong;
};
class ITEM13
{
	public:
	void SendData(GS_ITEM13* lpMsg);
	BYTE MainItemRong;
};
extern ITEM00 GITEM00; // Vu Khi
extern ITEM06 GITEM06; // Khieng
extern ITEM07 GITEM07; // Mu
extern ITEM08 GITEM08; // Ao
extern ITEM09 GITEM09; // Quan
extern ITEM10 GITEM10; // Gang
extern ITEM11 GITEM11; // Giay
extern ITEM12 GITEM12; // Wing
extern ITEM13 GITEM13; // RingPen

