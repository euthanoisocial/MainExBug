#pragma once
#include "Protocol.h"
#include "Object.h"

#define VIEWCHARITEMS TRUE
#if(VIEWCHARITEMS)
struct CharItems
{
	BYTE Result;
	char Guild[9];
	char Name[11];
};

class cViewCharItems
{
	public:
	void ClearSession();
	CharItems charItem;
};

extern cViewCharItems ViewCharItems;
#endif

