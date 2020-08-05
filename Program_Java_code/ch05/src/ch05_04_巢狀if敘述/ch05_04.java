package ch05_04_±_ª¬if±Ô­z;

import java.util.Scanner;

public class ch05_04 {

	public static void main(String[] args) {
		int score;
		Scanner scanner1 = new Scanner(System.in);

		System.out.print("¿é¤J¤À¼Æ");
		score = scanner1.nextInt();

		if (score >= 90)
			System.out.println("level A");
		else if (score >= 80)
			System.out.println("level B");
		else if (score >= 70)
			System.out.println("level C");
		else if (score >= 60)
			System.out.println("level D");
		else
			System.out.println("level E");		
	}

}
