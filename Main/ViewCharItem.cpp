#include "stdafx.h"
#if BXH_LUCHIEN
#include "ViewCharItem.h"
cViewCharItems ViewCharItems;

void cViewCharItems::ClearSession()
{
	ZeroMemory(this->charItem.Name, sizeof(this->charItem.Name));
	ZeroMemory(this->charItem.Guild, sizeof(this->charItem.Guild));
}
#endif