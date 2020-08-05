;
;   各種組譯指引(Directive)
;       配合MACRO,MEND示範巨指令程式設計
; 
;
$GEN   ; generate macro list
ADD3	MACRO	T1,T2,T3
	MOV	A,T1
	ADD	A,T2
	ADD	A,T3
	ENDM

	CSEG

	ADD3	10,11,12
	END
