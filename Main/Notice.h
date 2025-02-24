#pragma once
#pragma once
// -------------------------------------------------------------------------------

#include "Protocol.h"
#include <WinDef.h>
// -------------------------------------------------------------------------------

#define MAX_CUSTOM_Notice 100

//void InitNotices();
void InitNoticesTue();

struct CUSTOM_Notice_INFO
{
	int Index;
	int Color;
	char Notice[40];
	char Description[40];
};

class CCustomNoticeInfo
{
public:
	CCustomNoticeInfo();
	~CCustomNoticeInfo();

	void Init();
	void Load(CUSTOM_Notice_INFO* info);
	void SetInfo(CUSTOM_Notice_INFO info);
	CUSTOM_Notice_INFO* GetInfo(int index);
	void DrawNoticeWindow();
	void OpenNoticeWindow();
	bool EventNoticeWindow_Close(DWORD Event);
	bool NoticeNext(DWORD Event);
	bool NoticePrev(DWORD Event);
	// ----
public:
	CUSTOM_Notice_INFO m_CustomNoticeInfo[MAX_CUSTOM_Notice];
	int Page;
	int Count;
	// ----
}; extern CCustomNoticeInfo gCustomNoticeInfo;
// -------------------------------------------------------------------------------