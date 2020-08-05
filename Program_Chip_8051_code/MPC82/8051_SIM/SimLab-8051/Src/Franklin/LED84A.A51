;
; 配合"8個LED(共陽)實習板"
;   P0所接的8個LED(初始狀態:最左1個熄；其餘7個LED亮著),其變化方式:
;         當熄的LED出現在最左邊時,進行右旋, 
;         反之,當熄的LED出現在最右邊時,進行左旋
;
TP0:	EQU	020H
	MOV	TP0,#01111111B
	MOV	A,TP0
	CPL	A
	MOV	P0,A
RIGHT:
	JNB	TP0.0,LEFT
	ACALL	DELAY100MS
	MOV	A,TP0
	RR	A
	MOV	TP0,A
	CPL	A
	MOV	P0,A
	SJMP	RIGHT
LEFT:
	ACALL	DELAY100MS
	JNB	TP0.7,RIGHT
	MOV	A,TP0
	RL	A
	MOV	TP0,A
	CPL	A
	MOV	P0,A
	SJMP	LEFT

	$include (delay.inc)

	END
