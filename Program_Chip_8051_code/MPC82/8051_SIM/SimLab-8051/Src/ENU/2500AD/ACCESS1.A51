;
;   The methods to access internal data memory(address  at 0,8,40h,90h)
;
;
;   three methods to load from internal data memory 0 to ACC
	MOV	A,R0
	CLR	A

	MOV	A,00
	CLR	A

	MOV	R1,#00
	MOV	A,@R1

;   three methods to load from internal data memory 8 to ACC
	SETB	RS0
	MOV	A,R0
	CLR	RS0
	CLR	A

	MOV	A,08
	CLR	A

	MOV	R1,#08
	MOV	A,@R1
	CLR	A

;   two methods to load from internal data memory 40h to ACC

	MOV	A,40h
	CLR	A

	MOV	R1,#40h
	MOV	A,@R1
	CLR	A

;   only one  method to load from internal data memory 90h to ACC

	MOV	A,90h     ; error(access special function register)
	CLR	A

	MOV	R1,#90h
	MOV	A,@R1
	CLR	A

	END
