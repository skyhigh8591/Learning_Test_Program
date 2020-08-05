; PROGRAM : U1_1_1.ASM            		By Steven                    
; FUNCTION: LED SCANNING DEMO PROGRAM   2017.0407      		  
#INCLUDE    HT66F2390.INC 
;=================================================================================
MY_DATA    .SECTION			'DATA'      ;== DATA SECTION == 
DEL1    DB       ?                  	;DELAY LOOP COUNT 1 
DEL2    DB       ?                  	;DELAY LOOP COUNT 2 
DEL3	DB   	 ?        				;DELAY LOOP COUNT 3 
;========================================================================================
LED_PORT  	EQU    PF        			;DEFINE LED_PORT 
LED_PORTC  	EQU    PFC        			;DEFINE LED_PORT CONTROL REG.  
MY_CODE    .SECTION	 at 0	'CODE'     	;== PROGRAM SECTION, ���m�V�q(RESET VECTOR)                 	
MAIN: 
		MOV		A,10101111B				;����WDT
		MOV		WDTC,A
		CLR		LED_PORTC          		;�W��PORT����X�ݩ� 
		SET		LED_PORT           		;�]�mPORT��X 11111111B
		CLR		C                  		;�M��C�X��(STATUS.0) 
RIGHT:             
		RRC		LED_PORT        		;PORT�k�� 
		MOV 	A,100        			;����100*1mS 
		CALL	DELAY               	
		SZ  	LED_PORT.0          	;�O�_PORT��LSB=0? 
		JMP		RIGHT               	;�_. �~��k��. 
LEFT:   
		RLC     LED_PORT    			;PORT���� 
		MOV		A,200         			;���� 200*1mS 
		CALL	DELAY               	
		SZ		LED_PORT.7          	;�O�_PORT��MSB=0?? 
		JMP		LEFT                	;�_. �~�򥪱�. 
		JMP		RIGHT               	;���s�}�l�k��. 
;========================================================================================
; PROC	: DELAY
; FUNC	: DEALY ABOUT ACC*1mS @fSYS=8MHz  (1998xACC)+2 Cycles!
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