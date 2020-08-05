//
// 配合"32個LED(共陽)實習板"
//    P0所接的8個LED當二進制計數器,P1所接的8個LED依序亮熄著,並交互變化, 
//    P2所接的8個LED只有一LED亮著,並進行左旋的變化, 
//    P3所接的8個LED只有一LED亮著,並進行右旋的變化
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "Delay.h"
main()
{
	char i ;
	int j ;
	unsigned char tP0,tP1,tP2,tP3 ;

	tP0=0 ;
	P0= ~tP0 ;
	tP1=0x55 ;
	P1=~tP1 ;
	tP2=tP3=0x1 ;
	P2=P3=~tP2 ;
	for(;;) {
	    Delay100ms() ;
	    tP0++ ;        // P0當二進制計數器
	    P0=~tP0 ;
	    tP1=(tP1== 0x55)? 0xaa : 0x55 ; //P1 0x55/0xaa交互變化
	    P1= ~tP1 ;
	    if(tP2 ==0x80){  //P2左旋
		tP2= 0x1 ;
	    }
	    else{
		tP2 <<=1 ;
	    }
	    P2= ~tP2 ;

	    if(tP3== 0x1){      //P3右旋
		tP3= 0x80 ;
	    }
	    else{
		tP3 >>=1  ;
	    }
    	    P3= ~tP3 ;
	}
}
