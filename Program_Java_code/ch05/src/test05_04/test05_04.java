package test05_04;

import java.util.Scanner;

public class test05_04 {

	public static void main(String[] args) {
		int i;
		Scanner scanner1 = new Scanner(System.in);

		System.out.print("块だ计");
		i = scanner1.nextInt();
		
		if(i%2==0) {
			System.out.print("案计");
		}
		else {
			System.out.print("计");
		}

		
		switch (i%2) {
		case 1:
			System.out.print("计");
			break;
		default:
			System.out.print("案计");
		
		
		
		
		}
		
		
		
		
		
		
		
		
	}

}



