//
//
//   Read  the value setting in DIP Switch ,then send to the DAC0800
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
main()
{
	for(;;){
	    P0=~P1 ;
	}
}
