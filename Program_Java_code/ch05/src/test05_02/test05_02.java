package test05_02;

import java.util.Scanner;

public class test05_02 {

	public static void main(String[] args) {
		double price;
		int age;
		int ticket = 100;
		Scanner scanner = new Scanner(System.in);
		System.out.print("enter your age : ");
		age = scanner.nextInt();
		if (age > 100) {
			System.out.print("¶W¥X½d³ò");
		} else if (age < 0) {
			System.out.print("¶W¥X½d³ò");
		} else {

			if (age >= 80 || age <= 6) {
				price = ticket * 0.2;
				System.out.print("ticket price is: " + price);
			} else if (age >= 60 || age <= 12) {
				price = ticket * 0.5;
				System.out.print("ticket price is: " + price);
			} else {
				price = ticket;
				System.out.print("ticket price is: " + price);
			}

		}

	}

}
