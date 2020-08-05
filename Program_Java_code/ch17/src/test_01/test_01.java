package test_01;

interface Math {

	public void show();

	public void add(int a, int b); // 計算 a+b

	public void sub(int a, int b); // 計算 a-b

	public void mul(int a, int b); // 計算 a*b

	public void div(int a, int b); // 計算 a/b
}

class Compute implements Math {

	int ans ;

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

}

public class test_01 {

	public static void main(String[] args) {
		Compute cmp = new Compute();
		cmp.mul(3, 5);// 計算 3*5
		cmp.show();// 此行會回應”ans=15”字串

	}

}
