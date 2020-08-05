;
;    8 pieces of LED in P0  change state by  binary counter;
;    8 pieces of LED in P1 interchange state between   OFF-ON-OFF-ON-OFF-ON-OFF-ON and ON-OFF-ON-OFF-ON-OFF-ON-OFF  
;    8 pieces of LED in P2(only 1 piece of LED is ON)change state by ON-LED to rotate left,
;    8 pieces of LED in P3(only 1 piece of LED is ON)change state  by ON-LED to rotate right
;
TP0:	EQU	020H
TP1:	EQU	021H
TP2:	EQU	022H
TP3:	EQU	023H
START:
	MOV	TP0,#0
	MOV	A,TP0
	CPL	A
	MOV	P0,A
	MOV	TP1,#55H
	MOV	A,TP1
	CPL	A
	MOV	P1,A
	MOV	TP2,#1
	MOV	A,TP2
	CPL	A
	MOV	P2,A
	MOV	TP3,#1
	MOV	A,TP3
	CPL	A
	MOV	P3,A
LOOP:
	INC	TP0          ; P0 binary counter
	MOV	A,TP0
	CPL	A
	MOV	P0,A

	MOV	A,TP1        ; P1 0x55/0xaa interchange
	CJNE	A,#55H,FILL55H
	MOV	TP1,#0AAH
	AJMP	NEXT1
FILL55H:
	MOV	TP1,#055H
NEXT1:
	MOV	A,TP1
	CPL	A
	MOV	P1,A

	MOV	A,TP2        ;P2  left rotate
	RL	A
	MOV	TP2,A
	CPL	A
	MOV	P2,A


	MOV	A,TP3        ;P3 right rotate
	RR	A
	MOV	TP3,A
	CPL	A
	MOV	P3,A

	ACALL	DELAY100MS
	SJMP	LOOP

	$include (delay.inc)

	END
