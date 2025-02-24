#include "Defines.h"
#include "Protocol.h"
#if BXHDAME
struct SPK_DAMEBOSS_STR
{
	WORD monsterid;
	int Level;
	float MinLife;
	float MaxLife;
	char szName[11];
	QWORD Kill;
};

class SPK_DAMEBOSS_CLASS
{
	public:
	
	WORD SPK_DAMEBOSS_ID;
	int Level;
	float MinLife;
	float MaxLife;

	int CalcString ;
	void DAMEGETINFO(PMSG_NEW_HEALTH_BAR_RECV* lpMsg);
	void DAMEDRAW();
	SPK_DAMEBOSS_STR gDmgBoss[10];
	void DAMECLEAR();
	bool CheckDrawBxhDame;
	BYTE ADD_OFF_ANTOAN;
	void Initz();
private:
	float guiX;
	float guiY;
	short curX;
	short curY;
	bool  dragging;
	DWORD ActionTime;
	bool is_move;
};
extern SPK_DAMEBOSS_CLASS gDmgBoss;

#endif
