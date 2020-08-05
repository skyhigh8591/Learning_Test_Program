; PROGRAM : SUM1To100V2.ASM            By Steven                    
; FUNCTION: BCD DEMO PROGRAM         2017.0512      		  
#INCLUDE    HT66F70A.INC 
;=================================================================================
MY_DATA    .SECTION		'DATA'    	;== DATA SECTION == 
SUM    	DB   	2 DUP	(?)         
X    	DB      ?                  	
;========================================================================================
MY_CODE    .SECTION	 at 0	'CODE' 	;== PROGRAM SECTION == 
		MOV		A,0AFh				;DISABLE WDT
		MOV		WDTC,A
		CLR		SUM[0]
		CLR		SUM[1]
		MOV		A,100
		MOV		X,A
LOOP:		
		MOV		A,X
		ADDM	A,SUM[0]	
		CLR		ACC
		ADCM	A,SUM[1]
		SDZ		X
		JMP		LOOP
		JMP		$