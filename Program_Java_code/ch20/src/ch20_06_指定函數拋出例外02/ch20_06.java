package ch20_06_���w��ƩߥX�ҥ~02;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ch20_06 {

	public static void main(String[] args) {
		try {
		myMethod();
		}catch(ArithmeticException e) {
			System.out.println("���Ƭ�0 " + e );
		}catch(InputMismatchException e) {
			System.out.println("��ƫ��A���~" +e);
		}
				
	}
	
	public static void myMethod() {
		
		Scanner s = new Scanner(System.in);
		System.out.println("�п�J��Ӿ��(�Ʀr���Ϊťչj�}) " );
		int x1,x2;
		x1=s.nextInt();
		x2=s.nextInt();
		
		System.out.println("result is:" + (x1/x2));
		
	}

}
