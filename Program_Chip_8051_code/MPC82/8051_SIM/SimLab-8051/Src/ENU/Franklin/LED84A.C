//
//
//
//      1. When the most left  LED is OFF ====>OFF-LED rotate right
//      2. When the most right LED is OFF ====>OFF-LED rotate  left
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "Delay.h"
enum {LEFT,RIGHT} ;
main()
{
	unsigned char tP0 ;
	char State ;
	tP0 =0x7f;
	P0= ~tP0 ;
	State=RIGHT ;
	for(;;) {
	    Delay100ms() ;
	    if(State == RIGHT){
		tP0 >>= 1;
		tP0 |=0x80 ;
	    }
	    if(State == LEFT){
		tP0 <<= 1;
		tP0 ++ ;
	    }
	    if((tP0&0x1)==0){
		State= LEFT ;
	    }
	    if((tP0&0x80)==0){
		State= RIGHT ;
	    }
	    P0= ~tP0 ;
	}
}
