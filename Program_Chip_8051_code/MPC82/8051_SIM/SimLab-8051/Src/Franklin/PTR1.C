//
//  指到內部資料記憶體的指標佔一位元組
//  指到程式記憶體的指標佔二位元組
//  指到任意記憶體的指標佔參位元組
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
char data *pd ;
char code *pc ;
char *pp ;
void main()
{
char s1,s2,s3 ;
s1 = sizeof(pd) ;
s2 =  sizeof(pc) ;
s3 = sizeof(pp) ;
}
