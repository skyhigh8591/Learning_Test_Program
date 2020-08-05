// PROGRAM	: BT_Ext_01.c							2020.0325
// FUNCTION	: Multi 7 SEGMENT LED Control 	      	By Steven
//			  HC-05 BT is Used, PA6->HC05 TX, PA7->HC05 RX
//			  PC2->Buzzer for Alarm	 
#include	<HT66F2390.h>
#include	"MyType.H"
#define	fH		8000000								//MCU HIRC Frequency
#define BR		9600								//Baud Rate
#define	SEGPort	_pg
#define SEGPortC	_pgc
#define	ScanPort	_pe
#define	ScanPortC	_pec
const u8 SEG_TAB[] =	{			   				//7-Segment Table
			         0x3F,0x06,0x5B,0x4F,0x66,
			         0x6D,0x7D,0x07,0x7F,0x67};
volatile u8 *ptr,R100ms,ScanCode,Digit[4];
volatile u8 min=0,hour=0,sec=0;						//可改變以設定時間
volatile u8 buf[6];
volatile bit FG_RX;
void Delayms(u16 i);
void main()
{	u8 Ahour=25,Amin=0,Asec=0;
	bit FG_OK;					
	_wdtc=0b10101111;								//關閉看們狗計時器
	SEGPort=0; SEGPortC=0; 							//Config Port as Output
	ScanPort&=0xF0; ScanPortC&=0xF0;
	_stm2c0=0;										//fINT=fSYS/4(0.5us)
	_stm2c1=0b11000001;								//Timer/Counter, sTM2A Match Clear
	_stm2al=(u8)10000; _stm2ah=10000>>8;        	//sTM2A=10000 (10000*0.5us=5ms)
	
	_pac1=1; _papu1=1;
	_pas1=0b00110000;								//設置RX0->PA6
	_u0cr1=0b10000000;								//UARTEN0/8-Bit/No_parity//1 Stop Bit///
	_u0cr2=0b01100100;								///RXEN0/BRGH0//RIEn//	
	_brg0=fH/((u32)16*BR)-1;						//BRGH0=1
	_mf5e=1; _ur0e=1;								//致能UART0中斷
	
	_ptm0c0=0; _ptm0c1=0b00110001; _pcs0=0x20;		//PC2 as PTP0
	_sledc1=0x02;

	Digit[1]=min/10;  Digit[0]=min%10; 
	Digit[3]=hour/10; Digit[2]=hour%10;
	R100ms=200; 									//Initial Counter(200*5ms)=1 Sec
	ptr=Digit; ScanCode=0b10000000;		   			//Initial Pointer
	_mf4e=1; _stm2ae=1;								//Enable STM2 Interrupt
	_emi=1; _st2on=1; 								//Start STM2, Interrupt	
	Digit[1]=min/10;  Digit[0]=min%10; 
	Digit[3]=hour/10; Digit[2]=hour%10;
	while(1)
	{	if(FG_RX)
		{	FG_RX=0;
			hour=buf[0]; min=buf[1]; sec=buf[2];
			Ahour=buf[3]; Amin=buf[4]; Asec=buf[5];
			Digit[1]=min/10;  Digit[0]=min%10; 
			Digit[3]=hour/10; Digit[2]=hour%10;
			_ptm0al=(u8)400; _ptm0ah=400>>8;
			_pt0on=1; Delayms(80);_pt0on=0;
		}
		if(hour==Ahour && min==Amin && sec==Asec) FG_OK=1;
		while(FG_OK)
		{	_ptm0al=(u8)500; _ptm0ah=500>>8;
			_pt0on=1; Delayms(60);_pt0on=0;
			_ptm0al=(u8)1000; _ptm0ah=1000>>8;
			_pt0on=1; Delayms(60);_pt0on=0;
			if(!_pa1) FG_OK=0;
			if(FG_RX) {FG_OK=0; FG_RX=0;}
		}
	}	
}
DEFINE_ISR(STM2,0x38)
{	_emi=1;
	SEGPort=0;										//Turn-off 7-Seg
	GCC_RL(ScanCode);								//Update Scan Code
	if(ScanCode==0b00010000)
	{	ScanCode=0b00000001; ptr=Digit;	      		//Restart ScanCode	
	}
	ScanPort=ScanCode;									
/*=============== Connect PG7 to dp or dps=====================*/
	//4 DPs Flash with rate=0.5 sec	
	if(R100ms<100 ) SEGPort=SEG_TAB[*ptr++];	
	else SEGPort=(SEG_TAB[*ptr++]|0b10000000);
/*================ Connect PG7 to dp =========================*/
	//Each DP Turn-On 1 sec then Change to Next one 
//	if(1<<(sec%4)==ScanCode ) SEGPort=(SEG_TAB[*ptr++]|(1<<7));
//	else SEGPort=SEG_TAB[*ptr++];
/*===================================================*/
//	if(FG_GoStop)
	{ if(--R100ms==0)
		{	R100ms=200;
			if(++sec==60)
			{	sec=0;	
				if(++min==60)
				{	min=0;
					if(++hour==24) hour=0;
				}
				Digit[1]=min/10;  Digit[0]=min%10; 
				Digit[3]=hour/10; Digit[2]=hour%10;
			}
		}
	}
	_stm2af=0;			
}
DEFINE_ISR(UART0,0x3C)
{	static u8 i=0;
	if(_rxif0) buf[i++]=_txr_rxr0;				//取得接收資料
	if(i>5)
	{	FG_RX=1;								//設置接收旗標
		i=0;
	}
	_ur0f=0;									//清除UR0F旗標(共享型)	
}
void Delayms(u16 i)
{	u16	j;
	for(j=0;j<i;j++) GCC_DELAY(2000);			      	//Dealy i*1ms
}