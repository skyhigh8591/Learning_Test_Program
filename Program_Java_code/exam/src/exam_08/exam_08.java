package exam_08;
class Ca {
	private int num1;
	private int num2;
	public int getNum2() {
		return num2;
	}
	public void setNum2(int num2) {
		this.num2 = num2;
	}
	public int getNum1() {
		return num1;
	}
	public void setNum1(int num1) {
		this.num1 = num1;
	}
}
class Cb extends Ca {
	Ca a = new Ca();
	public void set_num(int num1, int num2) {
		a.setNum1(num1);
		a.setNum2(num2);
	}
	public void show() {
		System.out.println(a.getNum1());
		System.out.println(a.getNum2());
	}
}
public class exam_08 {
	public static void main(String[] args) {
		Cb b = new Cb();
		b.set_num(5, 10);
		b.show();
	}
}
