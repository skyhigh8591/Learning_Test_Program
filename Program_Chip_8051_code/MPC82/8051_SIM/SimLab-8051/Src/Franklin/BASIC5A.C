//
// ¦r¤¸¤À³Î
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
char val1,high4,low4;
main()
{
	high4= (val1 >> 4 ) &0xf ;
	low4= val1 & 0xf ;
	for(;;);
}
