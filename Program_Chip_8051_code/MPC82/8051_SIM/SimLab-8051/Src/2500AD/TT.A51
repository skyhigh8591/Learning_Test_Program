;
;   各種組譯指引(Directive)
;    配合DSEG,DS或EQU,示範內部資料記憶體的安置及位址設定
;
di:	EQU	30H
dd:	EQU	di+2
	MOV	A,dd
	RLC	A
	SUBB	A,ACC
	MOV	di,A
	MOV	di+01H,dd
	END
