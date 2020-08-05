//
//    Let Stepping Motor counterclockwise to rotate n steps ,using half-step method
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include	"Delay.h"
#define n   10
char code pp[]={
	0x1 ,
	0x9 ,
	0x8 ,
	0xC ,
	0x4 ,
	0x6 ,
	0x2 ,
	0x3 
} ;
main()
{
	int Step ;
	char idx_pp=0 ;
	for(Step=0 ;Step < (n*2+1) ; Step++){
	    P0=pp[idx_pp++] ;
	    if(idx_pp == 8){
		idx_pp=0 ;
	    }
	    Delay10ms() ;
	}
	for(;;) ;
}
