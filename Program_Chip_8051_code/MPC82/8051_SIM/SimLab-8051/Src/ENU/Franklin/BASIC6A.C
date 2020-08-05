//
// The sum of 8-bit numbers (the sum is 8-bit)
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
unsigned char val[10],sum;
main()
{
	unsigned char i ;
	F0=1 ;
	sum=0 ;
	for(i=0 ; i < val[0];i++){
	    sum += val[1+i] ;
	}
	for(;;);
}
