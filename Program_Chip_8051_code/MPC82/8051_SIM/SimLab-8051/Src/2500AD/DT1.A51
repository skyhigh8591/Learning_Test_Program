;
;   各種組譯指引(Directive)
;    配合EQU,示範內部資料記憶體的安置及位址設定
;
;

TDT1	EQU	30H
TDT2	EQU	32H

	ORG	0

	MOV	A,TDT1
	MOV	A,TDT2
	END
