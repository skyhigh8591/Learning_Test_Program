//
//
//    ON/OFF setting in DIP Switch control Light/Dark of 8 pieces of LED
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
main()
{
	for(;;){
	    P0=~P1 ;  //complement switch setting value(0->1,1->0)
	}
}
