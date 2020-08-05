; PROGRAM : Lab01_00                       		By Steven                    
; FUNCTION: LED SCANNING DEMO PROGRAM           2019.0305
; �ٲ�HT66F2390.inc�w�q�ɤ����J�A�����䤣��K�ʡ�   		  
;=================================================================================
MY_DATA    .SECTION		'DATA'          ;== DATA SECTION == 
DEL1    DB       ?                  	;DELAY LOOP COUNT 1 
DEL2    DB       ?                  	;DELAY LOOP COUNT 2 
DEL3	DB   	 ?        				;DELAY LOOP COUNT 3 
;========================================================================================
MY_CODE    .SECTION		'CODE'     		;== PROGRAM SECTION == 
        ORG     00H                    	;HT66Fxx RESET VECTOR 
MAIN: 
		MOV		A,0AFh					;DISABLE WDTC
		MOV		[3Eh],A
		CLR		[1Ch]          			;CONFIG PC AS O/P MODE 
		SET		[1Bh]           		;SET INITIAL LED STATE(off)
LOOP:             
		CPL		[1Bh]        			;SHIFT RIGHT 
		MOV 	A,100         			;SET DELAY FACTOR 
		CALL	DELAY               	;DELAY 100*1mS 
		JMP		LOOP               		;REPEAT THE RIGHT PROCESS. 
;========================================================================================
; PROC	: DELAY
; FUNC	: DEALY ABOUT ACC*1mS @fSYS=8MHz  (19966��Acc)+2 Cycles!
; PARA	: ACC : DELAY FACTOR
; REG	: DEL1,DEL2,DEL3
;======================================================================================== 
DELAY  	PROC
		MOV		DEL1,A					;SET DEL1 COUNTER	
DEL_1:  MOV		A,3		        	                   	
        MOV		DEL2,A					;SET DEL2 COUNTER 
DEL_2:	MOV		A,220
		MOV		DEL3,A					;SET DEL3 COUNTER
DEL_3:  SDZ		DEL3                  	;DEL3 DOWN COUNT
        JMP		DEL_3                      
        SDZ		DEL2                  	;DEL2 DOWN COUNT
        JMP		DEL_2                   
		SDZ		DEL1					;DEL1 DOWN COUNT
		JMP		DEL_1
        RET
DELAY	ENDP