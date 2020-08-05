;
;   存取內部資料記憶體(位址為0,8,40h,90h)的各種方法
;
;
;   將內部記憶體位址0載入到ACC(三種)
	MOV	A,R0
	CLR	A

	MOV	A,00
	CLR	A

	MOV	R1,#00
	MOV	A,@R1

;     將內部記憶體位址8載入到ACC(三種)
	SETB	RS0
	MOV	A,R0
	CLR	RS0
	CLR	A

	MOV	A,08
	CLR	A

	MOV	R1,#08
	MOV	A,@R1
	CLR	A

;     將內部記憶體位址40h載入到ACC(二種)

	MOV	A,40h
	CLR	A

	MOV	R1,#40h
	MOV	A,@R1
	CLR	A

;     將內部記憶體位址40h載入到ACC(一種)

	MOV	A,90h     ; 錯誤結果(存取到特殊暫存器)
	CLR	A

	MOV	R1,#90h
	MOV	A,@R1
	CLR	A

	END
