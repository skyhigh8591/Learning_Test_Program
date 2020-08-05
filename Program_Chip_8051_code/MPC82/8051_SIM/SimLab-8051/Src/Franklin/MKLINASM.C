//
//  配合"自動測試行組譯程式實習"
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
	    // 觸發輸入
	    P2 = P2|0x01;
	    P2 = P2&0xfe;
	    // 讀入一個ASCII CODE
	    c = P0;

	    // 如果是0表示讀完一行指令
	    if( c==0 ){
		// 如果是1表示連續兩次讀取ASCII CODE都是0,
		// 表示讀完所有資料
		if(flag==1 ){
		    for(j=0; j < 7; j++){
			// 寫入MACHINE CODE
			P1=tt[j];
			// 觸發輸出
			P2 = P2|0x02;
			P2 = P2&0xfd;
		    }
		    // 停止計時
		    P2 = P2&0xfb;
		    break;
		}
		else{
		    // 讀完一行指令
		    flag=1;
		}
	    }
	    else{
		flag = 0;
	    }
	}
	for(;;);
}
