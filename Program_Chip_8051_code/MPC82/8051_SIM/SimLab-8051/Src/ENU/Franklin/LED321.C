//
//    8 pieces of LED in P0  change state by  binary counter,
//    8 pieces of LED in P1 interchange state between  OFF-ON-OFF-ON-OFF-ON-OFF-ON and ON-OFF-ON-OFF-ON-OFF-ON-OFF,
//    8 pieces of LED in P2(only 1 piece of LED is ON)change state by ON-LED to rotate left,
//    8 pieces of LED in P3(only 1 piece of LED is ON)change state  by ON-LED to rotate right
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
	    P0++ ;        // P0 binary counter
	    P1=(P1== 0x55)? 0xaa : 0x55 ; //P1 0x55/0xaa interchange
	    if(P2 ==0x80){  //P2 left rotate
		P2= 0x1 ;
	    }
	    else{
		P2 <<=1 ;
	    }
	    if(P3== 0x1){      //P3 right rotate
		P3= 0x80 ;
	    }
	    else{
		P3 >>=1  ;
	    }
	}
}
