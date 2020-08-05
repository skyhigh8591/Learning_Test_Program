//
// 兩個8位元數的相加
//
#pragma oe db pw(80) SM SB CD
unsigned char val1,val2,res;
unsigned char  data * pval1 ;
unsigned char  data * pval2 ;
unsigned char  data * pres ;
main()
{
	pval1= &val1 ;
	pval2= &val2 ;
	pres= &res ;
	*pres= *pval1+*pval2 ;
	for(;;);
}
