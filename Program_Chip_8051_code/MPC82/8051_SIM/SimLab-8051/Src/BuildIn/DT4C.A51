;
;   各種組譯指引(Directive)
;       配合區域標記$n,示範包括有標記的巨指令程式設計
; 
;

TM2	MACRO
$1:	NOP
	AJMP	$1
	ENDM

	ORG	0

	TM2
	TM2
	END
