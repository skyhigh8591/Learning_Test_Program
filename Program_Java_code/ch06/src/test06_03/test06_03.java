package test06_03;

import java.util.Scanner;

public class test06_03 {

	public static void main(String[] args) {

		int score, x;
		Scanner scanner1 = new Scanner(System.in);

		System.out.print("��J�����");
		score = scanner1.nextInt();

		for (x = 2; x < score; x++) {
			if (score % x == 0) {
				System.out.println(score + "���O���");
				break;
			}
		}
		if (x >= score) {
			System.out.println(score + "�O���");

		}

	}
}
