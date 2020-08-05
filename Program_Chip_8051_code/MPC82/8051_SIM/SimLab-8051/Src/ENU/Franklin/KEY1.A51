;
;
;   The phenomenon of Key bounce
;
KEY1	EQU	P1.0
START:
	MOV	P0,#0
LOOP:
	JB	KEY1,$
	INC	P0
	JNB	KEY1,$
	SJMP	LOOP
	END
