//
//   配合"8個LED(共陽)實習板"
//      P0所接的8個LED(初始狀態:最左1個熄；其餘7個LED亮著),其變化方式:
//         當熄的LED出現在最左邊時,進行右旋, 
//         反之,當熄的LED出現在最右邊時,進行左旋
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "Delay.h"
enum {LEFT,RIGHT} ;
main()
{
	unsigned char tP0 ;
	char State ;
	tP0 =0x7f;
	P0= ~tP0 ;
	State=RIGHT ;
	for(;;) {
	    Delay100ms() ;
	    if(State == RIGHT){
		tP0 >>= 1;
		tP0 |=0x80 ;
	    }
	    if(State == LEFT){
		tP0 <<= 1;
		tP0 ++ ;
	    }
	    if((tP0&0x1)==0){
		State= LEFT ;
	    }
	    if((tP0&0x80)==0){
		State= RIGHT ;
	    }
	    P0= ~tP0 ;
	}
}
