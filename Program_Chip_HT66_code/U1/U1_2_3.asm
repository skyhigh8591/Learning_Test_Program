;PROGRAM : U1_2_3.ASM 								2017.0413
;FUNCTION: 7 SEGMENT LED DEMO PROGRAM(LMOV/ITABRDL) By Steven   
#INCLUDE  HT66F2390.INC 
;========================================================================================
MY_DATA    .SECTION  'DATA'         	;== DATA SECTION == 
DEL1      	DB  	?       			;DELAY LOOP COUNT 1 
DEL2      	DB   	?       			;DELAY LOOP COUNT 2 
DEL3	    DB  	?       			;DELAY LOOP COUNT 3 
RAMBANK 2  	MY_DATA1					;���wMY_DATA1��RAM Section 2
MY_DATA1    .SECTION  'DATA'         	;== DATA SECTION == 
COUNT   	DB  	? 
;========================================================================================
SEG_PORT 	EQU  	PG   				;DEFINE 7-SEGMENT LED PORT 
SEG_PORTC  	EQU    	PGC     			;DEFINE SEG_PORT CONTROL REG. 
MY_CODE  .SECTION  AT 0  'CODE'     	;== PROGRAM SECTION , ���m�V�q(RESET VECTOR) 
		MOV		A,0ABh					;����WDT
		MOV		WDTC,A
		CLR    	SEG_PORT				;�]�m��XLow
		CLR    	SEG_PORTC      			;�W��PORT����X�ݩ�
MAIN:         
		MOV    	A,LOW  (TAB_7_SEG-1) 
		MOV  	TBLP,A    				;���o�ت�_�l��}(Low-byte)  
		MOV    	A,10 
		LMOV   	COUNT,A      			;�]�w�j�馸�� 
LOOP: 
		ITABRDL	SEG_PORT     			;���o�ت��ơA�ñNLow-byte�e��SEG_PORT 
		MOV  	A,TBLH   				;���oHigh-byte��� 
		CALL    DELAY    				;����ACC*10ms 
		LSDZ    COUNT      				;(COUNT=COUNT-1)�O�_��0?
		JMP  	LOOP    				;�_�A�j���~�� 
		JMP  	MAIN    				;�O�A���s����
;========================================================================================
; PROC	: DELAY
; FUNC	: DEALY ABOUT ACC*10mS @fSYS=8MHz
; PARA	: ACC : DELAY FACTOR
; REG	: DEL1,DEL2,DEL3
;======================================================================================== 
DELAY	PROC
		MOV		DEL1,A					;SET DEL1 COUNTER	
DEL_1:  MOV		A,30		        	                   	
		MOV		DEL2,A					;SET DEL2 COUNTER 
DEL_2:	MOV		A,220
		MOV		DEL3,A					;SET DEL3 COUNTER
DEL_3:	SDZ		DEL3                  	;DEL3 DOWN COUNT
		JMP		DEL_3                      
		SDZ		DEL2                  	;DEL2 DOWN COUNT
		JMP		DEL_2                   
		SDZ		DEL1					;DEL1 DOWN COUNT
		JMP		DEL_1
		RET
DELAY	ENDP
ROMBANK 7  		TABLE					;���w��ROM BANK 7
TABLE  .SECTION 	'CODE'     			;== PROGRAM SECTION
		ORG   	01F00h 					;Last Page
TAB_7_SEG: 
		DC      (20 SHL 8)+03Fh  		;�@�����C�q��ܾ�(0~9)��ܽX�ت��
		DC    	(30 SHL 8)+006h  		;High-byte������ɶ��`��
		DC    	(40 SHL 8)+05Bh  		;Low-byte���C�q��ܾ���ܽX
		DC     	(50 SHL 8)+04Fh  		
		DC     	(60 SHL 8)+066h 
		DC    	(70 SHL 8)+06Dh 
		DC     	(80 SHL 8)+07Dh
		DC     	(90 SHL 8)+007h 
		DC     	(100 SHL 8)+07Fh 
		DC     	(110 SHL 8)+067h 
		END 