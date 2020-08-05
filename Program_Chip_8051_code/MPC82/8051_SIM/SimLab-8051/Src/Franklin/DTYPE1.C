#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
char val1,val2,res,i;
char data *pcd ;
char code *pcc ;
int ival1,ival2,ires;
int data *pid ;
long lval1,lval2,lres;
long data *pld ;
main()
{
	pcd= &val1 ;
	val1= *pcd ;
	val2= pcd[1] ;
	val1= pcd[i] ;
	ival1= *pid ;
	ival2= pid[1] ;
	ival1= pid[i] ;
	lval1= *pld ;
	lval2= pld[1] ;
	lval1= pld[i] ;

	res=val1+val2 ;
	for(;;);
}
