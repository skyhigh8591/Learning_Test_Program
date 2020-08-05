//
// The addition of two 8-bit numbers (BCD)
//
#pragma oe db pw(80) SM SB CD
#include    <reg51.h>
unsigned char val1,val2,res;
main()
{
	unsigned char low4,high4 ,carry ;
	F0=1 ;
	low4=(val1&0xf)+(val2&0xf) ;
	carry=0 ;
	if(low4 >= 10){
	    carry=0x1 ;
	    low4-= 10 ;
	}
	high4=(val1 >> 4)+(val2 >> 4)+carry ;
	carry=0 ;
	if(high4 >=10){
	    carry=1 ;
	    high4-= 10 ;
	}
	res = (high4 << 4)+low4 ;
	for(;;);
}
