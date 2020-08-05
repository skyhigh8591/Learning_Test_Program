;
;
;  Sequence ON a-segment, b-segment, c-segment, d-segment, e-segment, f-segment, g-segment , and dot-segment on Seven-Segment LED
;
START:
	MOV	P0,#0FEH
LOOP:
	ACALL	DELAY100MS
	MOV	A,P0
	RL	A
	MOV	P0,A
	AJMP	LOOP

	$include (delay.inc)

	END
