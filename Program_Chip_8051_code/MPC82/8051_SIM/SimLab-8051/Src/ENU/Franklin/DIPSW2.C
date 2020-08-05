//
//
//   The value setting in DIP Switch control  8 pieces of LED counting speed
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
main()
{
	unsigned char i;
	for(;;){
	    P0++ ;
	    for(i=0 ; i < ~P1 ; i++){
		Delay10ms() ;
	    }
	}
}
