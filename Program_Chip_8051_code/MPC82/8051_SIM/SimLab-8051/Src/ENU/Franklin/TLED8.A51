;
; 配合"8個LED實習板"
;   P0所接的8個LED有二相鄰的LED亮著,並進行右旋的變化
;
	MOV	A,#01111111B
right:
	jnb	p0.0,left
	ACALL	DELAY100MS
	RR	A
	MOV	P0,A
	SJMP	right
left:
	jnb	p0.7,right
	acall	delay100ms
	rl	a
	MOV	P0,A
	sjmp	left

	$include (delay.inc)

	END
