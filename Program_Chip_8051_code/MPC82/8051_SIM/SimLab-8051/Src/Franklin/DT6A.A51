;
;   各種組譯指引(Directive)
;       配合PUBLIC,EXTRN,示範多檔案連結功能
;
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
