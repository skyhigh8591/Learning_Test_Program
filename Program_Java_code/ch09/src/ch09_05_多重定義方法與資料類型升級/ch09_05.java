package ch09_05_�h���w�q��k�P��������ɯ�;

class Math{
	void additiom(long x , int y) {
		System.out.println(x+y);
	}
	void addition(int x , int y , int z) {
		System.out.println((x+y+z));
	}
}

public class ch09_05 {

	public static void main(String[] args) {
		Math A = new Math();
		A.additiom(5, 10);
		A.addition(5, 10, 15);

	}

}
