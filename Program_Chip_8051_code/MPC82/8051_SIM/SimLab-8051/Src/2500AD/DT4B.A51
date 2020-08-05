;
;   各種組譯指引(Directive)
;       示範巨指令定義TM1內有標記LOOP, 由於TM1被呼叫兩次, 
;       將使LOOP在程式內出現兩次造成標記LOOP重覆定義的錯誤
;

TM1	MACRO
LOOP:	NOP
	AJMP	LOOP
	ENDM


	ORG	0

	TM1
	TM1
	END
