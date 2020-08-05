package test06_02;

public class test06_02 {

	public static void main(String[] args) {
		int x;

		for (int i = 2; i <= 100; i++) {

			for (x = 2; x < i; x++) {
				if (i % x == 0)
					break;
			}
			if (x >= i) {
				System.out.println(i);
			}
		}
	}
}
