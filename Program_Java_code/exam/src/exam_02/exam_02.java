package exam_02;
import java.util.Scanner;
public class exam_02 {
	public static void main(String[] args) {
		int student[] = new int[5];
		for (int i = 0; i < student.length; i++) {
			System.out.printf("�п�J��%d���ǥͦ��Z", i + 1);
			Scanner scanner = new Scanner(System.in);
			student[i] = scanner.nextInt();
		}
		for (int i = 0; i < student.length; i++) {
			String x;
			x = (student[i] > 80) ? "level A" 
					: (student[i] <= 80 && student[i] >= 60) ? "level B" 
							: "level C";
			System.out.printf("��%d���ǥ�\n%d=>%s\n", i + 1, student[i], x);
		}
	}
}
