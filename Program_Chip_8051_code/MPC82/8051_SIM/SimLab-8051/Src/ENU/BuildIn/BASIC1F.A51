;
; The addition of two 8-bit numbers
;
VAL1	EQU	40H
;
START:
	MOV	R0,#VAL1
 	MOV	A,@R0
	INC	R0
	ADD	A,@R0
	INC	R0
	MOV	@R0,A
 	AJMP	$
	END
