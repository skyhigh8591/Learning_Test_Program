//
//   配合"8個LED(共陰)實習板"
//      P0所接的8個LED(初始狀態:最左1個熄；其餘7個LED亮著),其變化方式:
//         當熄的LED出現在最左邊時,進行右旋, 
//         反之,當熄的LED出現在最右邊時,進行左旋
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "Delay.h"
code tbl1[]= { 0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf } ;
main()
{
	char i ;
	for(;;) {
	    for(i = 0 ; i < 14 ; i++ ){
		P0=tbl1[i] ;
		Delay100ms() ;
	    }
	}
}
