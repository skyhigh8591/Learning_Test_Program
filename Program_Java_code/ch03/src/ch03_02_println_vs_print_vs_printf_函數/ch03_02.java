package ch03_02_println_vs_print_vs_printf_���;

public class ch03_02 {

	public static void main(String[] args) {
		// int i = 4; //���
		// double j = 5;

		int i;
		double j;
		i = 4;
		j = 5;

		// print
		System.out.print("��Xi=" + i + "\n");
		System.out.print("��Xj=" + j + "\n");

		// println �۰ʴ���
		System.out.println("��Xi=" + i);
		System.out.println("��Xj=" + j);

		// printf
		System.out.printf("��Xi=%d\n", i);
		System.out.printf("��Xj=%f\n", j);
		System.out.printf("��Xi=%d,��Xj=%f\n", i, j);
		
	}

}
