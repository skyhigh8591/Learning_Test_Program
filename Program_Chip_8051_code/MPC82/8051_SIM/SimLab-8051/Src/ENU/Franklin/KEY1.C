//
//
//   The phenomenon of Key bounce
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
sbit KEY1=P1 ^0 ;
main()
{
	P0=0 ;
	for(;;){
	    while(KEY1 ==1) ;
	    P0++;
	    while(KEY1==0) ;
	}
}
