//
//
//       ON-LED  rotate  right
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "Delay.h"

main()
{
	P0 =0xc0;
	for(;;) {
	    Delay100ms() ;
	    if(P0&0x01){                 //P0 rotate right 1 bit
		P0 >>=1 ;
		P0 |=0x80 ;
	    }
	    else{
		P0 >>= 1 ;
	    }
	}
}
