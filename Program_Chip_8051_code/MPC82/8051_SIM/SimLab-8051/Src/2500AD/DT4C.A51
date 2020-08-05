;
;   各種組譯指引(Directive)
;       配合區域標記後加上#,示範包括有標記的巨指令程式設計
; 
;

TM2	MACRO
 LOOP#:	NOP
	AJMP	LOOP#
	ENDM

	ORG	0

	TM2
	TM2
	END
