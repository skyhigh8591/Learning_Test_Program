//
//
//       ON-LED  rotate  right
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "Delay.h"

main()
{
	unsigned char tP0 ;
	tP0 =0xc0;
	P0=~tP0 ;
	for(;;) {
	    Delay100ms() ;
	    if(tP0&0x01){                 //P0 rotate right 1 bit
		tP0 >>=1 ;
		tP0 |=0x80 ;
	    }
	    else{
		tP0 >>= 1 ;
	    }
	    P0=~tP0 ;
	}
}
