package ch16_04_��H���O�`�Ϊx��;

abstract class MyMath{
	abstract int add(int n1,int n2);
	abstract int cut(int n1,int n2);
	void output() {
		System.out.println("�ڪ��p�⾹");
	}
}

class MyTest extends MyMath{
	@Override
	int add(int n1 ,int n2) {
		return n1+n2;
	}
	@Override
	int cut(int n1 ,int n2) {
		return n1+n2;
	}
	
	public int mul(int n1,int n2) {
		return n1*n2;
	}
	
	public double divide(int n1,int n2) {
		return (double)n1/(double)n2;
	}
}

public class ch16_04 {

	public static void main(String[] args) {
		MyTest obj1 = new MyTest();
		obj1.output();
		System.out.println("�[�k" + obj1.add(3, 8));
		System.out.println("��k" + obj1.cut(3, 8));
		System.out.println("���k" + obj1.mul(3, 8));
		System.out.println("���k" + obj1.divide(3, 8));
		
		MyMath obj2 = new MyTest();//upcasting
		obj2.output();
		System.out.println("�[�k" + obj2.add(3, 8));
		System.out.println("��k" + obj2.cut(3, 8));
//		System.out.println("���k" + obj2.mul(3, 8));
//		System.out.println("���k" + obj2.divide(3, 8));
		
		
	}

}
