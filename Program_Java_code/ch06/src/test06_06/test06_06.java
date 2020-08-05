package test06_06;

import java.util.Scanner;

public class test06_06 {

	public static void main(String[] args) {
		final int pwd = 70;// 密碼數字
		int num;// 儲存所猜的數字
		char X;
		Scanner scanner = new Scanner(System.in);

		while (true) { // 無限迴圈
			System.out.print("請猜0-99的數字");
			num = scanner.nextInt(); // 讀取輸入數字
			if (num == pwd) {
				System.out.println("恭喜猜對");
				break;
			}
			if (num > pwd) {
				System.out.println("猜錯了請輸入小一些");
			}
			if (num < pwd) {
				System.out.println("猜錯了請輸入大一些");
			}

			System.out.println("如要離開 請輸入Q或q");
			Scanner scanner2 = new Scanner(System.in);
			X = scanner2.next().charAt(0);
			if ((X == 'Q') || (X == 'q')) {
				System.out.println("GG");
				break;
			}

		}

	}

}
