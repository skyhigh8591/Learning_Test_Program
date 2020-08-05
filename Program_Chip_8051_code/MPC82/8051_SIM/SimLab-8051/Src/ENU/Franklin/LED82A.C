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
	char State ;
	P0 =0x7f;
	State=RIGHT ;
	for(;;) {
	    Delay100ms() ;
	    if(State == RIGHT){
		P0 >>= 1;
		P0 |=0x80 ;
	    }
	    if(State == LEFT){
		P0 <<= 1;
		P0 ++ ;
	    }
	    if((P0&0x1)==0){
		State= LEFT ;
	    }
	    if((P0&0x80)==0){
		State= RIGHT ;
	    }
	}
}
