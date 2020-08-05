;
; 配合"8個LED(共陰)實習板"
;   P0所接的8個LED(初始狀態:最左1個熄；其餘7個LED亮著),其變化方式:
;         當熄的LED出現在最左邊時,進行右旋, 
;         反之,當熄的LED出現在最右邊時,進行左旋
;
	MOV	P0,#01111111B
RIGHT:
	JNB	P0.0,LEFT
	ACALL	DELAY100MS
	MOV	A,P0
	RR	A
	MOV	P0,A
	SJMP	RIGHT
LEFT:
	ACALL	DELAY100MS
	JNB	P0.7,RIGHT
	MOV	A,P0
	RL	A
	MOV	P0,A
	SJMP	LEFT

	include delay.inc

	END
