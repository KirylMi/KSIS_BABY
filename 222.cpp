#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


//bool check(char* stroka, int sizeStr){
//	bool result;
//	__asm{
//		mov		esi, stroka
//		mov		ecx, sizeStr
//		mov		eax,0
//
//CYCLER:
//		cmp		[esi],92
//		jle		HUGEE
//		call	small
//BACK:
//		inc esi;
//		loop	CYCLER
//
//		jmp		EXIT
//small:
//		inc		eax
//		ret
//HUGEE:
//		dec		eax
//		jmp		BACK
//
//
//EXIT:
//		mov		result, al
//	}
//	return !result;
//}

bool check(char* stroka, int sizeStr){
	bool result;
	__asm{
		mov		esi, stroka
		mov		ecx, sizeStr
		mov		eax,0
CYCLER:
		cmp		[esi],122 ;122 = latin z
		jbe		ENG;
		call	RUS;
BACK:
		inc esi;
		loop	CYCLER

		jmp		EXIT
			RUS:
		cmp		[esi],224
		jb		BACK
		;cmp		[esi],255
		;ja		BACK
		inc		eax
		ret
			
			ENG:
		cmp		[esi],97
		jb		BACK
		dec		eax
		jmp		BACK


EXIT:
		mov		result, al
			; sub		esi, sizeStr
	}
	return !result;
}

//bool check(char* stroka, int sizeStr){
//	bool result;
//	__asm{
//		mov		esi, stroka
//		mov		ecx, sizeStr
//		mov		eax,0
//CYCLER:
//		mov al, [esi]
//		cmp		al,07Ah ;122 = latin z
//		jbe		ENG;
//		call	RUS;
//BACK:
//		inc esi;
//		loop	CYCLER
//
//		jmp		EXIT
//
//			RUS:
//		cmp		[esi],0E0h
//		jl		BACK
//		cmp		[esi],0FFh
//		jg		BACK
//		inc		eax
//		ret
//			
//			ENG:
//		cmp		[esi],061h
//		jl		BACK
//		dec		eax
//		jmp		BACK
//
//
//EXIT:
//		mov		result, al
//			; sub		esi, sizeStr
//	}
//	return !result;
//}

//bool checkold(char* stroka, int sizeStr) {
//	bool result;
//	__asm {
//		mov		esi, stroka
//		mov		ecx, sizeStr
//		mov		eax, 0
//
//		CYCLER:
//		cmp[esi], 92
//			jle		HUGEE
//			call	small
//			BACK :
//		inc esi;
//		loop	CYCLER
//
//			jmp		EXIT
//			small :
//		inc		eax
//			ret
//			HUGEE :
//		dec		eax
//			jmp		BACK
//
//
//			EXIT :
//		mov		result, al
//	}
//	return !result;
//}

void function1(char* stroka, int sizeStr){
	_asm{
		mov		esi, stroka
		mov		ecx, sizeStr

CYCLER:
		cmp		[esi],65
		jb BACK			;skip if not latin
		cmp		[esi], 122
		ja BACK			;skip if not latin

		cmp		[esi],90
		jbe		HUGEE
		call	small
BACK:
		inc esi;
		loop	CYCLER

		jmp		EXIT

small:
		sub		[esi],32
		ret
HUGEE:
		add	[esi],32
		jmp		BACK

EXIT:
	}
}

void function2(char* stroka, int sizeStr){
	
}

int main(){
	setlocale(LC_ALL, "rus");
	char stroka[] = "ðàçdvaòðèCHE.";
	int strokaSize=strlen(stroka)-1;
	//checkold(stroka, strokaSize);
	check(stroka, strokaSize);
	//if(check(stroka,strokaSize)){
		function1(stroka,strokaSize);
	//}
	//else{
		//function2(stroka,strokaSize);
	//}
	cout<<stroka<<"  easy"<<endl;
	system("pause");
}