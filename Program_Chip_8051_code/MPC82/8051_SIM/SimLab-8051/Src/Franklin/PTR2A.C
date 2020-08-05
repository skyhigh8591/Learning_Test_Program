//
//示範char data *pd之存取
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
char data *pd ;
void main()
{
	char v1,v2,v3;
	char i ;
	v1=*pd ;
	v2=*(pd+1) ;
	v3=*(pd+i) ;
}
