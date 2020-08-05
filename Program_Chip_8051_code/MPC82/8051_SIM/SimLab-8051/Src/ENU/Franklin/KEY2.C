//
//
//   Using debounce technique on key-scanning design
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
sbit KEY1=P1 ^0 ;
void delay20ms()
{
	Delay10ms();
	Delay10ms();
}

main()
{
	P0=0 ;
	for(;;){
	    do{
		while(KEY1 ==1) ;
		delay20ms() ;
	    }
	    while(KEY1 == 1) ;
	    P0++;
	    do{
		while(KEY1==0) ;
		delay20ms() ;
	    }
	    while(KEY1== 0) ;    
	}
}
