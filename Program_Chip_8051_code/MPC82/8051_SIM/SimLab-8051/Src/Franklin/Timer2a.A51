;
;    計時/計數器1工作在模式2的計數器
;     每當在T1接腳出現3個脈波,將產生中斷,於是P0依序使bit7~bit4或bit3~bit0為1
;
;**** 閃爍(1號計數器中斷) c1i ****
	ORG	00H		;開機的起始位址
	JMP	MAIN
	ORG	1BH		;1 號計數器中斷的起始位址
	CPL	A	
	MOV	P0,A
	RETI			;中斷副程式, 返回
MAIN:	MOV	TMOD,#60H	;設定, 1 號計數器工作於模式2 
	MOV	TH1,#256-3
	MOV	TL1,#256-3
	SETB	EA		;致能, 所有中斷
	SETB	ET1		;致能, 1 號計數器中斷
	SETB	TR1		;啟動, 1 號計數器
	MOV	A,#0F0H
	MOV	P0,A
HALT:	JMP	HALT
	END			;程式結束
