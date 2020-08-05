; PROGRAM : SUM1To1000.ASM        		By Steven                    
; FUNCTION: BCD DEMO PROGRAM         	2019.0305   
; ANS=500500(Dec) ==> 73A14 (Hex) 
; Note:°O¿ý RAM¡BROM¡B«ü¥O¶g´Á 		  
#INCLUDE    HT66F2390.INC 
;=================================================================================
MY_DATA    .SECTION		'DATA'    	;== DATA SECTION == 
SUM    	DB   	3 DUP	(?)  
X		DB   	2 DUP	(?) 
L1    	DB      ?
L2		DB 		?                 	
;========================================================================================
MY_CODE    .SECTION	 at 0	'CODE' 	;== PROGRAM SECTION == 
		MOV		A,0AFh				;DISABLE WDT
		MOV		WDTC,A
		CLR		SUM[0]
		CLR		SUM[1]
		CLR		SUM[2]
		MOV		A,1
		MOV		X[0],A
		CLR		X[1]
		MOV		A,10
		MOV		L1,A
LOOP1:		
		MOV		A,100
		MOV		L2,A
LOOP:		
		MOV		A,X[0]
		ADDM	A,SUM[0]	
		MOV		A,X[1]
		ADCM	A,SUM[1]
		CLR		ACC
		ADCM	A,SUM[2]
		MOV		A,1
		ADDM	A,X[0]
		CLR		ACC
		ADCM	A,X[1]
		SDZ		L2
		JMP		LOOP
		SDZ		L1
		JMP		LOOP1
		JMP		$