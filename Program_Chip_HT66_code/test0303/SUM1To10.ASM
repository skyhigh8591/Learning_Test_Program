; PROGRAM : SUM1To10.ASM            By Steven                    
; FUNCTION: BCD DEMO PROGRAM        2019.0305   
; Note:記錄 RAM、ROM、指令週期 	   		  
#INCLUDE    HT66F2390.INC 
;=================================================================================
MY_DATA    .SECTION		'DATA'     	;== DATA SECTION == 
SUM    	DB       ?                  	
X    	DB       ?               	;DELAY LOOP COUNT 2 
;========================================================================================
MY_CODE    .SECTION	 at 0	'CODE'	;== PROGRAM SECTION == 
		MOV		A,0AFh				;DISABLE WDT
		MOV		WDTC,A
		CLR		SUM
		CLR		X
LOOP:		
		MOV		A,x					;MOV  A,x
		ADD		A,SUM				;ADDM A,SUM
		MOV		SUM,a				;//***
;		DAA		SUM					;Decimal Adjust(BCD: Binary Coded Decimal)
		INC		X
		MOV		A,10
		SUB		A,X					;C=0 if X > 10  (需要借位)
		SZ		C
		JMP		LOOP
		JMP		$