package ch09_02_�غc��k_02;

class Samllmath {//�ۭq�غc��k
	int x , y;

	Samllmath(int x , int y) {
		this.x = x;
		this.y = y;
	}

	void add() {
		System.out.println("�[�k���G" + (x+y));
	}
	void mul()
	{
		System.out.println("���k���G" + (x*y));
	}
}
public class ch09_02 {
	public static void main(String[] args) {
		Samllmath A = new Samllmath(10,5);
		A.add();
		A.mul();
		
	}
}
