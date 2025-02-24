#include "StdAfx.h"
#include "CustomMessage.h"
#include "SEASON3B.h"

char * GlobalText2(int iNum, bool custom)
{
	if(custom == false)
	{
		return iGlobalText(GlobalLine, iNum);
	}
	else
	{
		return gCustomMessage.GetMessage(iNum);
	}
}
