package ch05_06_條件運算子;

import java.util.Scanner;

public class ch05_06 {

	public static void main(String[] args) {
		
		
		int x;
		Scanner scanner2 = new Scanner(System.in);
		System.out.print("請輸入任意整數 : ");
		x = scanner2.nextInt();		// 讀取螢幕輸入
//		if (x > 0) 
//			System.out.println("絕對值是" + x);
//		else
//			System.out.println("絕對值是" + -x);
		
		x=(x>=0)? x:-x;
		System.out.println("絕對值是:" + x );
				
		

	}

}
