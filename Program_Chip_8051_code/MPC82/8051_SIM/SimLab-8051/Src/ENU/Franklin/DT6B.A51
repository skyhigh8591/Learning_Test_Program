;
;   Assembler Directive
;       using PUBLIC,EXTRN
;    Demonstrate  the assembler directive of linking  Multiple files
;
	CSEG	AT   0
	EXTRN	CODE(SUB1),CODE(SUB2),DATA(DT1)
	LCALL	SUB1
	LCALL	SUB2
	MOV	A,DT1
	END
