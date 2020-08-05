package ch04_07_自動轉型_強制轉型;

public class ch04_07 {

	public static void main(String[] args) {
		//自動轉型
		System.out.println(".....1.....");
		int x1;
		byte b1 = 10;
		float f1;
		x1= b1;//byte to int
		System.out.println("x1=" + x1);
		
		f1=b1;//byte to float
		System.out.println("f1=" + f1);
		
		char ch1 = 'A';
		x1 = ch1;
		System.out.println("x1=" + x1);
		
		//強迫
		System.out.println("......2......");
		f1=20;
		//x1=f1; //float to int
		x1 = (int) f1 ;// float to int
		
		by=1 = (byte)x1;
		System.out.println("b1" + b1);
		
		//運算
		short s1 = 1;
		short s2 = 2;
		short s3 = (short)(s1+s2);//運算時轉成int
		System.out.println("s3" + s3);
		
		
		int x2 = 25;
		int x3 =9;
		System.out.println("x2/x2=" + x2/x3);
		
		System.out.println("x2/x3" + x2/(float)x3);

		System.out.println("x2/x3" + x2/(double)x3);

		
	}

}
