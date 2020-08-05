//
//
//
//   1. When the most left  LED is OFF ====>OFF-LED rotate right
//   2. When the most right LED is OFF ====>OFF-LED rotate  left 
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
		P0=~tbl1[i] ;
		Delay100ms() ;
	    }
	}
}
