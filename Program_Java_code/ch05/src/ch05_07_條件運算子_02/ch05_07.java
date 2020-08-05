package ch05_07_條件運算子_02;

import java.util.Scanner;

public class ch05_07 {

	public static void main(String[] args) {
		int score;
		Scanner scanner1 = new Scanner(System.in);

		System.out.print("輸入分數");
		score = scanner1.nextInt();

//		if (score >= 90)
//			System.out.println("level A");
//		else if (score >= 80)
//			System.out.println("level B");
//		else if (score >= 70)
//			System.out.println("level C");
//		else if (score >= 60)
//			System.out.println("level D");
//		else
//			System.out.println("level E");	
		String result;
		result = (score>=90)? "level A" : (score>=80)? "level B" : (score>=70)? "level C" :
				 (score>=60)? "level D" : "level E";
		
		
		System.out.println(result);
		
		
		
		
		
		
		
		
		
		
		
		
		
		

	}

}
