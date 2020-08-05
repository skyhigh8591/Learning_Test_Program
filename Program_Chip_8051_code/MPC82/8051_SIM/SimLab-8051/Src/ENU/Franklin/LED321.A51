;
;    8 pieces of LED in P0  change state by  binary counter;
;    8 pieces of LED in P1 interchange state between   OFF-ON-OFF-ON-OFF-ON-OFF-ON and ON-OFF-ON-OFF-ON-OFF-ON-OFF  
;    8 pieces of LED in P2(only 1 piece of LED is ON)change state by ON-LED to rotate left,
;    8 pieces of LED in P3(only 1 piece of LED is ON)change state  by ON-LED to rotate right
;
START:
	MOV	P0,#0
	MOV	P1,#55H
	MOV	P2,#1
	MOV	P3,#1
LOOP:
	INC	P0          ; P0 binary counter

	MOV	A,P1        ; P1 0x55/0xaa interchange
	CJNE	A,#55H,FILL55H
	MOV	P1,#0AAH
	AJMP	NEXT1
FILL55H:
	MOV	P1,#055H
NEXT1:

	MOV	A,P2        ;P2  left rotate
	RL	A
	MOV	P2,A

	MOV	A,P3        ;P3 right rotate
	RR	A
	MOV	P3,A

	ACALL	DELAY100MS
	SJMP	LOOP

	$include (delay.inc)

	END
