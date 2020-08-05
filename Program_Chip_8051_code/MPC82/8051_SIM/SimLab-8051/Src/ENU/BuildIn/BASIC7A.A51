;
; The sum of 8-bit numbers (the sum is 16-bit)
;
VAL:	EQU	40H   ; first byte is NO. of values
SUM:	EQU	VAL+10

START:
	MOV	R0,VAL
	MOV	R1,#VAL+1
	MOV	A,#0
	MOV	B,A
NEXT1:
	ADD	A,@R1
	INC	R1
	JNC	CON1
	INC	B
CON1:
	DJNZ	R0,NEXT1
	MOV	SUM,B
	MOV	SUM+1,A
	AJMP	$
	END
