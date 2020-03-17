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
//s
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

//russkiy - ne hochet. english (checkold == working). 
//problema v tom, 4to russkie simvoly v chare predstavleny kak -33..-1 (primerno). Otricatelnye zna4enia nelz9 sravnivatb c ESI v kotorom char -> 
//1) Poprosit y nego delatb drygoi varik
//2) Sprositb y nego pro etot rofl
//3) Pon9tb, kakogo xrena voobshe eto proisxodit
//4) KosbIlb dl9 russkogo 9zika
//����� �����-��, ��������� ����� �������������, ��� ����� ��� �������������, �� ���������� Ũ � [ESI] ������ (������������� ��������)
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