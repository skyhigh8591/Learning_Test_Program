;
; Find the maximum from two 8-bit numbers (unsigned view)
;
	DSEG	AT 40H
VAL1:	DS	1
VAL2:	DS	1
RES:	DS	1

	CSEG
START:
	CLR	C
	MOV	A,VAL1
	SUBB	A,VAL2
	JNC	VAL1G
	MOV	A,VAL2
	MOV	RES,A
	AJMP	CON
VAL1G:
	MOV	A,VAL1
	MOV	RES,A
CON:
	AJMP	$
	END
