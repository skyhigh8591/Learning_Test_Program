//
//
//     Sequence display number 0,1,2,3,4,5,6,7,8,9 on Seven-Segment LED
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
unsigned char code sstbl[]= { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90} ;
main()
{
	char i ;
	i=0 ;
	for( ; ;){
	    P0=sstbl[i++] ;
	    if(i >=10){
		i=0 ;
	    }
	    Delay100ms() ;
	}
}
