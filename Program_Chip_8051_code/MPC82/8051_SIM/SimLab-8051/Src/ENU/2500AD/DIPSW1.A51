;
;
;   ON/OFF setting in DIP Switch control Light/Dark of 8 pieces of LED
;
START:
	MOV	A,P1
	CPL	A	;complement switch setting value (0->1,1->0)
	MOV	P0,A
	AJMP	START
	END
