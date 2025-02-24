#include "StdAfx.h"
#include "Util.h"
#include "SEASON3B.h"
#include "CustomPet.h"
#include "NewUIMyInventory.h"
#include "CharacterMachine.h"
#include "GIPetManager.h"

namespace giPetManager
{
	void Create_PetDarkSpirit ( int c, int Model)
	{
		SetDword(0x004F1316 + 1, Model);
		((void(__cdecl*)(int)) 0x004F8B80)(c);
		SetDword(0x004F1316 + 1, 0xE3);
	}

	void CreatePetDarkSpirit_Now( int c )
	{
		((void(__cdecl*)(int)) 0x004F8C30)(c);
	}

	PET_INFO* GetPetInfo(int pItem)
	{
		/*if ( *(WORD *)pItem != 6661 && *(WORD *)pItem != 6660 && *(WORD *)pItem != 0xFFFF)
		{
			return (PET_INFO*)*(DWORD *)(Hero + 680);//Get_EquipedPetInfo((char*)Hero, PET_TYPE_DARK_SPIRIT);
		}*/
		return ((PET_INFO*(__cdecl*)(int)) 0x004F9930)(pItem);
	}

	void SetPetInfo(int PetSystem, PET_INFO* pPetInfo)
	{
		*(DWORD *)(PetSystem + 1448) = (int)pPetInfo;
	}

	void DeletePet( int c )
	{
		((void(__cdecl*)(int)) 0x004F94A0)(c);
	}

	void InitDarkSpirit()
	{
		SetCompleteHook(0xE8, 0x004F8D62, &GetPetInfo);
		SetCompleteHook(0xE8, 0x004F9CBD, &GetPetInfo);
		SetCompleteHook(0xE8, 0x0051BCD1, &GetPetInfo);
		SetCompleteHook(0xE8, 0x0057FEE5, &GetPetInfo);
		SetCompleteHook(0xE8, 0x0058DCBF, &GetPetInfo);
		SetCompleteHook(0xE8, 0x0058FDE5, &GetPetInfo);
		SetCompleteHook(0xE8, 0x0059092A, &GetPetInfo);
		SetCompleteHook(0xE8, 0x007DD3A8, &GetPetInfo);
		SetCompleteHook(0xE8, 0x00834138, &GetPetInfo);


		/*SetCompleteHook(0xE8, 0x004F8B9F, &DeletePet);
		SetCompleteHook(0xE8, 0x004F8C61, &DeletePet);
		SetCompleteHook(0xE8, 0x0057D6DE, &DeletePet);
		SetCompleteHook(0xE8, 0x0057D826, &DeletePet);
		SetCompleteHook(0xE8, 0x0057D918, &DeletePet);
		SetCompleteHook(0xE8, 0x0057DBF8, &DeletePet);
		SetCompleteHook(0xE8, 0x0057DCAF, &DeletePet);
		SetCompleteHook(0xE8, 0x0057DDA0, &DeletePet);
		SetCompleteHook(0xE8, 0x005C811C, &DeletePet);
		SetCompleteHook(0xE8, 0x0063F350, &DeletePet);
		SetCompleteHook(0xE8, 0x006412CA, &DeletePet);
		SetCompleteHook(0xE8, 0x00833BBD, &DeletePet);
		SetCompleteHook(0xE8, 0x008CC5A8, &DeletePet);*/

	}
}