package ch08_07_存取成員變數;


class Test{
	int x = 10;
	int y = 50;
	void pritInfo(int x)
	{
		System.out.println("區域變數" + x);
		System.out.println("屬性" + this.x);
		System.out.println("屬性" + y);
		System.out.println("屬性" + this.y);
	}
}



public class ch08_07 {

	public static void main(String[] args) {
		Test A = new Test();
		A.pritInfo(20);

	}

}
