//
//    用單相激磁的方式,使步進馬達反轉n格
//       由於步進馬達初值的刻意設定,迴路內只須右旋即可
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include	"Delay.h"
#define n   10
main()
{
	unsigned char pp=0x88 ;
	int Step ;

	for(Step=0 ;Step < (n+1) ; Step++){
	    P0=pp ;
	    // pp內容作右旋
	    if(pp&0x1){
		pp >>=1 ;
		pp+=0x80 ;
	    }
	    else{
		pp >>=1 ;
	    }
	    Delay10ms() ;
	}
	for(;;) ;
}
