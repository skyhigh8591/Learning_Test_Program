//
//   Read analog voltage from ADC0804(synchronize by delay method),
//     then display voltage on 8 pieces of LED 
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
sbit ADCRD=P1 ^0 ;
sbit ADCWR=P1 ^1 ;
void delay150us()
{
	int i=0 ;
	for(i=0 ; i < 18 ; i++) ;
}
main()
{
	for(;;){
	    // start ADC
	    ADCWR=0 ; ADCWR= 1 ;
	    delay150us() ;
	    ADCRD=0 ;
	    P2=P0 ;
	    ADCRD=1 ;
	}
}
