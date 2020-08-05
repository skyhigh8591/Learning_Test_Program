;
;   Display number string "1234" on 4 pieces of Seven-Segment LED,
;其掃瞄間隔為(1ms*連接DIPSW15~8指撥開關所代表的數值) ;     the scanning interval is 1ms * DIP Switch setting (on DIPSW15~7)
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
	MOV	A,P2
	CPL	A
	JZ	NEXT3
	MOV	R3,A

NEXT2:
	ACALL	DELAY1MS
	DJNZ	R3,NEXT2
NEXT3:
	AJMP	LOOP

	$include (delay.inc)

SSTBL:
	DB	0C0H
	DB	0F9H
	DB	0A4H,0B0H,099H
	DB	092H,082H,0F8H,080H,090H
LOC:
	DB	0F7H,0FBH,0FDH,0FEH
	END
