//
//   配合"揚聲器實習板"
//       P0.0所接的揚聲器順序發出Do~Si的音, 各音持續1秒鐘. 
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "Delay.h"

char code tbl1[]={19,17,15,14,12,11,10,9};
int code  tbl2[]={523,587,659,698,785,880,988,1047};
main()
{
	char j, t1;
	int  i, k, t2;

	P0 =0;
	
	for(i=0; i<8; i++){
	    t2=tbl2[i];
	    t1=tbl1[i];	
	    for(k=0; k<t2; k++){
		for(j=0; j<t1; j++){
		    Delay100us();
		}
		P0 = ~P0;
	    }
	}
	for(;;);
}
