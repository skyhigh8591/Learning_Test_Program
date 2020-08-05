;
;   各種組譯指引(Directive)
;       配合區域標記組譯指引LOCAL,示範包括有標記的巨指令程式設計
; 
;
$GEN   ; generate macro list

TM2	MACRO
	LOCAL	LOOP
LOOP:	NOP
	AJMP	LOOP
	ENDM

	CSEG

	TM2
	TM2
	END
