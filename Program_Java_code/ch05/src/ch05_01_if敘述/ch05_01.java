package ch05_01_if�ԭz;

import java.util.Scanner;

public class ch05_01 {

	public static void main(String[] args) {
		int age;
		Scanner scanner = new Scanner(System.in);

		System.out.print("you age : ");
		age = scanner.nextInt(); // Ū���~�ָ��
		
		if (age < 20) {
			System.out.println("Your age is too small");
		}
	
		//�@��i�ٲ��j�A��
		if (age < 20)
			System.out.println("Your age is too small");
		
		//�@��i��b�k��
		if (age < 20) System.out.println("Your age is too small");
	}

}
