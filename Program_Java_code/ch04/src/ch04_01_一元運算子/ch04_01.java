package ch04_01_一元運算子;

public class ch04_01 {

	public static void main(String[] args) {
		int x1,y1,z1;
		x1=y1=z1=100;
		System.out.println("x1=" + x1);
		System.out.println("y1=" + y1);
		System.out.println("z1=" + z1);
		
		int x2 =25, y2=3, z2;
		double f2;
		z2 = x2 + y2;
		System.out.println("加法結果z2 = " + z2);	
		z2 = x2 - y2;
		System.out.println("減法結果z2 = " + z2);	
		z2 = x2 * y2;
		System.out.println("乘法結果z2 = " + z2);	
		z2 = x2 / y2;
		System.out.println("除法結果z2 = " + z2);
		
		f2 = x2 / y2;
		System.out.println("整數除法結果f2 = " + f2);	
		f2 = 25 / 3;
		System.out.println("整數除法結果f2 = " + f2);	
		f2 = 25.0 / 3.0;
		System.out.println("浮點數除法結果f2 = " + f2);		
		System.out.printf("格式化浮點數除法結果f2 = %5.2f\n", f2);
		
		
		
	}

}
