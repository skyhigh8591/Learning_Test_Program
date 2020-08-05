package ch20_03_多個catch區塊的應用;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ch20_03 {

	public static void main(String[] args) {
		int x1,x2;
		Scanner s = new Scanner(System.in);
		System.out.println("請輸入兩個整數(數字間用空白隔開) " );
		try {
			x1=s.nextInt();
			x2=s.nextInt();
			
//			if((double)x1/x2== Double.POSITIVE_INFINITY) {
//				throw new ArithmeticException();
//			}
//			System.out.println("result is:" + (double)(x1/x2));
			System.out.println("result is:" + (x1/x2));
			
		}catch(ArithmeticException e) {
			System.out.println("除數為0: " +e );
		}catch(InputMismatchException e) {
			System.out.println("資料類型錯誤 : " +e);
		}
		System.out.println("end.........");
	}

}
