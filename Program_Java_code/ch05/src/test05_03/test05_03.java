package test05_03;

import java.util.Scanner;

public class test05_03 {

	public static void main(String[] args) {
		int score;
		Scanner scanner1 = new Scanner(System.in);

		System.out.print("¿é¤J¤À¼Æ");
		score = scanner1.nextInt();
		
		String x ;
		x = (score >= 90)? "level A": (score >= 80)? "level B": (score >= 70)? "level C":
			 (score >= 60)? "level D":"level E";
		System.out.println(x);	
			
			
			
		
	}

}
