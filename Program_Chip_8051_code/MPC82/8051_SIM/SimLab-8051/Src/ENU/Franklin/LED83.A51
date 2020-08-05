;
;
;     ON-LED  rotate  right
;

	MOV	A,#11000000B
START:
	CPL	A
	MOV	P0,A
	CPL	A

	ACALL	DELAY100MS
	RR	A
	SJMP	START

	$include (delay.inc)

	END
