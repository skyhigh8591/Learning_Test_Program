/********** PWM0.C ******基本I/O輸出PWM波形****************
*動作：由接腳P12~5輸出4個PWM波形
*硬體：先SW1-4(P1LED)OFF量測電壓，再SW1-4(P1LED)ON觀察LED亮度
************************************************************/
#include "..\MPC82.H" 
unsigned char PWM_VAR=0;//宣告PWM變數
#define  PWM0_VAR 0x10  //PWM0設定輸出脈波寬度
#define  PWM1_VAR 0x30  //PWM1設定輸出脈波寬度
#define  PWM2_VAR 0x80  //PWM2設定輸出脈波寬度
#define  PWM3_VAR 0xA0  //PWM3設定輸出脈波寬度

sbit PWM0=0x92;  //PWM0=P12
sbit PWM1=0x93;  //PWM1=P13
sbit PWM2=0x94;  //PWM2=P14
sbit PWM3=0x95;  //PWM3=P15

main()
{
  while(1)      //週而覆始
   {
    PWM0=PWM1=PWM2=PWM3=1;	 //PWM的開始準位=1
    while(PWM_VAR++)	//若PWM_VAR未遞加到0則PWM輸出
	 {
	  if(PWM_VAR > PWM0_VAR) PWM0=0;//若計時值 >PWM0值，PWM0=0
	  if(PWM_VAR > PWM1_VAR) PWM1=0;//若計時值 >PWM1值，PWM1=0
	  if(PWM_VAR > PWM2_VAR) PWM2=0;//若計時值 >PWM2值，PWM2=0
	  if(PWM_VAR > PWM3_VAR) PWM3=0;//若計時值 >PWM3值，PWM3=0
     }	  
   }		 
}