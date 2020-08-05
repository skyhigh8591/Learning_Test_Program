//
// 配合"32個LED(共陰)實習板"
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

	P0=0 ;
	P1=0x55 ;
	P2=P3=0x1 ;
	for(;;) {
	    Delay100ms() ;
	    P0++ ;        // P0當二進制計數器
	    P1=(P1== 0x55)? 0xaa : 0x55 ; //P1 0x55/0xaa交互變化
	    if(P2 ==0x80){  //P2左旋
		P2= 0x1 ;
	    }
	    else{
		P2 <<=1 ;
	    }
	    if(P3== 0x1){      //P3右旋
		P3= 0x80 ;
	    }
	    else{
		P3 >>=1  ;
	    }
	}
}
