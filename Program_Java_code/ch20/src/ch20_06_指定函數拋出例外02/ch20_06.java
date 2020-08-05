package ch20_06_指定函數拋出例外02;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ch20_06 {

	public static void main(String[] args) {
		try {
		myMethod();
		}catch(ArithmeticException e) {
			System.out.println("除數為0 " + e );
		}catch(InputMismatchException e) {
			System.out.println("資料型態錯誤" +e);
		}
				
	}
	
	public static void myMethod() {
		
		Scanner s = new Scanner(System.in);
		System.out.println("請輸入兩個整數(數字間用空白隔開) " );
		int x1,x2;
		x1=s.nextInt();
		x2=s.nextInt();
		
		System.out.println("result is:" + (x1/x2));
		
	}

}
