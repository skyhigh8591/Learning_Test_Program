package ch05_02_if_else敘述;

import java.util.Scanner;

public class ch05_02 {

	public static void main(String[] args) {
		int age;
		Scanner scanner1 = new Scanner(System.in);

		System.out.print("you age : ");
		age = scanner1.nextInt(); // 讀取年齡資料
		
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
		System.out.print("請輸入任意整數 : ");
		x = scanner2.nextInt();		// 讀取螢幕輸入
		if (x > 0) 
			System.out.println("絕對值是" + x);
		else
			System.out.println("絕對值是" + -x);
		
	}

}
