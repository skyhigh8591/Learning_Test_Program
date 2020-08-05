;
; The addition of two 16-bit numbers
;
	DSEG	AT 40H
VAL1:	DS	2 ; low address store high byte of 16-bit value
VAL2:	DS	2
RES:	DS	2

	CSEG
START:
	MOV	A,VAL1+1
	ADD	A,VAL2+1
	MOV	RES+1,A

	MOV	A,VAL1
	ADDC	A,VAL2
	MOV	RES,A

	AJMP	$
	END
