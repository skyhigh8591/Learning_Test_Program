package test08_3_01;


import java.util.Scanner;



class Trapezoid{
	
	public double TW;
	public double DW;
	public double T;
	
	public double Area() {	
		
		return ((TW+DW)*T)/2;	
		
	}	
}



public class test08_3_01 {

	public static void main(String[] args) {
		double num1;
		double num2;
		double num3;
		
		
		System.out.println("請輸入上底");
		Scanner scanner = new Scanner(System.in);
		num1 = scanner.nextInt();
		System.out.println("請輸入下底");
		Scanner scanner2 = new Scanner(System.in);
		num2 = scanner2.nextInt();
		System.out.println("請輸入高");
		Scanner scanner3 = new Scanner(System.in);
		num3 = scanner3.nextInt();
						
		System.out.println("上底為" + num1 + "下底為" + num2 + "高為" + num3);
		Trapezoid C = new Trapezoid();
		C.TW = num1;
		C.DW = num2;
		C.T = num3;
		
		double Trapezoid_Area = C.Area();
		System.out.println("area = " + Double.toString(Trapezoid_Area));
		
		
		// Double.toString(C.Area()) 數字轉字串 呼叫 程式
		
		
	}
}

