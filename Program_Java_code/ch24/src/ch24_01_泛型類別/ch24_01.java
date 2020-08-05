package ch24_01_ªx«¬Ãþ§O;

class MyDate{
	private Integer obj1;
	private Double obj2;
	
	public void setObj(Integer obj) {
		this.obj1 = obj;
	}
	
	public void setObj(Double obj) {
		this.obj2 = obj;
	}
	public Integer getObj1() {
		return obj1;
	}
	public Double getObj2() {
		return obj2;
	}
	
	
	
}

public class ch24_01 {

	public static void main(String[] args) {
		MyDate m = new MyDate();
		m.setObj(10);
		System.out.println(m.getObj1());
		
		MyDate m1 = new MyDate();
		m.setObj(11.2);
		System.out.println(m.getObj2());

	}

}
