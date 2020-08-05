;
;
;   The value setting in DIP Switch control  8 pieces of LED counting speed
;
START:
	INC	P0
	MOV	A,P1
	CPL	A
	JZ	START
DLY1:
	ACALL	DELAY10MS
	DEC	A
	JNZ	DLY1
	AJMP	START

	$include (delay.inc)

	END
