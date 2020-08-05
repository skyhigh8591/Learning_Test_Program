;
;   Assembler Directive
;       Demonstrate  the assembler directive of Local label in Macro design(error)
;  because macro call TM1 2 times , so generate two label name LOOP
;

TM1	MACRO
LOOP:	NOP
	AJMP	LOOP
	ENDM


	ORG	0

	TM1
	TM1
	END
