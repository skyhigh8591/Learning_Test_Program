;
; The addition of two 8-bit numbers
;
VAL1:	EQU	40H
START:
	MOV	A,VAL1
	ADD	A,VAL1+1
	MOV	VAL1+2,A
	AJMP	$
	END
