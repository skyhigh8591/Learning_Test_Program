//
// auto testing for line assembler
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>

unsigned char code tt[]={0xa4, 0xa5, 0xc6, 0xa5, 0xc5, 0x88, 0xa5};

void main ()
{
	unsigned char c, flag=0;
	int j=0;

	P2=0xff;
	for(;;){
	    // trigger input
	    P2 = P2|0x01;
	    P2 = P2&0xfe;
	    // read ASCII CODE
	    c = P0;

	    //
	    if( c==0 ){
		//
		//
		if(flag==1 ){
		    for(j=0; j < 7; j++){
			// write MACHINE CODE
			P1=tt[j];
			// trigger output
			P2 = P2|0x02;
			P2 = P2&0xfd;
		    }
		    // stop
		    P2 = P2&0xfb;
		    break;
		}
		else{
		    //
		    flag=1;
		}
	    }
	    else{
		flag = 0;
	    }
	}
	for(;;);
}
