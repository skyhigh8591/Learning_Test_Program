//
// 許多8位元數的相加(和為8位元) 
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
