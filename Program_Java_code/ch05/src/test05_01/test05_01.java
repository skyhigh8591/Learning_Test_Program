package test05_01;

import java.util.Scanner;

public class test05_01 {

	public static void main(String[] args) {

		int score;
		Scanner scanner1 = new Scanner(System.in);

		System.out.print("��J����");
		score = scanner1.nextInt();
		if (score > 100) {
			System.out.print("�W�X�d��");
		} else if (score < 0) {
			System.out.print("�W�X�d��");
		} else {
			switch (score / 10) {
			case 9:
				System.out.print("level A");
			case 8:
				System.out.print("level B");
			case 7:
				System.out.print("level C");
			case 6:
				System.out.print("level D");
			default:
				System.out.print("level E");
			}
		}

	}

}
