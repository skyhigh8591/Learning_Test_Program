;
;   Assembler Directive
;       using PUBLIC,EXTRN
;    Demonstrate  the assembler directive of linking  Multiple files
;
	DSEG	AT	30H
	PUBLIC   DT1
DT1:	DS	1
	CSEG	AT 200H
	PUBLIC	SUB1,SUB2
SUB1:
	NOP
	RET
SUB2: NOP
	RET
	END
