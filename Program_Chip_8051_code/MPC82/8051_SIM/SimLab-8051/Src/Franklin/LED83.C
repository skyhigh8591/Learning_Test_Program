//
//   配合"8個LED(共陽)實習板"
//       P0所接的8個LED(初始狀態:最左2個亮；其餘6個LED熄著),並進行右旋的變化
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "Delay.h"

main()
{
	unsigned char tP0 ;
	tP0 =0xc0;
	P0=~tP0 ;
	for(;;) {
	    Delay100ms() ;
	    if(tP0&0x01){                 //P0右旋1位元
		tP0 >>=1 ;
		tP0 |=0x80 ;
	    }
	    else{
		tP0 >>= 1 ;
	    }
	    P0=~tP0 ;
	}
}
