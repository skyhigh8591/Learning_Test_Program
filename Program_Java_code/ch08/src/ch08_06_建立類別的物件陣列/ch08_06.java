package ch08_06_�إ����O������}�C;


class TaipeiBank
{
	int account;
	int balance;
	void printinfo() {
		System.out.printf("�b��:%d , �l�B:%d\n",account,balance);
	}
}




public class ch08_06 {

	public static void main(String[] args) {
		TaipeiBank[] shilin = new TaipeiBank[5];
		
//		shilin[0] = new TaipeiBank();
//		shilin[0].account=1;
//		shilin[0].balance=100;
//		shilin[0].printinfo();
//		
//		shilin[1] = new TaipeiBank();
//		shilin[1].account=1;
//		shilin[1].balance=100;
//		shilin[1].printinfo();
		
		for(int i=0 ; i<shilin.length ; i++)
		{
			shilin[i] = new TaipeiBank();
			shilin[i].account=100001+i;
			shilin[i].balance=100;
		}
		
		//show data
		for(int i=0 ; i<shilin.length ; i++)
		{
			shilin[i].printinfo();
		}
		
		
		System.out.println("*************************************");
		
		//show data
		for(TaipeiBank sh:shilin)
		{
			sh.printinfo();
		}

	}

}
