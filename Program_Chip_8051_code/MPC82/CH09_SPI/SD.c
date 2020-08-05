//********SD.C********SD記憶卡函數式*************
#include "MPC82.H"
#include "SD.H"
#include "SD_define.h"

char SDGetResponse(void);	 //讀取SD記憶卡回應
unsigned char SDGetXXResponse(const char resp);	//讀取SD記憶卡回應
char SDCheckBusy(void);	 //檢查SD記憶卡忙碌
unsigned char spiSendByte(const unsigned char dat);	 //由SPI設定SD記憶卡命令

//---------寫入SD記憶卡命令----------------------------------------------
void SDSendCmd (const char cmd, unsigned long dat, const char crc)
{
  char frame[6];//SD記憶卡命令為6-byte(48-bit)
  char temp;
  char i;
  frame[0]=(cmd|0x40); //設定命令的bit6=1(host命令)並存入frame[0]

  for(i=3;i>=0;i--)	 //將4-byte的資料分別存入frame[1-4]
   {
    temp=(char)(dat>>(8*i));//將資料的bit31~24存入frame[1]
    frame[4-i]=(temp);		//將資料的bit7~0存入frame[4]
   }
  frame[5]=(crc); //將檢核碼存入frame[5]
  for(i=0;i<6;i++) spiSendByte(frame[i]); //由SPI界面將frame[0-5]寫入SD記憶卡
}
//--------------- 設定SD記憶卡區塊長度= 2^n -----------------------------
char SDSetBlockLength (const unsigned long blocklength)
{
  CS = 0;  //開啟SPI晶片選擇
  // Set the block length to read
  SDSendCmd(SD_SET_BLOCKLEN, blocklength, 0xFF); //設定SD記憶卡區塊長度

  // get response from SD - make sure that its 0x00 (R1 ok response format)
  if(SDGetResponse()!=0x00)	  //讀取SD記憶卡回應，若未完成(回應不等於0)，再做一次
  { 
    initSD();	 //初始化SD記憶卡
    SDSendCmd(SD_SET_BLOCKLEN, blocklength, 0xFF);//設定SD記憶卡區塊長度
    SDGetResponse();  //讀取SD記憶卡回應
  }

  CS=1;	//若已完成(回應0)關閉SPI晶片選擇
  spiSendByte(0xff); //由SPI設定SD記憶卡為 8 Clock pulses of delay.

  return SD_SUCCESS; //回應完成
} // Set block_length

//--------------- SPI發射1-byte資料-----------------------------
unsigned char spiSendByte(const unsigned char dat)
{
	SPDAT = dat;            //SPI發射1-byte資料
	while(SPSTAT != SPIF);	//若中斷旗標SPIF=0未傳輸完畢，等待之
	SPSTAT = SPIF;	        //若SPIF=1已傳輸完畢，須清除SPIF=0
	return SPDAT;           //將SPI資料回傳
}
//--------------- SD記憶卡進入SPI模式 -----------------------------
char SD_GoIdle()
{
  char response=0x01;
  CS = 0;  //開啟SPI晶片選擇
  
  SDSendCmd(SD_GO_IDLE_STATE,0,0x95);//送出命令CMD0，SD卡進SPI模式
  
  if(SDGetResponse()!=0x01)//等待SD卡備妥回應
    return SD_INIT_ERROR; //response不等於0x01，則回應錯誤

  while(response==0x01)	 //若SD卡回應未備妥
  {
    CS = 1; //關閉SPI晶片選擇
    spiSendByte(0xff); //由SPI設定SD記憶卡命令
    CS = 0;	//開啟SPI晶片選擇
    SDSendCmd(SD_SEND_OP_COND,0x00,0xff); //送出CMD1設定操作電壓
    response=SDGetResponse();
  }
  CS=1;	 //關閉SPI晶片選擇
  spiSendByte(0xff);//由SPI設定SD記憶卡命令
  return (SD_SUCCESS);
}
//--------------- 初始化SD記憶卡-----------------------------
char initSD (void)
{
  //raise SS and MOSI for 80 clock cycles
  //SendByte(0xff) 10 times with SS high
  //raise SS
  char i;

  SPCTL = SSIG+SPEN+MSTR; //致能SPI為Master，bit7先傳輸,忽略SS腳晶片選擇
 
  //  initSPI();
  IFADRL = 0x01;	       //ISP/IAP的flash低位址
  if((SCMD & 0xf0)!=0xf0)  //ISP/IAP順序命令
    return SD_INIT_ERROR;

  //initialization sequence on PowerUp
  CS=1;	//關閉SPI晶片選擇
  for(i=0;i<=9;i++) spiSendByte(0xff); //由SPI設定SD記憶卡開機順序動作
  return (SD_GoIdle());  //進入SPI模式，並回歸response
}
//--------------- 讀取SD記憶卡回應-----------------------------
// SD Get Responce
char SDGetResponse(void)
{
  //Response comes 1-8 bytes after command
  //the first bit will be a 0
  //followed by an error code
  //data will be 0xff until response
  char i=0;	   //計數值
  char response;//回應值

  while(i<=64)	//重覆讀取64次SD記憶卡的回應
  {
    response=spiSendByte(0xff);//由SPI設定SD記憶卡命令，讀取回應
    if(response==0x00)break;   //若回應response=0x00，SD卡備妥
    if(response==0x01)break;   //若回應response=0x01，SD卡未備妥
    i++;  //計數值遞加
  }
  return response; //回歸response
}
//--------------- 讀取SD記憶卡回應-----------------------------
unsigned char SDGetXXResponse(const unsigned char resp)
{
  //Response comes 1-8 bytes after command
  //the first bit will be a 0
  //followed by an error code
  //data will be 0xff until response
  unsigned int i=0;
  unsigned char response;

  while(i<=1000)	//重覆1000次
  {
    response=spiSendByte(0xff);	 //由SPI設定SD記憶卡命令
    if(response==resp)break;
    i++;
  }
  return response;
}
//--------------- 檢查SD記憶卡忙碌----------------------------
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
    response=spiSendByte(0xff);	//由SPI設定SD記憶卡命令
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
    response=spiSendByte(0xff);	//由SPI設定SD記憶卡命令
    i++;
  }while(response==0);
  return response; //回歸response
}
//--------------- 讀取SD記憶卡區塊內容-----------------------------
char SDReadBlock(const unsigned int sector, unsigned char *pBuffer)
{
    unsigned int i = 0;
    char rvalue = SD_RESPONSE_ERROR;
    unsigned long address = (unsigned long)sector * 512;
  // Set the block length to read
   if (SDSetBlockLength (512) == SD_SUCCESS) //設定SD記憶卡區塊長度，並回應完成
    {
      CS = 0;	//開啟SPI晶片選擇
    // send read command SD_READ_SINGLE_BLOCK=CMD17
      SDSendCmd (SD_READ_SINGLE_BLOCK,address, 0xFF);
    // Send 8 Clock pulses of delay, check if the SD acknowledged the read block command
    // it will do this by sending an affirmative response
    // in the R1 format (0x00 is no errors)
      if (SDGetResponse() == 0x00) //SD卡回應無錯誤
      {
      // now look for the data token to signify the start of
      // the data
       if (SDGetXXResponse(SD_START_DATA_BLOCK_TOKEN) == SD_START_DATA_BLOCK_TOKEN) //開始單一區塊讀取
        {
           // clock the actual data transfer and receive the bytes; spi_read automatically finds the Data Block
          for (i = 0; i < 512; i++)  pBuffer[i] = spiSendByte(0xff);  //讀取512-byte存入緩衝器
        
		  // get CRC bytes (not really needed by us, but required by SD)
           spiSendByte(0xff);	//由SPI設定SD記憶卡命令
           spiSendByte(0xff);	//由SPI設定SD記憶卡命令
           rvalue = SD_SUCCESS; //回歸讀取成功
		
		 }
      else  rvalue = SD_DATA_TOKEN_ERROR;  // 3 回歸讀取錯誤the data token was never received
    } 
    else rvalue = SD_RESPONSE_ERROR;  // 2	回歸SD卡回應錯誤the SD never acknowledge the read command
  }
  else	  rvalue = SD_BLOCK_SET_ERROR;  // 1 回歸設定SD記憶卡區塊長度錯誤
  CS=1;	//關閉SPI晶片選擇
  spiSendByte(0xff);  //由SPI設定SD記憶卡命令
  return rvalue;
}// SD_read_block

//--------------- 寫入SD記憶卡區塊-----------------------------
char SDWriteBlock (const unsigned int sector,unsigned char *pBuffer)
{
  unsigned int i = 0;
  char rvalue = SD_RESPONSE_ERROR;         // SD_SUCCESS;
  unsigned long address = (unsigned long)sector * 512;

  // Set the block length to read
  if (SDSetBlockLength (512) == SD_SUCCESS)   //設定SD記憶卡區塊長度，並回應完成
  {
    CS = 0;	//開啟SPI晶片選擇
    // send write command
    SDSendCmd (SD_WRITE_BLOCK,address, 0xFF); //下命令寫入單一區塊

    // check if the SD acknowledged the write block command
    // it will do this by sending an affirmative response
    // in the R1 format (0x00 is no errors)
    if (SDGetXXResponse(SD_R1_RESPONSE) == SD_R1_RESPONSE) //開始單一區塊寫入
    {
      spiSendByte(0xff); //由SPI設定SD記憶卡命令
      // send the data token to signify the start of the data
      spiSendByte(0xfe);  //由SPI設定SD記憶卡命令
      // clock the actual data transfer and transmitt the bytes
      for (i = 0; i < 512; i++)
        spiSendByte(pBuffer[i]);            
      // put CRC bytes (not really needed by us, but required by SD)
      spiSendByte(0xff); //由SPI設定SD記憶卡命令
      spiSendByte(0xff); //由SPI設定SD記憶卡命令
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
  //    spiSendByte(0xff);	 //由SPI設定SD記憶卡命令

  CS=1;	//關閉SPI晶片選擇
  
  spiSendByte(0xff); //由SPI設定SD記憶卡命令Send 8 Clock pulses of delay.
  return rvalue;
} // SD_write_block
