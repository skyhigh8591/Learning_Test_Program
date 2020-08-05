;
;
;   Let Stepping Motor counterclockwise to rotate n steps ,using single-phase pulse method
;
N	EQU	10
START:
	MOV	R0,#0
	MOV	R1,#00010001B
LOOP:
	MOV	P0,R1
	MOV	A,R1
	RR	A
	MOV	R1,A
	ACALL	DELAY10MS
	INC	R0
	CJNE	R0,#N+1,LOOP
	AJMP	$
	include delay.inc
	END
