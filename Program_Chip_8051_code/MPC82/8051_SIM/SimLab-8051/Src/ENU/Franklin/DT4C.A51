;
;   Assembler Directive
;       using LOCAL
;  Demonstrate  the assembler directive of Local label in Macro design
;
$GEN   ; generate macro list

TM2	MACRO
	LOCAL	LOOP
LOOP:	NOP
	AJMP	LOOP
	ENDM

	CSEG

	TM2
	TM2
	END
