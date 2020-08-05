package ch24_02_泛型類別_02;

class MyDate <T>{
	private T obj;
	
	void setobj(T obj) {
		this.obj = obj;
	}
	public T getobj() {
		return this.obj;
	}
	
}

public class ch24_02 {

	public static void main(String[] args) {
		MyDate<Integer> m = new MyDate<Integer>();
		m.setobj(10);
		System.out.println(m.getobj());
		
		MyDate<Double> d = new MyDate<Double>();
		d.setobj(10.21);
		System.out.println(d.getobj());
		
		MyDate<String> s = new MyDate<String>();
		s.setobj("你的名子");
		System.out.println(s.getobj());

	}

}
