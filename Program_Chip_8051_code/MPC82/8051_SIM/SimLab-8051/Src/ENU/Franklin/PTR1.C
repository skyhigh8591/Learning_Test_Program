//
//  The typed pointer to internal data memory can be stored using 1 byte
//  typed pointer to program memory can be stored using 2 bytes
//  untyped pointers are always stored using 3 bytes
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
