package ch17_10_透過UpCasting使用介面功能;

interface School{
	int num_s=100;
	default public void demo() {
		System.out.println("school...");
	}
	default public void test1() {
		System.out.println("test1..");
	}
	public void test2();
	public void test3();
}

class Department implements School{
	int num_D=200;
	@Override
	public void test2() {
		System.out.println("test2..");		
	}

	@Override
	public void test3() {	
		System.out.println("test3..");
	}
	
	public void test4() {
		System.out.println("test4..");
	}
	
	public void demo() {
		System.out.println("Department...");
	}
	
}

public class ch17_10 {

	public static void main(String[] args) {
		
		Department d = new Department();
		d.demo();
		d.test1();
		d.test2();
		d.test3();
		d.test4();
		System.out.println(d.num_D);
		System.out.println(d.num_s);
		
		System.out.println("...........2............");
		School ds = new Department();
		ds.demo();
		ds.test1();
		ds.test2();
		ds.test3();
		//d.test4();
		System.out.println(ds.num_s);
		//System.out.println(d.num_D);
		
		//downcasting
		System.out.println("..........3............");
		Department c = (Department)ds;
		c.demo();
		c.test1();
		c.test2();
		c.test3();
		c.test4();
		System.out.println(c.num_D);
		System.out.println(c.num_s);
		

	}

}
