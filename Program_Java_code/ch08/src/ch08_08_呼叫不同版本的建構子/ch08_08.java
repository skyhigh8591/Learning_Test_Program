package ch08_08_呼叫不同版本的建構子;

class TaipeiBank {
	int accuont;
	int balance;
	public int account;

	void saveMoney(int balance) {
		// balance += balance;
		this.balance += balance;
	}

	void printInfo() {
		System.out.printf("帳戶:%d , 餘額:%d\n", account, balance);
	}
}

public class ch08_08 {

	public static void main(String[] args) {
		TaipeiBank A = new TaipeiBank();

		A.account = 100001;
		A.balance = 0;
		A.printInfo();
		A.saveMoney(1000);
		A.printInfo();

	}

}
