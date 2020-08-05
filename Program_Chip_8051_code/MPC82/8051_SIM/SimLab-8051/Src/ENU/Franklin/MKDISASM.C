//
//auto testing for disassembler
//
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>

char code p[]={
	'M','U','L',' ','A','B',0,
	'X','C','H',' ','A',',','@','R','0',0,
	'X','C','H',' ','A',',','T','C','O','N',0
};

void main ()
{
	unsigned char c, i, j;
	int len;

	P2=0xff;
	for(;;){
	    // trigger input
	    P2 = P2|0x01;
	    P2 = P2&0xfe;
	    // read MACHINE CODE
	    c = P0;

	    // ending  all data when 0xa5
	    if( c == 0xa5 ){
		for(i=0;i<28;i++){
		    // write ASCII CODE
		    P1 = p[i];
		    // trigger output
		    P2 = P2|0x02;
		    P2 = P2&0xfd;
		}

		// stop operation
		P2 = P2&0xfb;
		break;
	    }
	    else{
		// process data
	    }
	}
	for(;;);
}
