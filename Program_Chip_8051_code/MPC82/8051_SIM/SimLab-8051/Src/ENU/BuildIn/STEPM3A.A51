;
;    Let Stepping Motor clockwise to rotate n steps ,using two-phase pulse method
;
N	EQU	10
START:
	MOV	R0,#0
	MOV	R1,#0
	MOV	DPTR,#PP
LOOP:
	MOV	A,R1
	MOVC	A,@A+DPTR
	MOV	P0,A
	INC	R1
	CJNE	R1,#4,NEXT1
	MOV	R1,#0
NEXT1:
	ACALL	DELAY10MS
	INC	R0
	CJNE	R0,#N+1,LOOP
	AJMP	$
PP:	
	DB	03H,06H,0CH,09H
	include delay.inc
	END
