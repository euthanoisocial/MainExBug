#include "StdAfx.h"
#include "Slide.h"
#include "Defines.h"
#include "TMemory.h"
#include "Import.h"

CSlide gSlide;

void CSlide::Load()
{
 SetOp((LPVOID)0x00425472,(LPVOID)this->SetPosition,ASM::CALL);
 SetOp((LPVOID)0x00425484,(LPVOID)this->SetPosition,ASM::CALL);
 printf("gSlide::Load() Success.");

}

int CSlide::SetPosition(DWORD This,int X,int Y)
{
	Y = 429;
	return pSlideSetPosition(This,X,Y);
}