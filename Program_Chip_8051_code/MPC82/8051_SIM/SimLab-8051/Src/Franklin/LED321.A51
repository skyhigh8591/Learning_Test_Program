;
; 配合"32個LED(共陰)實習板"
;    P0所接的8個LED當二進制計數器,P1所接的8個LED依序亮熄著,並交互變化,
;     P2所接的8個LED只有一LED亮著,並進行左旋的變化
;     P3所接的8個LED只有一LED亮著,並進行右旋的變化
;
START:
	MOV	P0,#0
	MOV	P1,#55H
	MOV	P2,#1
	MOV	P3,#1
LOOP:
	INC	P0          ; P0當二進制計數器

	MOV	A,P1        ; P1 0x55/0xaa交互變化
	CJNE	A,#55H,FILL55H
	MOV	P1,#0AAH
	AJMP	NEXT1
FILL55H:
	MOV	P1,#055H
NEXT1:

	MOV	A,P2        ;P2左旋
	RL	A
	MOV	P2,A

	MOV	A,P3        ;P3右旋
	RR	A
	MOV	P3,A

	ACALL	DELAY100MS
	SJMP	LOOP

	$include (delay.inc)

	END
