#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
main()
{
	TMOD =0xd0 ; // counter mode 
	TR0=1 ;
	for(;;) {
	    P0=TL0 ;
	}
}
