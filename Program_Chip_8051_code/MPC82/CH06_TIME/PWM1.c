/********** PWM1.C ***********************
*動作：使用基本I/O輸出4個的PWM波形 
*****************************************/
#include "..\MPC82.H"   //暫存器及組態定義
unsigned char PWM_VAR=0;      //定義PWM數值變數
unsigned char PWM1_VAR=0x10;  //定義PWM1腳輸出脈波
unsigned char PWM2_VAR=0x80;  //定義PWM2腳輸出脈波
unsigned char PWM3_VAR=0xA0;  //定義PWM3腳輸出脈波
unsigned char PWM4_VAR=0xF0;  //定義PWM4腳輸出脈波
unsigned char PWM5_VAR=0x10;  //定義PWM5腳輸出脈波
unsigned char PWM6_VAR=0x80;  //定義PWM6腳輸出脈波
unsigned char PWM7_VAR=0xA0;  //定義PWM7腳輸出脈波
unsigned char PWM8_VAR=0xF0;  //定義PWM8腳輸出脈波

sbit PWM1=0x80;  //PWM1=P00
sbit PWM2=0x81;  //PWM2=P01
sbit PWM3=0x82;  //PWM3=P02
sbit PWM4=0x83;  //PWM4=P03
sbit PWM5=0x84;  //PWM5=P04
sbit PWM6=0x85;  //PWM6=P05
sbit PWM7=0x86;  //PWM7=P06
sbit PWM8=0x87;  //PWM8=P07

main()
{
  while(1)      //週而覆始
   {
    PWM1=PWM2=PWM3=PWM4=1;	 //PWM的開始準位=1
    while(PWM_VAR++)	//若PWM_VAR未遞加到0則PWM輸出
	 {
	  if(PWM_VAR > PWM1_VAR) PWM1=0;//若計時值 >PWM1值，PWM1=0
	  if(PWM_VAR > PWM2_VAR) PWM2=0;//若計時值 >PWM2值，PWM2=0
	  if(PWM_VAR > PWM3_VAR) PWM3=0;//若計時值 >PWM3值，PWM3=0
	  if(PWM_VAR > PWM4_VAR) PWM4=0;//若計時值 >PWM4值，PWM4=0
		if(PWM_VAR > PWM1_VAR) PWM5=0;//若計時值 >PWM5值，PWM5=0
	  if(PWM_VAR > PWM2_VAR) PWM6=0;//若計時值 >PWM6值，PWM6=0
	  if(PWM_VAR > PWM3_VAR) PWM7=0;//若計時值 >PWM7值，PWM7=0
	  if(PWM_VAR > PWM4_VAR) PWM8=0;//若計時值 >PWM8值，PWM8=0
     }	  
   }
}