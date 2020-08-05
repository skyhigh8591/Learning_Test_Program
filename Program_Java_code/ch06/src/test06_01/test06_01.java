package test06_01;

public class test06_01 {

	public static void main(String[] args) {
		int sum = 0;
		for (int i = 0; i <= 100; i++) {
			if (i % 2 == 0) {
				continue;
			}
			sum += i;
		}
		System.out.println("1-100奇數和是:" + sum);

		int sum2 = 0;
		for (int i2 = 0; i2 <= 100; i2++) {
			if (i2 % 2 == 1) {
				continue;
			}
			sum2 += i2;
		}
		System.out.println("1-100偶數和是:" + sum2);

	}

}
