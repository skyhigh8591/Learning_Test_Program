// PROGRAM	: U4_5.c						2017.0505
// FUNCTION	: DHT-22 Reading Pgogram		By Steven
#include <HT66F2390.h>
#include "MyType.H"
#define	pLCMEN		_pe2	
#define	pLCMRW		_pe1	
#define	pLCMRS		_pe0	
#define	pLCMENC		_pec2	
#define	pLCMRWC		_pec1	
#define	pLCMRSC		_pec0	
#define	LCMData		_pg
#define	LCMDataC	_pgc
#define	pDHT		_pc2					//DHT�H����X�s���}��
#define	pDHTC		_pcc2
#define	pDHTPU		_pcpu2
#define	fSYS		8000000					//�t�Τu�@�ɯ�
#define StartTC		(2*(fSYS/(4*1000)))		//DHT22 Start�H���ɶ��Ѽ�:1ms
const u8 STR1[] = {" Humi.:   .  %RH"};		//�r��1�ت�			
const u8 STR2[] = {" Temp.:   .  Deg"};		//�r��2�ت�
u8 ReadDHT(u16*,u16*);
void LCMInit(void);
u8 LCMWrite(_Bool, u8);
void Delayms(u16);
void main()
{	const u8* ptr;
	u16 h,t;
	_wdtc=0b10101111;						//�����ݪ����p�ɾ�
	pDHTC=1; pDHTPU=1; 						//PC2�]�m����J�íP�ണ�ɹq��
	LCMInit();				           		//LCM��l��
	LCMWrite(0,0x80); ptr=STR1;				//�Ĥ@�C
	while(*ptr!=0) LCMWrite(1,*ptr++); 		//���STR1[]�r��
	LCMWrite(0,0xC0); ptr=STR2;				//�ĤG�C
	while(*ptr!=0) LCMWrite(1,*ptr++); 		//���STR2[]�r��
	while(1)
	{	while(ReadDHT(&h,&t)==1)			//���TŪ��DHT22?
		{	LCMWrite(0,0x88);
			LCMWrite(1,h/100+'0'); h%=100;	//��ܷë�:�Q���
			LCMWrite(1,h/10+'0'); h%=10;	//��ܷë�:�Ӧ��
			LCMWrite(0,0x8B);
			LCMWrite(1,h+'0');				//��ܷë�:�p���I��@��
			LCMWrite(0,0xC8);
			LCMWrite(1,t/100+'0'); t%=100;	//��ܷū�:�Q���
			LCMWrite(1,t/10+'0'); t%=10;	//��ܷū�:�Ӧ��
			LCMWrite(0,0xCB);				//��ܷū�:�p���I��@��
			LCMWrite(1,t+'0');
			Delayms(1000);					//����1��
		}
	}
}
u8 ReadDHT(u16* ptrh,u16* ptrt)
{	u32	temp=0,temp1=(u32)1<<31;
	volatile u16 TCnt; u8 parity=0;
	_ptm0c0=0;								//fINT=fSYS/4
	_ptm0c1=0b10110000;						//Single-Pulse/Active Low
	_ptm0al=(u8)StartTC; _ptm0ah=StartTC>>8;//Start Signal
	_pcs0=0x20;								//PC2==>PTP0		
	_ptm0af=0; _pt0on=1; 					//�}�l��X
	while(!_ptm0af); 						//����Start Signal����
	_pcs0=0;								//PC2==>I/O 						
	_ptm0rpl=(u8)400; _ptm0rph=400>>8;		//�]�m�����ȤW��(Response=80+80us)
	_ptm0c1=0b01010000;						//Capture I/P,�t�t���� 
	_ptp0ips=0;								//PTP2I -> PC2 (IFS1)	
 	_ptm0af=0; _ptm0pf=0; 					//�M���X��
 	while(pDHT);							//����DHT Pull-low
	_pt0on=1; 								//�Ұ�Capture
	while(!_ptm0af)							//����DHT����Response	
	{	if(_ptm0pf) { _pt0on=0; return 0;}	//�W�L�ɶ����^��,Ū�����~
	} 
	_pt0on=0;
	TCnt=_ptm0ah; TCnt=(TCnt<<8)|_ptm0al;	//���o������
	if(TCnt<240) return 0;					//Response�H���L�u,Ū�����~ 
	while(temp1!=0)							//���o32-Bit���
	{	_ptm0af=0; _pt0on=1;				//�Ұ�Capture
		while(!_ptm0af);					//���ݭt�t����		
		_pt0on=0;
		TCnt=(u16)_ptm0ah<<8; TCnt|=_ptm0al;//���o������	
		if(TCnt>200) temp|=temp1;			//0:78us, 1:120us
		temp1>>=1;
	}
	temp1=1<<7;	 							//���oCheck Sum
	while(temp1!=0)
	{	_ptm0af=0; _pt0on=1;				//�Ұ�Capture
		while(!_ptm0af);					//���ݭt�t����
		_pt0on=0;
		TCnt=(u16)_ptm0ah<<8; TCnt|=_ptm0al;//���o������	
		if(TCnt>200) parity|=temp1;
		temp1>>=1;
	}
	while(!pDHT);							//����End Signal����
	TCnt=temp;								//�p�� Checksum
	TCnt+=temp>>8;
	TCnt+=temp>>16;
	TCnt+=temp>>24;
	if((u8)TCnt!=parity) return 0;			//Checksum Error
	*ptrt=temp; *ptrh=temp>>16;				//���o�ūסB���
	return 1;								//�^��1(���TŪ��)
}
void LCMInit(void)
{	pLCMEN=0; pLCMRW=0; pLCMRS=0;	      	//�]�wEN/RW/RS�}�쬰�C�q��
	pLCMENC=0; pLCMRWC=0; pLCMRSC=0;	 	//�]�wEN/RW/RS�}�쬰��X�Ҧ�
	Delayms(40);							//LCM Power-On Time
	LCMWrite(0,0x38);						//�\��]�w:8-Bit, 2-Line, 5*7
	LCMWrite(0,0x0C);						//��ܱ���:Display on, No Cursor
	LCMWrite(0,0x06);						//�i�J�Ҧ�:Increse, Not Shift
	LCMWrite(0,0x01);						//�M��LCM
}
u8 LCMWrite(_Bool fgCD,u8 CD)
{	u8 BusyAC;
	LCMDataC=0b11111111;					//�W��Port����J�Ҧ�
	pLCMRS=0; pLCMRW=1;						//RS=0,RW=1 (Read IR)
	GCC_NOP(); 								//tAS
	do
	{	pLCMEN=1; GCC_NOP();				//EN=1,tDDR
		BusyAC=LCMData;						//Ū��LCM IR
		pLCMEN=0;							//EN=0	
	} while (BusyAC & 1<<7);				//�YLCM���L,�A��Ū��
	LCMDataC=0;								//�W��Port����X�Ҧ�
	pLCMRW=0;								//RW=0 (Write)
	pLCMRS=fgCD;							//��fgCD�ȳ]�m RS�}�쪬�A
	LCMData=CD;								//�e�X��ƩΩR�O
	pLCMEN=1; GCC_NOP(); pLCMEN=0; 			//EN=1,tPW,EN=0
	return BusyAC;							//�^��Address Counter
}
void Delayms(u16 del)
{	u16 i;									//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
}
