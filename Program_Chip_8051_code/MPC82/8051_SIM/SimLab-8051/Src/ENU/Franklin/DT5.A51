;
;   Assembler Directive
;        using $INCLUDE
;    Demonstrate  the assembler directive of include file
;
$GEN  ; generate macro list
	$INCLUDE	(dt5a.a51)
	CSEG
	ADD3	10,11,12
	END
