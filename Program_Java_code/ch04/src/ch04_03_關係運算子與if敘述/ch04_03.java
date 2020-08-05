package ch04_03_關係運算子與if敘述;

public class ch04_03 {

	public static void main(String[] args) {
		int x = 18;
		int y = 9;
		System.out.println("18 > 9     = " + (x > y));
		System.out.println("18 < 9     = " + (x < y));
		System.out.println("18 >= 18   = " + (x >= x));
		System.out.println("18 <= 18   = " + (x <= x));

		System.out.println("18 == 18   = " + (x == x));
		System.out.println("18 == 9    = " + (x == y));

		System.out.println("'x' == 'X' = " + ('x' == 'X'));

		System.out.println("18 != 18   = " + (x != x));
		System.out.println("18 != 9    = " + (x != y));

		System.out.println("'x' != 'X' = " + ('x' != 'X'));

	}
}

