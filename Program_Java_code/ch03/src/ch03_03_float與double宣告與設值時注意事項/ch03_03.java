package ch03_03_float籔double籔砞猔種ㄆ兜;

public class ch03_03 {

	public static void main(String[] args) {
		System.out.println(".......int and long......");
		int x1;
		long y1;
		x1 = 103; // 砞﹚10秈俱计
		System.out.println("103   = " + x1);
		x1 = 0b111; // 砞﹚2秈俱计
		System.out.println("0b111 = " + x1);
		y1 = 022; // 砞﹚8秈俱计
		System.out.println("022   =  " + y1);
		y1 = 0x2B; // 砞﹚16秈俱计
		System.out.println("0x2B  =  " + y1);

		long x2;
		x2 = 10345678L; // 砞﹚10秈俱计
		System.out.println("10345678  = " + x2);
		x2 = 1_000_200; // 砞﹚┏絬俱计
		System.out.println("1_000_200 = " + x2);
		x2 = 2_0000; // 砞﹚┏絬俱计
		System.out.println("2_0000    = " + x2);

		System.out.println(".......double......");
		double x3;
		x3 = 1.05;
		System.out.println("跑计x = " + x3);
		x3 = .789;
		System.out.println("跑计x = " + x3);
		x3 = 5;
		System.out.println("跑计x = " + x3);
		x3 = 1.29E-2;
		System.out.println("跑计x = " + x3);
		x3 = 1.78E3;
		System.out.println("跑计x = " + x3);

		System.out.println(".......float......");
		float x4, y4, z4;
		x4 = 1.05F;
		System.out.println("跑计x1 = " + x4);
		y4 = .789F;
		System.out.println("跑计x2 = " + y4);
		z4 = x4 + y4;
		System.out.println("跑计x3 = " + z4);

	}

}