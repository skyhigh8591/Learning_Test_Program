package ch04_06_運算式的資料型態轉換;

public class ch04_06 {

	public static void main(String[] args) {
		char ch = 'x';// char 要使用單引號
		short s = -5;
		int i = 6;
		float f = 9.7f;
		double d = 1.76;
		System.out.println((s * ch) - (d / f) * (i + f));
	}

}
