;
; The addition of two 8-bit numbers
;
VAL1	EQU	40H
VAL2	EQU	41H
RES	EQU	42H
;
START:
	MOV	R0,#VAL1
	MOV	R1,#VAL2
	MOV	A,@R0
	ADD	A,@R1
	MOV	R0,#RES
	MOV	@R0,A
	AJMP	$
	END
