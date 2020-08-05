package ch16_04_抽象類別常用泛型;

abstract class MyMath{
	abstract int add(int n1,int n2);
	abstract int cut(int n1,int n2);
	void output() {
		System.out.println("我的計算器");
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
		System.out.println("加法" + obj1.add(3, 8));
		System.out.println("減法" + obj1.cut(3, 8));
		System.out.println("乘法" + obj1.mul(3, 8));
		System.out.println("除法" + obj1.divide(3, 8));
		
		MyMath obj2 = new MyTest();//upcasting
		obj2.output();
		System.out.println("加法" + obj2.add(3, 8));
		System.out.println("減法" + obj2.cut(3, 8));
//		System.out.println("乘法" + obj2.mul(3, 8));
//		System.out.println("除法" + obj2.divide(3, 8));
		
		
	}

}
