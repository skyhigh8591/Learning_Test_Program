package test_02;

interface Math {

	public void show();

	public void add(int a, int b); // �p�� a+b

	public void sub(int a, int b); // �p�� a-b

	public void mul(int a, int b); // �p�� a*b

	public void div(int a, int b); // �p�� a/b
}

interface AdvancedMath {

	public void mod(int a, int b);// �p�� a%b

	public void fac(int a);// �p�� a!

	public void pow(int a, int b);// �p�� a b

}

class Compute implements Math, AdvancedMath {

	int ans = 0;

	@Override
	public void show() {
		System.out.println("ans=" + ans);
	}

	@Override
	public void add(int a, int b) {
		ans = a + b;
	}

	@Override
	public void sub(int a, int b) {
		ans = a - b;

	}

	@Override
	public void mul(int a, int b) {
		ans = a * b;

	}

	@Override
	public void div(int a, int b) {
		ans = a / b;

	}

	@Override
	public void mod(int a, int b) {
		ans = a % b;

	}

	@Override
	public void fac(int a) {
		ans = 1;
		for (int i = 1; i <= a; i++) {
			ans = ans * i;
		}

	}

	@Override
	public void pow(int a, int b) {
		ans = a;
		for (int i = 1; i < b; i++) {
			ans = ans * a;
		}
	}

}

public class test_02 {

	public static void main(String[] args) {
		Compute cmp = new Compute();
		cmp.mul(3, 5);// �p�� 3*5
		cmp.show();// ����|�^����ans=15���r��
		cmp.mod(14, 5);
		cmp.show();// ����|�^����ans=4���r��
		cmp.fac(5);
		cmp.show();// ����|�^����ans=120���r��
		cmp.pow(3, 5);
		cmp.show();
	}

}
