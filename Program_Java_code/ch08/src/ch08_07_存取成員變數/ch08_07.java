package ch08_07_�s�������ܼ�;


class Test{
	int x = 10;
	int y = 50;
	void pritInfo(int x)
	{
		System.out.println("�ϰ��ܼ�" + x);
		System.out.println("�ݩ�" + this.x);
		System.out.println("�ݩ�" + y);
		System.out.println("�ݩ�" + this.y);
	}
}



public class ch08_07 {

	public static void main(String[] args) {
		Test A = new Test();
		A.pritInfo(20);

	}

}
