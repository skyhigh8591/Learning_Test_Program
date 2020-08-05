;
; timer/counter0  working in  counter and mode 2  
;     每當在T0接腳出現3個脈波,將產生中斷,於是P0依序使bit7~bit4或bit3~bit0為1
;
;**** 閃爍(0號計數器中斷) cli ****
	ORG	00H		;開機的起始位址
	JMP	MAIN
	ORG	0BH		;0 號計數器中斷的起始位址
	CPL	A	
	MOV	P0,A
	RETI			;中斷副程式, 返回
MAIN:	MOV	TMOD,#06H	;設定, 0 號計數器工作於模式2
	MOV	TH0,#256-3
	MOV	TL0,#256-3
	SETB	EA		;致能, 所有中斷
	SETB	ET0		;致能, 0 號計數器中斷
	SETB	TR0		;啟動, 0 號計數器
	MOV	A,#0F0H
	MOV	P0,A
HALT:	JMP	HALT
	END			;程式結束
