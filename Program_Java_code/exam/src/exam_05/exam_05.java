package exam_05;
import java.util.Scanner;
public class exam_05 {
	public static void main(String[] args) {
		String x = "1234";
		System.out.println("½Ð¿é¤J0243");
		Scanner scanner = new Scanner(System.in);
		String z = scanner.next();
		int a = 0;
		int b = 0;
		int r = 0;
		int t = 0;
		int u = 0;
		int y = 0;
		for (int i = 0; i < 4; i++) {
			r = Integer.parseInt(x.substring(i, i + 1));
			t = Integer.parseInt(z.substring(i, i + 1));
			if (r == t) {
				a = a + 1;
			}
			u = Integer.parseInt(x.substring(i, i + 1));
			for (int q = 0; q < 4; q++) {
				y = Integer.parseInt(z.substring(q, q + 1));
				if (u == y) {
					b++;
				}
			}
		}
		b = b - a;
		System.out.printf("%dA%dB\n", a, b);
	}
}
