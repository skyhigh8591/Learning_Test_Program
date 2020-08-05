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
	unsigned char tP0,tP1,tP2,tP3 ;

	tP0=0 ;
	P0= ~tP0 ;
	tP1=0x55 ;
	P1=~tP1 ;
	tP2=tP3=0x1 ;
	P2=P3=~tP2 ;
	for(;;) {
	    Delay100ms() ;
	    tP0++ ;        // P0 binary counter
	    P0=~tP0 ;
	    tP1=(tP1== 0x55)? 0xaa : 0x55 ; //P1 0x55/0xaa interchange
	    P1= ~tP1 ;
	    if(tP2 ==0x80){  //P2 left rotate
		tP2= 0x1 ;
	    }
	    else{
		tP2 <<=1 ;
	    }
	    P2= ~tP2 ;

	    if(tP3== 0x1){      //P3 right rotate
		tP3= 0x80 ;
	    }
	    else{
		tP3 >>=1  ;
	    }
    	    P3= ~tP3 ;
	}
}
