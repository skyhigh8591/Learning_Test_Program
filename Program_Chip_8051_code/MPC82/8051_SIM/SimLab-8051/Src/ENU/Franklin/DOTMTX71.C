//
//
//   Display Chinese word "da" on 5*7 Mono Dot-matrix LED
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
unsigned char code dai[]= { 0x6d,0x6b,0x07,0x6b,0x6d} ;
delay3ms()
{
	Delay1ms() ;
	Delay1ms() ;
	Delay1ms() ;
}
main()
{
	unsigned char com ,idx;

	com=0x10 ;
	idx=0 ;
	for( ;;){
	    P1=0xff ;
	    P0=dai[idx++] ;
	    P1=~com ;
	    com >>=1 ;
	    if(idx==5){
		idx=0;
		com=0x10 ;
	    }
	    delay3ms() ;
	}
}
