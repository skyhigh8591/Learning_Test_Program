;
;   Assembler Directive
;       local label suffix with #
;  Demonstrate  the assembler directive of Local label in Macro design
;

TM2	MACRO
 LOOP#:	NOP
	AJMP	LOOP#
	ENDM

	ORG	0

	TM2
	TM2
	END
