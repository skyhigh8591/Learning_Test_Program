;
;   Read analog voltage from ADC0804(synchronize by delay method),
;       then display voltage on 8 pieces of LED
;
ADCRD	REG	P1.0
ADCWR	REG	P1.1

START:
	CLR	ADCWR
	SETB	ADCWR
	ACALL	DELAY150US
	CLR	ADCRD
	MOV	P2,P0
	SETB	ADCRD
	SJMP	START
DELAY150US:
	MOV	R1,#74
	DJNZ	R1,$
	RET
	END
