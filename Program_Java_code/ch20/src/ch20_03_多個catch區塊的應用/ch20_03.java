package ch20_03_�h��catch�϶�������;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ch20_03 {

	public static void main(String[] args) {
		int x1,x2;
		Scanner s = new Scanner(System.in);
		System.out.println("�п�J��Ӿ��(�Ʀr���Ϊťչj�}) " );
		try {
			x1=s.nextInt();
			x2=s.nextInt();
			
//			if((double)x1/x2== Double.POSITIVE_INFINITY) {
//				throw new ArithmeticException();
//			}
//			System.out.println("result is:" + (double)(x1/x2));
			System.out.println("result is:" + (x1/x2));
			
		}catch(ArithmeticException e) {
			System.out.println("���Ƭ�0: " +e );
		}catch(InputMismatchException e) {
			System.out.println("����������~ : " +e);
		}
		System.out.println("end.........");
	}

}
