;
; The addition of two 16-bit numbers
;
VAL1:	EQU	40H ; low address store high byte of 16-bit value
VAL2:	EQU	VAL1+2
RES:	EQU	VAL2+2

START:
	MOV	A,VAL1+1
	ADD	A,VAL2+1
	MOV	RES+1,A

	MOV	A,VAL1
	ADDC	A,VAL2
	MOV	RES,A

	AJMP	$
	END
