;
;
;     ON-LED  rotate  right
;

	MOV	A,#11000000B
START:
	MOV	P0,A

	ACALL	DELAY100MS
	RR	A
	SJMP	START

	include delay.inc

	END
