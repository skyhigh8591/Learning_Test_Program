//
// Demonstrate the access of char data *pd
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
char data *pd ;
void main()
{
	char v1,v2,v3;
	char i ;
	v1=pd[0] ;
	v2=pd[1] ;
	v3=pd[i] ;
}
