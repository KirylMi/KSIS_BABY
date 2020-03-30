.MODEL  Huge    
.STACK 100h
    .data
    Msg db "Test eydaleniya probev$"
    .CODE
START:
		checkProb MACRO stroka, strsize
			mov     ax, @Data           ;Start initialization of DATA
			mov     ds, ax              ; 
			mov     cx, strsize         ;ecx==size of string
			mov     bx,OFFSET stroka	;Nash Msg to bx

				CYCLER:                 ;main loop
			cmp     byte ptr [bx], 32	;If current one is ' '
			je     Skipper				;Skip it
			call COPIER					;Copy the current symbol
			inc 	bx					;Next symbol to copy
			inc  	di					;Next symbol to paste
			loop CYCLER					;
        
			jmp     EXIT				;if loop finished -> end
        
				Skipper:				;micro-function for skipping the symbol(' ') to copy
			inc bx						;just jump to the next one
			loop CYCLER					;
        
			jmp     EXIT				;if loop finished -> end
        
				COPIER:					;Copies current [bx] to the [di]
			mov  	al, [bx]			;al = temp, bcs bx to di is not avaiable (po4emy?)
			mov 	[di], al			;
			ret							;

				EXIT:                   ;exit function (printing the value)
			mov 	di, 0				;Placing the di pointer to the start
			mov 	dx, di				;Copying the di data to dx (for the 09h output function)
			mov 	ah, 09h				;int 21h function for outputting the string (in dx)
			int 	21h					;Calling the 'preryvanie'
			mov     ax,4C00h			;From 1-oi metodi4ki == preryvanie vixoda
			int     21h  
		endm
		checkProb Msg, 23;
END start