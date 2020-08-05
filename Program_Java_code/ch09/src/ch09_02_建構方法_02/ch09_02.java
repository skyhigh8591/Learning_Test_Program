package ch09_02_建構方法_02;

class Samllmath {//自訂建構方法
	int x , y;

	Samllmath(int x , int y) {
		this.x = x;
		this.y = y;
	}

	void add() {
		System.out.println("加法結果" + (x+y));
	}
	void mul()
	{
		System.out.println("乘法結果" + (x*y));
	}
}
public class ch09_02 {
	public static void main(String[] args) {
		Samllmath A = new Samllmath(10,5);
		A.add();
		A.mul();
		
	}
}
