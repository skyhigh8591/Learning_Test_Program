//
// The addition of two 8-bit numbers
//
#pragma oe db pw(80) SM SB CD
unsigned char val1[3];
unsigned char data  * pval1 ;
main()
{
	pval1= val1 ;
	pval1[2]= pval1[0]+pval1[1] ;
	for(;;);
}
