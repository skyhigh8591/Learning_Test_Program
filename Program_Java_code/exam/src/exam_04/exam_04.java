package exam_04;
public class exam_04 {
	public static void main(String[] args) {
		System.out.println("40�P8 ���̤j���]�Ƭ��G" + common_factor(32, 6));
		System.out.println("41�P7 ���̤j���]�Ƭ��G" + common_factor(41, 7));
	}
	public static int common_factor(int a, int b) {
		int r = 0;
		while (b != 0) {
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
}
