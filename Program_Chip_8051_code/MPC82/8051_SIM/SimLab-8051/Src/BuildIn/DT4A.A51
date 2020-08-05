;
;   各種組譯指引(Directive)
;       配合MACRO,MEND示範巨指令程式設計
; 
;
ADD3	MACRO	T1,T2,T3
	MOV	A,T1
	ADD	A,T2
	ADD	A,T3
	ENDM

	ORG	0

	ADD3	10,11,12
	END
