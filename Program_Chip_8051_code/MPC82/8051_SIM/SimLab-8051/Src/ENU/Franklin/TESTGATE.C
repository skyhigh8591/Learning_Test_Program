//
// design  logical gate tester
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
#include "Delay.h"

struct tt{
	char in1,in2,out;
};

struct tt code Tbl[7][4]=
{
    {{0,0,0}, {0,1,0}, {1,0,0}, {1,1,1}},
    {{0,0,0}, {0,1,1}, {1,0,1}, {1,1,1}},
    {{0,0,0}, {0,1,1}, {1,0,1}, {1,1,0}},
    {{0,0,1}, {0,1,1}, {1,0,1}, {1,1,0}},
    {{0,0,1}, {0,1,0}, {1,0,0}, {1,1,0}},
    {{0,0,1}, {0,1,0}, {1,0,0}, {1,1,1}},
    {{0,0,1}, {0,1,1}, {1,0,0}, {1,1,0}}, 
};

void delay20ms()
{
	Delay10ms();
	Delay10ms();
}

void main ()
{
	unsigned char i, j, k, t;

	P0 = 0;
	for(;;){
	    if( (P2&0x01) == 1 ){
		delay20ms() ;
		delay20ms() ;
		while((P2&0x01) == 1);
		for( i=0; i < 7; i++ ){
		    t = 0x01<<i;
		    if( (P1&t) != 0 ){
			k=0;
			for(j=0;j<4;j++){
			    if( Tbl[i][j].in1 ) P0 |= 1;
			    else  P0 &= 0xfe;
			    if( Tbl[i][j].in2 ) P0 |= 2;
			    else	  P0 &= 0xfd;
			    t = P2>>1;
			    if( (t&0x01) != Tbl[i][j].out ){
				k=1;
			    }
			}
			P0&=0xf3;
			if( k==1){
			    P0 |=0x08;
			}
			else{
			    P0 |=0x04;
			}	
			break;
		    }
		}
	    }
	}
}
