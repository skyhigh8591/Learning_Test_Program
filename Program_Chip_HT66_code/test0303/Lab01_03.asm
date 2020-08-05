; PROGRAM : Lab01_03.ASM  	        			By Steven                    
; FUNCTION: LED SCANNING DEMO PROGRAM           2019.0305      		  
;�[�W�ۤv���w�q�A�Y�n���n�ק�A��K�h�F��
#INCLUDE    HT66F2390.INC 
LED_PORT  	EQU    PC        			;DEFINE LED_PORT 
LED_PORTC  	EQU    PCC        			;DEFINE LED_PORT CONTROL REG.  
;=================================================================================
MY_DATA    .SECTION		'DATA'          ;== DATA SECTION == 
DEL1    DB       ?                  	;DELAY LOOP COUNT 1 
DEL2    DB       ?                  	;DELAY LOOP COUNT 2 
DEL3	DB   	 ?        				;DELAY LOOP COUNT 3 
;========================================================================================
MY_CODE    .SECTION	 at 0	'CODE'     	;== PROGRAM SECTION == 
MAIN: 
		MOV		A,0AFh					;DISABLE WDT
		MOV		WDTC,A
		CLR		LED_PORTC          		;CONFIG LED_PORT AS O/P MODE 
		SET		LED_PORT           		;SET INITIAL LED STATE
		CLR		C                  		;SET CARRY FLAG (STATUS.0) 
RIGHT:             
		RRC		LED_PORT        		;SHIFT RIGHT 
		MOV 	A,100         			;SET DELAY FACTOR 
		CALL	DELAY               	;DELAY 100*1mS 
		SZ  	LED_PORT.0          	;IS ALL LEDs HAVE BEEN LIT? 
		JMP		RIGHT               	;NO. CONTINUE RIGHT SHIFT. 
LEFT:   
		RLC     LED_PORT    			;SHIFT LEFT 
		MOV		A,200         			;SET DALAY FACTOR 
		CALL	DELAY               	;DELAY 200*1mS 
		SZ		LED_PORT.7          	;IS ALL LEDs HAVE BEEN LIT? 
		JMP		LEFT                	;NO. CONTINUE LEFT SHIFT. 
		JMP		RIGHT               	;REPEAT THE RIGHT PROCESS. 
;========================================================================================
; PROC	: DELAY
; FUNC	: DEALY ABOUT ACC*1mS @fSYS=8MHz  (1996��Acc)+2 Cycles!
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