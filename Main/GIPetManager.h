#pragma once
//#include "_struct.h"
#include "pet.h"
#define Get_EquipedPetInfo					((int(__thiscall*)(char* This, int iPetType)) 0x004CCC40)

namespace giPetManager
{
	enum PET_TYPE
	{
		PET_TYPE_NONE		 = -1,
		PET_TYPE_DARK_SPIRIT = 0,
		PET_TYPE_DARK_HORSE,
		PET_TYPE_END
	};

	void Create_PetDarkSpirit(int c, int Model);
	void CreatePetDarkSpirit_Now( int c );
	PET_INFO* GetPetInfo(int pItem);
	void SetPetInfo(int PetSystem, PET_INFO* pPetInfo);


	void DeletePet( int c );
	void InitDarkSpirit();
}
