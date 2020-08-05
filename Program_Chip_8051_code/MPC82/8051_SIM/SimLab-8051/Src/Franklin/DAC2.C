//
//  配合"DAC0800實習板"
//   由DAC0800送出SIN波形
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
unsigned char code sintbl[]= {
	128,167,203,231,249,
	255,249,231,203,167,
	127,88 , 52, 24,  6,
	0  ,6  , 24, 52, 88
} ;
main()
{
	char i ;
	for(;;){
	    for(i=0;i < 20;i++){
		P0=sintbl[i];
		Delay1ms() ;
	    }
	}
}
