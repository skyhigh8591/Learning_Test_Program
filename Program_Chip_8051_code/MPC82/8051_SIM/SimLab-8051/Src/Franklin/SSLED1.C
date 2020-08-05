//
//  配合"1個七段式LED(共陽)實習板"
//    依序打亮七段式LED的a段,b段,c段,d段,e段,f段,g段及dot段
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"
main()
{
	P0=0xfe ;
	for(;;){
	    Delay100ms() ;
	    P0 <<=1 ;
	    P0 +=1 ;
	    if(P0 ==0xff){
		P0=0xfe ;
	    }
	}
}
