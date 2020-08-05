;
;
;¨ä±½ºË¶¡¹j¬°100ms;  Display number string "1234" on 4 pieces of Seven-Segment LED; the scanning interval is 100ms
;
START:
	MOV	R2,#0
LOOP:
	MOV	P1,#0FFH   ;  OFF common anode

 	MOV	A,R2
	INC	A
	MOV	DPTR,#SSTBL
	MOVC	A,@A+DPTR
	MOV	P0,A

	MOV	A,R2
	MOV	DPTR,#LOC
	MOVC	A,@A+DPTR
	MOV	P1,A

	INC	R2
	CJNE	R2,#4,NEXT1
	MOV	R2,#0
NEXT1:
	ACALL	DELAY100MS
	AJMP	LOOP

	include delay.inc

SSTBL:
	DB	0C0H
	DB	0F9H
	DB	0A4H,0B0H,099H
	DB	092H,082H,0F8H,080H,090H
LOC:
	DB	0F7H,0FBH,0FDH,0FEH
	END
