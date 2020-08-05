//
//   配合"指撥開關/8個LED實習板"
//    指撥開關的ON/OFF分別控制8個LED的亮/熄
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
main()
{
	for(;;){
	    P0=~P1 ;  //將Switch讀到的值做反相(0->1,1->0) 
	}
}
