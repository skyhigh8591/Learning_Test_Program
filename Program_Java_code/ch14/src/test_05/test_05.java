package test_05;

class school{
	protected String title;
	protected String name;
	public void demo(){
		System.out.println("學校名稱" + title);
		System.out.println("學生名稱" + name);
	}		
}

class EE extends school{
	protected String Department;	
	public void DemoEE(){
		System.out.println("學校名稱" + title);
		System.out.println("學生名稱" + name);
		System.out.println("學生科系" + Department);
	}
	
}

class ME extends school{
	protected String Department;	
	public void DemoME(){
		System.out.println("學校名稱" + title);
		System.out.println("學生名稱" + name);
		System.out.println("學生科系" + Department);
	}	
}

public class test_05 {

	public static void main(String[] args) {
		EE E = new EE();
		ME M = new ME();
		E.Department = "朝揚科大";
		E.name = "電機";
		E.title = "Sam";
		E.DemoEE();
		System.out.println("....................");
		M.Department = "台北科大";
		M.name = "機械";
		M.title = "Lish";
		M.DemoME();
		
	}

}
