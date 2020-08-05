//
//  配合"自動測試反組譯程式實習"
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
	    // 觸發輸入
	    P2 = P2|0x01;
	    P2 = P2&0xfe;
	    // 讀入一個MACHINE CODE
	    c = P0;

	    // 如果是0xa5表示讀完所有的資料
	    if( c == 0xa5 ){
		for(i=0;i<28;i++){
		    // 寫入一個ASCII CODE
		    P1 = p[i];
		    // 觸發輸出
		    P2 = P2|0x02;
		    P2 = P2&0xfd;
		}

		// 停止計時
		P2 = P2&0xfb;
		break;
	    }
	    else{
		// 處理讀入的資料
	    }
	}
	for(;;);
}
