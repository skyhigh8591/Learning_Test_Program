;
;   Assembler Directive
;       using ORG,EQU,DB,DW
; Demonstrate the assembler directive of  reserved program  memory
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
