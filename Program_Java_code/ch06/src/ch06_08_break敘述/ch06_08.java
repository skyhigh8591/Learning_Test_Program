package ch06_08_break�ԭz;

import java.util.Scanner;

public class ch06_08 {

	public static void main(String[] args) {

//		final int pwd = 70;

		final int pwd = (int) (Math.random() * 99);
		System.out.println(pwd);
		int num;
		Scanner scanner = new Scanner(System.in);

		while (true) {

			System.out.print("�вq0-99���Ʀr");
			num = scanner.nextInt();
			if (num == pwd) {
				System.out.print("���߲q��");
				break;
			} else {
				System.out.print("�q���F �Цb�q�@��");
			}

		}

	}
}
