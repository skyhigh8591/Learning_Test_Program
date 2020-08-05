;
;   各種組譯指引(Directive)
;       配合EQU,示範位元的安置及位址設定
;
;
TDT1	EQU	30H
ADT1	REG	26h.0
TDT2	EQU	33H
ADT2	REG	26h.3

	ORG 0
	MOV	C,TDT1
	MOV	C,ADT1
	MOV	C,26h.0
	MOV	C,TDT2
	MOV	C,ADT2
	MOV	C,26h.3
	END
