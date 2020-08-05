//************* LCD3A.c *********************
//*�ʧ@�G�bLCD��ܤW�U��12�p�ɹq�l�����ܤ�
//*******************************************
#include "..\MPC82.H"   //�Ȧs���βպA�w�q
main()
{
   char hor=11,min=58,sec=52;//�]�w�ɡB���B����
   LCD_init();           //���m�βM��LCD    
   while(1)
   {
    LCD_Cmd(0x82);        //�ѲĤ@��}�l��� 
	if (hor<12) {LCD_Data('A');LCD_Data('M');}
	else  {LCD_Data('P');LCD_Data('M');}
	LCD_Data(' ');
    LCD_Data(hor%12/10+'0'); //�ɪ��Q��ƨ�LCD���
    LCD_Data(hor%12%10+'0'); //�ɪ��Ӧ�ƨ�LCD���
    LCD_Data(':');
    
    LCD_Data(min/10+'0'); //�����Q��ƨ�LCD���
    LCD_Data(min%10+'0'); //�����Ӧ�ƨ�LCD���
    LCD_Data(':');
    
    LCD_Data(sec/10+'0'); //���Q��ƨ�LCD���
    LCD_Data(sec%10+'0'); //���Ӧ�ƨ�LCD���
    
	Delay_ms(500);
    sec++;              //��[�@
    if (sec < 60) continue; //�Y��p��60��loop�B   
    sec=0; min++;       //����60�h�O��=0�A���[�@
    if (min < 60) continue; //�Y���p��60��loop�B   
    min=0; hor++;       //�Y������60�h�O��=0�A�ɥ[�@
    if (hor <25)  continue; //�Y�ɤp��25��loop�B
    hor=1;min=0; sec=0;//�Y��=25�h�O��=1�B��=0�B��=0 
	
   }
}
/***********************************************************
*��ƦW��: LCD_Data
*�\��y�z: �ǰe��ƨ��r��LCD
*��J�ѼơGdat
************************************************************/
void LCD_Data(unsigned char dat)  //�ǰe��ƨ�LCD
{
    unsigned char dly=2;
	Data=dat;      //��ưe��BUS
    RS=1;RW=0;EN=1;//��Ƽg�J��LCD��
    while(dly--);
	EN=0;          //�T��LCD 
	LCD_wait();    //LCD���ݼg�J����  
}
/***************************************************************
*��ƦW��: LCD_Cmd
*�\��y�z: �ǰe�R�O���r��LCD
*��J�ѼơGCmd
************************************************************/
void LCD_Cmd(unsigned char Cmd) //�ǰe�R�O��LCD
{
    unsigned char dly=2;
	Data=Cmd;       //�R�O�e��BUS
    RS=0;RW=0;EN=1; //�R�O�g�J��LCD��
    while(dly--);
    EN=0;           //�T��LCD
	LCD_wait(); //LCD���ݼg�J���� 
}
/***************************************************************
*��ƦW��: LCD_Cmd
*�\��y�z: �ǰe�R�O���r��LCD
*��J�ѼơGCmd
************************************************************/
void LCD_Cmd_Init(unsigned char Cmd) //�ǰe�R�O��LCD
{
	Data=Cmd;       //�R�O�e��BUS
    RS=0;RW=0;EN=1; //�R�O�g�J��LCD��
    Delay_ms(1);
    EN=0;           //�T��LCD
    Delay_ms(1);
}
/***************************************************************
*��ƦW��: LCD_init
*�\��y�z: �ҩl�Ƥ�r��LCD
*****************************************************************/
void LCD_init(void)    //LCD���ҩl�{��  
{
    LCD_Cmd_Init(0x38);//0011 1000,8bit�ǿ�,���2��,5*7�r��
    LCD_Cmd_Init(0x38);//bit4:DL=1,8bit�ǿ�,
    LCD_Cmd_Init(0x38);//bit3:N=1,���2��
                       //bit2:F=0,5*7�r��    
    LCD_Cmd(0x0c);/*0000 1100,��ܹ�ON,����ܴ��,��Ф��{�{
                    bit2:D=1,��ܹ�ON
                    bit1:C=0,����ܴ��
	                bit0:B=0,��Ф��{�{*/
    LCD_Cmd(0x06);/*0000 0110,//��ܧ���Хk��,��в���T�� 
                    bit1:I/D=1,��ܧ���Хk��,
                    bit0:S=0,��в���T��*/  
    LCD_Cmd(0x01); //�M����ܹ�  
    LCD_Cmd(0x02); //��Ц^���  
}
/**************************************************
*��ƦW��: LCD_wait
*�\��y�z: LCD���ݦ��L�X��BF
****************************************************/
void LCD_wait(void)
{
  unsigned char status;  //�w�qLCDŪ�����A
  Data=0xff; //P0�]�w����J��
  do
  {
    RS=0;RW=1;EN=1;//Ū���R�O
    status= Data;	//��JLCD���R�O
    EN=0;			//�T��LCD
  }
  while(status & 0x80); //���ݦ��L�X��BF=0
}
