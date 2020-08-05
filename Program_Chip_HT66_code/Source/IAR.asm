; PROGRAM : IAR.ASM  		        				By Steven                    
; FUNCTION: Indirect Addressing DEMO PROGRAM        2019.0305
; 首先觀察 RAM Sector 0,3,4 之內容      		  
#INCLUDE    HT66F2390.INC 
;=================================================================================
MY_DATA    .SECTION		'DATA'          ;== DATA SECTION == 
Array1		DB 128 dup(?)        		;Reserve 128 Byte with Start Address -> Array 
RAMBANK 3  	MY_DATA1
MY_DATA1 	.SECTION	'DATA'          ;== DATA SECTION == 
Array2		DB 128 dup(?)        		;Reserve 128 Byte with Start Address -> Array 

RAMBANK 4  	MY_DATA2
MY_DATA2 	.SECTION	'DATA'          ;== DATA SECTION == 
Array3		DB 128 dup(?)        		;Reserve 128 Byte with Start Address -> Array 

;========================================================================================
MY_CODE    .SECTION	 at 0	'CODE'     	;== PROGRAM SECTION == 
MAIN:
		MOV		A,0AFh					;DISABLE WDT
		MOV		WDTC,A
		MOV		a,Low OFFSET Array1		;MP0永遠僅指向BANK0
		MOV		MP0,A
		MOV		a,128
LOOP1:		
		CLR		IAR0					;將MP0所指向的位址內容清為0
		INC		MP0
		SDZ		ACC
		JMP		LOOP1
;=======================================================================		
		MOV		A,Low OFFSET Array2		;斷點1
		MOV		MP1L,A					
		MOV		A,High OFFSET Array2
		MOV		MP1H,A		
		MOV		a,128
LOOP2:		
		SET		IAR1					;將MP1所指向的位址內容設為FF
		INC		MP1L
		SDZ		ACC
		JMP		LOOP2
;=======================================================================		
		MOV		a,OFFSET Array3			;斷點2
		MOV		MP0,A
		MOV		a,128
LOOP3:		
		SET		IAR0					;將MP0所指向的位址內容清為0
		INC		MP0
		SDZ		ACC
		JMP		LOOP3
;=======================================================================
		JMP		$						;斷點3					
		END