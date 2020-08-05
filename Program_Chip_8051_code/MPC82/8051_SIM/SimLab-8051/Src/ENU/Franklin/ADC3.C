//
//   Read analog voltage from ADC0804 (synchronize by interrupt method),
//     then display voltage on 8 pieces of LED
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
sbit ADCRD=P1 ^0 ;
sbit ADCWR=P1 ^1 ;
main()
{
	EA=1 ;
	IT0=1 ; // detect negative edge trigger
	EX0=1 ; // active INT0
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
