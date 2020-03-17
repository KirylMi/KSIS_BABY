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
		cmp		[esi],97 ;97 = latin a
		jge		ENG;
		call	RUS;
BACK:
		inc esi;
		loop	CYCLER

		jmp		EXIT
			RUS:
		cmp		[esi],-1
		jl		BACK
		cmp		[esi],0
		jg		BACK
		inc		eax
		ret
			
			ENG:
		cmp		[esi],122
		jg		BACK
		dec		eax
		jmp		BACK


EXIT:
		mov		result, al
			; sub		esi, sizeStr
	}
	return !result;
}


//œ»œ≈÷  ¿ Œ…-ÚÓ,  »–»ÀÀ»÷¿ »Ã≈≈“ œ–≈ƒ—“¿¬À≈Õ»≈,  ¿  ¡”ƒ“Œ ŒÕ¿ Œ“–»÷¿“≈À‹Õ¿ﬂ, ÕŒ —–¿¬Õ»¬¿“‹ ≈® — [ESI] Õ≈À‹«ﬂ (ŒÚËˆ‡ÚÂÎ¸Ì˚Â ÁÌ‡˜ÂÌËˇ)
//

bool checkold(char* stroka, int sizeStr) {
	bool result;
	__asm {
		mov		esi, stroka
		mov		ecx, sizeStr
		mov		eax, 0

		CYCLER:
		cmp[esi], 92
			jle		HUGEE
			call	small
			BACK :
		inc esi;
		loop	CYCLER

			jmp		EXIT
			small :
		inc		eax
			ret
			HUGEE :
		dec		eax
			jmp		BACK


			EXIT :
		mov		result, al
	}
	return !result;
}

void function1(char* stroka, int sizeStr){
	_asm{
		mov		esi, stroka
		mov		ecx, sizeStr

CYCLER:
		cmp		[esi],92
		jle		HUGEE
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
	char stroka[] = "oneTWO.";
	int strokaSize=strlen(stroka)-1;
	checkold(stroka, strokaSize);
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