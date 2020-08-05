;
;   用單相激磁的方式,使步進馬達正轉n格
;    由於步進馬達初值的刻意設定,迴路內只須左旋即可
;
N	EQU	10
START:
	MOV	R0,#0
	MOV	R1,#00010001B
LOOP:
	MOV	P0,R1
	MOV	A,R1
	RL	A
	MOV	R1,A
	ACALL	DELAY10MS
	INC	R0
	CJNE	R0,#N+1,LOOP
	AJMP	$
	$include (delay.inc)
	END
