package test06_06;

import java.util.Scanner;

public class test06_06 {

	public static void main(String[] args) {
		final int pwd = 70;// �K�X�Ʀr
		int num;// �x�s�Ҳq���Ʀr
		char X;
		Scanner scanner = new Scanner(System.in);

		while (true) { // �L���j��
			System.out.print("�вq0-99���Ʀr");
			num = scanner.nextInt(); // Ū����J�Ʀr
			if (num == pwd) {
				System.out.println("���߲q��");
				break;
			}
			if (num > pwd) {
				System.out.println("�q���F�п�J�p�@��");
			}
			if (num < pwd) {
				System.out.println("�q���F�п�J�j�@��");
			}

			System.out.println("�p�n���} �п�JQ��q");
			Scanner scanner2 = new Scanner(System.in);
			X = scanner2.next().charAt(0);
			if ((X == 'Q') || (X == 'q')) {
				System.out.println("GG");
				break;
			}

		}

	}

}
