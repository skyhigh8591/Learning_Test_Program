package ch05_02_if_else�ԭz;

import java.util.Scanner;

public class ch05_02 {

	public static void main(String[] args) {
		int age;
		Scanner scanner1 = new Scanner(System.in);

		System.out.print("you age : ");
		age = scanner1.nextInt(); // Ū���~�ָ��
		
		if (age < 20) {
			System.out.println("Your age is too small");
		}else {
			System.out.println("Welcome!");
		}
		
		if (age < 20)
			System.out.println("Your age is too small");
		else
			System.out.println("Welcome!");
		
		////////////////////////////////////////////////
		int x;
		Scanner scanner2 = new Scanner(System.in);
		System.out.print("�п�J���N��� : ");
		x = scanner2.nextInt();		// Ū���ù���J
		if (x > 0) 
			System.out.println("����ȬO" + x);
		else
			System.out.println("����ȬO" + -x);
		
	}

}
