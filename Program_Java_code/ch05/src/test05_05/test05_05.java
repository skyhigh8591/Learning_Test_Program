package test05_05;

import java.util.Scanner;

public class test05_05 {

	private static final String Happy = null;

	public static void main(String[] args) {
		int i;
		String x;
		Scanner scanner1 = new Scanner(System.in);
		System.out.print("��J�b��");
		x = scanner1.nextLine();
		
		
		Scanner scanner2 = new Scanner(System.in);
		System.out.print("��J�K�X");
		i = scanner2.nextInt();
		
		
		
		
		
		if(x != Happy) {
			System.out.print("��J���~");
		}
		else if(i != 1122) {
			System.out.print("��J���~");
		}
		else {
			System.out.print("���T");
		}

	}

}
