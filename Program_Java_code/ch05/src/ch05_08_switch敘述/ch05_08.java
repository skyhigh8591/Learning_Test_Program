package ch05_08_switch±Ô­z;

import java.util.Scanner;

public class ch05_08 {

	public static void main(String[] args) {
		
			int score;
			Scanner scanner1 = new Scanner(System.in);

			System.out.print("¿é¤J¤À¼Æ");
			score = scanner1.nextInt();

			switch (score/10) {
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


