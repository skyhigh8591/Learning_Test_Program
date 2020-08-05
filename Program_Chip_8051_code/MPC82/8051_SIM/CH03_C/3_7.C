/*********** 3_7.c *************************
*笆盢璸计糶皚跑计ず
*********************************************/ 
unsigned char TABLE[120]=0;//睲埃ず场RAM皚ず甧
//unsigned char idata TABLE[240]=0;//睲埃ず场丁钡RAM皚ず甧
//unsigned char xdata TABLE[1024]=0;//睲埃耎RAM皚ず甧

main()
{
  unsigned char i=0;  //8-bit璸计跑计
 loop:
  TABLE[i]=i; //璸计糶皚跑计
  i=i+1;	  //璸计患
 goto loop;
}