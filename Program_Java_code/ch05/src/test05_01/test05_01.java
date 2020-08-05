package test05_01;

import java.util.Scanner;

public class test05_01 {

	public static void main(String[] args) {

		int score;
		Scanner scanner1 = new Scanner(System.in);

		System.out.print("輸入分數");
		score = scanner1.nextInt();
		if (score > 100) {
			System.out.print("超出範圍");
		} else if (score < 0) {
			System.out.print("超出範圍");
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
