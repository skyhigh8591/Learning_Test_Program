;
; 配合"1個七段式LED實習板"
;  依序打亮七段式LED的a段,b段,c段,d段,e段,f段,g段及dot段
;
START:
	MOV	P0,#0FEH
LOOP:
	ACALL	DELAY100MS
	MOV	A,P0
	RL	A
	MOV	P0,A
	AJMP	LOOP

	$include (delay.inc)

	END
