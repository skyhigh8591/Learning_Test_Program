;
;
;
;   1. When the most left  LED is OFF ====>OFF-LED rotate right
;   2. When the most right LED is OFF ====>OFF-LED rotate  left
;
	MOV	P0,#01111111B
RIGHT:
	JNB	P0.0,LEFT
	ACALL	DELAY100MS
	MOV	A,P0
	RR	A
	MOV	P0,A
	SJMP	RIGHT
LEFT:
	ACALL	DELAY100MS
	JNB	P0.7,RIGHT
	MOV	A,P0
	RL	A
	MOV	P0,A
	SJMP	LEFT

	$include (delay.inc)

	END
