package exam_03;
public class exam_03 {
	public static void main(String[] args) {
		for (int i3 = 5; i3 >= 1; i3--) {
			for (int i4 = 1; i4 <= i3 - 1; i4++) {
				System.out.print(" ");
			}
			for (int i2 = 5; i2 >= i3; i2--) {
				System.out.print("*");
			}
			System.out.print("\n");
		}
	}
}
