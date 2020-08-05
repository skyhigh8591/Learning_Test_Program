;
; The addition of two 8-bit numbers
;
	DSEG	AT 40H
VAL1:	DS	3

	CSEG
START:
	MOV	A,VAL1
	ADD	A,VAL1+1
	MOV	VAL1+2,A
	AJMP	$
	END
