package ch05_01_if敘述;

import java.util.Scanner;

public class ch05_01 {

	public static void main(String[] args) {
		int age;
		Scanner scanner = new Scanner(System.in);

		System.out.print("you age : ");
		age = scanner.nextInt(); // 讀取年齡資料
		
		if (age < 20) {
			System.out.println("Your age is too small");
		}
	
		//一行可省略大括號
		if (age < 20)
			System.out.println("Your age is too small");
		
		//一行可放在右邊
		if (age < 20) System.out.println("Your age is too small");
	}

}
