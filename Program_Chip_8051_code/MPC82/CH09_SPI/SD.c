//********SD.C********SD�O�Хd��Ʀ�*************
#include "MPC82.H"
#include "SD.H"
#include "SD_define.h"

char SDGetResponse(void);	 //Ū��SD�O�Хd�^��
unsigned char SDGetXXResponse(const char resp);	//Ū��SD�O�Хd�^��
char SDCheckBusy(void);	 //�ˬdSD�O�Хd���L
unsigned char spiSendByte(const unsigned char dat);	 //��SPI�]�wSD�O�Хd�R�O

//---------�g�JSD�O�Хd�R�O----------------------------------------------
void SDSendCmd (const char cmd, unsigned long dat, const char crc)
{
  char frame[6];//SD�O�Хd�R�O��6-byte(48-bit)
  char temp;
  char i;
  frame[0]=(cmd|0x40); //�]�w�R�O��bit6=1(host�R�O)�æs�Jframe[0]

  for(i=3;i>=0;i--)	 //�N4-byte����Ƥ��O�s�Jframe[1-4]
   {
    temp=(char)(dat>>(8*i));//�N��ƪ�bit31~24�s�Jframe[1]
    frame[4-i]=(temp);		//�N��ƪ�bit7~0�s�Jframe[4]
   }
  frame[5]=(crc); //�N�ˮֽX�s�Jframe[5]
  for(i=0;i<6;i++) spiSendByte(frame[i]); //��SPI�ɭ��Nframe[0-5]�g�JSD�O�Хd
}
//--------------- �]�wSD�O�Хd�϶�����= 2^n -----------------------------
char SDSetBlockLength (const unsigned long blocklength)
{
  CS = 0;  //�}��SPI�������
  // Set the block length to read
  SDSendCmd(SD_SET_BLOCKLEN, blocklength, 0xFF); //�]�wSD�O�Хd�϶�����

  // get response from SD - make sure that its 0x00 (R1 ok response format)
  if(SDGetResponse()!=0x00)	  //Ū��SD�O�Хd�^���A�Y������(�^��������0)�A�A���@��
  { 
    initSD();	 //��l��SD�O�Хd
    SDSendCmd(SD_SET_BLOCKLEN, blocklength, 0xFF);//�]�wSD�O�Хd�϶�����
    SDGetResponse();  //Ū��SD�O�Хd�^��
  }

  CS=1;	//�Y�w����(�^��0)����SPI�������
  spiSendByte(0xff); //��SPI�]�wSD�O�Хd�� 8 Clock pulses of delay.

  return SD_SUCCESS; //�^������
} // Set block_length

//--------------- SPI�o�g1-byte���-----------------------------
unsigned char spiSendByte(const unsigned char dat)
{
	SPDAT = dat;            //SPI�o�g1-byte���
	while(SPSTAT != SPIF);	//�Y���_�X��SPIF=0���ǿ駹���A���ݤ�
	SPSTAT = SPIF;	        //�YSPIF=1�w�ǿ駹���A���M��SPIF=0
	return SPDAT;           //�NSPI��Ʀ^��
}
//--------------- SD�O�Хd�i�JSPI�Ҧ� -----------------------------
char SD_GoIdle()
{
  char response=0x01;
  CS = 0;  //�}��SPI�������
  
  SDSendCmd(SD_GO_IDLE_STATE,0,0x95);//�e�X�R�OCMD0�ASD�d�iSPI�Ҧ�
  
  if(SDGetResponse()!=0x01)//����SD�d�Ƨ��^��
    return SD_INIT_ERROR; //response������0x01�A�h�^�����~

  while(response==0x01)	 //�YSD�d�^�����Ƨ�
  {
    CS = 1; //����SPI�������
    spiSendByte(0xff); //��SPI�]�wSD�O�Хd�R�O
    CS = 0;	//�}��SPI�������
    SDSendCmd(SD_SEND_OP_COND,0x00,0xff); //�e�XCMD1�]�w�ާ@�q��
    response=SDGetResponse();
  }
  CS=1;	 //����SPI�������
  spiSendByte(0xff);//��SPI�]�wSD�O�Хd�R�O
  return (SD_SUCCESS);
}
//--------------- ��l��SD�O�Хd-----------------------------
char initSD (void)
{
  //raise SS and MOSI for 80 clock cycles
  //SendByte(0xff) 10 times with SS high
  //raise SS
  char i;

  SPCTL = SSIG+SPEN+MSTR; //�P��SPI��Master�Abit7���ǿ�,����SS�}�������
 
  //  initSPI();
  IFADRL = 0x01;	       //ISP/IAP��flash�C��}
  if((SCMD & 0xf0)!=0xf0)  //ISP/IAP���ǩR�O
    return SD_INIT_ERROR;

  //initialization sequence on PowerUp
  CS=1;	//����SPI�������
  for(i=0;i<=9;i++) spiSendByte(0xff); //��SPI�]�wSD�O�Хd�}�����ǰʧ@
  return (SD_GoIdle());  //�i�JSPI�Ҧ��A�æ^�kresponse
}
//--------------- Ū��SD�O�Хd�^��-----------------------------
// SD Get Responce
char SDGetResponse(void)
{
  //Response comes 1-8 bytes after command
  //the first bit will be a 0
  //followed by an error code
  //data will be 0xff until response
  char i=0;	   //�p�ƭ�
  char response;//�^����

  while(i<=64)	//����Ū��64��SD�O�Хd���^��
  {
    response=spiSendByte(0xff);//��SPI�]�wSD�O�Хd�R�O�AŪ���^��
    if(response==0x00)break;   //�Y�^��response=0x00�ASD�d�Ƨ�
    if(response==0x01)break;   //�Y�^��response=0x01�ASD�d���Ƨ�
    i++;  //�p�ƭȻ��[
  }
  return response; //�^�kresponse
}
//--------------- Ū��SD�O�Хd�^��-----------------------------
unsigned char SDGetXXResponse(const unsigned char resp)
{
  //Response comes 1-8 bytes after command
  //the first bit will be a 0
  //followed by an error code
  //data will be 0xff until response
  unsigned int i=0;
  unsigned char response;

  while(i<=1000)	//����1000��
  {
    response=spiSendByte(0xff);	 //��SPI�]�wSD�O�Хd�R�O
    if(response==resp)break;
    i++;
  }
  return response;
}
//--------------- �ˬdSD�O�Хd���L----------------------------
char SDCheckBusy(void)
{
  //Response comes 1-8 bytes after command
  //the first bit will be a 0
  //followed by an error code
  //data will be 0xff until response
  char i=0;

  char response;
  char rvalue;
  while(i<=64)
  {
    response=spiSendByte(0xff);	//��SPI�]�wSD�O�Хd�R�O
    response &= 0x1f;
    switch(response)
    {
      case 0x05: rvalue=SD_SUCCESS;break;
      case 0x0b: return(SD_CRC_ERROR);
      case 0x0d: return(SD_WRITE_ERROR);
      default:
        rvalue = SD_OTHER_ERROR;
        break;
    }
    if(rvalue==SD_SUCCESS)break;
    i++;
  }
  i=0;
  do
  {
    response=spiSendByte(0xff);	//��SPI�]�wSD�O�Хd�R�O
    i++;
  }while(response==0);
  return response; //�^�kresponse
}
//--------------- Ū��SD�O�Хd�϶����e-----------------------------
char SDReadBlock(const unsigned int sector, unsigned char *pBuffer)
{
    unsigned int i = 0;
    char rvalue = SD_RESPONSE_ERROR;
    unsigned long address = (unsigned long)sector * 512;
  // Set the block length to read
   if (SDSetBlockLength (512) == SD_SUCCESS) //�]�wSD�O�Хd�϶����סA�æ^������
    {
      CS = 0;	//�}��SPI�������
    // send read command SD_READ_SINGLE_BLOCK=CMD17
      SDSendCmd (SD_READ_SINGLE_BLOCK,address, 0xFF);
    // Send 8 Clock pulses of delay, check if the SD acknowledged the read block command
    // it will do this by sending an affirmative response
    // in the R1 format (0x00 is no errors)
      if (SDGetResponse() == 0x00) //SD�d�^���L���~
      {
      // now look for the data token to signify the start of
      // the data
       if (SDGetXXResponse(SD_START_DATA_BLOCK_TOKEN) == SD_START_DATA_BLOCK_TOKEN) //�}�l��@�϶�Ū��
        {
           // clock the actual data transfer and receive the bytes; spi_read automatically finds the Data Block
          for (i = 0; i < 512; i++)  pBuffer[i] = spiSendByte(0xff);  //Ū��512-byte�s�J�w�ľ�
        
		  // get CRC bytes (not really needed by us, but required by SD)
           spiSendByte(0xff);	//��SPI�]�wSD�O�Хd�R�O
           spiSendByte(0xff);	//��SPI�]�wSD�O�Хd�R�O
           rvalue = SD_SUCCESS; //�^�kŪ�����\
		
		 }
      else  rvalue = SD_DATA_TOKEN_ERROR;  // 3 �^�kŪ�����~the data token was never received
    } 
    else rvalue = SD_RESPONSE_ERROR;  // 2	�^�kSD�d�^�����~the SD never acknowledge the read command
  }
  else	  rvalue = SD_BLOCK_SET_ERROR;  // 1 �^�k�]�wSD�O�Хd�϶����׿��~
  CS=1;	//����SPI�������
  spiSendByte(0xff);  //��SPI�]�wSD�O�Хd�R�O
  return rvalue;
}// SD_read_block

//--------------- �g�JSD�O�Хd�϶�-----------------------------
char SDWriteBlock (const unsigned int sector,unsigned char *pBuffer)
{
  unsigned int i = 0;
  char rvalue = SD_RESPONSE_ERROR;         // SD_SUCCESS;
  unsigned long address = (unsigned long)sector * 512;

  // Set the block length to read
  if (SDSetBlockLength (512) == SD_SUCCESS)   //�]�wSD�O�Хd�϶����סA�æ^������
  {
    CS = 0;	//�}��SPI�������
    // send write command
    SDSendCmd (SD_WRITE_BLOCK,address, 0xFF); //�U�R�O�g�J��@�϶�

    // check if the SD acknowledged the write block command
    // it will do this by sending an affirmative response
    // in the R1 format (0x00 is no errors)
    if (SDGetXXResponse(SD_R1_RESPONSE) == SD_R1_RESPONSE) //�}�l��@�϶��g�J
    {
      spiSendByte(0xff); //��SPI�]�wSD�O�Хd�R�O
      // send the data token to signify the start of the data
      spiSendByte(0xfe);  //��SPI�]�wSD�O�Хd�R�O
      // clock the actual data transfer and transmitt the bytes
      for (i = 0; i < 512; i++)
        spiSendByte(pBuffer[i]);            
      // put CRC bytes (not really needed by us, but required by SD)
      spiSendByte(0xff); //��SPI�]�wSD�O�Хd�R�O
      spiSendByte(0xff); //��SPI�]�wSD�O�Хd�R�O
      // read the data response xxx0<status>1 : status 010: Data accected, status 101: Data
      //   rejected due to a crc error, status 110: Data rejected due to a Write error.
      SDCheckBusy();
      rvalue = SD_SUCCESS;
    }
    else
    {
      // the SD never acknowledge the write command
      rvalue = SD_RESPONSE_ERROR;   // 2
    }
  }
  else
  {
    rvalue = SD_BLOCK_SET_ERROR;   // 1
  }
  // give the SD the required clocks to finish up what ever it needs to do
  //  for (i = 0; i < 9; ++i)
  //    spiSendByte(0xff);	 //��SPI�]�wSD�O�Хd�R�O

  CS=1;	//����SPI�������
  
  spiSendByte(0xff); //��SPI�]�wSD�O�Хd�R�OSend 8 Clock pulses of delay.
  return rvalue;
} // SD_write_block
