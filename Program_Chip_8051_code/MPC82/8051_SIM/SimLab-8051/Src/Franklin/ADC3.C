//
//  配合"ADC0804實習板"
//   讀取ADC0804的類比電壓值(採用中斷方式來同步),並將之顯示於8個LED上
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
sbit ADCRD=P1 ^0 ;
sbit ADCWR=P1 ^1 ;
main()
{
	EA=1 ;
	IT0=1 ; // 偵測負緣觸發動作
	EX0=1 ; // 啟動INT0
	// start first ADC
	ADCWR=0 ; ADCWR= 1 ;
	for(;;) ;
}
void external0(void ) interrupt 0
{
	ADCRD=0 ;
	P2=P0 ;
	ADCRD=1 ;
	// start next ADC
	ADCWR=0 ; ADCWR= 1 ;
}
