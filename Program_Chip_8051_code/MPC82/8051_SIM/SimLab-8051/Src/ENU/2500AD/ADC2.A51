;
;   Read analog voltage from ADC0804 (synchronize by polling method),
;     then display voltage on 8 pieces of LED
;
ADCRD	REG	P1.0
ADCWR	REG	P1.1
ADCINTR	REG	P3.2

START:
	CLR	ADCWR
	SETB	ADCWR
	JB	ADCINTR,$
	CLR	ADCRD
	MOV	P2,P0
	SETB	ADCRD
	SJMP	START
	END
