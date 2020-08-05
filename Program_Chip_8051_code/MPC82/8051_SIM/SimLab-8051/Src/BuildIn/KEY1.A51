;
; 配合"單鍵實習板"
;   按鍵的彈跳現象(bounce) 
;
KEY1	REG	P1.0
START:
	MOV	P0,#0
LOOP:
	JB	KEY1,$
	INC	P0
	JNB	KEY1,$
	SJMP	LOOP
	END
