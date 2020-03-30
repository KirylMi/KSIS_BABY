#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool check(char* stroka, int sizeStr){
	bool result;
	__asm{
		mov		esi, stroka					;copy the string to the esi registry
		mov		ecx, sizeStr				;size of string -> ecx
		mov		eax,0						;eax as a counter. If it stays 0, then N of russian and latin is equal
CYCLER:
		cmp		[esi],122 ;122 = latin z	;if current symbol is z or less
		jbe		ENG;						;jump to ENGLISH
		call	RUS;						;else RUSSIAN
BACK:										;Label for returning to the Cycle
		inc esi;							;next char
		loop	CYCLER						;loop

		jmp		EXIT						;if ended -> end

			RUS:							;checking if char is russian
		cmp		[esi],224					;if it's < 224 (à)
		jb		BACK						;return (skip)
		cmp		[esi],255					;if it's > 255 (ÿ)  ;;
		ja		BACK						;return (skip)		;;
		inc		eax							;if it's inside 224-255 -> russian -> eax++
		ret
			
			ENG:							;checking if char is latin
		cmp		[esi],97					;if it's < 97 (a)
		jb		BACK						; return (skip)
		dec		eax							;If it's inside 97-122 -> english -> eax--
		jmp		BACK						;back the the cycle


EXIT:										;finishing
		mov		result, al					;if eax (al)==0, then N of russian == N of latin
	}
	return !result;							//if result == 0 -> ok;
}

void function1(char* stroka, int sizeStr){
	_asm{
		mov		esi, stroka					;esi = string
		mov		ecx, sizeStr				;ecx = size

CYCLER:										;loop for going all over the string
		cmp		[esi],65					;if current element is <65
		jb BACK								;skip if not latin
		cmp		[esi], 122					;if current element is > 122
		ja BACK								;skip if not latin

		cmp		[esi],90					;if it's <=90 -> it's small, and must be increased
		jbe		HUGEE						;for increasing the char
		call	small						;if it's > 90 -> it's huge, and must be decreased
BACK:										;for returning in the cycle
		inc esi;							;next char
		loop	CYCLER						;loop 

		jmp		EXIT						;if ended -> exit

small:										;makes the char smaller (to_smaller?)
		sub		[esi],32					;bcs A -> a difference is 32
		ret									;back to the algorithm

HUGEE:										;makes the char bigger (to_upper)
		add	[esi],32						;bcs a -> A difference is 32
		jmp		BACK						;back to the algorithm

EXIT:										;exit
	}
}

void function2(char* stroka, int sizeStr){
	
}

int main(){
	setlocale(LC_ALL, "rus");
	char stroka[] = "ðàçdvaòðèCHE.";
	int strokaSize=strlen(stroka)-1;
	check(stroka, strokaSize);
	if(check(stroka,strokaSize)){
		function1(stroka,strokaSize);
	}
	else{
		function2(stroka,strokaSize);
	}
	cout<<stroka<<"  easy"<<endl;
	system("pause");
}