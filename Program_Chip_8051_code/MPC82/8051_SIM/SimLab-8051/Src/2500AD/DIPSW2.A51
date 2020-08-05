;
; 配合"指撥開關/8個LED實習板"
;   指撥開關所代表的數值控制8個LED計數的速度
;
START:
	INC	P0
	MOV	A,P1
	CPL	A
	JZ	START
DLY1:
	ACALL	DELAY10MS
	DEC	A
	JNZ	DLY1
	AJMP	START

	$include (delay.inc)

	END
