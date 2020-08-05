;
;   各種組譯指引(Directive)
;       配合ORG,EQU,DB,DW,示範程式記憶體的安置及位址設定
;
;
	ORG	0
	MOV	DPTR,#DT1
	MOV	DPTR,#TDT1
	MOV	DPTR,#DT2
	MOV	DPTR,#TDT2
TDT1	EQU	$
DT1:	DB	1,2,3,4
TDT2	EQU	$
DT2:	DW	1,2,3,4
	END
