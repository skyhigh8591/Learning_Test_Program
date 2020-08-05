//
//
//    Let Stepping Motor clockwise to rotate n steps ,using two-phase pulse method
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include	"Delay.h"
#define n   10
main()
{
	unsigned char pp=0x33 ;
	int Step ;

	for(Step=0 ;Step < (n+1) ; Step++){
	    P0=pp ;
	    // pp rotate left
	    if(pp &0x80){
		pp <<=1 ;
		pp+=1 ;
	    }
	    else{
		pp <<=1 ;
	    }
	    Delay10ms() ;
	}
	for(;;) ;
}
