;
;    Let Stepping Motor counterclockwise to rotate n steps ,using half-step method
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
	CJNE	R1,#8,NEXT1
	MOV	R1,#0
NEXT1:
	ACALL	DELAY10MS
	INC	R0
	CJNE	R0,#N*2+1,LOOP
	AJMP	$
PP:	
	DB	01H,09H,08H,0CH,04H,06H,02H,03H
	$include (delay.inc)
	END
