package ch08_08_�I�s���P�������غc�l;

class TaipeiBank {
	int accuont;
	int balance;
	public int account;

	void saveMoney(int balance) {
		// balance += balance;
		this.balance += balance;
	}

	void printInfo() {
		System.out.printf("�b��:%d , �l�B:%d\n", account, balance);
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
