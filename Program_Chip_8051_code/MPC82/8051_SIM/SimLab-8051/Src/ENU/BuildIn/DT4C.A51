;
;   Assembler Directive
;       local label $n
;  Demonstrate  the assembler directive of Local label in Macro design
;

TM2	MACRO
$1:	NOP
	AJMP	$1
	ENDM

	ORG	0

	TM2
	TM2
	END
