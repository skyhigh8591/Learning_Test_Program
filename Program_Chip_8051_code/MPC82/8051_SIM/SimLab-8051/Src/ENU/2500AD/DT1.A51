;
;   Assembler Directive
;    using EQU
;  Demonstrate the assembler directive of reserved internal data memory
;

TDT1	EQU	30H
TDT2	EQU	32H

	ORG	0

	MOV	A,TDT1
	MOV	A,TDT2
	END
