//
//
//   Display Chinese word "da" on 8*8 Mono Dot-matrix LED
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
unsigned char code dai[]= { 0xfd,0xdb,0xd7,0x0f,0xd7,0xdb,0xdd,0xff} ;
delay3ms()
{
	Delay1ms() ;
	Delay1ms() ;
	Delay1ms() ;
}
main()
{
	unsigned char com ,idx;

	com=0x80 ;
	idx=0 ;
	for( ;;){
	    P1=0xff ;
	    P0=dai[idx++] ;
	    P1=~com ;
	    com >>=1 ;
	    if(idx==8){
   		idx=0;
		com=0x80 ;
	    }
	    delay3ms() ;
	}
}
