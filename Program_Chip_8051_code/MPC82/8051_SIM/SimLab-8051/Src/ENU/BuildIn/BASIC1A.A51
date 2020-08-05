;
; The addition of two 8-bit numbers
;
VAL1:	EQU	40H
VAL2:	EQU	VAL1+1
RES:	EQU	VAL2+1

START:
	MOV	A,VAL1
	ADD	A,VAL2
	MOV	RES,A
	AJMP	$
	END
