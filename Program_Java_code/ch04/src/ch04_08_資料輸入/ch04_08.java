package ch04_08_¸ê®Æ¿é¤J;

import java.util.Scanner;

public class ch04_08 {

	public static void main(String[] args) {

		int x1, x2;
		Scanner scanner1 = new Scanner(System.in);
		x1 = scanner1.nextInt();
		x2 = scanner1.nextInt();

		System.out.println("the number one is :" + x1);
		System.out.println("the number one is :" + x2);

		String name;
		Scanner scanner2 = new Scanner(System.in);
		System.out.println("Enter your name:");
		name = scanner2.next();
		System.out.printf("Hi %s , how do you do! \n",name);
		
		double d1, d2;
		Scanner scanner3 = new Scanner(System.in);
		d1 = scanner3.nextDouble();
		d2 = scanner3.nextDouble();
		System.out.println("the number one is :" + d1);
		System.out.println("the number one is :" + d2);
		
	}

}
