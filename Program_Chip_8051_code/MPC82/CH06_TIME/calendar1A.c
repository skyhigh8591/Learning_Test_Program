//************* calendar1A.c *************************************
//�ʧ@�G�HTimer2�p�ɤ��_�A�bLCD��ܹq�l���ɡB���B��
//      ��KEY1�����[�A��KEY2�ɻ��[
//*************************************************************
#include "..\MPC82.H"   //�Ȧs���βպA�w�q
                  //Fosc=22.1184MHz�ATimer�ɯ�=Fosc/12=1.8432MHz
#define T  57600  //Timer���ɮɶ�=(1/1.8432MHz)*57600=31250uS
 unsigned char dly_sec=32; //�]�w�p�ɭ��Ц��ơA�ɶ�=31250uS*32=1��
 unsigned char hor=13,min=32,sec=55;  //�]�w�ɡB������	

main()
{
   EA=1; ET2=1; //�P��Timet2�p�ɷ��줤�_
   T2CON=0x00; //�]�w�������p�ɡA���쭫�s���J
   RCAP2=T2R=65536-T; //�]�wTimer2�έ��s���J�ɶ�
   TR2=1;      //�Ұ�Timet2
   					    
   LCD_init();           //���m�βM��LCD 

   while(1)	  //�}�l��ܤέp��U�~��
   {	
   	  LCD_Cmd(0x80);	//��ܲĤ@���m
      LCD_Data(hor/10+'0');LCD_Data(hor%10+'0'); //��ܮ�
      LCD_Data(':');
           
	  LCD_Data(min/10+'0');LCD_Data(min%10+'0'); //��ܤ�
      LCD_Data(':');
    
      LCD_Data(sec/10+'0'); LCD_Data(sec%10+'0');//��ܬ�
	  
	  if(P3_2==0) { min++; Delay_ms(1000);}  //��KEY1�����[
	  if(P3_3==0) { hor++; Delay_ms(1000);}	 //��KEY2�ɻ��[
	  if(min > 59) {min=0; hor++;}    
	  if(hor > 23) hor=0;    
      
	  if (sec < 60) continue; //�Y��p��60��while(1)�B   
      sec=0; min++;           //����60�h�O��=0�A���[�@
	  if (min < 60) continue; //�Y���p��60��while(1)�B   
      min=0; hor++;           //�Y������60�h�O��=0�A�ɥ[�@
      
	  if (hor <24)  continue; //�Y�ɤp��24��while(1)�B
      hor=0; min=0; sec=0;    //�Y�ɵ���24�h�O�ɡB���B��=0 
  }
}
/*******************************************************/ 
void T2_int(void) interrupt 5  //Timet2���_���
{
  dly_sec--;	        //�p�ɭ��Ц��ƻ���
  if(dly_sec==0)        //�Y��ɶ���
   {sec++; dly_sec=32;} //���[�έ��Ц���(�]���_�I)
   TF2=0;    //�M��TF2=0
}
/***********************************************************
*��ƦW��: LCD_Data
*�\��y�z: �ǰe��ƨ��r��LCD
*��J�ѼơGdat
************************************************************/
void LCD_Data(char dat)  //�ǰe��ƨ�LCD
{
    Data=dat; //��ưe��BUS
    RS=1;RW=0;EN=1;//��Ƽg�J��LCD��
    Delay_ms(1);   //LCD���ݼg�J����
    EN=0;          //�T��LCD    
}
/***************************************************************
*��ƦW��: LCD_Cmd
*�\��y�z: �ǰe�R�O���r��LCD
*��J�ѼơGCmd
************************************************************/
void LCD_Cmd(unsigned char Cmd) //�ǰe�R�O��LCD
{
    Data=Cmd;  //�R�O�e��BUS
    RS=0;RW=0;EN=1; //�R�O�g�J��LCD��
    Delay_ms(1);    //LCD���ݼg�J����     
    EN=0;           //�T��LCD
}
/***************************************************************
*��ƦW��: LCD_init
*�\��y�z: �ҩl�Ƥ�r��LCD
*****************************************************************/
void LCD_init(void)    //LCD���ҩl�{��  
{
    LCD_Cmd(0x38);/*0011 1000,8bit�ǿ�,���2��,5*7�r��
                    bit4:DL=1,8bit�ǿ�,
                    bit3:N=1,���2��
                    bit2:F=0,5*7�r��*/    
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
