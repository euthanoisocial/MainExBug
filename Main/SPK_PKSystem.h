#include "Stdafx.h"
#if(NOTICE_PKSYSTEM)
struct DATA_NOTICEPK
{
	int Delay;
	DWORD	Color;
	DWORD	Time;
	char	Mess[90];
};

class SPKPKSystem
{
	public:
	void DrawNoticePKSystem();
	std::vector<DATA_NOTICEPK> m_DataNoticePK;
};
extern SPKPKSystem gPKSys;
#endif