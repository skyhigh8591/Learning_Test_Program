//
//    用二相激磁的方式,使步進馬達正轉n格
//       由於步進馬達初值的刻意設定,迴路內只須左旋即可
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
	    // pp內容作左旋
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
