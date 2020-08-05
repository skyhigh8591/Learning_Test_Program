package ch06_08_break敘述;

import java.util.Scanner;

public class ch06_08 {

	public static void main(String[] args) {

//		final int pwd = 70;

		final int pwd = (int) (Math.random() * 99);
		System.out.println(pwd);
		int num;
		Scanner scanner = new Scanner(System.in);

		while (true) {

			System.out.print("請猜0-99的數字");
			num = scanner.nextInt();
			if (num == pwd) {
				System.out.print("恭喜猜中");
				break;
			} else {
				System.out.print("猜錯了 請在猜一次");
			}

		}

	}
}
