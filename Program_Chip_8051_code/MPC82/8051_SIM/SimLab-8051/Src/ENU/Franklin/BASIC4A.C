//
// Find the maximum from two 8-bit numbers (signed view)
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
char val1,val2,res;
main()
{
	if(val1 >val2){
	    res= val1 ;
	}
	else{
	    res=val2 ;
	}
	for(;;);
}
