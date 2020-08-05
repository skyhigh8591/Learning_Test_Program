//
// 兩個8位元數的相加
//
#pragma oe db pw(80) SM SB CD
unsigned char val1[3];
unsigned char data  * pval1 ;
main()
{
	pval1= val1 ;
	*(pval1+2)= *pval1+*(pval1+1) ;
	for(;;);
}
