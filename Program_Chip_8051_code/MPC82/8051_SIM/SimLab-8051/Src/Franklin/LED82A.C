//
//   配合"8個LED(共陰)實習板"
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
	char State ;
	P0 =0x7f;
	State=RIGHT ;
	for(;;) {
	    Delay100ms() ;
	    if(State == RIGHT){
		P0 >>= 1;
		P0 |=0x80 ;
	    }
	    if(State == LEFT){
		P0 <<= 1;
		P0 ++ ;
	    }
	    if((P0&0x1)==0){
		State= LEFT ;
	    }
	    if((P0&0x80)==0){
		State= RIGHT ;
	    }
	}
}
