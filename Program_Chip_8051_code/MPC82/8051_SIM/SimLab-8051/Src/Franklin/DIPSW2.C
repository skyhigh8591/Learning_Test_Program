//
//   配合"指撥開關/8個LED實習板"
//     指撥開關所代表的數值控制8個LED計數的速度
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
