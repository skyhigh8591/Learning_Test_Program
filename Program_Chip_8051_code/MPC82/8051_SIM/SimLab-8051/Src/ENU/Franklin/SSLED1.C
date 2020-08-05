//
//
//    Sequence ON a-segment, b-segment, c-segment, d-segment, e-segment, f-segment, g-segment , and dot-segment on Seven-Segment LED
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
main()
{
	P0=0xfe ;
	for(;;){
	    Delay100ms() ;
	    P0 <<=1 ;
	    P0 +=1 ;
	    if(P0 ==0xff){
		P0=0xfe ;
	    }
	}
}
