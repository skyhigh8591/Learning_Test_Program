;
; The addition of two 8-bit numbers
;
VAL1	EQU	40H
VAL2	EQU	41H
RES	EQU	42H
;
START:
	MOV	A,VAL1
	ADD	A,VAL2
	MOV	RES,A
	AJMP	$
	END
