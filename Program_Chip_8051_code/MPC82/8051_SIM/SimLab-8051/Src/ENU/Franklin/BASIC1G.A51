;
; The addition of two 8-bit numbers (BCD)
;
	DSEG	AT 40H
VAL1:	DS	1
VAL2:	DS	1
RES:	DS	1

	CSEG
START:
	MOV	A,VAL1
	ADD	A,VAL2
	DA	A
	MOV	RES,A
	AJMP	$
	END
