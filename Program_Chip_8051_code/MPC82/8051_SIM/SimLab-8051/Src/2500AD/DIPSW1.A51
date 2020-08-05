;
; 配合"指撥開關/8個LED實習板"
;   指撥開關的ON/OFF分別控制8個LED的亮/熄
;
START:
	MOV	A,P1
	CPL	A	;將Switch讀到的值做反相(0->1,1->0) 
	MOV	P0,A
	AJMP	START
	END
