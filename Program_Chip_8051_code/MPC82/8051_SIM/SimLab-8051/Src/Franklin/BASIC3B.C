//
// 找出兩個8位元數中的較大值(unsigned view) 
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
unsigned char val1,val2,res;
main()
{
	res= (val1 >val2)? val1 : val2 ;
	for(;;);
}
