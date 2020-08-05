;
;
;
;   1. When the most left  LED is OFF ====>OFF-LED rotate right
;   2. When the most right LED is OFF ====>OFF-LED rotate  left
;
TP0:	EQU	020H
	MOV	TP0,#01111111B
	MOV	A,TP0
	CPL	A
	MOV	P0,A
RIGHT:
	JNB	TP0.0,LEFT
	ACALL	DELAY100MS
	MOV	A,TP0
	RR	A
	MOV	TP0,A
	CPL	A
	MOV	P0,A
	SJMP	RIGHT
LEFT:
	ACALL	DELAY100MS
	JNB	TP0.7,RIGHT
	MOV	A,TP0
	RL	A
	MOV	TP0,A
	CPL	A
	MOV	P0,A
	SJMP	LEFT

	include delay.inc

	END
