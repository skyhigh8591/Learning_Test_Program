;
;   Assembler Directive
;       using MACRO,MEND
;   Demonstrate the assembler directive of MACRO design
;
ADD3	MACRO	T1,T2,T3
	MOV	A,T1
	ADD	A,T2
	ADD	A,T3
	ENDM

	ORG	0

	ADD3	10,11,12
	END
