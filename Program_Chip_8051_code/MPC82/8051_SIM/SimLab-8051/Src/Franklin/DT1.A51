;
;   各種組譯指引(Directive)
;    配合DSEG,DS或EQU,示範內部資料記憶體的安置及位址設定
;
;
	DSEG	AT 30H
DT1:	DS	2
DT2:	DS	1

TDT1	EQU	30H
TDT2	EQU	32H

	CSEG

	MOV	A,DT1
	MOV	A,TDT1
	MOV	A,DT2
	MOV	A,TDT2
	END
