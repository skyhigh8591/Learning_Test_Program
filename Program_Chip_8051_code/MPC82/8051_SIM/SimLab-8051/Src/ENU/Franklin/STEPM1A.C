//
//    Let Stepping Motor clockwise to rotate n steps ,using single-phase pulse method
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include	"Delay.h"
#define n   10
main()
{
	unsigned char pp=0x1 ;
	int Step ;

	for(Step=0 ;Step < (n+1) ; Step++){
	    P0=pp ;
	    pp <<=1 ;
	    if(pp == 0x10){
		pp=0x1 ;
	    }
	    Delay10ms() ;
	}
	for(;;) ;
}
