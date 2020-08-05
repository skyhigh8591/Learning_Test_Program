//
// The addition of two 16-bit numbers
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
unsigned int val1,val2,res;
unsigned char data *pval1 ;
unsigned char data *pval2 ;
unsigned char data *pres ;
main()
{
	unsigned char carry ;

	F0=1 ;
	pval1= (unsigned char *)&val1 ;
	pval2= (unsigned char *)&val2 ;
	pres = (unsigned char *)&res ;
	*(pres+1)=*(pval1+1)+*(pval2+1) ;
	carry = (*(pres+1) < *(pval1+1)) ? 1:0 ;
	*pres= pval1[0]+pval2[0]+carry ;
	for(;;);
}
