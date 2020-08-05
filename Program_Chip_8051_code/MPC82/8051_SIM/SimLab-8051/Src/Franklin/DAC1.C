//
//  配合"DAC0800實習板"
//   將指撥開關的設定值,送到DAC0800
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
main()
{
	for(;;){
	    P0=~P1 ;
	}
}
