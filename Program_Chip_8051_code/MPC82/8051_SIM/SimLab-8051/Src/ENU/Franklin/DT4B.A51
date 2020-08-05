;
;   Assembler Directive
;       Demonstrate  the assembler directive of Local label in Macro design(error)
;  because macro call TM1 2 times , so generate two label name LOOP
;
$GEN   ; generate macro list

TM1	MACRO
LOOP:	NOP
	AJMP	LOOP
	ENDM


	CSEG

	TM1
	TM1
	END
