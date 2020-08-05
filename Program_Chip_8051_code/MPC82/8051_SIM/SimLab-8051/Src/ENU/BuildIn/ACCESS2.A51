;
;   The methods to access bit data (address at 3)
;
;
	SETB	3
	CLR	3
	SETB	20h.3
	CLR	20h.3

	MOV	A,20h
	ORL	A,#008H
	MOV	20h,A

	MOV	A,20h
	ANL	A,#0F7h
	MOV	20h,A


	END
