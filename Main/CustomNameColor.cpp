#include "stdafx.h"
#include "Item.h"
#include "TMemory.h"
#include "Import.h"
#include "CustomNameColor.h"
#include "ToolKit.h"
#include "Defines.h"
//--
CustomNameColor gCustomNameColor;
//--
DWORD DivineWeapon_Buff=0;
DWORD DivineWeapon_Pointer=0;
DWORD DropColorProtect;
DWORD DropColorPointer;

void CustomNameColor::Load()
{
	SetRange((LPVOID)0x007E7827,4,ASM::NOP);
	SetOp((LPVOID)0x007E7827,(LPVOID) this->DivineWeapon,ASM::JMP);
	//--
	SetRange((LPVOID)0x005F479E,10,ASM::NOP);
	SetOp((LPVOID)0x005F479E,(LPVOID) this->DropColor,ASM::JMP);
}

Naked(CustomNameColor::DivineWeapon)
{
	static DWORD DivineWeaponAdress1=0x007E785F;
	static DWORD DivineWeaponAdress2=0x007E7866;
	_asm
	{
		Mov DivineWeapon_Buff,Edx
		MOVSX EDX,WORD PTR SS:[EBP+0x8]
		mov DWORD PTR SS:[EBP+0x8],Edx
		mov DivineWeapon_Pointer,Edx
		Mov Edx,DivineWeapon_Buff
	}
	if(DivineWeapon_Pointer==0x13
		||DivineWeapon_Pointer==0x812
		||DivineWeapon_Pointer==0x0A0A
		||DivineWeapon_Pointer==0x40D
		||DivineWeapon_Pointer==0x0A24
		||DivineWeapon_Pointer==ITEM(0,60) //Vuốt Thiên Tử 1
		||DivineWeapon_Pointer==ITEM(0,61) //Vuốt Thiên Tử (Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(2,25) //Trượng Thiên Tử (Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(5,49) //Gậy Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(4,30) //Nỏ Hỏa Long (Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(0,51) //Thiên Tử Kiếm (Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(5,50) //Gậy Thiên Nữ (Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(0,47) //Thiên Tử Kiếm MG (Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(0,48) //Thiên Tử Kiếm MG(Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(0,90) //Thiên Tử Kiếm MG(Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(0,91) //Thiên Tử Kiếm MG(Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(0,92) //Thiên Tử Kiếm MG(Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(0,94) //Thiên Tử Kiếm MG(Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(0,95) //Thiên Tử Kiếm MG(Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(0,98) //Thiên Tử Kiếm MG(Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(0,99) //Thiên Tử Kiếm MG(Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(3,111) //Thiên Tử Kiếm MG(Cấp 1)
		||DivineWeapon_Pointer==ITEM(3,112) //Thiên Tử Kiếm MG(Cấp 2)
		||DivineWeapon_Pointer==ITEM(0,64) //Thiên Tử Kiếm MG(Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(2,35) //Thiên Tử Kiếm (Cấp 1) 1
		||DivineWeapon_Pointer==ITEM(2,44) //Thiên Tử Kiếm (Cấp 1) 1
		||DivineWeapon_Pointer==ITEM(2,91) //Thiên Tử Kiếm (Cấp 1) 1
		||DivineWeapon_Pointer==ITEM(3,90) //Thiên Tử Kiếm (Cấp 1) 1
		||DivineWeapon_Pointer==ITEM(4,38) //Cung Hỏa Long (Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(4,90) //Thiên Tử Kiếm (Cấp 1) 1
		||DivineWeapon_Pointer==ITEM(4,91) //Thiên Tử Kiếm (Cấp 1) 1
		||DivineWeapon_Pointer==ITEM(2,35) //Thiên Tử Kiếm (Cấp 1) 1
		||DivineWeapon_Pointer==ITEM(5,50) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(5,61) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(5,90) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(5,91) //Cung Hỏa Long (Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(5,92) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(5,54) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(5,95) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(5,96) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(6,90) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(6,91) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(5,93) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(5,94) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(4,92) //Cung Hỏa Long (Cấp 2) 1
		||DivineWeapon_Pointer==ITEM(2,92) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(0,88) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(0,89) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(0,93) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(0,96) //Cung Hỏa Long (Cấp 2)
		||DivineWeapon_Pointer==ITEM(0,97) //Cung Hỏa Long (Cấp 2)
		)
	{
		_asm{Jmp DivineWeaponAdress1}
	}
	else
	{
		_asm{Jmp DivineWeaponAdress2}
	}
}

Naked(CustomNameColor::DropColor)
{
	_asm
	{
		Mov DropColorProtect,Eax
		MOV EDX,DWORD PTR SS:[EBP-0x18]
		Mov Eax,DWORD PTR DS:[EDX+0x30]
		Mov DropColorPointer,Eax
		Mov Eax,DropColorProtect
	}
	if(DropColorPointer==0x253B)
	{
		_asm{
			Mov DropColorPointer,0x005F47AA//Cam
			Jmp DropColorPointer
		}
	}
	else if(
		
			DropColorPointer==ITEM2(0,60) //Vuốt Thiên Tử 
		  ||DropColorPointer==ITEM2(0,61)//Vuốt Thiên Tử (Cấp 2)
		  ||DropColorPointer==ITEM2(2,25)//Trượng Thiên Tử (Cấp 2)
		  ||DropColorPointer==ITEM2(5,49)//Gậy Hỏa Long (Cấp 2)
		  ||DropColorPointer==ITEM2(4,30)//Nỏ Hỏa Long (Cấp 2)
		  ||DropColorPointer==ITEM2(0,51)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(5,50)//Gậy Thiên Nữ (Cấp 2)
		  ||DropColorPointer==ITEM2(0,47)//Nỏ Hỏa Long (Cấp 2)
		  ||DropColorPointer==ITEM2(0,48)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(0,90)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(0,91)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(0,92)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(0,94)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(0,95)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(0,98)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(0,99)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(3,111)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(3,112)//Thiên Tử Kiếm (Cấp 2)
		  ||DropColorPointer==ITEM2(0,64)//Gậy Thiên Nữ (Cấp 2)
		  ||DropColorPointer==ITEM2(2,35)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(2,44)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(2,91)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(3,90)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(4,38)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(4,90)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(4,91)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(2,35)//Thiên Tử Kiếm (Cấp 1)	
		  ||DropColorPointer==ITEM2(5,50)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(5,61)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(5,90)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(5,91)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(5,92)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(5,54)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(5,95)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(5,96)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(6,90)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(6,91)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(5,93)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(5,94)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(4,92)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(2,92)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(0,88)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(0,89)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(0,93)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(0,96)//Thiên Tử Kiếm (Cấp 1)
		  ||DropColorPointer==ITEM2(0,97)//Thiên Tử Kiếm (Cấp 1)
		  )
	{
		_asm
		{
			Mov DropColorPointer,0x005F4918//Tím
			Jmp DropColorPointer
		}
	}
	else if(DropColorPointer==ITEM2(14,14)
		||DropColorPointer==ITEM2(5,50))
	{
		_asm
		{
			mov DropColorPointer,0x005F439E//Màu vàng
			jmp DropColorPointer
		}
	}
	else
		{
		_asm{
			Mov DropColorPointer,0x005F47BC//Kế tiếp
			Jmp DropColorPointer
		}
	}
}
