package ch05_06_����B��l;

import java.util.Scanner;

public class ch05_06 {

	public static void main(String[] args) {
		
		
		int x;
		Scanner scanner2 = new Scanner(System.in);
		System.out.print("�п�J���N��� : ");
		x = scanner2.nextInt();		// Ū���ù���J
//		if (x > 0) 
//			System.out.println("����ȬO" + x);
//		else
//			System.out.println("����ȬO" + -x);
		
		x=(x>=0)? x:-x;
		System.out.println("����ȬO:" + x );
				
		

	}

}
