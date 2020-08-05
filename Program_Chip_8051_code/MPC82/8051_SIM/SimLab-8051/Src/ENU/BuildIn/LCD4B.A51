;
;   Display 4 "Hello!!" on Text LCD,
;      at line 1 location 1 , line 1 location 11 ,
;         line 2 location 1 , and line 2 location 11
;
E	REG	P1.2
RW	REG	P1.1
RS	REG	P1.0

DSPSTR	MACRO	LOC
	MOV	A,#LOC
	ACALL	COMMAND
	MOV	DPTR,#MES
$1:
	CLR	A
	MOVC	A,@A+DPTR
	JZ	$2
	ACALL	SDATA
	INC	DPTR
	SJMP	$1
$2:
	ENDM

START:
	ACALL	DELAY5MS     ; wait for LCD Power-on Ready
	MOV	A,#0111111B  ; 8 bits data bus/2 lines/5*10 dots
	ACALL	COMMAND
	MOV	A,#01110B   ; display ON
	ACALL	COMMAND
	MOV	A,#1     ;clear display
	ACALL	COMMAND

	DSPSTR	010000000B      ; DD RAM address = 0-->line 1 location 1
	DSPSTR	010000000B+10   ; DD RAM address =10--> line 1 location 11
	DSPSTR	010000000B+40H   ; DD RAM address =40H---> line 2 location 1
	DSPSTR	010000000B+40H+10   ; DD RAM address =40H+10---> line 2 location 11

	SJMP	$
COMMAND:
	MOV	P0,A
	SETB	E
	CLR	RW
	CLR	RS
	CLR	E
	ACALL	WAITLCD
	RET
SDATA:
	MOV	P0,A
	SETB	E
	CLR	RW
	SETB	RS
	CLR	E
WAITLCD:
	MOV	P0,#0FFH  ; P0 set to input port
WAITLCD1:
	CLR	RS
	SETB	RW
	SETB	E
	MOV	A,P0
	CLR	E
	ANL	A,#80H
	JNZ	WAITLCD1
	RET
DELAY5MS:
	ACALL	DELAY1MS
	ACALL	DELAY2MS
	ACALL	DELAY2MS
	RET
DELAY2MS:
	ACALL	DELAY1MS
	ACALL	DELAY1MS
	RET

	include delay.inc

MES:	DB	"Hello!!",0
	END
