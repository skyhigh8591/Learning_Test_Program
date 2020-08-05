//
//    用二相激磁的方式,使步進馬達正轉n格
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include	"Delay.h"
#define n   10
char code pp[]={
	0x3 ,
	0x6 ,
	0xC ,
	0x9 
} ;
main()
{
	int Step ;
	char idx_pp=0 ;
	for(Step=0 ;Step < (n+1) ; Step++){
	    P0=pp[idx_pp++] ;
	    if(idx_pp == 4){
		idx_pp=0 ;
	    }
	    Delay10ms() ;
	}
	for(;;) ;
}
